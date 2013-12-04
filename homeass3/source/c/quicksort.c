#include "records2.h"

#define RECORD_LENGTH 27
#define ARRAY_LENGTH 1000

void quicksort( int a[][ RECORD_LENGTH ], int l, int r ) {
	int v, i, j, t, ti;
	int length = r - l + 1;
	if ( length < 5 ) {
		for ( i = 0; i < length; i++ ) {
			j = i;
			while ( j > 0 && a[ j + l - 1 ][ 0 ] > a[ j + l ][ 0 ] ) {
				for ( ti = 0; ti < RECORD_LENGTH; ti++ ) {
					t = a[ j + l ][ ti ];
					a[ j + l ][ ti ] = a[ j + l - 1 ][ ti ];
					a[ j + l - 1 ][ ti ] = t;
				}
				j--;
			}
		}
	} else if ( r > l ) {
		v = a[ r ][ 0 ];
		i = l - 1;
		j = r;

		for ( ;; ) {
			while ( a[ ++i ][ 0 ] < v );
			while ( a[ --j ][ 0 ] > v );
			if ( i >= j ) break;
			for ( ti = 0; ti < RECORD_LENGTH; ti++ ) {
				t = a[ i ][ ti ];
				a[ i ][ ti ] = a[ j ][ ti ];
				a[ j ][ ti ] = t;
			}
		}
		for ( ti = 0; ti < RECORD_LENGTH; ti++ ) {
			t = a[ i ][ ti ];
			a[ i ][ ti ] = a[ r ][ ti ];
			a[ r ][ ti ] = t;
		}

		quicksort( a, l, i - 1 );
		quicksort( a, i + 1, r );
	}
}

int main() {
	clear_cache();
	quicksort( records, 0, ARRAY_LENGTH );
	promexit();
	return 0;
}
