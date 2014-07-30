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
  GC_start();
  printf("Executing draft ...\n");
  // Insert code here
  GC_quit();
  return 0;
}


pair6360 pvs_a6358() {
  pair6360 result;
  result = GC_malloc(1, sizeof( struct struct_pair6360 ) );
  mpz_init(result->y);
  result->x = 2;
  mpz_set_si(result->y, (long) 12);
  return result;
}

pair6360 pvs_a_d6359() {
  pair6360 result;
  result = GC_malloc(1, sizeof( struct struct_pair6360 ) );
  mpz_init(result->y);
  result->x = 2;
  mpz_set_si(result->y, (long) 12);
  return result;
}

int pvs_first6361(pair6360 a) {
  int result;
  result = a->x;
  if( GC_count( a ) == 1 ) {
    mpz_clear(a->y);
  }
  GC_free(a);
  return result;
}

int pvs_first_d6362(pair6360 a) {
  int result;
  result = a->x;
  if( GC_count( a ) == 1 ) {
    mpz_clear(a->y);
  }
  GC_free(a);
  return result;
}

pair6360 pvs_zero6363(pair6360 a) {
  pair6360 result;
  if ( GC_count( a ) == 1 )
    result = a;
  else {
    result = GC_malloc(1, sizeof( struct struct_pair6360 ));
    mpz_set(result->y, a->y);
    result->x = a->x;
  }
  result->x = 0;
  return result;
}

pair6360 pvs_zero_d6364(pair6360 a) {
  a->x = 0;
  return a;
}

uli pvs_a6367() {
  return (uli) 2;
}

uli pvs_a_d6368() {
  return (uli) 2;
}

int pvs_b6369() {
  return (3 + 1);
}

int pvs_b_d6370() {
  return (3 + 1);
}

void pvs_c6371(mpz_t result) {
  mpz_set_si(result, (long) (3 * (1 + 2)));
}

void pvs_c_d6372(mpz_t result) {
  mpz_set_si(result, (long) (3 * (1 + 2)));
}

int pvs_incr6373(int x) {
  return (x + 1);
}

int pvs_incr_d6374(int x) {
  return (x + 1);
}

int pvs_zero6375(mpz_t x) {
  mpz_clear(x);
  return 0;
}

int pvs_zero_d6376(mpz_t x) {
  mpz_clear(x);
  return 0;
}

int pvs_f6377(int a, int b) {
  mpz_t conv6379;
  mpz_set_si(conv6379, (long) b);
  int result;
  result = (int) (pvs_zero_d6376( conv6379 ) * pvs_incr_d6374( a ));
  mpz_clear(conv6379);
  return result;
}

int pvs_f_d6378(int a, int b) {
  mpz_t conv6380;
  mpz_set_si(conv6380, (long) b);
  int result;
  result = (int) (pvs_zero_d6376( conv6380 ) * pvs_incr_d6374( a ));
  mpz_clear(conv6380);
  return result;
}

int pvs_f6381(int x) {
  int if6385;
  if (((x <= 1) && 1)) {
    int if6383;
    if (((x == 0) || (x < 0))) {
      return if6385;
    } else {
      return if6385;
    }
  } else {
    int if6384;
    if ((x > 10)) {
      return if6385;
    } else {
      if6384 = (x - 5);
      return if6385;
    }
  }
}

int pvs_f_d6382(int x) {
  int if6388;
  if (((x <= 1) && 1)) {
    int if6386;
    if (((x == 0) || (x < 0))) {
      return if6388;
    } else {
      return if6388;
    }
  } else {
    int if6387;
    if ((x > 10)) {
      return if6388;
    } else {
      if6387 = (x - 5);
      return if6388;
    }
  }
}

int pvs_t6389(int x) {
  return x;
}

int pvs_t_d6390(int x) {
  return x;
}

int* pvs_id26391(int* t57547) {
  return t57547;
}

int* pvs_id2_d6392(int* t57547) {
  return t57547;
}

int* pvs_f6395(int x) {
  int* result;
  result = GC_malloc(1000, sizeof(int) );
  int i6397;
  for(i6397 = 0; i6397 < 1000; i6397++) {
    result[i6397] = pvs_t_d6390( i6397 );
  }
  return result;
}

