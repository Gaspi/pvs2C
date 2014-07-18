// ---------------------------------------------
//        C file generated from report.pvs
// ---------------------------------------------
//   Make sure to link GC.c and GMP in compilation:
//      gcc -o report report.c GC.c -lgmp
//      ./report
// ---------------------------------------------

#include<stdio.h>
#include<gmp.h>
#include "GC.h"
#include "report.h"

#define TRUE 1
#define FALSE 0

int main(void) {
  printf("Executing report ...\n");
  return 0;
}


int* pvs_f1650(int* A) {
  int* result;
  result = (int*) GC( A );
  return result;
}

int* pvs_d_f1651(int* A) {
  int* result;
  result = (int*) GC( A );
  return result;
}

int* pvs_f2652(int* A) {
  int* B;
  B = (int*) GC( A );
  int* result;
  result = (int*) GC( B );
  GC_free(B)
  return result;
}

int* pvs_d_f2653(int* A) {
  int* B;
  B = (int*) GC( A );
  int* result;
  result = (int*) GC( B );
  GC_free(B)
  return result;
}

int pvs_f3656(int* A) {
  int* B;
  B = (int*) GC( A );
  int result;
  result = (A[0] + B[0]);
  GC_free(B)
  return result;
}

int pvs_d_f3657(int* A) {
  int* B;
  B = (int*) GC( A );
  int result;
  result = (A[0] + B[0]);
  GC_free(B)
  return result;
}

int* pvs_f4660(int* A) {
  int* result;
  int* B;
  B = (int*) GC( A );
  int L665;
  L665 = 0;
  int res666;
  res666 = B[0];
  result = GC_malloc(10, sizeof(int) );
  int i667;
  for(i667 = 0; i667 < 10; i667++) {
    result[i667] = A[i667];
  }
  result[L665] = res666;
  return result;
}

int* pvs_d_f4661(int* A) {
  int* result;
  int* B;
  B = (int*) GC( A );
  int L665;
  L665 = 0;
  int res666;
  res666 = B[0];
  result = GC_malloc(10, sizeof(int) );
  int i667;
  for(i667 = 0; i667 < 10; i667++) {
    result[i667] = A[i667];
  }
  result[L665] = res666;
  return result;
}

int* pvs_g1668(int* A) {
  int* result;
  int L673;
  L673 = 0;
  int res674;
  res674 = 0;
  result = GC_malloc(10, sizeof(int) );
  int i675;
  for(i675 = 0; i675 < 10; i675++) {
    result[i675] = A[i675];
  }
  result[L673] = res674;
  return result;
}

int* pvs_d_g1669(int* A) {
  int* result;
  int L673;
  L673 = 0;
  int res674;
  res674 = 0;
  result = GC_malloc(10, sizeof(int) );
  int i675;
  for(i675 = 0; i675 < 10; i675++) {
    result[i675] = A[i675];
  }
  result[L673] = res674;
  return result;
}

int* pvs_g2676(int* A) {
  int* result;
  int* B;
  int L684;
  L684 = 0;
  int res685;
  res685 = 0;
  B = GC_malloc(10, sizeof(int) );
  int i688;
  for(i688 = 0; i688 < 10; i688++) {
    B[i688] = A[i688];
  }
  B[L684] = res685;
  int L686;
  L686 = 0;
  int res687;
  res687 = B[0];
  result = GC_malloc(10, sizeof(int) );
  int i689;
  for(i689 = 0; i689 < 10; i689++) {
    result[i689] = A[i689];
  }
  result[L686] = res687;
  return result;
}

int* pvs_d_g2677(int* A) {
  int* result;
  int* B;
  int L684;
  L684 = 0;
  int res685;
  res685 = 0;
  B = GC_malloc(10, sizeof(int) );
  int i688;
  for(i688 = 0; i688 < 10; i688++) {
    B[i688] = A[i688];
  }
  B[L684] = res685;
  int L686;
  L686 = 0;
  int res687;
  res687 = B[0];
  result = GC_malloc(10, sizeof(int) );
  int i689;
  for(i689 = 0; i689 < 10; i689++) {
    result[i689] = A[i689];
  }
  result[L686] = res687;
  return result;
}