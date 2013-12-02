#include <stdio.h>

#define TAB_SIZE 2048
#define CACHE_SIZE 128

int main() {
	int A[ TAB_SIZE ];
	register int sum, i, j;
	
	promexit();
	clear_cache();
	
	//Initialization
	sum = 0;
	for ( i = 0; i < TAB_SIZE; i++ ) {
		A[ i ] = 1;
	}
	
	//Data referencing
	for ( i = 0; i < TAB_SIZE; i++ ) {
		for ( j = 0; j < 5; j++ ) {
			sum += A[ i ];
		}
	}

	for ( i = CACHE_SIZE; i < TAB_SIZE - CACHE_SIZE; i++ ) {
		for ( j = 0; j < 5; j++ ) {
			sum += A[ i ];
		}
	}
	
	promexit();

	printf( "Sum = %d\n", sum );
	return 0;
}
