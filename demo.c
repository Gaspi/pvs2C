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


int fun525(void *env) {
  mpz_t y = (mpz_t) env[1];
  mpz_t x = (mpz_t) env[0];
  return (mpz_cmp(x, y) == 0);
}

int fun527(void *env) {
  mpz_t y = (mpz_t) env[1];
  mpz_t x = (mpz_t) env[0];
  return (mpz_cmp(x, y) == 0);
}

int fun531(void *env) {
  mpz_t x = (mpz_t) env[0];
  return pvs_b521(x);
}

int fun533(void *env) {
  mpz_t x = (mpz_t) env[0];
  return pvs_b521(x);
}

int pvs_b521(mpz_t x) {
  int result;
  result = isEven(x);
  return result;
}

int pvs_d_b522(mpz_t x) {
  int result;
  result = isEven(x);
  return result;
}

void pvs_singl523(pvsClosure result, mpz_t x) {
  void env528[2];
  env528[0] = x;
  makeClosure(result, fun527, env528);
}

void pvs_d_singl524(pvsClosure result, mpz_t x) {
  void env528[2];
  env528[0] = x;
  makeClosure(result, fun527, env528);
}

void pvs_getB529(pvsClosure result, int y) {
  void env534[1];
  makeClosure(result, fun533, env534);
}

void pvs_d_getB530(pvsClosure result, int y) {
  void env534[1];
  makeClosure(result, fun533, env534);
}