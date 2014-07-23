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


int* pvs_f499(int* A) {
  !int* #result#;
  int L501;
  L501 = 0;
  int res502;
  res502 = 0;
  if ( GC_count( *A* ) == 1 )
    #result# = GC( *A* );
  else {
    #result# = GC_malloc(1000, sizeof(int) );
    int i513;
    for(i513 = 0; i513 < 1000; i513++) {
      #result#[i513] = *A*[i513];
    }
  }
  #result#[L501] = res502;
  return *#result#*;
}

int* pvs_f_d500(!int* #A#) {
  int L503;
  L503 = 0;
  int res504;
  res504 = 0;
  #A#[L503] = res504;
  return *#A#*;
}

int pvs_g505(int* A, int* *B*) {
  int result;
  result = *A*[0];
  return result;
}

int pvs_g_d506(int* A, int* *B*) {
  int result;
  result = *A*[0];
  return result;
}

int* pvs_h507(int a) {
  !int* #result#;
  #result# = GC_malloc(1000, sizeof(int) );
  int i509;
  for(i509 = 0; i509 < 1000; i509++) {
    #result#[i509] = a;
  }
  return *#result#*;
}

int* pvs_h_d508(int a) {
  !int* #result#;
  #result# = GC_malloc(1000, sizeof(int) );
  int i510;
  for(i510 = 0; i510 < 1000; i510++) {
    #result#[i510] = a;
  }
  return *#result#*;
}

void pvs_x511(mpz_t result) {
  mpz_set_si(result, (long) pvs_g505(pvs_h507(0), pvs_h507(1)));
}

void pvs_x_d512(mpz_t result) {
  mpz_set_si(result, (long) pvs_g505(pvs_h507(0), pvs_h507(1)));
}