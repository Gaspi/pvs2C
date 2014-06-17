// ---------------------------------------------
//        C file generated from arrays.pvs
// ---------------------------------------------
//   Make sure to link GMP in compilation:
//      gcc -o arrays arrays.c -lgmp
//      ./arrays
// ---------------------------------------------

#include<stdio.h>
#include<gmp.h>
#include "arrays.h"

#define TRUE 1
#define FALSE 0

int main(void) {
  printf("Executing arrays ...\n");
  return 0;
}


mpq_t fun319(void *args) {
  mpz_t y = (mpz_t)args[1];
  int x = (int)args[0];
  mpz_t conv314;
  mpz_init(conv314);
  mpz_set_si(conv314, (long) 0);
  int aux315;
  aux315 = (mpz_cmp(y, conv314) == 0);
  mpz_clear(conv314);
  mpz_t if316;
  mpz_init(if316);
  if(aux315) {
    mpz_set_si(if316, (long) 1);
  } else {
    mpz_set_si(if316, (long) 0);
  }
  mpz_t aux317;
  mpz_init(aux317);
  mpz_add_ui(aux317, if316, (unsigned long) x);
  mpz_clear(if316);
  mpq_t conv318;
  mpq_init(conv318);
  mpq_set_z(conv318, aux317);
  mpq_canonicalize(conv318);
  mpz_clear(aux317);
  mpq_clear(conv318);
  return conv318;
}

mpq_t fun325(void *args) {
  mpz_t y = (mpz_t)args[1];
  int x = (int)args[0];
  mpz_t conv320;
  mpz_init(conv320);
  mpz_set_si(conv320, (long) 0);
  int aux321;
  aux321 = (mpz_cmp(y, conv320) == 0);
  mpz_clear(conv320);
  mpz_t if322;
  mpz_init(if322);
  if(aux321) {
    mpz_set_si(if322, (long) 1);
  } else {
    mpz_set_si(if322, (long) 0);
  }
  mpz_t aux323;
  mpz_init(aux323);
  mpz_add_ui(aux323, if322, (unsigned long) x);
  mpz_clear(if322);
  mpq_t conv324;
  mpq_init(conv324);
  mpq_set_z(conv324, aux323);
  mpq_canonicalize(conv324);
  mpz_clear(aux323);
  mpq_clear(conv324);
  return conv324;
}

