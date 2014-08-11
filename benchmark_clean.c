// ---------------------------------------------
//        C file generated from benchmark.pvs
// ---------------------------------------------
//   Make sure to link GC.c and GMP in compilation:
//      gcc -o benchmark benchmark.c GC.c -lgmp
//      ./benchmark
// ---------------------------------------------

#include<stdio.h>
#include<gmp.h>
#include "GC.h"
#include "benchmark.h"

#define TRUE 1
#define FALSE 0

#define SIZE   20000
#define SIZE_1 19999

int main(void) {
  GC_start();
  printf("Executing benchmark ...\n");
//  printf("jsort = %lu\n", jsort() );
  printf("tsort = %lu\n", tsort() );
  GC_quit();
  return 0;
}

unsigned long int* init(unsigned long int* A, int i, unsigned long int v) {
  A[i] = v;
  if ((i >= SIZE_1)) {
    return A;
  } else {
    return init( A , (i + 1) , ((12345 * v) % 59557) );
  }
}

unsigned long int J(int k) {
  return (unsigned long int) (SIZE_1 - k);
}

unsigned long int Z(int x) {
  return (unsigned long int) 0;
}

unsigned long int* T() {
  unsigned long int* aux;
  aux = GC_malloc(SIZE, sizeof(unsigned long int) );
  int i;
  for(i = 0; i < SIZE; i++) {
    aux[i] = Z( i );
  }
  return init( aux , 0 , (unsigned long int) 9876 );
}

unsigned long int* insert(unsigned long int* A, unsigned long int v, int i) {
  if (((i == 0) || (v >= A[(i - 1)]))) {
    A[i] = v;
    return A;
  } else {
    unsigned long int res;
    res = A[(i - 1)];
    A[i] = res;
    return insert( A , v , (i - 1) );
  }
}

unsigned long int* insort_rec(unsigned long int* A, int n) {
  if ((n < SIZE)) {
    unsigned long int An;
    An = A[n];
    return insort_rec( insert( A , An , n ) , (n + 1) );
  } else {
    return A;
  }
}

unsigned long int* insort(unsigned long int* A) {
  return insort_rec( A , 0 );
}

unsigned long int tsort() {
  return insort( T() )[0];
}

unsigned long int jsort() {
  unsigned long int* aux;
  aux = GC_malloc(SIZE, sizeof(unsigned long int) );
  int i;
  for(i = 0; i < SIZE; i++) {
    aux[i] = J( i );
  }
  return insort( aux )[0];
}
