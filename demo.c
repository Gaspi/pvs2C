// ---------------------------------------------
//        C file generated from demo.pvs
// ---------------------------------------------
//   Make sure to link GMP in compilation:
//      gcc -o demo demo.c -lgmp
//      ./demo
// ---------------------------------------------

#include<stdio.h>
#include<gmp.h>
#include "demo.h"

#define TRUE 1
#define FALSE 0

int main(void) {
  printf("Executing demo ...\n");
  return 0;
}


int pvs_a199() {
  int result;
  result = 8;
  return result;
}

int pvs_d_a200() {
  int result;
  result = 8;
  return result;
}

int pvs_b201(int x) {
  int result;
  result = x;
  return result;
}

int pvs_d_b202(int x) {
  int result;
  result = x;
  return result;
}

void pvs_incr203(int* result, int* t56039) {
  int L210;
  L210 = t56039[0];
  for(int i209 = 0; i209 < 10; i209++) {
    result[i209] = t56039[i209];
  }
  result[L210] = t56039[9];
}

void pvs_d_incr204(int* result, int* t56039) {
  int L210;
  L210 = t56039[0];
  for(int i209 = 0; i209 < 10; i209++) {
    result[i209] = t56039[i209];
  }
  result[L210] = t56039[9];
}

void pvs_foo211(int* result, int* t56039) {
  int L228;
  L228 = 0;
  mpz_t conv229;
  mpz_init(conv229);
  mpz_set_si(conv229, (long) 1);
  mpz_t aux230;
  mpz_init(aux230);
  mpz_add_ui(aux230, conv229, (unsigned long) t56039[9]);
  mpz_clear(conv229);
  int L231;
  L231 = t56039[0];
  mpz_t conv232;
  mpz_init(conv232);
  mpz_set_si(conv232, (long) 1);
  mpz_t aux233;
  mpz_init(aux233);
  mpz_add_ui(aux233, conv232, (unsigned long) t56039[0]);
  mpz_clear(conv232);
  for(int i227 = 0; i227 < 10; i227++) {
    result[i227] = t56039[i227];
  }
  result[L228] = ( (int) mpz_get_si(aux230) );
  result[L231] = ( (int) mpz_get_si(aux233) );
  mpz_clear(aux230);
  mpz_clear(aux233);
}

void pvs_d_foo212(int* result, int* t56039) {
  int L228;
  L228 = 0;
  mpz_t conv229;
  mpz_init(conv229);
  mpz_set_si(conv229, (long) 1);
  mpz_t aux230;
  mpz_init(aux230);
  mpz_add_ui(aux230, conv229, (unsigned long) t56039[9]);
  mpz_clear(conv229);
  int L231;
  L231 = t56039[0];
  mpz_t conv232;
  mpz_init(conv232);
  mpz_set_si(conv232, (long) 1);
  mpz_t aux233;
  mpz_init(aux233);
  mpz_add_ui(aux233, conv232, (unsigned long) t56039[0]);
  mpz_clear(conv232);
  for(int i227 = 0; i227 < 10; i227++) {
    result[i227] = t56039[i227];
  }
  result[L228] = ( (int) mpz_get_si(aux230) );
  result[L231] = ( (int) mpz_get_si(aux233) );
  mpz_clear(aux230);
  mpz_clear(aux233);
}

void pvs_bar234(int** result, int** t56039) {
  int L256;
  L256 = 0;
  int L258;
  L258 = 0;
  int** aux259;
  aux259 = malloc( 10 * sizeof(int*) );
  for(int i260 = 0; i260 < 10; i260++) {
    aux259[i260] = malloc( 12 * sizeof(int) );
  }
  for(int i254 = 0; i254 < 10; i254++) {
    for(int i255 = 0; i255 < 12; i255++) {
      aux259[i254][i255] = t56039[i254][i255];
    }
  }
  int* E257 = aux259[L256];
  E257[L258] = 0;
  int** a = aux259;
  for(int i261 = 0; i261 < 10; i261++) {
    for(int i262 = 0; i262 < 12; i262++) {
      result[i261][i262] = a[i261][i262];
    }
  }
  free(aux259);
}

void pvs_d_bar235(int** result, int** t56039) {
  int L256;
  L256 = 0;
  int L258;
  L258 = 0;
  int** aux259;
  aux259 = malloc( 10 * sizeof(int*) );
  for(int i260 = 0; i260 < 10; i260++) {
    aux259[i260] = malloc( 12 * sizeof(int) );
  }
  for(int i254 = 0; i254 < 10; i254++) {
    for(int i255 = 0; i255 < 12; i255++) {
      aux259[i254][i255] = t56039[i254][i255];
    }
  }
  int* E257 = aux259[L256];
  E257[L258] = 0;
  int** a = aux259;
  for(int i261 = 0; i261 < 10; i261++) {
    for(int i262 = 0; i262 < 12; i262++) {
      result[i261][i262] = a[i261][i262];
    }
  }
  free(aux259);
}