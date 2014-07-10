// ---------------------------------------------
//        C file generated from draft.pvs
// ---------------------------------------------
//   Make sure to link GC.c and GMP in compilation:
//      gcc -o draft draft.c GC/GC.c -lgmp
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
struct pair169 {
  mpz_t y;
  int x;
};


struct pair169 pvs_a167() {
  struct pair169 result;
  mpz_init(result.y);
  result.x = 2;
  mpz_set_si(result.y, (long) 12);
  return result;
}

struct pair169 pvs_d_a168() {
  struct pair169 result;
  mpz_init(result.y);
  result.x = 2;
  mpz_set_si(result.y, (long) 12);
  return result;
}

int pvs_first170(struct pair169 a) {
  int result;
  result = a.x;
  return result;
}

int pvs_d_first171(struct pair169 a) {
  int result;
  result = a.x;
  return result;
}

struct pair169 pvs_zero172(struct pair169 a) {
  struct pair169 result;
  mpz_init(result.y);
  int res176;
  res176 = 0;
  mpz_set(result.y, a.y);
  result.x = a.x;
  result.x = res176;
  return result;
}

struct pair169 pvs_d_zero173(struct pair169 a) {
  struct pair169 result;
  mpz_init(result.y);
  int res176;
  res176 = 0;
  mpz_set(result.y, a.y);
  result.x = a.x;
  result.x = res176;
  return result;
}

unsigned long int pvs_a177() {
  unsigned long int result;
  result = (unsigned long) 2;
  return result;
}

unsigned long int pvs_d_a178() {
  unsigned long int result;
  result = (unsigned long) 2;
  return result;
}

int pvs_b179() {
  int result;
  result = (3 + 1);
  return result;
}

int pvs_d_b180() {
  int result;
  result = (3 + 1);
  return result;
}

void pvs_c181(mpz_t result) {
  mpz_set_si(result, (long) (3 * (1 + 2)));
}

void pvs_d_c182(mpz_t result) {
  mpz_set_si(result, (long) (3 * (1 + 2)));
}

int pvs_incr183(int x) {
  int result;
  result = (x + 1);
  return result;
}

int pvs_d_incr184(int x) {
  int result;
  result = (x + 1);
  return result;
}

int pvs_zero185(mpz_t x) {
  int result;
  result = 0;
  return result;
}

int pvs_d_zero186(mpz_t x) {
  int result;
  result = 0;
  return result;
}

int pvs_f187(int a, int b) {
  mpz_t conv190;
  mpz_init(conv190);
  mpz_set_si(conv190, (long) b);
  int result;
  result = (int) (pvs_d_zero186(conv190) * pvs_d_incr184(a));
  mpz_clear(conv190);
  return result;
}

int pvs_d_f188(int a, int b) {
  mpz_t conv190;
  mpz_init(conv190);
  mpz_set_si(conv190, (long) b);
  int result;
  result = (int) (pvs_d_zero186(conv190) * pvs_d_incr184(a));
  mpz_clear(conv190);
  return result;
}

int pvs_f191(int x) {
  int if198;
  if((x <= 1)) {
    int if196;
    if((x == 0)) {
      if196 = 0;
    } else {
      if196 = x;
    }
    if198 = if196;
  } else {
    int if197;
    if((x > 10)) {
      if197 = 10;
    } else {
      if197 = (x + 5);
    }
    if198 = if197;
  }
  int result;
  result = if198;
  return result;
}

int pvs_d_f192(int x) {
  int if198;
  if((x <= 1)) {
    int if196;
    if((x == 0)) {
      if196 = 0;
    } else {
      if196 = x;
    }
    if198 = if196;
  } else {
    int if197;
    if((x > 10)) {
      if197 = 10;
    } else {
      if197 = (x + 5);
    }
    if198 = if197;
  }
  int result;
  result = if198;
  return result;
}

int pvs_t199(int x) {
  int result;
  result = x;
  return result;
}

int pvs_d_t200(int x) {
  int result;
  result = x;
  return result;
}

int* pvs_id201(int* t56604) {
  int* result;
  result = (int*) GC( t56604 );
  return result;
}

int* pvs_d_id202(int* t56604) {
  int* result;
  result = (int*) GC( t56604 );
  return result;
}

int* pvs_f203(int x) {
  int* result;
  result = GC_malloc(1000, sizeof(int));
  int i206;
  for(i206 = 0; i206 < 1000; i206++) {
    result[i206] = pvs_d_t200(i206);
  }
  return result;
}

int* pvs_d_f204(int x) {
  int* result;
  result = GC_malloc(1000, sizeof(int));
  int i206;
  for(i206 = 0; i206 < 1000; i206++) {
    result[i206] = pvs_d_t200(i206);
  }
  return result;
}

