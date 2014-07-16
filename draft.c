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

struct pair521 {
  mpz_t y;
  int x;
};
typedef (struct pair521)* struct_pair521;


struct_pair521 pvs_a519() {
  struct_pair521 result;
  mpz_init(result->y);
  result->x = 2;
  mpz_set_si(result->y, (long) 12);
  return result;
}

struct_pair521 pvs_d_a520() {
  struct_pair521 result;
  mpz_init(result->y);
  result->x = 2;
  mpz_set_si(result->y, (long) 12);
  return result;
}

int pvs_first522(struct_pair521 a) {
  int result;
  result = a->x;
  return result;
}

int pvs_d_first523(struct_pair521 a) {
  int result;
  result = a->x;
  return result;
}

struct_pair521 pvs_zero524(struct_pair521 a) {
  struct_pair521 result;
  mpz_init(result->y);
  int res527;
  res527 = 0;
  result = GC_malloc(1, sizeof(struct_pair521));
  mpz_set(result->y, a->y);
  result->x = a->x;
  result->x = res527;
  return result;
}

struct_pair521 pvs_d_zero525(struct_pair521 a) {
  struct_pair521 result;
  mpz_init(result->y);
  int res527;
  res527 = 0;
  result = GC_malloc(1, sizeof(struct_pair521));
  mpz_set(result->y, a->y);
  result->x = a->x;
  result->x = res527;
  return result;
}

unsigned long int pvs_a528() {
  unsigned long int result;
  result = (unsigned long) 2;
  return result;
}

unsigned long int pvs_d_a529() {
  unsigned long int result;
  result = (unsigned long) 2;
  return result;
}

int pvs_b530() {
  int result;
  result = (3 + 1);
  return result;
}

int pvs_d_b531() {
  int result;
  result = (3 + 1);
  return result;
}

void pvs_c532(mpz_t result) {
  mpz_set_si(result, (long) (3 * (1 + 2)));
}

void pvs_d_c533(mpz_t result) {
  mpz_set_si(result, (long) (3 * (1 + 2)));
}

int pvs_incr534(int x) {
  int result;
  result = (x + 1);
  return result;
}

int pvs_d_incr535(int x) {
  int result;
  result = (x + 1);
  return result;
}

int pvs_zero536(mpz_t x) {
  int result;
  result = 0;
  return result;
}

int pvs_d_zero537(mpz_t x) {
  int result;
  result = 0;
  return result;
}

int pvs_f538(int a, int b) {
  mpz_t conv541;
  mpz_set_si(conv541, (long) b);
  int result;
  result = (int) (pvs_zero536(conv541) * pvs_incr534(a));
  mpz_clear(conv541);
  return result;
}

int pvs_d_f539(int a, int b) {
  mpz_t conv541;
  mpz_set_si(conv541, (long) b);
  int result;
  result = (int) (pvs_zero536(conv541) * pvs_incr534(a));
  mpz_clear(conv541);
  return result;
}

int pvs_f542(int x) {
  int if549;
  if (((x <= 1) && 1)) {
    int if547;
    if (((x == 0) || (x < 0))) {
      if547 = 0;
    } else {
      if547 = x;
    }
    if549 = if547;
  } else {
    int if548;
    if ((x > 10)) {
      if548 = 10;
    } else {
      if548 = (x - 5);
    }
    if549 = if548;
  }
  int result;
  result = if549;
  return result;
}

int pvs_d_f543(int x) {
  int if549;
  if (((x <= 1) && 1)) {
    int if547;
    if (((x == 0) || (x < 0))) {
      if547 = 0;
    } else {
      if547 = x;
    }
    if549 = if547;
  } else {
    int if548;
    if ((x > 10)) {
      if548 = 10;
    } else {
      if548 = (x - 5);
    }
    if549 = if548;
  }
  int result;
  result = if549;
  return result;
}

int pvs_t550(int x) {
  int result;
  result = x;
  return result;
}

int pvs_d_t551(int x) {
  int result;
  result = x;
  return result;
}

int* pvs_id2552(int* t56059) {
  int* result;
  result = (int*) GC( t56059 );
  return result;
}

int* pvs_d_id2553(int* t56059) {
  int* result;
  result = (int*) GC( t56059 );
  return result;
}

int* pvs_f554(int x) {
  int* result;
  result = GC_malloc(1000, sizeof(int) );
  int i557;
  for(i557 = 0; i557 < 1000; i557++) {
    result[i557] = pvs_t550(i557);
  }
  return result;
}

int* pvs_d_f555(int x) {
  int* result;
  result = GC_malloc(1000, sizeof(int) );
  int i557;
  for(i557 = 0; i557 < 1000; i557++) {
    result[i557] = pvs_t550(i557);
  }
  return result;
}

int* pvs_update558(int* x) {
  int* result;
  int L563;
  L563 = 0;
  int res564;
  res564 = 0;
  result = GC_malloc(1000, sizeof(int) );
  int i565;
  for(i565 = 0; i565 < 1000; i565++) {
    result[i565] = x[i565];
  }
  result[L563] = res564;
  return result;
}

