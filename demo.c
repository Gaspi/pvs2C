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


int fun51(void *env) {
  mpz_t y = (mpz_t) env[1];
  mpz_t x = (mpz_t) env[0];
  return (mpz_cmp(x, y) == 0);
}

int fun53(void *env) {
  mpz_t y = (mpz_t) env[1];
  mpz_t x = (mpz_t) env[0];
  return (mpz_cmp(x, y) == 0);
}

int fun57(void *env) {
  mpz_t x = (mpz_t) env[0];
  return pvs_b47(x);
}

int fun59(void *env) {
  mpz_t x = (mpz_t) env[0];
  return pvs_b47(x);
}

int pvs_b47(mpz_t x) {
  int result;
  result = isEven(x);
  return result;
}

int pvs_d_b48(mpz_t x) {
  int result;
  result = isEven(x);
  return result;
}

void pvs_singl49(pvsClosure result, mpz_t x) {
  void env54[2];
  env54[0] = x;
  makeClosure(result, fun53, env54);
}

void pvs_d_singl50(pvsClosure result, mpz_t x) {
  void env54[2];
  env54[0] = x;
  makeClosure(result, fun53, env54);
}

void pvs_getB55(pvsClosure result, int y) {
  void env60[1];
  makeClosure(result, fun59, env60);
}

void pvs_d_getB56(pvsClosure result, int y) {
  void env60[1];
  makeClosure(result, fun59, env60);
}