int* pvs_update207(int* x) {
  int* result;
  int L216;
  L216 = 0;
  int res217;
  res217 = 0;
  if ( GC_count( x ) == 1 )
    result = x;
  else {
    result = GC_malloc(1000, sizeof(int));
    int i215;
    for(i215 = 0; i215 < 1000; i215++) {
      result[i215] = x[i215];
    }
  }
  result[L216] = res217;
  return result;
}

int* pvs_d_update208(int* x) {
  int* result;
  int L216;
  L216 = 0;
  int res217;
  res217 = 0;
  if ( GC_count( x ) == 1 )
    result = x;
  else {
    result = GC_malloc(1000, sizeof(int));
    int i215;
    for(i215 = 0; i215 < 1000; i215++) {
      result[i215] = x[i215];
    }
  }
  result[L216] = res217;
  return result;
}

int* pvs_t2218(int x) {
  mpq_t* set225;
  set225 = GC_malloc(1000, sizeof(mpq_t));
  int i224;
  for(i224 = 0; i224 < 1000; i224++) {
    mpq_init(set225[i224]);
  }
  int i223;
  for(i223 = 0; i223 < 1000; i223++) {
    mpq_set_d(set225[i223], (double) (x + i223) );
    mpq_canonicalize(set225[i223]);
  }
  int* result;
  result = (int*) GC( set225 );
  GC_free(set225);
  return result;
}

int* pvs_d_t2219(int x) {
  mpq_t* set225;
  set225 = GC_malloc(1000, sizeof(mpq_t));
  int i224;
  for(i224 = 0; i224 < 1000; i224++) {
    mpq_init(set225[i224]);
  }
  int i223;
  for(i223 = 0; i223 < 1000; i223++) {
    mpq_set_d(set225[i223], (double) (x + i223) );
    mpq_canonicalize(set225[i223]);
  }
  int* result;
  result = (int*) GC( set225 );
  GC_free(set225);
  return result;
}

int* pvs_id226(int** t56604) {
  int** a;
  a = (int**) GC( t56604 );
  int* result;
  result = (int*) GC( a[0] );
  int i229;
  for(i229 = 0; i229 < 1000; i229++) {
    GC_free(a[i229]);
  }
  GC_free(a);
  return result;
}

int* pvs_d_id227(int** t56604) {
  int** a;
  a = (int**) GC( t56604 );
  int* result;
  result = (int*) GC( a[0] );
  int i229;
  for(i229 = 0; i229 < 1000; i229++) {
    GC_free(a[i229]);
  }
  GC_free(a);
  return result;
}

int** pvs_update230(int** x) {
  int** result;
  int L255;
  L255 = 1;
  int res256;
  res256 = 0;
  int L253;
  L253 = 0;
  int L258;
  L258 = 1;
  int* res259;
  res259 = GC_malloc(1000, sizeof(int));
  int i260;
  for(i260 = 0; i260 < 1000; i260++) {
    res259[i260] = i260;
  }
  if ( GC_count( x ) == 1 )
    result = x;
  else {
    result = GC_malloc(1000, sizeof(int*));
    int i252;
    for(i252 = 0; i252 < 1000; i252++) {
      result[i252] = (int*) GC( x[i252] );
    }
  }
  int* E254;
  if ( GC_count( result[L253] ) == 1 )
    E254 = result[L253];
  else {
    E254 = GC_malloc(1000, sizeof(int));
    int i257;
    for(i257 = 0; i257 < 1000; i257++) {
      E254[i257] = result[L253][i257];
    }
  }
  E254[L255] = res256;
  result[L258] = (int*) GC( res259 );
  GC_free(res259);
  return result;
}

int** pvs_d_update231(int** x) {
  int** result;
  int L255;
  L255 = 1;
  int res256;
  res256 = 0;
  int L253;
  L253 = 0;
  int L258;
  L258 = 1;
  int* res259;
  res259 = GC_malloc(1000, sizeof(int));
  int i260;
  for(i260 = 0; i260 < 1000; i260++) {
    res259[i260] = i260;
  }
  if ( GC_count( x ) == 1 )
    result = x;
  else {
    result = GC_malloc(1000, sizeof(int*));
    int i252;
    for(i252 = 0; i252 < 1000; i252++) {
      result[i252] = (int*) GC( x[i252] );
    }
  }
  int* E254;
  if ( GC_count( result[L253] ) == 1 )
    E254 = result[L253];
  else {
    E254 = GC_malloc(1000, sizeof(int));
    int i257;
    for(i257 = 0; i257 < 1000; i257++) {
      E254[i257] = result[L253][i257];
    }
  }
  E254[L255] = res256;
  result[L258] = (int*) GC( res259 );
  GC_free(res259);
  return result;
}