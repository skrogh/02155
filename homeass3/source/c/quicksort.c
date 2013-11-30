#include <stdio.h>

#include "records.h"

#define RECORD_LENGTH 7
#define ARRAY_LENGTH 1000

void quicksort( int a[][ RECORD_LENGTH ], int l, int r ) {
	int v, i, j, t[ RECORD_LENGTH ], ti;
	if ( r > l ) {
		v = a[ r ][ 0 ];
		i = l - 1;
		j = r;

		for ( ;; ) {
			while ( a[ ++i ][ 0 ] < v );
			while ( a[ --j ][ 0 ] > v );
			if ( i >= j ) break;
			for ( ti = 0; ti < RECORD_LENGTH; ti++ ) {
				t[ ti ] = a[ i ][ ti ];
				a[ i ][ ti ] = a[ j ][ ti ];
				a[ j ][ ti ] = t[ ti ];
			}
		}
		for ( ti = 0; ti < RECORD_LENGTH; ti++ ) {
			t[ ti ] = a[ i ][ ti ];
			a[ i ][ ti ] = a[ r ][ ti ];
			a[ r ][ ti ] = t[ ti ];
		}

		quicksort( a, l, i - 1 );
		quicksort( a, i + 1, r );
	}
}

int main() {

	quicksort( records, 0, ARRAY_LENGTH );

}
