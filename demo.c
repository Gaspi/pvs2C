/*
C file generated from demo.pvs
Make sure to link GMP and PVS.c in compilation:
    gcc -o demo demo.c -lgmp
    ./demo
*/

#include<stdio.h>
#include<gmp.h>
#include "demo.h"

#define TRUE 1
#define FALSE 0

int main(void) {
  printf("Executing demo ...\n");
  return 0;
}

int pvs_a194() {
  int result;
  result = 8;
  return result;
}

int pvs_d_a195() {
  int result;
  result = 8;
  return result;
}

int pvs_b196(int x) {
  int result;
  result = x;
  return result;
}

int pvs_d_b197(int x) {
  int result;
  result = x;
  return result;
}

void pvs_incr198(int* result, int* t55880) {
  int L202;
  L202 = pvsSelect(t55880, 0);
  copy_int*(result, t55880);
  pvsDestructiveUpdate(result, L202, pvsSelect(t55880, 9));
}

void pvs_d_incr199(int* result, int* t55880) {
  int L202;
  L202 = pvsSelect(t55880, 0);
  copy_int*(result, t55880);
  pvsDestructiveUpdate(result, L202, pvsSelect(t55880, 9));
}

void pvs_foo203(int* result, int* t55880) {
  int L219;
  L219 = 0;
  mpz_t conv220;
  mpz_init(conv220);
  mpz_set_si(conv220, (long) 1);
  mpz_t aux221;
  mpz_init(aux221);
  mpz_add_ui(aux221, conv220, (unsigned long) pvsSelect(t55880, 9));
  mpz_clear(conv220);
  int L222;
  int aux223;
  aux223 = 0;
  mpz_clear(aux221);
  L222 = pvsSelect(t55880, aux223);
  mpz_t conv224;
  mpz_init(conv224);
  mpz_set_si(conv224, (long) 1);
  mpz_t aux225;
  mpz_init(aux225);
  mpz_add_ui(aux225, conv224, (unsigned long) pvsSelect(t55880, 0));
  mpz_clear(conv224);
  copy_int*(result, t55880);
  pvsDestructiveUpdate(result, L219, ( (int) mpz_get_si(aux221) ));
  pvsDestructiveUpdate(result, L222, ( (int) mpz_get_si(aux225) ));
  mpz_clear(aux225);
}

void pvs_d_foo204(int* result, int* t55880) {
  int L219;
  L219 = 0;
  mpz_t conv220;
  mpz_init(conv220);
  mpz_set_si(conv220, (long) 1);
  mpz_t aux221;
  mpz_init(aux221);
  mpz_add_ui(aux221, conv220, (unsigned long) pvsSelect(t55880, 9));
  mpz_clear(conv220);
  int L222;
  int aux223;
  aux223 = 0;
  mpz_clear(aux221);
  L222 = pvsSelect(t55880, aux223);
  mpz_t conv224;
  mpz_init(conv224);
  mpz_set_si(conv224, (long) 1);
  mpz_t aux225;
  mpz_init(aux225);
  mpz_add_ui(aux225, conv224, (unsigned long) pvsSelect(t55880, 0));
  mpz_clear(conv224);
  copy_int*(result, t55880);
  pvsDestructiveUpdate(result, L219, ( (int) mpz_get_si(aux221) ));
  pvsDestructiveUpdate(result, L222, ( (int) mpz_get_si(aux225) ));
  mpz_clear(aux225);
}