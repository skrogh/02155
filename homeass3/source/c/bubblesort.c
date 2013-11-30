#include <stdlib.h>
#include <stdio.h>

#define ARRAY_LENGTH 10

int a[10] = {9,8,7,6,5,4,3,2,1,0};

void bubblesort( int a[], int N ) {
	int i,j,t;
	for( i = N-1; i >= 1; i--) {			//BUG, should be N-1
		for( j = 1; j <= i; j++ ) {		//BUG, should be j=1
			if ( a[ j - 1 ] > a[ j ] ) {
				t = a[ j - 1 ];
				a[ j - 1 ] = a[ j ];
				a[ j ] = t;
			}
		}
	}
};


int main() {

	bubblesort( a, ARRAY_LENGTH );

	int i = 0;
	for (i = 0; i < ARRAY_LENGTH; i++ ) {
		printf( "%d,", a[ i ] );
	}

	printf( "\n" );

	return 0;
}
