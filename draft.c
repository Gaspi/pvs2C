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

struct struct_pair2419 {
  mpz_t y;
  int x;
};
typedef (struct struct_pair2419)* pair2419;


pair2419 pvs_a2417() {
  pair2419 result;
  mpz_init(result->y);
  result->x = 2;
  mpz_set_si(result->y, (long) 12);
  return *result*;
}

pair2419 pvs_a_d2418() {
  pair2419 result;
  mpz_init(result->y);
  result->x = 2;
  mpz_set_si(result->y, (long) 12);
  return *result*;
}

int pvs_first2420(pair2419 a) {
  int result;
  result = *a*->x;
  return result;
}

int pvs_first_d2421(pair2419 a) {
  int result;
  result = *a*->x;
  return result;
}

pair2419 pvs_zero2422(pair2419 a) {
  pair2419 result;
  mpz_init(result->y);
  int res2425;
  res2425 = 0;
  result = copy_pair2419(*a*);
  result->x = res2425;
  return *result*;
}

pair2419 pvs_zero_d2423(pair2419 a) {
  pair2419 result;
  mpz_init(result->y);
  int res2425;
  res2425 = 0;
  result = copy_pair2419(*a*);
  result->x = res2425;
  return *result*;
}

unsigned long int pvs_a2426() {
  unsigned long int result;
  result = (unsigned long) 2;
  return result;
}

unsigned long int pvs_a_d2427() {
  unsigned long int result;
  result = (unsigned long) 2;
  return result;
}

int pvs_b2428() {
  int result;
  result = (3 + 1);
  return result;
}

int pvs_b_d2429() {
  int result;
  result = (3 + 1);
  return result;
}

void pvs_c2430(mpz_t result) {
  mpz_set_si(result, (long) (3 * (1 + 2)));
}

void pvs_c_d2431(mpz_t result) {
  mpz_set_si(result, (long) (3 * (1 + 2)));
}

int pvs_incr2432(int x) {
  int result;
  result = (x + 1);
  return result;
}

int pvs_incr_d2433(int x) {
  int result;
  result = (x + 1);
  return result;
}

int pvs_zero2434(mpz_t x) {
  int result;
  result = 0;
  return result;
}

int pvs_zero_d2435(mpz_t x) {
  int result;
  result = 0;
  return result;
}

int pvs_f2436(int a, int b) {
  mpz_t conv2439;
  mpz_set_si(conv2439, (long) b);
  int result;
  result = (int) (pvs_zero2434(conv2439) * pvs_incr2432(a));
  mpz_clear(conv2439);
  return result;
}

int pvs_f_d2437(int a, int b) {
  mpz_t conv2439;
  mpz_set_si(conv2439, (long) b);
  int result;
  result = (int) (pvs_zero2434(conv2439) * pvs_incr2432(a));
  mpz_clear(conv2439);
  return result;
}

int pvs_f2440(int x) {
  int if2447;
  if (((x <= 1) && 1)) {
    int if2445;
    if (((x == 0) || (x < 0))) {
      if2445 = 0;
    } else {
      if2445 = x;
    }
    if2447 = if2445;
  } else {
    int if2446;
    if ((x > 10)) {
      if2446 = 10;
    } else {
      if2446 = (x - 5);
    }
    if2447 = if2446;
  }
  int result;
  result = if2447;
  return result;
}

int pvs_f_d2441(int x) {
  int if2447;
  if (((x <= 1) && 1)) {
    int if2445;
    if (((x == 0) || (x < 0))) {
      if2445 = 0;
    } else {
      if2445 = x;
    }
    if2447 = if2445;
  } else {
    int if2446;
    if ((x > 10)) {
      if2446 = 10;
    } else {
      if2446 = (x - 5);
    }
    if2447 = if2446;
  }
  int result;
  result = if2447;
  return result;
}

int pvs_t2448(int x) {
  int result;
  result = x;
  return result;
}

int pvs_t_d2449(int x) {
  int result;
  result = x;
  return result;
}

int* pvs_id22450(int* t57712) {
  int* result;
  result = (int*) GC( *t57712* );
  return *result*;
}

int* pvs_id2_d2451(int* t57712) {
  int* result;
  result = (int*) GC( *t57712* );
  return *result*;
}

int* pvs_f2452(int x) {
  int* result;
  result = GC_malloc(1000, sizeof(int) );
  int i2455;
  for(i2455 = 0; i2455 < 1000; i2455++) {
    result[i2455] = pvs_t2448(i2455);
  }
  return *result*;
}

int* pvs_f_d2453(int x) {
  int* result;
  result = GC_malloc(1000, sizeof(int) );
  int i2455;
  for(i2455 = 0; i2455 < 1000; i2455++) {
    result[i2455] = pvs_t2448(i2455);
  }
  return *result*;
}

int* pvs_update2456(int* x) {
  int* result;
  int L2460;
  L2460 = 0;
  int res2461;
  res2461 = 0;
  result = (int*) GC( *x* );
  result[L2460] = res2461;
  return *result*;
}