mpq_t fun422(void *args) {
  mpz_t x = (mpz_t)args[3];
  pvsClosure t = (pvsClosure)args[2];
  int x1 = (int)args[1];
  mpz_t y = (mpz_t)args[0];
  mpz_t if420;
  mpz_init(if420);
  if((mpz_cmp(x#0, y) == 0)) {
    mpz_set_si(if420, (long) 12);
  } else {
    pvsClosure aux419;
    aux419 = malloc( sizeof(pvsClosure) );
    t56036(aux419, x1);
    mpz_set_si(if420, (long) aux419(x#0));
    free(aux419);
  }
  mpq_t conv421;
  mpq_init(conv421);
  mpq_set_z(conv421, if420);
  mpq_canonicalize(conv421);
  mpz_clear(if420);
  mpq_clear(conv421);
  return conv421;
}

pvsClosure fun424(void *args) {
  int x1 = (int)args[3];
  pvsClosure t = (pvsClosure)args[2];
  mpz_t y = (mpz_t)args[1];
  int x = (int)args[0];
  pvsClosure if423;
  if423 = malloc( sizeof(pvsClosure) );
  if((x1 == x)) {
    void args[4];
    args[1] = x1;
    args[0] = y;
    args[3] = x;
    makeClosure(if423, fun422, args);
  } else {
    t56036(if423, x1);
  }
  free(if423);
  return if423;
}

mpq_t fun429(void *args) {
  mpz_t x = (mpz_t)args[3];
  pvsClosure t = (pvsClosure)args[2];
  int x1 = (int)args[1];
  mpz_t y = (mpz_t)args[0];
  mpz_t if427;
  mpz_init(if427);
  if((mpz_cmp(x#0, y) == 0)) {
    mpz_set_si(if427, (long) 12);
  } else {
    pvsClosure aux426;
    aux426 = malloc( sizeof(pvsClosure) );
    t56036(aux426, x1);
    mpz_set_si(if427, (long) aux426(x#0));
    free(aux426);
  }
  mpq_t conv428;
  mpq_init(conv428);
  mpq_set_z(conv428, if427);
  mpq_canonicalize(conv428);
  mpz_clear(if427);
  mpq_clear(conv428);
  return conv428;
}

pvsClosure fun431(void *args) {
  int x1 = (int)args[3];
  pvsClosure t = (pvsClosure)args[2];
  mpz_t y = (mpz_t)args[1];
  int x = (int)args[0];
  pvsClosure if430;
  if430 = malloc( sizeof(pvsClosure) );
  if((x1 == x)) {
    void args[4];
    args[1] = x1;
    args[0] = y;
    args[3] = x;
    makeClosure(if430, fun429, args);
  } else {
    t56036(if430, x1);
  }
  free(if430);
  return if430;
}

void pvs_a312(pvsClosure result, int x) {
  void args[2];
  args[0] = x;
  makeClosure(result, fun325, args);
}

void pvs_d_a313(pvsClosure result, int x) {
  void args[2];
  args[0] = x;
  makeClosure(result, fun325, args);
}

int pvs_b326(int x) {
  int result;
  result = x;
  return result;
}

int pvs_d_b327(int x) {
  int result;
  result = x;
  return result;
}

void pvs_incr328(int* result, int* t56036) {
  int L335;
  L335 = t56036[0];
  for(int i334 = 0; i334 < 10; i334++) {
    result[i334] = t56036[i334];
  }
  result[L335] = t56036[9];
}

void pvs_d_incr329(int* result, int* t56036) {
  int L335;
  L335 = t56036[0];
  for(int i334 = 0; i334 < 10; i334++) {
    result[i334] = t56036[i334];
  }
  result[L335] = t56036[9];
}

void pvs_decr336(int* result, int* t56036) {
  int L341;
  L341 = 0;
  for(int i340 = 0; i340 < 10; i340++) {
    result[i340] = pvs_d_b327(i340);
  }
  result[L341] = 1;
}

void pvs_d_decr337(int* result, int* t56036) {
  int L341;
  L341 = 0;
  for(int i340 = 0; i340 < 10; i340++) {
    result[i340] = pvs_d_b327(i340);
  }
  result[L341] = 1;
}

void pvs_sum342(int* result, int* T, int* U) {
  mpq_t* set351;
  set351 = malloc( 10 * sizeof(mpq_t) );
  for(int i352 = 0; i352 < 10; i352++) {
    mpq_init(set351[i352]);
  }
  for(int i349 = 0; i349 < 10; i349++) {
    mpz_t conv350;
    mpz_init(conv350);
    mpz_set_si(conv350, (long) T[i349]);
    mpz_add_ui(set351[i349], conv350, (unsigned long) U[i349]);
    mpz_clear(conv350);
  }
  for(int i353 = 0; i353 < 10; i353++) {
    result[i353] = ( (int) mpq_get_d(set351[i353]) );
  }
  free(set351);
}

void pvs_d_sum343(int* result, int* T, int* U) {
  mpq_t* set351;
  set351 = malloc( 10 * sizeof(mpq_t) );
  for(int i352 = 0; i352 < 10; i352++) {
    mpq_init(set351[i352]);
  }
  for(int i349 = 0; i349 < 10; i349++) {
    mpz_t conv350;
    mpz_init(conv350);
    mpz_set_si(conv350, (long) T[i349]);
    mpz_add_ui(set351[i349], conv350, (unsigned long) U[i349]);
    mpz_clear(conv350);
  }
  for(int i353 = 0; i353 < 10; i353++) {
    result[i353] = ( (int) mpq_get_d(set351[i353]) );
  }
  free(set351);
}

void pvs_foo354(int* result, int* t56036) {
  int L371;
  L371 = 0;
  mpz_t conv372;
  mpz_init(conv372);
  mpz_set_si(conv372, (long) 1);
  mpz_t aux373;
  mpz_init(aux373);
  mpz_add_ui(aux373, conv372, (unsigned long) t56036[9]);
  mpz_clear(conv372);
  int L374;
  L374 = t56036[0];
  mpz_t conv375;
  mpz_init(conv375);
  mpz_set_si(conv375, (long) 1);
  mpz_t aux376;
  mpz_init(aux376);
  mpz_add_ui(aux376, conv375, (unsigned long) t56036[0]);
  mpz_clear(conv375);
  for(int i370 = 0; i370 < 10; i370++) {
    result[i370] = t56036[i370];
  }
  result[L371] = ( (int) mpz_get_si(aux373) );
  result[L374] = ( (int) mpz_get_si(aux376) );
  mpz_clear(aux373);
  mpz_clear(aux376);
}

void pvs_d_foo355(int* result, int* t56036) {
  int L371;
  L371 = 0;
  mpz_t conv372;
  mpz_init(conv372);
  mpz_set_si(conv372, (long) 1);
  mpz_t aux373;
  mpz_init(aux373);
  mpz_add_ui(aux373, conv372, (unsigned long) t56036[9]);
  mpz_clear(conv372);
  int L374;
  L374 = t56036[0];
  mpz_t conv375;
  mpz_init(conv375);
  mpz_set_si(conv375, (long) 1);
  mpz_t aux376;
  mpz_init(aux376);
  mpz_add_ui(aux376, conv375, (unsigned long) t56036[0]);
  mpz_clear(conv375);
  for(int i370 = 0; i370 < 10; i370++) {
    result[i370] = t56036[i370];
  }
  result[L371] = ( (int) mpz_get_si(aux373) );
  result[L374] = ( (int) mpz_get_si(aux376) );
  mpz_clear(aux373);
  mpz_clear(aux376);
}

void pvs_bar377(int** result, int** t56036) {
  int L399;
  L399 = 0;
  int L401;
  L401 = 0;
  int** aux402;
  aux402 = malloc( 10 * sizeof(int*) );
  for(int i403 = 0; i403 < 10; i403++) {
    aux402[i403] = malloc( 12 * sizeof(int) );
  }
  for(int i397 = 0; i397 < 10; i397++) {
    for(int i398 = 0; i398 < 12; i398++) {
      aux402[i397][i398] = t56036[i397][i398];
    }
  }
  int* E400 = aux402[L399];
  E400[L401] = 0;
  int** a = aux402;
  for(int i404 = 0; i404 < 10; i404++) {
    for(int i405 = 0; i405 < 12; i405++) {
      result[i404][i405] = a[i404][i405];
    }
  }
  free(aux402);
}

void pvs_d_bar378(int** result, int** t56036) {
  int L399;
  L399 = 0;
  int L401;
  L401 = 0;
  int** aux402;
  aux402 = malloc( 10 * sizeof(int*) );
  for(int i403 = 0; i403 < 10; i403++) {
    aux402[i403] = malloc( 12 * sizeof(int) );
  }
  for(int i397 = 0; i397 < 10; i397++) {
    for(int i398 = 0; i398 < 12; i398++) {
      aux402[i397][i398] = t56036[i397][i398];
    }
  }
  int* E400 = aux402[L399];
  E400[L401] = 0;
  int** a = aux402;
  for(int i404 = 0; i404 < 10; i404++) {
    for(int i405 = 0; i405 < 12; i405++) {
      result[i404][i405] = a[i404][i405];
    }
  }
  free(aux402);
}

void pvs_test406(mpz_t* result, mpz_t* t56036) {
  int L415;
  L415 = 0;
  mpz_t conv416;
  mpz_init(conv416);
  mpz_set_si(conv416, (long) 12);
  for(int i414 = 0; i414 < 10; i414++) {
    mpz_set(result[i414], t56036[i414]);
  }
  mpz_set(result[L415], conv416);
  mpz_clear(conv416);
}

void pvs_d_test407(mpz_t* result, mpz_t* t56036) {
  int L415;
  L415 = 0;
  mpz_t conv416;
  mpz_init(conv416);
  mpz_set_si(conv416, (long) 12);
  for(int i414 = 0; i414 < 10; i414++) {
    mpz_set(result[i414], t56036[i414]);
  }
  mpz_set(result[L415], conv416);
  mpz_clear(conv416);
}

void pvs_set417(pvsClosure result, pvsClosure t56036, int x, mpz_t y) {
  void args[4];
  args[1] = y;
  args[0] = x;
  pvsClosure aux432;
  aux432 = malloc( sizeof(pvsClosure) );
  makeClosure(aux432, fun431, args);
  copy_pvsClosure(result, aux432);
  free(aux432);
}

void pvs_d_set418(pvsClosure result, pvsClosure t56036, int x, mpz_t y) {
  void args[4];
  args[1] = y;
  args[0] = x;
  pvsClosure aux432;
  aux432 = malloc( sizeof(pvsClosure) );
  makeClosure(aux432, fun431, args);
  copy_pvsClosure(result, aux432);
  free(aux432);
}