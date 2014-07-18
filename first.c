// ---------------------------------------------
//        C file generated from first.pvs
// ---------------------------------------------
//   Make sure to link GC.c and GMP in compilation:
//      gcc -o first first.c GC.c -lgmp
//      ./first
// ---------------------------------------------

#include<stdio.h>
#include<gmp.h>
#include "GC.h"
#include "first.h"

#define TRUE 1
#define FALSE 0

int main(void) {
  printf("Executing first ...\n");
  return 0;
}


int* pvs_f616(int* A) {
  int* result;
  int* B;
  B = (int*) GC( *A* );
  int L620;
  L620 = 0;
  int res621;
  res621 = 0;
  result = GC_malloc(1000, sizeof(int) );
  int i622;
  for(i622 = 0; i622 < 1000; i622++) {
    result[i622] = *B*[i622];
  }
  result[L620] = res621;
  return *result*;
}

int* pvs_f_d617(int* A) {
  int* result;
  int* B;
  B = (int*) GC( *A* );
  int L620;
  L620 = 0;
  int res621;
  res621 = 0;
  result = GC_malloc(1000, sizeof(int) );
  int i623;
  for(i623 = 0; i623 < 1000; i623++) {
    result[i623] = *B*[i623];
  }
  result[L620] = res621;
  return *result*;
}