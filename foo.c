/*
C file generated from foo.pvs
Make sure to link GMP and PVS.c in compilation:
    gcc -o foo foo.c -lgmp
    ./foo
*/

#include<stdio.h>
#include<gmp.h>
#include "foo.h"

#define TRUE 1
#define FALSE 0

int main(void) {
  printf("Executing foo ...\n");
  return 0;
}

int pvs_a377() {
  int result;
  result = 2;
  return result;
}

int pvs_d_a378() {
  int result;
  result = 2;
  return result;
}

int pvs_b379() {
  int result;
  mpz_t conv384;
  mpz_init(conv384);
  mpz_set_si(conv384, (long) pvs_a377());
  mpz_t conv385;
  mpz_init(conv385);
  mpz_set_si(conv385, (long) pvs_a377());
  mpz_t aux386;
  mpz_init(aux386);
  mpz_add(aux386, conv384, conv385);
  mpz_clear(conv385);
  mpz_clear(conv384);
  result = ( (int) mpz_get_si(aux386) );
  mpz_clear(aux386);
  return result;
}

int pvs_d_b380() {
  int result;
  mpz_t conv384;
  mpz_init(conv384);
  mpz_set_si(conv384, (long) pvs_a377());
  mpz_t conv385;
  mpz_init(conv385);
  mpz_set_si(conv385, (long) pvs_a377());
  mpz_t aux386;
  mpz_init(aux386);
  mpz_add(aux386, conv384, conv385);
  mpz_clear(conv385);
  mpz_clear(conv384);
  result = ( (int) mpz_get_si(aux386) );
  mpz_clear(aux386);
  return result;
}

int pvs_f387(mpz_t x, int y) {
  int result;
  mpz_t conv399;
  mpz_init(conv399);
  mpz_set_si(conv399, (long) y);
  mpz_t conv400;
  mpz_init(conv400);
  mpz_set_si(conv400, (long) 0);
  int aux401;
  aux401 = (mpz_cmp(conv399, (conv400)) == 0);
  mpz_clear(conv400);
  mpz_clear(conv399);
  int if408;
  if(aux401) {
    if408 = 0;
  } else {
    mpz_t conv402;
    mpz_init(conv402);
    mpz_set_si(conv402, (long) y);
    int aux403;
    aux403 = (mpz_cmp(x, conv402) < 0);
    mpz_clear(conv402);
    int if407;
    if(aux403) {
      if407 = ( (int) mpz_get_si(x) );
    } else {
      mpz_t conv404;
      mpz_init(conv404);
      mpz_set_si(conv404, (long) y);
      mpz_t aux405;
      mpz_init(aux405);
      mpz_sub(aux405, x, conv404);
      mpz_clear(conv404);
      int aux406;
      aux406 = pvs_d_f388(aux405, y);
      mpz_clear(aux405);
      if407 = aux406;
    }
    if408 = if407;
  }
  result = if408;
  return result;
}

int pvs_d_f388(mpz_t x, int y) {
  int result;
  mpz_t conv399;
  mpz_init(conv399);
  mpz_set_si(conv399, (long) y);
  mpz_t conv400;
  mpz_init(conv400);
  mpz_set_si(conv400, (long) 0);
  int aux401;
  aux401 = (mpz_cmp(conv399, (conv400)) == 0);
  mpz_clear(conv400);
  mpz_clear(conv399);
  int if408;
  if(aux401) {
    if408 = 0;
  } else {
    mpz_t conv402;
    mpz_init(conv402);
    mpz_set_si(conv402, (long) y);
    int aux403;
    aux403 = (mpz_cmp(x, conv402) < 0);
    mpz_clear(conv402);
    int if407;
    if(aux403) {
      if407 = ( (int) mpz_get_si(x) );
    } else {
      mpz_t conv404;
      mpz_init(conv404);
      mpz_set_si(conv404, (long) y);
      mpz_t aux405;
      mpz_init(aux405);
      mpz_sub(aux405, x, conv404);
      mpz_clear(conv404);
      int aux406;
      aux406 = pvs_d_f388(aux405, y);
      mpz_clear(aux405);
      if407 = aux406;
    }
    if408 = if407;
  }
  result = if408;
  return result;
}