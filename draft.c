// ---------------------------------------------
//        C file generated from draft.pvs
// ---------------------------------------------
//   Make sure to link GC.c and GMP in compilation:
//      gcc -o draft draft.c GC.c -lgmp
//      ./draft
// ---------------------------------------------

#include<stdio.h>
#include<gmp.h>
#include "GC.h"
#include "draft.h"

#define TRUE 1
#define FALSE 0

int main(void) {
  printf("Executing draft ...\n");
  return 0;
}
struct pair457 {
  mpz_t y;
  int x;
};


struct pair457 pvs_a455() {
  struct pair457 result;
  result.x = 2;
  mpz_set_si(result.y, (long) 12);
  return result;
}

struct pair457 pvs_d_a456() {
  struct pair457 result;
  result.x = 2;
  mpz_set_si(result.y, (long) 12);
  return result;
}

int pvs_first458(struct pair457 a) {
  int result;
  result = a.x;
  return result;
}

int pvs_d_first459(struct pair457 a) {
  int result;
  result = a.x;
  return result;
}

struct pair457 pvs_zero460(struct pair457 a) {
  struct pair457 result;
  int res463;
  res463 = 0;
  mpz_set(result.y, a.y);
  result.x = a.x;
  result.x = res463;
  int res463;
  return result;
}

struct pair457 pvs_d_zero461(struct pair457 a) {
  struct pair457 result;
  int res463;
  res463 = 0;
  mpz_set(result.y, a.y);
  result.x = a.x;
  result.x = res463;
  int res463;
  return result;
}

unsigned long int pvs_a464() {
  unsigned long int result;
  result = (unsigned long) 2;
  return result;
}

unsigned long int pvs_d_a465() {
  unsigned long int result;
  result = (unsigned long) 2;
  return result;
}

int pvs_b466() {
  int result;
  result = (3 + 1);
  return result;
}

int pvs_d_b467() {
  int result;
  result = (3 + 1);
  return result;
}

void pvs_c468(mpz_t result) {
  mpz_set_si(result, (long) (3 * (1 + 2)));
}

void pvs_d_c469(mpz_t result) {
  mpz_set_si(result, (long) (3 * (1 + 2)));
}

int pvs_incr470(int x) {
  int result;
  result = (x + 1);
  return result;
}

int pvs_d_incr471(int x) {
  int result;
  result = (x + 1);
  return result;
}

int pvs_zero472(mpz_t x) {
  int result;
  result = 0;
  return result;
}

int pvs_d_zero473(mpz_t x) {
  int result;
  result = 0;
  return result;
}

int pvs_f474(int a, int b) {
  mpz_t conv477;
  mpz_set_si(conv477, (long) b);
  int result;
  result = (int) (pvs_d_zero473(conv477) * pvs_d_incr471(a));
  mpz_t conv477;
  return result;
}

int pvs_d_f475(int a, int b) {
  mpz_t conv477;
  mpz_set_si(conv477, (long) b);
  int result;
  result = (int) (pvs_d_zero473(conv477) * pvs_d_incr471(a));
  mpz_t conv477;
  return result;
}

int pvs_f478(int x) {
  int if485;
  if((x <= 1)) {
    int if483;
    if((x == 0)) {
      if483 = 0;
    } else {
      if483 = x;
    }
    if485 = if483;
    int if483;
  } else {
    int if484;
    if((x > 10)) {
      if484 = 10;
    } else {
      if484 = (x - 5);
    }
    if485 = if484;
    int if484;
  }
  int result;
  result = if485;
  int if485;
  return result;
}

int pvs_d_f479(int x) {
  int if485;
  if((x <= 1)) {
    int if483;
    if((x == 0)) {
      if483 = 0;
    } else {
      if483 = x;
    }
    if485 = if483;
    int if483;
  } else {
    int if484;
    if((x > 10)) {
      if484 = 10;
    } else {
      if484 = (x - 5);
    }
    if485 = if484;
    int if484;
  }
  int result;
  result = if485;
  int if485;
  return result;
}

int pvs_t486(int x) {
  int result;
  result = x;
  return result;
}

int pvs_d_t487(int x) {
  int result;
  result = x;
  return result;
}

int* pvs_id2488(int* t62429) {
  int* result;
  result = (int*) GC( t62429 );
  return result;
}

int* pvs_d_id2489(int* t62429) {
  int* result;
  result = (int*) GC( t62429 );
  return result;
}

int* pvs_f490(int x) {
  int* result;
  result = GC_malloc(1000, sizeof(int));
  int i493;
  for(i493 = 0; i493 < 1000; i493++) {
    result[i493] = pvs_d_t487(i493);
  }
  return result;
}

int* pvs_d_f491(int x) {
  int* result;
  result = GC_malloc(1000, sizeof(int));
  int i493;
  for(i493 = 0; i493 < 1000; i493++) {
    result[i493] = pvs_d_t487(i493);
  }
  return result;
}

int* pvs_update494(int* x) {
  int* result;
  int L500;
  L500 = 0;
  int res501;
  res501 = 0;
  if ( GC_count( x ) == 1 )
    result = x;
  else {
    result = GC_malloc(1000, sizeof(int));
    int i499;
    for(i499 = 0; i499 < 1000; i499++) {
      result[i499] = x[i499];
    }
  }
  result[L500] = res501;
  int L500;
  int res501;
  return result;
}

