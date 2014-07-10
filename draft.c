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
struct pair49 {
  mpz_t y;
  int x;
};


struct pair49 pvs_a47() {
  struct pair49 result;
  mpz_init(result.y);
  result.x = 2;
  mpz_set_si(result.y, (long) 12);
  return result;
}

struct pair49 pvs_d_a48() {
  struct pair49 result;
  mpz_init(result.y);
  result.x = 2;
  mpz_set_si(result.y, (long) 12);
  return result;
}

int pvs_first50(struct pair49 a) {
  int result;
  result = a.x;
  return result;
}

int pvs_d_first51(struct pair49 a) {
  int result;
  result = a.x;
  return result;
}

struct pair49 pvs_zero52(struct pair49 a) {
  struct pair49 result;
  mpz_init(result.y);
  int res56;
  res56 = 0;
  mpz_set(result.y, a.y);
  result.x = a.x;
  result.x = res56;
  return result;
}

struct pair49 pvs_d_zero53(struct pair49 a) {
  struct pair49 result;
  mpz_init(result.y);
  int res56;
  res56 = 0;
  mpz_set(result.y, a.y);
  result.x = a.x;
  result.x = res56;
  return result;
}

unsigned long int pvs_a57() {
  unsigned long int result;
  result = (unsigned long) 2;
  return result;
}

unsigned long int pvs_d_a58() {
  unsigned long int result;
  result = (unsigned long) 2;
  return result;
}

int pvs_b59() {
  int result;
  result = (3 + 1);
  return result;
}

int pvs_d_b60() {
  int result;
  result = (3 + 1);
  return result;
}

void pvs_c61(mpz_t result) {
  mpz_set_si(result, (long) (3 * (1 + 2)));
}

void pvs_d_c62(mpz_t result) {
  mpz_set_si(result, (long) (3 * (1 + 2)));
}

int pvs_incr63(int x) {
  int result;
  result = (x + 1);
  return result;
}

int pvs_d_incr64(int x) {
  int result;
  result = (x + 1);
  return result;
}

int pvs_zero65(mpz_t x) {
  int result;
  result = 0;
  return result;
}

int pvs_d_zero66(mpz_t x) {
  int result;
  result = 0;
  return result;
}

int pvs_f67(int a, int b) {
  mpz_t conv70;
  mpz_init(conv70);
  mpz_set_si(conv70, (long) b);
  int result;
  result = (int) (pvs_d_zero66(conv70) * pvs_d_incr64(a));
  mpz_clear(conv70);
  return result;
}

int pvs_d_f68(int a, int b) {
  mpz_t conv70;
  mpz_init(conv70);
  mpz_set_si(conv70, (long) b);
  int result;
  result = (int) (pvs_d_zero66(conv70) * pvs_d_incr64(a));
  mpz_clear(conv70);
  return result;
}

int pvs_f71(int x) {
  int if78;
  if((x <= 1)) {
    int if76;
    if((x == 0)) {
      if76 = 0;
    } else {
      if76 = x;
    }
    if78 = if76;
  } else {
    int if77;
    if((x > 10)) {
      if77 = 10;
    } else {
      if77 = (x + 5);
    }
    if78 = if77;
  }
  int result;
  result = if78;
  return result;
}

int pvs_d_f72(int x) {
  int if78;
  if((x <= 1)) {
    int if76;
    if((x == 0)) {
      if76 = 0;
    } else {
      if76 = x;
    }
    if78 = if76;
  } else {
    int if77;
    if((x > 10)) {
      if77 = 10;
    } else {
      if77 = (x + 5);
    }
    if78 = if77;
  }
  int result;
  result = if78;
  return result;
}

int pvs_t79(int x) {
  int result;
  result = x;
  return result;
}

int pvs_d_t80(int x) {
  int result;
  result = x;
  return result;
}

int* pvs_id81(int* t56665) {
  int* result;
  result = (int*) GC( t56665 );
  return result;
}

int* pvs_d_id82(int* t56665) {
  int* result;
  result = (int*) GC( t56665 );
  return result;
}

int* pvs_f83(int x) {
  int* result;
  result = GC_malloc(1000, sizeof(int));
  int i86;
  for(i86 = 0; i86 < 1000; i86++) {
    result[i86] = pvs_d_t80(i86);
  }
  return result;
}

int* pvs_d_f84(int x) {
  int* result;
  result = GC_malloc(1000, sizeof(int));
  int i86;
  for(i86 = 0; i86 < 1000; i86++) {
    result[i86] = pvs_d_t80(i86);
  }
  return result;
}

