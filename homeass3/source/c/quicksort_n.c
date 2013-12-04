#include <stdio.h>
#include <stdlib.h>

#include "records2.h"

#define RECORD_LENGTH 27
#define ARRAY_LENGTH 1000

void print_array( int *array, int length, int elements ) {
	int i, j;
	for( i = 0; i < length; i++) {
	    for( j = 0; j < elements; j++) {
	        printf("%d ", *(array + i*elements + j) );
	    }
	    printf("\n");
	}
}

void array_copy( int *source, int *sink, int length ) {
	int i;
	for( i = 0; i < length; i++) {
		*(sink + i) = *(source + i);
	}
}



/*
* source is the array whished to be sorted
* sink is the initalized helper array
* length is the number of records 
* elements_rows is the number of elements pr row
*/

void init_n( int helper[][2], int *source, int length, int elements_row ) {
	int i;
	for( i = 0; i < length; i++ ) {
		helper[i][0] = *(source + elements_row*i); // set sink[i][0] to source[i][0]
		helper[i][1] = i;
	}
} 

/*
* copy lines from source to result,
* arranged in the order dictated by helper
*/
void arrange_n( int helper[][2], int *source, int *result, int length, int elements_row ) {
	int i, j;
	register int t;
	for( i = 0; i < length; i++ ) {
		t = helper[i][1];
		for( j = 0; j < elements_row; j++ ) {
			*(result + elements_row*i + j ) = *(source + elements_row*t + j);
		}
	}
}

void quicksort_n( int a[][ 2 ], int l, int r ) { // used to sort the helper array from init_n
	int v, i, j, t, ti;
	if ( r > l ) {
		v = a[ r ][ 0 ];
		i = l - 1;
		j = r;

		for ( ;; ) {
			while ( a[ ++i ][ 0 ] < v );
			while ( a[ --j ][ 0 ] > v );
			if ( i >= j ) break;
			for ( ti = 0; ti < 2; ti++ ) {
				t = a[ i ][ ti ];
				a[ i ][ ti ] = a[ j ][ ti ];
				a[ j ][ ti ] = t;
			}
		}
		for ( ti = 0; ti < 2; ti++ ) {
			t = a[ i ][ ti ];
			a[ i ][ ti ] = a[ r ][ ti ];
			a[ r ][ ti ] = t;
		}

		quicksort_n( a, l, i - 1 );
		quicksort_n( a, i + 1, r );
	}
}

void bubblesort_n( int a[][ 2 ], int N ) {
	int i,j,t, ti;
	for( i = N-1; i >= 1; i--) {			//BUG, should be N-1
		for( j = 1; j <= i; j++ ) {		//BUG, should be j=1
			if ( a[ j - 1 ][ 0 ] > a[ j ][ 0 ] ) {
				for ( ti = 0; ti < 2; ti++ ) {
					t = a[ j - 1 ][ ti ];
					a[ j - 1 ][ ti ] = a[ j ][ ti ];
					a[ j ][ ti ] = t;
				}
			}
		}
	}
};

void quicksort_var( int *array, int length, int elements ) {
	int *sorted = (int*)malloc( sizeof(int)*length*elements );
	int *helper = (int*)malloc( sizeof(int)*length*2 );
	
	init_n( helper, records, length, elements );
	
	clear_cache();
	quicksort_n( helper, 0, length );
	promexit();
	
	arrange_n( helper, records, sorted, length, elements );
	
	array_copy( sorted, array, length*elements );
	
	free( sorted );
	free( helper );
}

void bubblesort_var( int *array, int length, int elements ) {
	int *sorted = (int*)malloc( sizeof(int)*length*elements );
	int *helper = (int*)malloc( sizeof(int)*length*2 );
	
	init_n( helper, records, length, elements );
	
	bubblesort_n( helper, length );
	arrange_n( helper, records, sorted, length, elements );
	
	array_copy( sorted, array, length*elements );
	
	free( sorted );
	free( helper );
}

int main() {
	// clone records
	int records_c[ARRAY_LENGTH][RECORD_LENGTH];
	array_copy( records, records_c, ARRAY_LENGTH*RECORD_LENGTH  );

	// do profilling
	clear_cache();
	
	quicksort_var( records, ARRAY_LENGTH, RECORD_LENGTH );
	
	// do a new profilling
	promexit();
	clear_cache();
	
	bubblesort_var( records_c, ARRAY_LENGTH, RECORD_LENGTH );
	
	// check
	promexit();
	print_array( records_c, ARRAY_LENGTH, RECORD_LENGTH );
	return 0;
}
