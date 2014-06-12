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

int pvs_a366() {
  int result;
  result = 8;
  return result;
}

int pvs_d_a367() {
  int result;
  result = 8;
  return result;
}

int pvs_b368(int x) {
  int result;
  result = x;
  return result;
}

int pvs_d_b369(int x) {
  int result;
  result = x;
  return result;
}

void pvs_incr370(int* result, int* t56296) {
  int L374;
  L374 = pvsSelect(t56296, 0);
  copy_int*(result, t56296);
  pvsDestructiveUpdate(result, L374, pvsSelect(t56296, 9));
}

void pvs_d_incr371(int* result, int* t56296) {
  int L374;
  L374 = pvsSelect(t56296, 0);
  copy_int*(result, t56296);
  pvsDestructiveUpdate(result, L374, pvsSelect(t56296, 9));
}

void pvs_foo375(int* result, int* t56296) {
  int L389;
  L389 = 0;
  mpz_t conv390;
  mpz_init(conv390);
  mpz_set_si(conv390, (long) 1);
  mpz_t aux391;
  mpz_init(aux391);
  mpz_add_ui(aux391, conv390, (unsigned long) pvsSelect(t56296, 9));
  mpz_clear(conv390);
  int L392;
  L392 = pvsSelect(t56296, 0);
  mpz_t conv393;
  mpz_init(conv393);
  mpz_set_si(conv393, (long) 1);
  mpz_t aux394;
  mpz_init(aux394);
  mpz_add_ui(aux394, conv393, (unsigned long) pvsSelect(t56296, 0));
  mpz_clear(conv393);
  copy_int*(result, t56296);
  pvsDestructiveUpdate(result, L389, ( (int) mpz_get_si(aux391) ));
  pvsDestructiveUpdate(result, L392, ( (int) mpz_get_si(aux394) ));
  mpz_clear(aux391);
  mpz_clear(aux394);
}

void pvs_d_foo376(int* result, int* t56296) {
  int L389;
  L389 = 0;
  mpz_t conv390;
  mpz_init(conv390);
  mpz_set_si(conv390, (long) 1);
  mpz_t aux391;
  mpz_init(aux391);
  mpz_add_ui(aux391, conv390, (unsigned long) pvsSelect(t56296, 9));
  mpz_clear(conv390);
  int L392;
  L392 = pvsSelect(t56296, 0);
  mpz_t conv393;
  mpz_init(conv393);
  mpz_set_si(conv393, (long) 1);
  mpz_t aux394;
  mpz_init(aux394);
  mpz_add_ui(aux394, conv393, (unsigned long) pvsSelect(t56296, 0));
  mpz_clear(conv393);
  copy_int*(result, t56296);
  pvsDestructiveUpdate(result, L389, ( (int) mpz_get_si(aux391) ));
  pvsDestructiveUpdate(result, L392, ( (int) mpz_get_si(aux394) ));
  mpz_clear(aux391);
  mpz_clear(aux394);
}