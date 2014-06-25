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


unsigned long int pvs_a185() {
  unsigned long int result;
  result = (unsigned long) 2;
  return result;
}

unsigned long int pvs_d_a186() {
  unsigned long int result;
  result = (unsigned long) 2;
  return result;
}

int pvs_b187() {
  mpz_t aux192;
  mpz_init(aux192);
  mpz_t conv191;
  mpz_init(conv191);
  mpz_set_si(conv191, (long) 3);
  mpz_add_ui(aux192, conv191, (unsigned long) 1);
  mpz_clear(conv191);
  int result;
  result = ( (int) mpz_get_si(aux192) );
  mpz_clear(aux192);
  return result;
}

int pvs_d_b188() {
  mpz_t aux192;
  mpz_init(aux192);
  mpz_t conv191;
  mpz_init(conv191);
  mpz_set_si(conv191, (long) 3);
  mpz_add_ui(aux192, conv191, (unsigned long) 1);
  mpz_clear(conv191);
  int result;
  result = ( (int) mpz_get_si(aux192) );
  mpz_clear(aux192);
  return result;
}

void pvs_c193(mpz_t result) {
  mpz_t aux198;
  mpz_init(aux198);
  mpz_t conv197;
  mpz_init(conv197);
  mpz_set_si(conv197, (long) 1);
  mpz_add_ui(aux198, conv197, (unsigned long) 2);
  mpz_clear(conv197);
  mpz_mul_ui(result, aux198, (unsigned long) 3);
  mpz_clear(aux198);
}

void pvs_d_c194(mpz_t result) {
  mpz_t aux198;
  mpz_init(aux198);
  mpz_t conv197;
  mpz_init(conv197);
  mpz_set_si(conv197, (long) 1);
  mpz_add_ui(aux198, conv197, (unsigned long) 2);
  mpz_clear(conv197);
  mpz_mul_ui(result, aux198, (unsigned long) 3);
  mpz_clear(aux198);
}

int pvs_incr199(int x) {
  mpz_t aux204;
  mpz_init(aux204);
  mpz_t conv203;
  mpz_init(conv203);
  mpz_set_si(conv203, (long) x);
  mpz_add_ui(aux204, conv203, (unsigned long) 1);
  mpz_clear(conv203);
  int result;
  result = ( (int) mpz_get_si(aux204) );
  mpz_clear(aux204);
  return result;
}

int pvs_d_incr200(int x) {
  mpz_t aux204;
  mpz_init(aux204);
  mpz_t conv203;
  mpz_init(conv203);
  mpz_set_si(conv203, (long) x);
  mpz_add_ui(aux204, conv203, (unsigned long) 1);
  mpz_clear(conv203);
  int result;
  result = ( (int) mpz_get_si(aux204) );
  mpz_clear(aux204);
  return result;
}

int pvs_zero205(mpz_t x) {
  int result;
  result = 0;
  return result;
}

int pvs_d_zero206(mpz_t x) {
  int result;
  result = 0;
  return result;
}

int pvs_f207(int a, int b) {
  mpz_t aux214;
  mpz_init(aux214);
  mpz_t conv212;
  mpz_init(conv212);
  mpz_set_si(conv212, (long) b);
  mpz_t conv213;
  mpz_init(conv213);
  mpz_set_si(conv213, (long) pvs_d_zero206(conv212));
  mpz_clear(conv212);
  mpz_mul_ui(aux214, conv213, (unsigned long) pvs_d_incr200(a));
  mpz_clear(conv213);
  int result;
  result = ( (int) mpz_get_si(aux214) );
  mpz_clear(aux214);
  return result;
}

int pvs_d_f208(int a, int b) {
  mpz_t aux214;
  mpz_init(aux214);
  mpz_t conv212;
  mpz_init(conv212);
  mpz_set_si(conv212, (long) b);
  mpz_t conv213;
  mpz_init(conv213);
  mpz_set_si(conv213, (long) pvs_d_zero206(conv212));
  mpz_clear(conv212);
  mpz_mul_ui(aux214, conv213, (unsigned long) pvs_d_incr200(a));
  mpz_clear(conv213);
  int result;
  result = ( (int) mpz_get_si(aux214) );
  mpz_clear(aux214);
  return result;
}

int pvs_t215(int x) {
  int result;
  result = x;
  return result;
}

int pvs_d_t216(int x) {
  int result;
  result = x;
  return result;
}

int* pvs_f217(int x) {
  int* result;
  for(int i220 = 0; i220 < 1000;;; i220++) {
    result[i220] = pvs_d_t216(i220);
  }
  return result;
}

int* pvs_d_f218(int x) {
  int* result;
  for(int i220 = 0; i220 < 1000;;; i220++) {
    result[i220] = pvs_d_t216(i220);
  }
  return result;
}

int* pvs_update221(int* x) {
  int* result;
  int L230;
  L230 = 0;
  int res231;
  res231 = 0;
  if ( GC_count( x ) == 1 )
    result = x;
  else {
    result = GC_malloc( 1000 * sizeof(int) );
    for(int i229 = 0; i229 < 1000; i229++)
      result[i229] = x[i229];
    }
  }
  result[L230] = res231;
  return result;
}

int* pvs_d_update222(int* x) {
  int* result;
  int L230;
  L230 = 0;
  int res231;
  res231 = 0;
  if ( GC_count( x ) == 1 )
    result = x;
  else {
    result = GC_malloc( 1000 * sizeof(int) );
    for(int i229 = 0; i229 < 1000; i229++)
      result[i229] = x[i229];
    }
  }
  result[L230] = res231;
  return result;
}