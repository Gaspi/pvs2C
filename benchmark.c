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

int main(void) {
  GC_start();
  printf("Executing benchmark ...\n");
  // Insert code here
  GC_quit();
  return 0;
}


unsigned long int* pvs_init47(unsigned long int* A, int i, unsigned long int v) {
  unsigned long int* B;
  if ( GC_count( A ) == 1 )
    B = A;
  else {
    B = GC_malloc(20000, sizeof(unsigned long int) );
    int i197;
    for(i197 = 0; i197 < 20000; i197++) {
      B[i197] = A[i197];
    }
  }
  B[i] = v;
  if ((i >= 999)) {
    return B;
  } else {
    return pvs_init_d48( B , (i + 1) , ((12345 * v) % 59557) );
  }
}

unsigned long int* pvs_init_d48(unsigned long int* A, int i, unsigned long int v) {
  A[i] = v;
  if ((i >= 999)) {
    return A;
  } else {
    return pvs_init_d48( A , (i + 1) , ((12345 * v) % 59557) );
  }
}

unsigned long int pvs_J73(int k) {
  return (unsigned long int) (999 - k);
}

unsigned long int pvs_J_d74(int k) {
  return (unsigned long int) (999 - k);
}

unsigned long int pvs_Z75(int x) {
  return (unsigned long int) 0;
}

unsigned long int pvs_Z_d76(int x) {
  return (unsigned long int) 0;
}

unsigned long int* pvs_T77() {
  unsigned long int* aux80;
  aux80 = GC_malloc(20000, sizeof(unsigned long int) );
  int i79;
  for(i79 = 0; i79 < 20000; i79++) {
    aux80[i79] = pvs_Z_d76( i79 );
  }
  return pvs_init_d48( aux80 , 0 , (unsigned long int) 9876 );
}

unsigned long int* pvs_T_d78() {
  unsigned long int* aux82;
  aux82 = GC_malloc(20000, sizeof(unsigned long int) );
  int i81;
  for(i81 = 0; i81 < 20000; i81++) {
    aux82[i81] = pvs_Z_d76( i81 );
  }
  return pvs_init_d48( aux82 , 0 , (unsigned long int) 9876 );
}

unsigned long int* pvs_insert85(unsigned long int* A, unsigned long int v, int i) {
  unsigned long int* result;
  if (((i == 0) || (v >= A[(i - 1)]))) {
    if ( GC_count( A ) == 1 )
      result = A;
    else {
      result = GC_malloc(20000, sizeof(unsigned long int) );
      int i198;
      for(i198 = 0; i198 < 20000; i198++) {
        result[i198] = A[i198];
      }
    }
    result[i] = v;
    return result;
  } else {
    unsigned long int res90;
    res90 = A[(i - 1)];
    unsigned long int* aux91;
    if ( GC_count( A ) == 1 )
      aux91 = A;
    else {
      aux91 = GC_malloc(20000, sizeof(unsigned long int) );
      int i199;
      for(i199 = 0; i199 < 20000; i199++) {
        aux91[i199] = A[i199];
      }
    }
    aux91[i] = res90;
    return pvs_insert_d86( aux91 , v , (i - 1) );
  }
}

unsigned long int* pvs_insert_d86(unsigned long int* A, unsigned long int v, int i) {
  if (((i == 0) || (v >= A[(i - 1)]))) {
    A[i] = v;
    return A;
  } else {
    unsigned long int res95;
    res95 = A[(i - 1)];
    A[i] = res95;
    return pvs_insert_d86( A , v , (i - 1) );
  }
}

unsigned long int* pvs_insort_rec179(unsigned long int* A, int n) {
  if ((n < 1000)) {
    unsigned long int An;
    An = A[n];
    return pvs_insort_rec_d180( pvs_insert85( A , An , n ) , (n + 1) );
  } else {
    return A;
  }
}

unsigned long int* pvs_insort_rec_d180(unsigned long int* A, int n) {
  if ((n < 1000)) {
    unsigned long int An;
    An = A[n];
    return pvs_insort_rec_d180( pvs_insert_d86( A , An , n ) , (n + 1) );
  } else {
    return A;
  }
}

unsigned long int* pvs_insort183(unsigned long int* A) {
  return pvs_insort_rec179( A , 0 );
}

unsigned long int* pvs_insort_d184(unsigned long int* A) {
  return pvs_insort_rec_d180( A , 0 );
}

unsigned long int pvs_tsort187() {
  return pvs_insort_d184( pvs_T_d78() )[0];
}

unsigned long int pvs_tsort_d188() {
  return pvs_insort_d184( pvs_T_d78() )[0];
}

unsigned long int pvs_jsort189() {
  unsigned long int* aux192;
  aux192 = GC_malloc(20000, sizeof(unsigned long int) );
  int i191;
  for(i191 = 0; i191 < 20000; i191++) {
    aux192[i191] = pvs_J_d74( i191 );
  }
  return pvs_insort_d184( aux192 )[0];
}

unsigned long int pvs_jsort_d190() {
  unsigned long int* aux194;
  aux194 = GC_malloc(20000, sizeof(unsigned long int) );
  int i193;
  for(i193 = 0; i193 < 20000; i193++) {
    aux194[i193] = pvs_J_d74( i193 );
  }
  return pvs_insort_d184( aux194 )[0];
}