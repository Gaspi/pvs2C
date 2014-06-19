// ---------------------------------------------
//        C file generated from draft.pvs
// ---------------------------------------------
//   Make sure to link GMP in compilation:
//      gcc -o draft draft.c -lgmp
//      ./draft
// ---------------------------------------------

#include<stdio.h>
#include<gmp.h>
#include "draft.h"

#define TRUE 1
#define FALSE 0

int main(void) {
  printf("Executing draft ...\n");
  return 0;
}


void pvs_f290(mpz_t result, mpz_t x) {
  mpz_t aux295;
  mpz_init(aux295);
  mpz_add(aux295, x, x);
  mpz_t conv296;
  mpz_init(conv296);
  mpz_set_si(conv296, (long) 2);
  mpz_t x: int = conv296;
  mpz_t aux297;
  mpz_init(aux297);
  aux297 = x#0;
  mpz_clear(conv296);
  mpz_add(result, aux295, aux297);
  mpz_clear(aux295);
  mpz_clear(aux297);
}

void pvs_d_f291(mpz_t result, mpz_t x) {
  mpz_t aux295;
  mpz_init(aux295);
  mpz_add(aux295, x, x);
  mpz_t conv296;
  mpz_init(conv296);
  mpz_set_si(conv296, (long) 2);
  mpz_t x: int = conv296;
  mpz_t aux297;
  mpz_init(aux297);
  aux297 = x#0;
  mpz_clear(conv296);
  mpz_add(result, aux295, aux297);
  mpz_clear(aux295);
  mpz_clear(aux297);
}

void pvs_incr298(mpz_t result, mpz_t x) {
  mpz_add_ui(result, x, (unsigned long) 1);
}

void pvs_d_incr299(mpz_t result, mpz_t x) {
  mpz_add_ui(result, x, (unsigned long) 1);
}

void pvs_a300(mpz_t result) {
  mpz_t conv303;
  mpz_init(conv303);
  mpz_set_si(conv303, (long) 10);
  pvs_d_incr299(result, conv303);
  mpz_clear(conv303);
}

void pvs_d_a301(mpz_t result) {
  mpz_t conv303;
  mpz_init(conv303);
  mpz_set_si(conv303, (long) 10);
  pvs_d_incr299(result, conv303);
  mpz_clear(conv303);
}

void pvs_f304(mpz_t* result, mpz_t* t56504) {
  int L311;
  L311 = 0;
  for(int i310 = 0; i310 < 10; i310++) {
    mpz_set(result[i310], t56504[i310]);
  }
  mpz_set_si(result[L311], (long) 0);
}

void pvs_d_f305(mpz_t* result, mpz_t* t56504) {
  int L311;
  L311 = 0;
  for(int i310 = 0; i310 < 10; i310++) {
    mpz_set(result[i310], t56504[i310]);
  }
  mpz_set_si(result[L311], (long) 0);
}

void pvs_e312(mpz_t result, int x) {
  mpz_set_si(result, (long) x);
}

void pvs_d_e313(mpz_t result, int x) {
  mpz_set_si(result, (long) x);
}

void pvs_g314(mpz_t* result) {
  mpz_t* aux322;
  aux322 = malloc( 10 * sizeof(mpz_t) );
  for(int i323 = 0; i323 < 10; i323++) {
    mpz_init(aux322[i323]);
  }
  for(int i321 = 0; i321 < 10; i321++) {
    pvs_d_e313(aux322[i321], i321);
  }
  mpz_t* aux324;
  aux324 = malloc( 10 * sizeof(mpz_t) );
  for(int i325 = 0; i325 < 10; i325++) {
    mpz_init(aux324[i325]);
  }
  pvs_d_f305(aux324, aux322);
  free(aux322);
  pvs_d_f305(result, aux324);
  free(aux324);
}

void pvs_d_g315(mpz_t* result) {
  mpz_t* aux322;
  aux322 = malloc( 10 * sizeof(mpz_t) );
  for(int i323 = 0; i323 < 10; i323++) {
    mpz_init(aux322[i323]);
  }
  for(int i321 = 0; i321 < 10; i321++) {
    pvs_d_e313(aux322[i321], i321);
  }
  mpz_t* aux324;
  aux324 = malloc( 10 * sizeof(mpz_t) );
  for(int i325 = 0; i325 < 10; i325++) {
    mpz_init(aux324[i325]);
  }
  pvs_d_f305(aux324, aux322);
  free(aux322);
  pvs_d_f305(result, aux324);
  free(aux324);
}