int* pvs_d_update495(int* x) {
  int* result;
  int L500;
  L500 = 0;
  int res501;
  res501 = 0;
  if ( GC_count( x ) == 1 )
    result = x;
  else {
    result = GC_malloc(1000, sizeof(int));
    int i499;
    for(i499 = 0; i499 < 1000; i499++) {
      result[i499] = x[i499];
    }
  }
  result[L500] = res501;
  int L500;
  int res501;
  return result;
}

int* pvs_t2502(int x) {
  mpq_t* set509;
  set509 = GC_malloc(1000, sizeof(mpq_t));
  int i508;
  for(i508 = 0; i508 < 1000; i508++) {
    mpq_init(set509[i508]);
  }
  int i507;
  for(i507 = 0; i507 < 1000; i507++) {
    mpq_set_d(set509[i507], (double) (x + i507) );
    mpq_canonicalize(set509[i507]);
  }
  int* result;
  result = (int*) GC( set509 );
  mpq_t* set509;
  return result;
}

int* pvs_d_t2503(int x) {
  mpq_t* set509;
  set509 = GC_malloc(1000, sizeof(mpq_t));
  int i508;
  for(i508 = 0; i508 < 1000; i508++) {
    mpq_init(set509[i508]);
  }
  int i507;
  for(i507 = 0; i507 < 1000; i507++) {
    mpq_set_d(set509[i507], (double) (x + i507) );
    mpq_canonicalize(set509[i507]);
  }
  int* result;
  result = (int*) GC( set509 );
  mpq_t* set509;
  return result;
}

int* pvs_id510(int** t62429) {
  int** a;
  a = (int**) GC( t62429 );
  int* result;
  result = (int*) GC( a[0] );
  int** a;
  return result;
}

int* pvs_d_id511(int** t62429) {
  int** a;
  a = (int**) GC( t62429 );
  int* result;
  result = (int*) GC( a[0] );
  int** a;
  return result;
}

int* pvs_te512() {
  int* aux517;
  aux517 = GC_malloc(1000, sizeof(int));
  int i516;
  for(i516 = 0; i516 < 1000; i516++) {
    aux517[i516] = pvs_d_t487(i516);
  }
  int* result;
  result = (int*) GC( pvs_d_update495(pvs_d_update495(aux517)) );
  int* aux517;
  return result;
}

int* pvs_d_te513() {
  int* aux517;
  aux517 = GC_malloc(1000, sizeof(int));
  int i516;
  for(i516 = 0; i516 < 1000; i516++) {
    aux517[i516] = pvs_d_t487(i516);
  }
  int* result;
  result = (int*) GC( pvs_d_update495(pvs_d_update495(aux517)) );
  int* aux517;
  return result;
}

int** pvs_update518(int** x) {
  int** result;
  int L532;
  L532 = 1;
  int res533;
  res533 = 0;
  int L530;
  L530 = 0;
  int L535;
  L535 = 1;
  int* res536;
  res536 = GC_malloc(1000, sizeof(int));
  int i537;
  for(i537 = 0; i537 < 1000; i537++) {
    res536[i537] = i537;
  }
  if ( GC_count( x ) == 1 )
    result = x;
  else {
    result = GC_malloc(1000, sizeof(int*));
    int i529;
    for(i529 = 0; i529 < 1000; i529++) {
      result[i529] = (int*) GC( x[i529] );
    }
  }
  int* E531;
  if ( GC_count( result[L530] ) == 1 )
    E531 = result[L530];
  else {
    E531 = GC_malloc(1000, sizeof(int));
    int i534;
    for(i534 = 0; i534 < 1000; i534++) {
      E531[i534] = result[L530][i534];
    }
  }
  result[L530] = (int*) GC( E531 );
  E531[L532] = res533;
  result[L535] = (int*) GC( res536 );
  int L530;
  int L532;
  int res533;
  int L535;
  int* res536;
  return result;
}

int** pvs_d_update519(int** x) {
  int** result;
  int L532;
  L532 = 1;
  int res533;
  res533 = 0;
  int L530;
  L530 = 0;
  int L535;
  L535 = 1;
  int* res536;
  res536 = GC_malloc(1000, sizeof(int));
  int i537;
  for(i537 = 0; i537 < 1000; i537++) {
    res536[i537] = i537;
  }
  if ( GC_count( x ) == 1 )
    result = x;
  else {
    result = GC_malloc(1000, sizeof(int*));
    int i529;
    for(i529 = 0; i529 < 1000; i529++) {
      result[i529] = (int*) GC( x[i529] );
    }
  }
  int* E531;
  if ( GC_count( result[L530] ) == 1 )
    E531 = result[L530];
  else {
    E531 = GC_malloc(1000, sizeof(int));
    int i534;
    for(i534 = 0; i534 < 1000; i534++) {
      E531[i534] = result[L530][i534];
    }
  }
  result[L530] = (int*) GC( E531 );
  E531[L532] = res533;
  result[L535] = (int*) GC( res536 );
  int L530;
  int L532;
  int res533;
  int L535;
  int* res536;
  return result;
}