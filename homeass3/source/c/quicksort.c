#include <stdio.h>

#include "records.h"
void quicksort( int a, int l, int r ) {
	int v, i, j, t;
	if ( r > l ) {
		v = a[ r ];
		i = l - 1;
		j = r;

		for ( ;; ) {
			while ( a[ ++i ] < v );
			while ( a[ --j ] > v );
			t = a[ i ];
			a[ i ] = a[ j ];
			a[ j ] = t;
		}
		t = a[ i ];
		a[ i ] = a[ r ];
		a[ r ] = t;

		quicksort( a, l, i - 1 );
		quicksort( a, i + 1, r );
	}
}

int main() {

}
