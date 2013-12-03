#include "records.h"

#define ARRAY_LENGTH 1000
#define RECORD_LENGTH 7

void bubblesort( int a[][ RECORD_LENGTH ], int N ) {
	int i,j,t, ti;
	for( i = N-1; i >= 1; i--) {			//BUG, should be N-1, not N
		for( j = 1; j <= i; j++ ) {		//BUG, should be j=1, not j=2
			if ( a[ j - 1 ][ 0 ] > a[ j ][ 0 ] ) {
				for ( ti = 0; ti < RECORD_LENGTH; ti++ ) {
					t = a[ j - 1 ][ ti ];
					a[ j - 1 ][ ti ] = a[ j ][ ti ];
					a[ j ][ ti ] = t;
				}
			}
		}
	}
};


int main() {
	clear_cache();
	bubblesort( records, ARRAY_LENGTH );
	promexit();
	return 0;
}
