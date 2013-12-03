#include <stdio.h>

void quicksort( int a[], int l, int r ) {
	int v, i, j, t;
	if ( r > l ) {
		v=a[ r ];
		i = l-1;
		j = r;

		for ( ;; ) {
			while ( a[ ++i ] < v);
			while ( a[ --j ] > v);
			if ( i >= j ) break;
			t = a[ i ];
			a[ i ] = a[ j ];
			a[ j ] = t;
		}

		t = a[ i ];
		a[ i ] = a[ r ];
		a[ r ] = t;

		quicksort( a, l, i - 1);
		quicksort( a, i + 1, r);
	}
}


int main() {
	int unsorted[] = {8,7,6,5,4,3,2,1,0};
	for ( int i = 0; i < 9; i++ ) {
		printf( " %d, ", unsorted[ i ] );
	}
	printf( "\n" );
	quicksort( unsorted, 0, 8 );
	
	for ( int i = 0; i < 9; i++ ) {
		printf( " %d, ", unsorted[ i ] );
	}
	printf( "\n" );
}
