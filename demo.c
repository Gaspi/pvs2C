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

int pvs_a190() {
  int result;
  result = 8;
  return result;
}

int pvs_d_a191() {
  int result;
  result = 8;
  return result;
}

int pvs_b192(int x) {
  int result;
  result = x;
  return result;
}

int pvs_d_b193(int x) {
  int result;
  result = x;
  return result;
}

void pvs_incr194(int* result, int* t55981) {
  int L198;
  L198 = pvsSelect(t55981, 0);
  copy_int*(result, t55981);
  pvsDestructiveUpdate(result, L198, pvsSelect(t55981, 9));
}

void pvs_d_incr195(int* result, int* t55981) {
  int L198;
  L198 = pvsSelect(t55981, 0);
  copy_int*(result, t55981);
  pvsDestructiveUpdate(result, L198, pvsSelect(t55981, 9));
}

void pvs_foo199(int* result, int* t55981) {
  int L215;
  L215 = 0;
  mpz_t conv216;
  mpz_init(conv216);
  mpz_set_si(conv216, (long) 1);
  mpz_t aux217;
  mpz_init(aux217);
  mpz_add_ui(aux217, conv216, (unsigned long) pvsSelect(t55981, 9));
  mpz_clear(conv216);
  int L218;
  int aux219;
  aux219 = 0;
  mpz_clear(aux217);
  L218 = pvsSelect(t55981, aux219);
  mpz_t conv220;
  mpz_init(conv220);
  mpz_set_si(conv220, (long) 1);
  mpz_t aux221;
  mpz_init(aux221);
  mpz_add_ui(aux221, conv220, (unsigned long) pvsSelect(t55981, 0));
  mpz_clear(conv220);
  copy_int*(result, t55981);
  pvsDestructiveUpdate(result, L215, ( (int) mpz_get_si(aux217) ));
  pvsDestructiveUpdate(result, L218, ( (int) mpz_get_si(aux221) ));
  mpz_clear(aux221);
}

void pvs_d_foo200(int* result, int* t55981) {
  int L215;
  L215 = 0;
  mpz_t conv216;
  mpz_init(conv216);
  mpz_set_si(conv216, (long) 1);
  mpz_t aux217;
  mpz_init(aux217);
  mpz_add_ui(aux217, conv216, (unsigned long) pvsSelect(t55981, 9));
  mpz_clear(conv216);
  int L218;
  int aux219;
  aux219 = 0;
  mpz_clear(aux217);
  L218 = pvsSelect(t55981, aux219);
  mpz_t conv220;
  mpz_init(conv220);
  mpz_set_si(conv220, (long) 1);
  mpz_t aux221;
  mpz_init(aux221);
  mpz_add_ui(aux221, conv220, (unsigned long) pvsSelect(t55981, 0));
  mpz_clear(conv220);
  copy_int*(result, t55981);
  pvsDestructiveUpdate(result, L215, ( (int) mpz_get_si(aux217) ));
  pvsDestructiveUpdate(result, L218, ( (int) mpz_get_si(aux221) ));
  mpz_clear(aux221);
}
