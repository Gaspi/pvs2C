#include <stdlib.h>
#include <stdio.h>

#include "GC.h"



int main( int argc, char **argv ) {
  GC_start();
  
  int* a = GC_malloc( 1, sizeof(int)  );
  a[0] = 5;
  int* b = GC( a );
  int* c = GC( b );
  
  char* d = GC( "d" );  // Carefull, pointers to "d" should not be freed
  
  printf( "a: %d\n", GC_count( a ) );
  printf( "b: %d\n", GC_count( b ) );
  if ( GC_free(a) ) free(a);
  printf( "c: %d\n", GC_count( c ) );
  printf( "d: %d\n", GC_count( d ) );
  
  if ( GC_free(b) ) free(b);
  printf("Count = %d, var[0] = %d \n", GC_count(a), a[0] ); 
  if ( GC_free(c) ) free(c);  // Last freeing
  printf("Count = %d, var[0] = %d \n", GC_count(a), a[0] ); 
  
  GC_quit();
  return 0;
}

