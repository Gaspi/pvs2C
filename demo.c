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


int pvs_a471() {
  int result;
  result = 8;
  return result;
}

int pvs_d_a472() {
  int result;
  result = 8;
  return result;
}

int pvs_b473(int x) {
  int result;
  result = x;
  return result;
}

int pvs_d_b474(int x) {
  int result;
  result = x;
  return result;
}

void pvs_incr475(int* result, int* t56000) {
  int L482;
  L482 = t56000[0];
  for(int i481 = 0; i481 < 10; i481++) {
    result[i481] = t56000[i481];
  }
  result[L482] = t56000[9];
}

void pvs_d_incr476(int* result, int* t56000) {
  int L482;
  L482 = t56000[0];
  for(int i481 = 0; i481 < 10; i481++) {
    result[i481] = t56000[i481];
  }
  result[L482] = t56000[9];
}

void pvs_foo483(int* result, int* t56000) {
  int L500;
  L500 = 0;
  mpz_t conv501;
  mpz_init(conv501);
  mpz_set_si(conv501, (long) 1);
  mpz_t aux502;
  mpz_init(aux502);
  mpz_add_ui(aux502, conv501, (unsigned long) t56000[9]);
  mpz_clear(conv501);
  int L503;
  L503 = t56000[0];
  mpz_t conv504;
  mpz_init(conv504);
  mpz_set_si(conv504, (long) 1);
  mpz_t aux505;
  mpz_init(aux505);
  mpz_add_ui(aux505, conv504, (unsigned long) t56000[0]);
  mpz_clear(conv504);
  for(int i499 = 0; i499 < 10; i499++) {
    result[i499] = t56000[i499];
  }
  result[L500] = ( (int) mpz_get_si(aux502) );
  result[L503] = ( (int) mpz_get_si(aux505) );
  mpz_clear(aux502);
  mpz_clear(aux505);
}

void pvs_d_foo484(int* result, int* t56000) {
  int L500;
  L500 = 0;
  mpz_t conv501;
  mpz_init(conv501);
  mpz_set_si(conv501, (long) 1);
  mpz_t aux502;
  mpz_init(aux502);
  mpz_add_ui(aux502, conv501, (unsigned long) t56000[9]);
  mpz_clear(conv501);
  int L503;
  L503 = t56000[0];
  mpz_t conv504;
  mpz_init(conv504);
  mpz_set_si(conv504, (long) 1);
  mpz_t aux505;
  mpz_init(aux505);
  mpz_add_ui(aux505, conv504, (unsigned long) t56000[0]);
  mpz_clear(conv504);
  for(int i499 = 0; i499 < 10; i499++) {
    result[i499] = t56000[i499];
  }
  result[L500] = ( (int) mpz_get_si(aux502) );
  result[L503] = ( (int) mpz_get_si(aux505) );
  mpz_clear(aux502);
  mpz_clear(aux505);
}

void pvs_bar506(int** result, int** t56000) {
  int L528;
  L528 = 0;
  int L530;
  L530 = 0;
  int** aux531;
  aux531 = malloc( 10 * sizeof(int*) );
  for(int i532 = 0; i532 < 10; i532++) {
    aux531[i532] = malloc( 12 * sizeof(int) );
  }
  for(int i526 = 0; i526 < 10; i526++) {
    for(int i527 = 0; i527 < 12; i527++) {
      aux531[i526][i527] = t56000[i526][i527];
    }
  }
  int* E529 = aux531[L528];
  E529[L530] = 0;
  int** a = aux531;
  for(int i533 = 0; i533 < 10; i533++) {
    for(int i534 = 0; i534 < 12; i534++) {
      result[i533][i534] = a[i533][i534];
    }
  }
  free(aux531);
}

void pvs_d_bar507(int** result, int** t56000) {
  int L528;
  L528 = 0;
  int L530;
  L530 = 0;
  int** aux531;
  aux531 = malloc( 10 * sizeof(int*) );
  for(int i532 = 0; i532 < 10; i532++) {
    aux531[i532] = malloc( 12 * sizeof(int) );
  }
  for(int i526 = 0; i526 < 10; i526++) {
    for(int i527 = 0; i527 < 12; i527++) {
      aux531[i526][i527] = t56000[i526][i527];
    }
  }
  int* E529 = aux531[L528];
  E529[L530] = 0;
  int** a = aux531;
  for(int i533 = 0; i533 < 10; i533++) {
    for(int i534 = 0; i534 < 12; i534++) {
      result[i533][i534] = a[i533][i534];
    }
  }
  free(aux531);
}