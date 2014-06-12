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

int pvs_a592() {
  int result;
  result = 8;
  return result;
}

int pvs_d_a593() {
  int result;
  result = 8;
  return result;
}

int pvs_b594(int x) {
  int result;
  result = x;
  return result;
}

int pvs_d_b595(int x) {
  int result;
  result = x;
  return result;
}

void pvs_incr596(int* result, int* t55982) {
  int L600;
  L600 = pvsSelect(t55982, 0);
  copy_int*(result, t55982);
  pvsDestructiveUpdate(result, L600, pvsSelect(t55982, 9));
}

void pvs_d_incr597(int* result, int* t55982) {
  int L600;
  L600 = pvsSelect(t55982, 0);
  copy_int*(result, t55982);
  pvsDestructiveUpdate(result, L600, pvsSelect(t55982, 9));
}

void pvs_foo601(int* result, int* t55982) {
  int L615;
  L615 = 0;
  mpz_t conv616;
  mpz_init(conv616);
  mpz_set_si(conv616, (long) 1);
  mpz_t aux617;
  mpz_init(aux617);
  mpz_add_ui(aux617, conv616, (unsigned long) pvsSelect(t55982, 9));
  mpz_clear(conv616);
  int L618;
  L618 = pvsSelect(t55982, 0);
  mpz_t conv619;
  mpz_init(conv619);
  mpz_set_si(conv619, (long) 1);
  mpz_t aux620;
  mpz_init(aux620);
  mpz_add_ui(aux620, conv619, (unsigned long) pvsSelect(t55982, 0));
  mpz_clear(conv619);
  copy_int*(result, t55982);
  pvsDestructiveUpdate(result, L615, ( (int) mpz_get_si(aux617) ));
  pvsDestructiveUpdate(result, L618, ( (int) mpz_get_si(aux620) ));
  mpz_clear(aux617);
  mpz_clear(aux620);
}

void pvs_d_foo602(int* result, int* t55982) {
  int L615;
  L615 = 0;
  mpz_t conv616;
  mpz_init(conv616);
  mpz_set_si(conv616, (long) 1);
  mpz_t aux617;
  mpz_init(aux617);
  mpz_add_ui(aux617, conv616, (unsigned long) pvsSelect(t55982, 9));
  mpz_clear(conv616);
  int L618;
  L618 = pvsSelect(t55982, 0);
  mpz_t conv619;
  mpz_init(conv619);
  mpz_set_si(conv619, (long) 1);
  mpz_t aux620;
  mpz_init(aux620);
  mpz_add_ui(aux620, conv619, (unsigned long) pvsSelect(t55982, 0));
  mpz_clear(conv619);
  copy_int*(result, t55982);
  pvsDestructiveUpdate(result, L615, ( (int) mpz_get_si(aux617) ));
  pvsDestructiveUpdate(result, L618, ( (int) mpz_get_si(aux620) ));
  mpz_clear(aux617);
  mpz_clear(aux620);
}
