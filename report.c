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


int* pvs_f1919(int* A) {
  return *A*;
}

int* pvs_f1_d920(int* A) {
  return *A*;
}

int* pvs_f2921(int* A) {
  int* result;
  result = (int*) GC( A );
  GC_free(*A*);
  return *result*;
}

int* pvs_f2_d922(int* A) {
  int* result;
  result = (int*) GC( A );
  GC_free(*A*);
  return *result*;
}

int pvs_f3923(int* A) {
  int result;
  result = (A[0] + B[0]);
  GC_free(*A*);
  return result;
}

int pvs_f3_d924(int* A) {
  int result;
  result = (A[0] + B[0]);
  GC_free(*A*);
  return result;
}

int* pvs_f4925(int* A) {
  int* result;
  int* B;
  B = (int*) GC( A );
  int L927;
  L927 = 0;
  result = GC_malloc(10, sizeof(int) );
  int i951;
  for(i951 = 0; i951 < 10; i951++) {
    result[i951] = *A*[i951];
  }
  result[L927] = *B*[0];
  return *result*;
}

int* pvs_f4_d926(int* A) {
  int* B;
  B = (int*) GC( A );
  int L929;
  L929 = 0;
  A[L929] = *B*[0];
  return *A*;
}

int* pvs_g1931(int* A) {
  int* result;
  int L933;
  L933 = 0;
  int res934;
  res934 = 0;
  result = GC_malloc(10, sizeof(int) );
  int i952;
  for(i952 = 0; i952 < 10; i952++) {
    result[i952] = *A*[i952];
  }
  result[L933] = res934;
  return *result*;
}

int* pvs_g1_d932(int* A) {
  int L935;
  L935 = 0;
  int res936;
  res936 = 0;
  A[L935] = res936;
  return *A*;
}

int* pvs_g2937(int* A) {
  int* result;
  int* B;
  int L939;
  L939 = 0;
  int res940;
  res940 = 0;
  B = GC_malloc(10, sizeof(int) );
  int i953;
  for(i953 = 0; i953 < 10; i953++) {
    B[i953] = A[i953];
  }
  B[L939] = res940;
  int L941;
  L941 = 0;
  result = GC_malloc(10, sizeof(int) );
  int i954;
  for(i954 = 0; i954 < 10; i954++) {
    result[i954] = *A*[i954];
  }
  result[L941] = *B*[0];
  return *result*;
}

int* pvs_g2_d938(int* A) {
  int* B;
  int L943;
  L943 = 0;
  int res944;
  res944 = 0;
  B = GC_malloc(10, sizeof(int) );
  int i955;
  for(i955 = 0; i955 < 10; i955++) {
    B[i955] = A[i955];
  }
  B[L943] = res944;
  int L945;
  L945 = 0;
  A[L945] = *B*[0];
  return *A*;
}