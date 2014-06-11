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

int pvs_a532() {
  int result;
  result = 8;
  return result;
}

int pvs_d_a533() {
  int result;
  result = 8;
  return result;
}

int pvs_b534(int x) {
  int result;
  result = x;
  return result;
}

int pvs_d_b535(int x) {
  int result;
  result = x;
  return result;
}

void pvs_incr536(int* result, int* t55888) {
  int L549;
  L549 = pvsSelect(t55888, 0);
  free(N546);
  int R547;
  R547 = pvsSelect(t55888, 9);
  int* N546;
  N546 = malloc( sizeof(int*) );
  copy_int*(N546, t55888);
  pvsDestructiveUpdate(N548, N546, L549, R547);//
  copy_int*(result, N548);
}

void pvs_d_incr537(int* result, int* t55888) {
  int L549;
  L549 = pvsSelect(t55888, 0);
  free(N546);
  int R547;
  R547 = pvsSelect(t55888, 9);
  int* N546;
  N546 = malloc( sizeof(int*) );
  copy_int*(N546, t55888);
  pvsDestructiveUpdate(N548, N546, L549, R547);//
  copy_int*(result, N548);
}

void pvs_foo550(int* result, int* t55888) {
  int L577;
  L577 = 0;
  free(N574);
  mpq_t R575;
  mpq_init(R575);
  mpz_t conv583;
  mpz_init(conv583);
  mpz_set_si(conv583, (long) 1);
  mpz_t set584;
  mpz_init(set584);
  mpz_add_ui(set584, conv583, (unsigned long) pvsSelect(t55888, 9));
  mpz_clear(conv583);
  mpq_clear(R578);
  mpq_set_z(R575, set584);
  mpq_canonicalize(R575);
  mpz_clear(set584);
  int L580;
  L580 = pvsSelect(t55888, 0);
  mpq_t R578;
  mpq_init(R578);
  mpz_t conv581;
  mpz_init(conv581);
  mpz_set_si(conv581, (long) 1);
  mpz_t set582;
  mpz_init(set582);
  mpz_add_ui(set582, conv581, (unsigned long) pvsSelect(t55888, 0));
  mpz_clear(conv581);
  mpq_set_z(R578, set582);
  mpq_canonicalize(R578);
  mpz_clear(set582);
  int* N574;
  N574 = malloc( sizeof(int*) );
  copy_int*(N574, t55888);
  pvsDestructiveUpdate(N579, N576, L580, R578);//
  pvsDestructiveUpdate(N576, N574, L577, R575);//
  copy_int*(result, N579);
  mpq_clear(R575);
}

void pvs_d_foo551(int* result, int* t55888) {
  int L577;
  L577 = 0;
  free(N574);
  mpq_t R575;
  mpq_init(R575);
  mpz_t conv583;
  mpz_init(conv583);
  mpz_set_si(conv583, (long) 1);
  mpz_t set584;
  mpz_init(set584);
  mpz_add_ui(set584, conv583, (unsigned long) pvsSelect(t55888, 9));
  mpz_clear(conv583);
  mpq_clear(R578);
  mpq_set_z(R575, set584);
  mpq_canonicalize(R575);
  mpz_clear(set584);
  int L580;
  L580 = pvsSelect(t55888, 0);
  mpq_t R578;
  mpq_init(R578);
  mpz_t conv581;
  mpz_init(conv581);
  mpz_set_si(conv581, (long) 1);
  mpz_t set582;
  mpz_init(set582);
  mpz_add_ui(set582, conv581, (unsigned long) pvsSelect(t55888, 0));
  mpz_clear(conv581);
  mpq_set_z(R578, set582);
  mpq_canonicalize(R578);
  mpz_clear(set582);
  int* N574;
  N574 = malloc( sizeof(int*) );
  copy_int*(N574, t55888);
  pvsDestructiveUpdate(N579, N576, L580, R578);//
  pvsDestructiveUpdate(N576, N574, L577, R575);//
  copy_int*(result, N579);
  mpq_clear(R575);
}