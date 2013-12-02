#include <stdio.h>

#define TAB_SIZE 2048
#define CACHE_SIZE 128

int main() {
	int A[ TAB_SIZE ];
	register int sum, i, j;
	
	promexit(); //pause, we don't want to wait for the initial init of the processor
	clear_cache();	//get ready for benchmark
	//Initialization
	sum = 0;
	for ( i = 0; i < TAB_SIZE; i++ ) {
		A[ i ] = 1;
	}

	//Data referencing
	for ( i = 0; i < TAB_SIZE - CACHE_SIZE; i++ ) {
		for ( j = 0; j < 5; j++ ) {
			sum += A[ i ];
			sum += A[ i + CACHE_SIZE ];
		}
	}
	
	promexit();

	printf( "Sum = %d\n", sum );
	return 0;
}
