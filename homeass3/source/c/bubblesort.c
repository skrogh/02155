#include <stdlib.h>
#include <stdio.h>
#include "records.h"

#define ARRAY_LENGTH 1000
#define RECORD_LENGTH 7

void bubblesort( int a[][ RECORD_LENGTH ], int N ) {
	int i,j,t[ RECORD_LENGTH ], ti;
	for( i = N-1; i >= 1; i--) {			//BUG, should be N-1
		for( j = 1; j <= i; j++ ) {		//BUG, should be j=1
			if ( a[ j - 1 ][ 0 ] > a[ j ][ 0 ] ) {
				for ( ti = 0; ti < RECORD_LENGTH; ti++ ) {
					t[ ti ] = a[ j - 1 ][ ti ];
					a[ j - 1 ][ ti ] = a[ j ][ ti ];
					a[ j ][ ti ] = t[ ti ];
				}
			}
		}
	}
};


int main() {
	int i = 0;
	bubblesort( records, ARRAY_LENGTH );

	
	for (i = 0; i < ARRAY_LENGTH; i++ ) {
		printf( "%d,", records[ i ][ 0 ] );
	}

	printf( "\n" );

	return 0;
}