int* pvs_update87(int* x) {
  int* result;
  int L96;
  L96 = 0;
  int res97;
  res97 = 0;
  if ( GC_count( x ) == 1 )
    result = x;
  else {
    result = GC_malloc(1000, sizeof(int));
    int i95;
    for(i95 = 0; i95 < 1000; i95++) {
      result[i95] = x[i95];
    }
  }
  result[L96] = res97;
  return result;
}

int* pvs_d_update88(int* x) {
  int* result;
  int L96;
  L96 = 0;
  int res97;
  res97 = 0;
  if ( GC_count( x ) == 1 )
    result = x;
  else {
    result = GC_malloc(1000, sizeof(int));
    int i95;
    for(i95 = 0; i95 < 1000; i95++) {
      result[i95] = x[i95];
    }
  }
  result[L96] = res97;
  return result;
}

int* pvs_t298(int x) {
  mpq_t* set105;
  set105 = GC_malloc(1000, sizeof(mpq_t));
  int i104;
  for(i104 = 0; i104 < 1000; i104++) {
    mpq_init(set105[i104]);
  }
  int i103;
  for(i103 = 0; i103 < 1000; i103++) {
    mpq_set_d(set105[i103], (double) (x + i103) );
    mpq_canonicalize(set105[i103]);
  }
  int* result;
  result = (int*) GC( set105 );
  GC_free(set105);
  return result;
}

int* pvs_d_t299(int x) {
  mpq_t* set105;
  set105 = GC_malloc(1000, sizeof(mpq_t));
  int i104;
  for(i104 = 0; i104 < 1000; i104++) {
    mpq_init(set105[i104]);
  }
  int i103;
  for(i103 = 0; i103 < 1000; i103++) {
    mpq_set_d(set105[i103], (double) (x + i103) );
    mpq_canonicalize(set105[i103]);
  }
  int* result;
  result = (int*) GC( set105 );
  GC_free(set105);
  return result;
}

int* pvs_id106(int** t56665) {
  int** a;
  a = (int**) GC( t56665 );
  int* result;
  result = (int*) GC( a[0] );
  int i109;
  for(i109 = 0; i109 < 1000; i109++) {
    GC_free(a[i109]);
  }
  GC_free(a);
  return result;
}

int* pvs_d_id107(int** t56665) {
  int** a;
  a = (int**) GC( t56665 );
  int* result;
  result = (int*) GC( a[0] );
  int i109;
  for(i109 = 0; i109 < 1000; i109++) {
    GC_free(a[i109]);
  }
  GC_free(a);
  return result;
}

int** pvs_update110(int** x) {
  int** result;
  int L135;
  L135 = 1;
  int res136;
  res136 = 0;
  int L133;
  L133 = 0;
  int L138;
  L138 = 1;
  int* res139;
  res139 = GC_malloc(1000, sizeof(int));
  int i140;
  for(i140 = 0; i140 < 1000; i140++) {
    res139[i140] = i140;
  }
  if ( GC_count( x ) == 1 )
    result = x;
  else {
    result = GC_malloc(1000, sizeof(int*));
    int i132;
    for(i132 = 0; i132 < 1000; i132++) {
      result[i132] = (int*) GC( x[i132] );
    }
  }
  int* E134;
  if ( GC_count( result[L133] ) == 1 )
    E134 = result[L133];
  else {
    E134 = GC_malloc(1000, sizeof(int));
    int i137;
    for(i137 = 0; i137 < 1000; i137++) {
      E134[i137] = result[L133][i137];
    }
  }
  E134[L135] = res136;
  result[L138] = (int*) GC( res139 );
  GC_free(res139);
  return result;
}

int** pvs_d_update111(int** x) {
  int** result;
  int L135;
  L135 = 1;
  int res136;
  res136 = 0;
  int L133;
  L133 = 0;
  int L138;
  L138 = 1;
  int* res139;
  res139 = GC_malloc(1000, sizeof(int));
  int i140;
  for(i140 = 0; i140 < 1000; i140++) {
    res139[i140] = i140;
  }
  if ( GC_count( x ) == 1 )
    result = x;
  else {
    result = GC_malloc(1000, sizeof(int*));
    int i132;
    for(i132 = 0; i132 < 1000; i132++) {
      result[i132] = (int*) GC( x[i132] );
    }
  }
  int* E134;
  if ( GC_count( result[L133] ) == 1 )
    E134 = result[L133];
  else {
    E134 = GC_malloc(1000, sizeof(int));
    int i137;
    for(i137 = 0; i137 < 1000; i137++) {
      E134[i137] = result[L133][i137];
    }
  }
  E134[L135] = res136;
  result[L138] = (int*) GC( res139 );
  GC_free(res139);
  return result;
}
