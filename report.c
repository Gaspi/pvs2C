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


int* pvs_f187(int* A) {
  return *A*;
}

!int* pvs_f1_d88(!int* A) {
  return *A*;
}

int* pvs_f289(int* A) {
  return *A*;
}

!int* pvs_f2_d90(!int* A) {
  return *A*;
}

int pvs_f391(int* A) {
  int* B;
  B = (int*) GC( A );
  int result;
  result = (*A*[0] + *B*[0]);
  GC_free(B);
  return result;
}

int pvs_f3_d92(!int* A) {
  int* B;
  B = (int*) GC( A );
  int result;
  result = (*A*[0] + *B*[0]);
  GC_free(B);
  return result;
}

!int* pvs_f493(int* A) {
  !int* result;
  int* B;
  B = (int*) GC( A );
  int L95;
  L95 = 0;
  result = GC_malloc(10, sizeof(int) );
  int i117;
  for(i117 = 0; i117 < 10; i117++) {
    result[i117] = *A*[i117];
  }
  result[L95] = *B*[0];
  return *result*;
}

!int* pvs_f4_d94(!int* A) {
  int* B;
  B = (int*) GC( A );
  int L97;
  L97 = 0;
  A[L97] = *B*[0];
  return *A*;
}

!int* pvs_g199(int* A) {
  !int* result;
  int L101;
  L101 = 0;
  int res102;
  res102 = 0;
  result = GC_malloc(10, sizeof(int) );
  int i118;
  for(i118 = 0; i118 < 10; i118++) {
    result[i118] = *A*[i118];
  }
  result[L101] = res102;
  return *result*;
}

!int* pvs_g1_d100(!int* A) {
  int L103;
  L103 = 0;
  int res104;
  res104 = 0;
  A[L103] = res104;
  return *A*;
}

!int* pvs_g2105(int* A) {
  !int* result;
  !int* B;
  int L107;
  L107 = 0;
  int res108;
  res108 = 0;
  B = GC_malloc(10, sizeof(int) );
  int i119;
  for(i119 = 0; i119 < 10; i119++) {
    B[i119] = A[i119];
  }
  B[L107] = res108;
  int L109;
  L109 = 0;
  result = GC_malloc(10, sizeof(int) );
  int i120;
  for(i120 = 0; i120 < 10; i120++) {
    result[i120] = *A*[i120];
  }
  result[L109] = *B*[0];
  return *result*;
}

!int* pvs_g2_d106(!int* A) {
  !int* B;
  int L111;
  L111 = 0;
  int res112;
  res112 = 0;
  B = GC_malloc(10, sizeof(int) );
  int i121;
  for(i121 = 0; i121 < 10; i121++) {
    B[i121] = A[i121];
  }
  B[L111] = res112;
  int L113;
  L113 = 0;
  A[L113] = *B*[0];
  return *A*;
}