int* pvs_update_d2457(int* x) {
  int* result;
  int L2460;
  L2460 = 0;
  int res2461;
  res2461 = 0;
  result = (int*) GC( *x* );
  result[L2460] = res2461;
  return *result*;
}

int* pvs_t22462(int x) {
  mpq_t* set2467;
  set2467 = GC_malloc(1000, sizeof(mpq_t) );
  int i2466;
  for(i2466 = 0; i2466 < 1000; i2466++) {
    mpq_init(set2467[i2466]);
    mpq_set_d(set2467[i2466], (double) (x + i2466) );
    mpq_canonicalize(set2467[i2466]);
  }
  int* result;
  result = (int*) GC( set2467 );
  if( GC_count( *set2467* ) == 1 ) {
    int i2492;
    for(i2492 = 0; i2492 < 1000; i2492++) {
      mpq_clear(*set2467*[i2492]);
    }
  }
  GC_free(*set2467*);
  return *result*;
}

int* pvs_t2_d2463(int x) {
  mpq_t* set2467;
  set2467 = GC_malloc(1000, sizeof(mpq_t) );
  int i2466;
  for(i2466 = 0; i2466 < 1000; i2466++) {
    mpq_init(set2467[i2466]);
    mpq_set_d(set2467[i2466], (double) (x + i2466) );
    mpq_canonicalize(set2467[i2466]);
  }
  int* result;
  result = (int*) GC( set2467 );
  if( GC_count( *set2467* ) == 1 ) {
    int i2493;
    for(i2493 = 0; i2493 < 1000; i2493++) {
      mpq_clear(*set2467*[i2493]);
    }
  }
  GC_free(*set2467*);
  return *result*;
}

int* pvs_id2468(int** t57712) {
  int** a;
  a = (int**) GC( *t57712* );
  int* result;
  result = (int*) GC( a[0] );
  if( GC_count( *a* ) == 1 ) {
    int i2494;
    for(i2494 = 0; i2494 < 1000; i2494++) {
      GC_free(*a*[i2494]);
    }
  }
  GC_free(*a*);
  return *result*;
}

int* pvs_id_d2469(int** t57712) {
  int** a;
  a = (int**) GC( *t57712* );
  int* result;
  result = (int*) GC( a[0] );
  if( GC_count( *a* ) == 1 ) {
    int i2496;
    for(i2496 = 0; i2496 < 1000; i2496++) {
      GC_free(*a*[i2496]);
    }
  }
  GC_free(*a*);
  return *result*;
}

int* pvs_te2470() {
  int* aux2475;
  aux2475 = GC_malloc(1000, sizeof(int) );
  int i2474;
  for(i2474 = 0; i2474 < 1000; i2474++) {
    aux2475[i2474] = pvs_t2448(i2474);
  }
  int* result;
  result = (int*) GC( pvs_update2456(pvs_update2456(aux2475)) );
  GC_free(*aux2475*);
  return *result*;
}

int* pvs_te_d2471() {
  int* aux2475;
  aux2475 = GC_malloc(1000, sizeof(int) );
  int i2474;
  for(i2474 = 0; i2474 < 1000; i2474++) {
    aux2475[i2474] = pvs_t2448(i2474);
  }
  int* result;
  result = (int*) GC( pvs_update2456(pvs_update2456(aux2475)) );
  GC_free(*aux2475*);
  return *result*;
}

int** pvs_update2476(int** x) {
  int** result;
  int L2487;
  L2487 = 1;
  int res2488;
  res2488 = 0;
  int L2485;
  L2485 = 0;
  int L2489;
  L2489 = 1;
  int* res2490;
  res2490 = GC_malloc(1000, sizeof(int) );
  int i2491;
  for(i2491 = 0; i2491 < 1000; i2491++) {
    res2490[i2491] = i2491;
  }
  result = (int**) GC( *x* );
  int* E2486;
  E2486 = GC_malloc(1000, sizeof(int) );
  int i2500;
  for(i2500 = 0; i2500 < 1000; i2500++) {
    E2486[i2500] = result[L2485][i2500];
  }
  E2486[L2487] = res2488;
  result[L2485] = (int*) GC( *E2486* );
  result[L2489] = (int*) GC( res2490 );
  GC_free(*res2490*);
  return *result*;
}

int** pvs_update_d2477(int** x) {
  int** result;
  int L2487;
  L2487 = 1;
  int res2488;
  res2488 = 0;
  int L2485;
  L2485 = 0;
  int L2489;
  L2489 = 1;
  int* res2490;
  res2490 = GC_malloc(1000, sizeof(int) );
  int i2491;
  for(i2491 = 0; i2491 < 1000; i2491++) {
    res2490[i2491] = i2491;
  }
  result = (int**) GC( *x* );
  int* E2486;
  E2486 = GC_malloc(1000, sizeof(int) );
  int i2502;
  for(i2502 = 0; i2502 < 1000; i2502++) {
    E2486[i2502] = result[L2485][i2502];
  }
  E2486[L2487] = res2488;
  result[L2485] = (int*) GC( *E2486* );
  result[L2489] = (int*) GC( res2490 );
  GC_free(*res2490*);
  return *result*;
}