int* pvs_d_update559(int* x) {
  int* result;
  int L563;
  L563 = 0;
  int res564;
  res564 = 0;
  result = GC_malloc(1000, sizeof(int) );
  int i565;
  for(i565 = 0; i565 < 1000; i565++) {
    result[i565] = x[i565];
  }
  result[L563] = res564;
  return result;
}

int* pvs_t2566(int x) {
  mpq_t* set572;
  set572 = GC_malloc(1000, sizeof(mpq_t) );
  int i571;
  for(i571 = 0; i571 < 1000; i571++) {
    mpq_init(set572[i571]);
    mpq_set_d(set572[i571], (double) (x + i571) );
    mpq_canonicalize(set572[i571]);
  }
  int* result;
  result = (int*) GC( set572 );
  if( GC_count( set572 ) == 1 ) {
    int i573;
    for(i573 = 0; i573 < 1000; i573++) {
      mpq_clear(set572[i573]);
    }
  }
  GC_free(set572)
  return result;
}

int* pvs_d_t2567(int x) {
  mpq_t* set572;
  set572 = GC_malloc(1000, sizeof(mpq_t) );
  int i571;
  for(i571 = 0; i571 < 1000; i571++) {
    mpq_init(set572[i571]);
    mpq_set_d(set572[i571], (double) (x + i571) );
    mpq_canonicalize(set572[i571]);
  }
  int* result;
  result = (int*) GC( set572 );
  if( GC_count( set572 ) == 1 ) {
    int i573;
    for(i573 = 0; i573 < 1000; i573++) {
      mpq_clear(set572[i573]);
    }
  }
  GC_free(set572)
  return result;
}

int* pvs_id574(int** t56059) {
  int** a;
  a = (int**) GC( t56059 );
  int* result;
  result = (int*) GC( a[0] );
  if( GC_count( a ) == 1 ) {
    int i578;
    for(i578 = 0; i578 < 1000; i578++) {
      GC_free(a[i578])
    }
  }
  GC_free(a)
  return result;
}

int* pvs_d_id575(int** t56059) {
  int** a;
  a = (int**) GC( t56059 );
  int* result;
  result = (int*) GC( a[0] );
  if( GC_count( a ) == 1 ) {
    int i578;
    for(i578 = 0; i578 < 1000; i578++) {
      GC_free(a[i578])
    }
  }
  GC_free(a)
  return result;
}

int* pvs_te580() {
  int* aux586;
  aux586 = GC_malloc(1000, sizeof(int) );
  int i585;
  for(i585 = 0; i585 < 1000; i585++) {
    aux586[i585] = pvs_t550(i585);
  }
  int* result;
  result = (int*) GC( pvs_update558(pvs_update558(aux586)) );
  GC_free(aux586)
  return result;
}

int* pvs_d_te581() {
  int* aux586;
  aux586 = GC_malloc(1000, sizeof(int) );
  int i585;
  for(i585 = 0; i585 < 1000; i585++) {
    aux586[i585] = pvs_t550(i585);
  }
  int* result;
  result = (int*) GC( pvs_update558(pvs_update558(aux586)) );
  GC_free(aux586)
  return result;
}

int** pvs_update588(int** x) {
  int** result;
  int L602;
  L602 = 1;
  int res603;
  res603 = 0;
  int L600;
  L600 = 0;
  int L604;
  L604 = 1;
  int* res605;
  res605 = GC_malloc(1000, sizeof(int) );
  int i606;
  for(i606 = 0; i606 < 1000; i606++) {
    res605[i606] = i606;
  }
  result = GC_malloc(1000, sizeof(int*) );
  int i607;
  for(i607 = 0; i607 < 1000; i607++) {
    result[i607] = (int*) GC( x[i607] );
  }
  int* E601;
  E601 = GC_malloc(1000, sizeof(int) );
  int i608;
  for(i608 = 0; i608 < 1000; i608++) {
    E601[i608] = result[L600][i608];
  }
  E601[L602] = res603;
  result[L600] = (int*) GC( E601 );
  result[L604] = (int*) GC( res605 );
  GC_free(res605)
  return result;
}

int** pvs_d_update589(int** x) {
  int** result;
  int L602;
  L602 = 1;
  int res603;
  res603 = 0;
  int L600;
  L600 = 0;
  int L604;
  L604 = 1;
  int* res605;
  res605 = GC_malloc(1000, sizeof(int) );
  int i606;
  for(i606 = 0; i606 < 1000; i606++) {
    res605[i606] = i606;
  }
  result = GC_malloc(1000, sizeof(int*) );
  int i607;
  for(i607 = 0; i607 < 1000; i607++) {
    result[i607] = (int*) GC( x[i607] );
  }
  int* E601;
  E601 = GC_malloc(1000, sizeof(int) );
  int i608;
  for(i608 = 0; i608 < 1000; i608++) {
    E601[i608] = result[L600][i608];
  }
  E601[L602] = res603;
  result[L600] = (int*) GC( E601 );
  result[L604] = (int*) GC( res605 );
  GC_free(res605)
  return result;
}