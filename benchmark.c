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


unsigned long int* pvs_init101(unsigned long int* A, int i, unsigned long int v) {
  unsigned long int* B;
  if ( GC_count( A ) == 1 )
    B = A;
  else {
    B = GC_malloc(20000, sizeof(unsigned long int) );
    int i251;
    for(i251 = 0; i251 < 20000; i251++) {
      B[i251] = A[i251];
    }
  }
  B[i] = v;
  if ((i >= 999)) {
    return B;
  } else {
    return pvs_init_d102( B , (i + 1) , ((12345 * v) % 59557) );
  }
}

unsigned long int* pvs_init_d102(unsigned long int* A, int i, unsigned long int v) {
  A[i] = v;
  if ((i >= 999)) {
    return A;
  } else {
    return pvs_init_d102( A , (i + 1) , ((12345 * v) % 59557) );
  }
}

unsigned long int pvs_J127(int k) {
  return (unsigned long int) (999 - k);
}

unsigned long int pvs_J_d128(int k) {
  return (unsigned long int) (999 - k);
}

unsigned long int pvs_Z129(int x) {
  return (unsigned long int) 0;
}

unsigned long int pvs_Z_d130(int x) {
  return (unsigned long int) 0;
}

unsigned long int* pvs_T131() {
  unsigned long int* aux134;
  aux134 = GC_malloc(20000, sizeof(unsigned long int) );
  int i133;
  for(i133 = 0; i133 < 20000; i133++) {
    aux134[i133] = pvs_Z_d130( i133 );
  }
  return pvs_init_d102( aux134 , 0 , (unsigned long int) 9876 );
}

unsigned long int* pvs_T_d132() {
  unsigned long int* aux136;
  aux136 = GC_malloc(20000, sizeof(unsigned long int) );
  int i135;
  for(i135 = 0; i135 < 20000; i135++) {
    aux136[i135] = pvs_Z_d130( i135 );
  }
  return pvs_init_d102( aux136 , 0 , (unsigned long int) 9876 );
}

unsigned long int* pvs_insert139(unsigned long int* A, unsigned long int v, int i) {
  unsigned long int* result;
  if (((i == 0) || (v >= A[(i - 1)]))) {
    if ( GC_count( A ) == 1 )
      result = A;
    else {
      result = GC_malloc(20000, sizeof(unsigned long int) );
      int i252;
      for(i252 = 0; i252 < 20000; i252++) {
        result[i252] = A[i252];
      }
    }
    result[i] = v;
    return result;
  } else {
    unsigned long int res144;
    res144 = A[(i - 1)];
    unsigned long int* aux145;
    if ( GC_count( A ) == 1 )
      aux145 = A;
    else {
      aux145 = GC_malloc(20000, sizeof(unsigned long int) );
      int i253;
      for(i253 = 0; i253 < 20000; i253++) {
        aux145[i253] = A[i253];
      }
    }
    aux145[i] = res144;
    return pvs_insert_d140( aux145 , v , (i - 1) );
  }
}

unsigned long int* pvs_insert_d140(unsigned long int* A, unsigned long int v, int i) {
  if (((i == 0) || (v >= A[(i - 1)]))) {
    A[i] = v;
    return A;
  } else {
    unsigned long int res149;
    res149 = A[(i - 1)];
    A[i] = res149;
    return pvs_insert_d140( A , v , (i - 1) );
  }
}

unsigned long int* pvs_insort_rec233(unsigned long int* A, int n) {
  if ((n < 1000)) {
    unsigned long int An;
    An = A[n];
    return pvs_insort_rec_d234( pvs_insert139( A , An , n ) , (n + 1) );
  } else {
    return A;
  }
}

unsigned long int* pvs_insort_rec_d234(unsigned long int* A, int n) {
  if ((n < 1000)) {
    unsigned long int An;
    An = A[n];
    return pvs_insort_rec_d234( pvs_insert_d140( A , An , n ) , (n + 1) );
  } else {
    return A;
  }
}

unsigned long int* pvs_insort237(unsigned long int* A) {
  return pvs_insort_rec233( A , 0 );
}

unsigned long int* pvs_insort_d238(unsigned long int* A) {
  return pvs_insort_rec_d234( A , 0 );
}

unsigned long int pvs_tsort241() {
  return pvs_insort_d238( pvs_T_d132() )[0];
}

unsigned long int pvs_tsort_d242() {
  return pvs_insort_d238( pvs_T_d132() )[0];
}

unsigned long int pvs_jsort243() {
  unsigned long int* aux246;
  aux246 = GC_malloc(20000, sizeof(unsigned long int) );
  int i245;
  for(i245 = 0; i245 < 20000; i245++) {
    aux246[i245] = pvs_J_d128( i245 );
  }
  return pvs_insort_d238( aux246 )[0];
}

unsigned long int pvs_jsort_d244() {
  unsigned long int* aux248;
  aux248 = GC_malloc(20000, sizeof(unsigned long int) );
  int i247;
  for(i247 = 0; i247 < 20000; i247++) {
    aux248[i247] = pvs_J_d128( i247 );
  }
  return pvs_insort_d238( aux248 )[0];
}