int* pvs_f_d6396(int x) {
  int* result;
  result = GC_malloc(1000, sizeof(int) );
  int i6398;
  for(i6398 = 0; i6398 < 1000; i6398++) {
    result[i6398] = pvs_t_d6390( i6398 );
  }
  return result;
}

int* pvs_update6399(int* x) {
  int* result;
  if ( GC_count( x ) == 1 )
    result = x;
  else {
    result = GC_malloc(1000, sizeof(int) );
    int i6608;
    for(i6608 = 0; i6608 < 1000; i6608++) {
      result[i6608] = x[i6608];
    }
  }
  result[0] = 0;
  return result;
}

int* pvs_update_d6400(int* x) {
  x[0] = 0;
  return x;
}

int* pvs_t26422(int x) {
  int* result;
  result = GC_malloc(1000, sizeof(int) );
  int i6424;
  for(i6424 = 0; i6424 < 1000; i6424++) {
    result[i6424] = (x + i6424);
  }
  return result;
}

int* pvs_t2_d6423(int x) {
  int* result;
  result = GC_malloc(1000, sizeof(int) );
  int i6425;
  for(i6425 = 0; i6425 < 1000; i6425++) {
    result[i6425] = (x + i6425);
  }
  return result;
}

int* pvs_id6426(int** t57547) {
  int* result;
  result = (int*) t57547[0];
  if( GC_count( t57547 ) == 1 ) {
    int i6609;
    for(i6609 = 0; i6609 < 1000; i6609++) {
      GC_free(t57547[i6609]);
    }
  }
  GC_free(t57547);
  return result;
}

int* pvs_id_d6427(int** t57547) {
  int* result;
  result = (int*) t57547[0];
  if( GC_count( t57547 ) == 1 ) {
    int i6611;
    for(i6611 = 0; i6611 < 1000; i6611++) {
      GC_free(t57547[i6611]);
    }
  }
  GC_free(t57547);
  return result;
}

int* pvs_te6458() {
  int* aux6461;
  aux6461 = GC_malloc(1000, sizeof(int) );
  int i6460;
  for(i6460 = 0; i6460 < 1000; i6460++) {
    aux6461[i6460] = pvs_t_d6390( i6460 );
  }
  return pvs_update_d6400( pvs_update_d6400( aux6461 ) );
}

int* pvs_te_d6459() {
  int* aux6463;
  aux6463 = GC_malloc(1000, sizeof(int) );
  int i6462;
  for(i6462 = 0; i6462 < 1000; i6462++) {
    aux6463[i6462] = pvs_t_d6390( i6462 );
  }
  return pvs_update_d6400( pvs_update_d6400( aux6463 ) );
}

int** pvs_update6476(int** x) {
  int** result;
  int* res6483;
  res6483 = GC_malloc(1000, sizeof(int) );
  int i6484;
  for(i6484 = 0; i6484 < 1000; i6484++) {
    res6483[i6484] = i6484;
  }
  if ( GC_count( x ) == 1 )
    result = x;
  else {
    result = GC_malloc(1000, sizeof(int*) );
    int i6613;
    for(i6613 = 0; i6613 < 1000; i6613++) {
      if ( GC_count( x[i6613] ) == 1 )
        result[i6613] = x[i6613];
      else {
        result[i6613] = GC_malloc(1000, sizeof(int) );
        int i6614;
        for(i6614 = 0; i6614 < 1000; i6614++) {
          result[i6613][i6614] = x[i6613][i6614];
        }
      }
    }
  }
  int* E6479;
  E6479 = GC_malloc(1000, sizeof(int) );
  int i6615;
  for(i6615 = 0; i6615 < 1000; i6615++) {
    E6479[i6615] = result[0][i6615];
  }
  E6479[1] = 0;
  result[0] = (int*) E6479;
  result[1] = (int*) res6483;
  return result;
}

int** pvs_update_d6477(int** x) {
  int* res6490;
  res6490 = GC_malloc(1000, sizeof(int) );
  int i6491;
  for(i6491 = 0; i6491 < 1000; i6491++) {
    res6490[i6491] = i6491;
  }
  int* E6486;
  E6486 = GC_malloc(1000, sizeof(int) );
  int i6616;
  for(i6616 = 0; i6616 < 1000; i6616++) {
    E6486[i6616] = x[0][i6616];
  }
  E6486[1] = 0;
  x[0] = (int*) E6486;
  x[1] = (int*) res6490;
  return x;
}