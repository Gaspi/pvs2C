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

struct struct_pair517 {
  mpz_t y;
  int x;
};
typedef (struct struct_pair517)* pair517;


pair517 pvs_a515() {
  pair517 result;
  result = GC_malloc(1, sizeof( struct_pair517 ) );
  mpz_init(result->y);
  result->x = 2;
  mpz_set_si(result->y, (long) 12);
  return *result*;}

pair517 pvs_a_d516() {
  pair517 result;
  result = GC_malloc(1, sizeof( struct_pair517 ) );
  mpz_init(result->y);
  result->x = 2;
  mpz_set_si(result->y, (long) 12);
  return *result*;}

int pvs_first518(pair517 a) {
  int result;
  result = *a*->x;
  return result;}

int pvs_first_d519(pair517 a) {
  int result;
  result = *a*->x;
  return result;}

pair517 pvs_zero520(pair517 a) {
  pair517 result;
  int res523;
  res523 = 0;
  result = GC_malloc(1, sizeof(pair517));
  mpz_set(result->y, *a*->y);
  result->x = *a*->x;
  result->x = res523;
  return *result*;}

pair517 pvs_zero_d521(pair517 a) {
  pair517 result;
  int res523;
  res523 = 0;
  result = GC_malloc(1, sizeof(pair517));
  mpz_set(result->y, *a*->y);
  result->x = *a*->x;
  result->x = res523;
  return *result*;}

unsigned long int pvs_a524() {
  unsigned long int result;
  result = (unsigned long) 2;
  return result;}

unsigned long int pvs_a_d525() {
  unsigned long int result;
  result = (unsigned long) 2;
  return result;}

int pvs_b526() {
  int result;
  result = (3 + 1);
  return result;}

int pvs_b_d527() {
  int result;
  result = (3 + 1);
  return result;}

void pvs_c528(mpz_t result) {
  mpz_set_si(result, (long) (3 * (1 + 2)));}

void pvs_c_d529(mpz_t result) {
  mpz_set_si(result, (long) (3 * (1 + 2)));}

int pvs_incr530(int x) {
  int result;
  result = (x + 1);
  return result;}

int pvs_incr_d531(int x) {
  int result;
  result = (x + 1);
  return result;}

int pvs_zero532(mpz_t x) {
  int result;
  result = 0;
  return result;}

int pvs_zero_d533(mpz_t x) {
  int result;
  result = 0;
  return result;}

int pvs_f534(int a, int b) {
  mpz_t conv537;
  mpz_set_si(conv537, (long) b);
  int result;
  result = (int) (pvs_zero532(conv537) * pvs_incr530(a));
  mpz_clear(conv537);
  return result;}

int pvs_f_d535(int a, int b) {
  mpz_t conv537;
  mpz_set_si(conv537, (long) b);
  int result;
  result = (int) (pvs_zero532(conv537) * pvs_incr530(a));
  mpz_clear(conv537);
  return result;}

int pvs_f538(int x) {
  int if545;
  if (((x <= 1) && 1)) {
    int if543;
    if (((x == 0) || (x < 0))) {
      if543 = 0;
    } else {
      if543 = x;
    }
    if545 = if543;
  } else {
    int if544;
    if ((x > 10)) {
      if544 = 10;
    } else {
      if544 = (x - 5);
    }
    if545 = if544;
  }
  int result;
  result = if545;
  return result;}

int pvs_f_d539(int x) {
  int if545;
  if (((x <= 1) && 1)) {
    int if543;
    if (((x == 0) || (x < 0))) {
      if543 = 0;
    } else {
      if543 = x;
    }
    if545 = if543;
  } else {
    int if544;
    if ((x > 10)) {
      if544 = 10;
    } else {
      if544 = (x - 5);
    }
    if545 = if544;
  }
  int result;
  result = if545;
  return result;}

int pvs_t546(int x) {
  int result;
  result = x;
  return result;}

int pvs_t_d547(int x) {
  int result;
  result = x;
  return result;}

int* pvs_id2548(int* t56210) {
  int* result;
  result = (int*) GC( *t56210* );
  return *result*;}

int* pvs_id2_d549(int* t56210) {
  int* result;
  result = (int*) GC( *t56210* );
  return *result*;}

int* pvs_f550(int x) {
  int* result;
  result = GC_malloc(1000, sizeof(int) );
  int i553;
  for(i553 = 0; i553 < 1000; i553++) {
    result[i553] = pvs_t546(i553);
  }
  return *result*;}

int* pvs_f_d551(int x) {
  int* result;
  result = GC_malloc(1000, sizeof(int) );
  int i553;
  for(i553 = 0; i553 < 1000; i553++) {
    result[i553] = pvs_t546(i553);
  }
  return *result*;}

int* pvs_update554(int* x) {
  int* result;
  int L558;
  L558 = 0;
  int res559;
  res559 = 0;
  result = GC_malloc(1000, sizeof(int) );
  int i590;
  for(i590 = 0; i590 < 1000; i590++) {
    result[i590] = *x*[i590];
  }
  result[L558] = res559;
  return *result*;}

int* pvs_update_d555(int* x) {
  int* result;
  int L558;
  L558 = 0;
  int res559;
  res559 = 0;
  result = GC_malloc(1000, sizeof(int) );
  int i591;
  for(i591 = 0; i591 < 1000; i591++) {
    result[i591] = *x*[i591];
  }
  result[L558] = res559;
  return *result*;}

