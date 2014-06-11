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

int pvs_a320() {
  int result;
  result = 8;
  return result;
}

int pvs_d_a321() {
  int result;
  result = 8;
  return result;
}

int pvs_b322(int x) {
  int result;
  result = x;
  return result;
}

int pvs_d_b323(int x) {
  int result;
  result = x;
  return result;
}

void pvs_incr324(int* result, int* t55888) {
  int L337;
  L337 = pvsSelect(t55888, 0);
  int R335;
  R335 = pvsSelect(t55888, 9);
  int* N336 = pvsDestructiveUpdate(E334, L337, R335);//
  int* E334;//
  E334 = malloc( sizeof(int*) );//
  copy_int*(E334, t55888);//
  free(E334);//
  copy_int*(result, N336);
}

void pvs_d_incr325(int* result, int* t55888) {
  int L337;
  L337 = pvsSelect(t55888, 0);
  int R335;
  R335 = pvsSelect(t55888, 9);
  int* N336 = pvsDestructiveUpdate(E334, L337, R335);//
  int* E334;//
  E334 = malloc( sizeof(int*) );//
  copy_int*(E334, t55888);//
  free(E334);//
  copy_int*(result, N336);
}

void pvs_foo338(int* result, int* t55888) {
  int L365;
  L365 = 0;
  mpq_t R363;
  mpq_init(R363);
  mpz_t conv371;
  mpz_init(conv371);
  mpz_set_si(conv371, (long) 1);
  mpz_t set372;
  mpz_init(set372);
  mpz_add_ui(set372, conv371, (unsigned long) pvsSelect(t55888, 9));
  mpz_clear(conv371);
  mpq_clear(R363);
  mpq_set_z(R363, set372);
  mpq_canonicalize(R363);
  mpz_clear(set372);
  int L368;
  L368 = pvsSelect(t55888, 0);
  mpq_t R366;
  mpq_init(R366);
  mpz_t conv369;
  mpz_init(conv369);
  mpz_set_si(conv369, (long) 1);
  mpz_t set370;
  mpz_init(set370);
  mpz_add_ui(set370, conv369, (unsigned long) pvsSelect(t55888, 0));
  mpz_clear(conv369);
  mpq_clear(R366);
  mpq_set_z(R366, set370);
  mpq_canonicalize(R366);
  mpz_clear(set370);
  int* N367 = pvsDestructiveUpdate(N364, L368, R366);//
  int* N364 = pvsDestructiveUpdate(E362, L365, R363);//
  int* E362;//
  E362 = malloc( sizeof(int*) );//
  copy_int*(E362, t55888);//
  free(E362);//
  copy_int*(result, N367);
}

void pvs_d_foo339(int* result, int* t55888) {
  int L365;
  L365 = 0;
  mpq_t R363;
  mpq_init(R363);
  mpz_t conv371;
  mpz_init(conv371);
  mpz_set_si(conv371, (long) 1);
  mpz_t set372;
  mpz_init(set372);
  mpz_add_ui(set372, conv371, (unsigned long) pvsSelect(t55888, 9));
  mpz_clear(conv371);
  mpq_clear(R363);
  mpq_set_z(R363, set372);
  mpq_canonicalize(R363);
  mpz_clear(set372);
  int L368;
  L368 = pvsSelect(t55888, 0);
  mpq_t R366;
  mpq_init(R366);
  mpz_t conv369;
  mpz_init(conv369);
  mpz_set_si(conv369, (long) 1);
  mpz_t set370;
  mpz_init(set370);
  mpz_add_ui(set370, conv369, (unsigned long) pvsSelect(t55888, 0));
  mpz_clear(conv369);
  mpq_clear(R366);
  mpq_set_z(R366, set370);
  mpq_canonicalize(R366);
  mpz_clear(set370);
  int* N367 = pvsDestructiveUpdate(N364, L368, R366);//
  int* N364 = pvsDestructiveUpdate(E362, L365, R363);//
  int* E362;//
  E362 = malloc( sizeof(int*) );//
  copy_int*(E362, t55888);//
  free(E362);//
  copy_int*(result, N367);
}