int* pvs_t2560(int x) {
  mpq_t* set565;
  set565 = GC_malloc(1000, sizeof(mpq_t) );
  int i564;
  for(i564 = 0; i564 < 1000; i564++) {
    mpq_init(set565[i564]);
    mpq_set_d(set565[i564], (double) (x + i564) );
    mpq_canonicalize(set565[i564]);
  }
  int* result;
  result = (int*) GC( set565 );
  if( GC_count( *set565* ) == 1 ) {
    int i592;
    for(i592 = 0; i592 < 1000; i592++) {
      mpq_clear(*set565*[i592]);
    }
  }
  GC_free(*set565*);
  return *result*;}

int* pvs_t2_d561(int x) {
  mpq_t* set565;
  set565 = GC_malloc(1000, sizeof(mpq_t) );
  int i564;
  for(i564 = 0; i564 < 1000; i564++) {
    mpq_init(set565[i564]);
    mpq_set_d(set565[i564], (double) (x + i564) );
    mpq_canonicalize(set565[i564]);
  }
  int* result;
  result = (int*) GC( set565 );
  if( GC_count( *set565* ) == 1 ) {
    int i593;
    for(i593 = 0; i593 < 1000; i593++) {
      mpq_clear(*set565*[i593]);
    }
  }
  GC_free(*set565*);
  return *result*;}

int* pvs_id566(int** t56210) {
  int** a;
  a = (int**) GC( *t56210* );
  int* result;
  result = (int*) GC( a[0] );
  if( GC_count( *a* ) == 1 ) {
    int i594;
    for(i594 = 0; i594 < 1000; i594++) {
      GC_free(*a*[i594]);
    }
  }
  GC_free(*a*);
  return *result*;}

int* pvs_id_d567(int** t56210) {
  int** a;
  a = (int**) GC( *t56210* );
  int* result;
  result = (int*) GC( a[0] );
  if( GC_count( *a* ) == 1 ) {
    int i596;
    for(i596 = 0; i596 < 1000; i596++) {
      GC_free(*a*[i596]);
    }
  }
  GC_free(*a*);
  return *result*;}

int* pvs_te568() {
  int* aux573;
  aux573 = GC_malloc(1000, sizeof(int) );
  int i572;
  for(i572 = 0; i572 < 1000; i572++) {
    aux573[i572] = pvs_t546(i572);
  }
  int* result;
  result = (int*) GC( pvs_update554(pvs_update554(aux573)) );
  GC_free(*aux573*);
  return *result*;}

int* pvs_te_d569() {
  int* aux573;
  aux573 = GC_malloc(1000, sizeof(int) );
  int i572;
  for(i572 = 0; i572 < 1000; i572++) {
    aux573[i572] = pvs_t546(i572);
  }
  int* result;
  result = (int*) GC( pvs_update554(pvs_update554(aux573)) );
  GC_free(*aux573*);
  return *result*;}

int** pvs_update574(int** x) {
  int** result;
  int L585;
  L585 = 1;
  int res586;
  res586 = 0;
  int L583;
  L583 = 0;
  int L587;
  L587 = 1;
  int* res588;
  res588 = GC_malloc(1000, sizeof(int) );
  int i589;
  for(i589 = 0; i589 < 1000; i589++) {
    res588[i589] = i589;
  }
  result = GC_malloc(1000, sizeof(int*) );
  int i600;
  for(i600 = 0; i600 < 1000; i600++) {
    result[i600] = GC_malloc(1000, sizeof(int) );
    int i601;
    for(i601 = 0; i601 < 1000; i601++) {
      result[i600][i601] = *x*[i600][i601];
    }
  }
  int* E584;
  E584 = GC_malloc(1000, sizeof(int) );
  int i602;
  for(i602 = 0; i602 < 1000; i602++) {
    E584[i602] = result[L583][i602];
  }
  E584[L585] = res586;
  result[L583] = (int*) GC( *E584* );
  result[L587] = (int*) GC( res588 );
  GC_free(*res588*);
  return *result*;}

int** pvs_update_d575(int** x) {
  int** result;
  int L585;
  L585 = 1;
  int res586;
  res586 = 0;
  int L583;
  L583 = 0;
  int L587;
  L587 = 1;
  int* res588;
  res588 = GC_malloc(1000, sizeof(int) );
  int i589;
  for(i589 = 0; i589 < 1000; i589++) {
    res588[i589] = i589;
  }
  result = GC_malloc(1000, sizeof(int*) );
  int i604;
  for(i604 = 0; i604 < 1000; i604++) {
    result[i604] = GC_malloc(1000, sizeof(int) );
    int i605;
    for(i605 = 0; i605 < 1000; i605++) {
      result[i604][i605] = *x*[i604][i605];
    }
  }
  int* E584;
  E584 = GC_malloc(1000, sizeof(int) );
  int i606;
  for(i606 = 0; i606 < 1000; i606++) {
    E584[i606] = result[L583][i606];
  }
  E584[L585] = res586;
  result[L583] = (int*) GC( *E584* );
  result[L587] = (int*) GC( res588 );
  GC_free(*res588*);
  return *result*;}