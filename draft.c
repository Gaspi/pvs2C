// ---------------------------------------------
//        C file generated from draft.pvs
// ---------------------------------------------
//   Make sure to link GC.c and GMP in compilation:
//      gcc -o draft draft.c GC/GC.c -lgmp
//      ./draft
// ---------------------------------------------

#include<stdio.h>
#include<gmp.h>
#include"GC.h"
#include "draft.h"

#define TRUE 1
#define FALSE 0

int main(void) {
  printf("Executing draft ...\n");
  return 0;
}


unsigned long int pvs_a47() {
  unsigned long int result;
  result = (unsigned long) 2;
  return result;
}

unsigned long int pvs_d_a48() {
  unsigned long int result;
  result = (unsigned long) 2;
  return result;
}

int pvs_b49() {
  int result;
  result = (3 + 1);
  return result;
}

int pvs_d_b50() {
  int result;
  result = (3 + 1);
  return result;
}

void pvs_c51(mpz_t result) {
  mpz_set_si(result, (long) (3 * (1 + 2)));
}

void pvs_d_c52(mpz_t result) {
  mpz_set_si(result, (long) (3 * (1 + 2)));
}

int pvs_incr53(int x) {
  int result;
  result = (x + 1);
  return result;
}

int pvs_d_incr54(int x) {
  int result;
  result = (x + 1);
  return result;
}

int pvs_zero55(mpz_t x) {
  int result;
  result = 0;
  return result;
}

int pvs_d_zero56(mpz_t x) {
  int result;
  result = 0;
  return result;
}

int pvs_f57(int a, int b) {
  mpz_t conv60;
  mpz_init(conv60);
  mpz_set_si(conv60, (long) b);
  int result;
  result = (int) (pvs_d_zero56(conv60) * pvs_d_incr54(a));
  mpz_clear(conv60);
  return result;
}

int pvs_d_f58(int a, int b) {
  mpz_t conv60;
  mpz_init(conv60);
  mpz_set_si(conv60, (long) b);
  int result;
  result = (int) (pvs_d_zero56(conv60) * pvs_d_incr54(a));
  mpz_clear(conv60);
  return result;
}

int pvs_f61(int x) {
  int if68;
  if((x <= 1)) {
    int if66;
    if((x == 0)) {
      if66 = 0;
    } else {
      if66 = x;
    }
    if68 = if66;
  } else {
    int if67;
    if((x > 10)) {
      if67 = 10;
    } else {
      if67 = (x + 5);
    }
    if68 = if67;
  }
  int result;
  result = if68;
  return result;
}

int pvs_d_f62(int x) {
  int if68;
  if((x <= 1)) {
    int if66;
    if((x == 0)) {
      if66 = 0;
    } else {
      if66 = x;
    }
    if68 = if66;
  } else {
    int if67;
    if((x > 10)) {
      if67 = 10;
    } else {
      if67 = (x + 5);
    }
    if68 = if67;
  }
  int result;
  result = if68;
  return result;
}

int pvs_t69(int x) {
  int result;
  result = x;
  return result;
}

int pvs_d_t70(int x) {
  int result;
  result = x;
  return result;
}

int* pvs_id71(int* t55798) {
  int* result;
  result = (int*) GC( t55798 );
  return result;
}

int* pvs_d_id72(int* t55798) {
  int* result;
  result = (int*) GC( t55798 );
  return result;
}

int* pvs_f73(int x) {
  int* result;
  result = GC_malloc(1000, sizeof(int));
  int i76;
  for(i76 = 0; i76 < 1000; i76++) {
    result[i76] = pvs_d_t70(i76);
  }
  return result;
}

int* pvs_d_f74(int x) {
  int* result;
  result = GC_malloc(1000, sizeof(int));
  int i76;
  for(i76 = 0; i76 < 1000; i76++) {
    result[i76] = pvs_d_t70(i76);
  }
  return result;
}

int* pvs_update77(int* x) {
  int* result;
  int L86;
  L86 = 0;
  int res87;
  res87 = 0;
  if ( GC_count( x ) == 1 )
    result = x;
  else {
    result = GC_malloc(1000, sizeof(int));
    int i85;
    for(i85 = 0; i85 < 1000; i85++) {
      result[i85] = x[i85];
    }
  }
  result[L86] = res87;
  return result;
}

int* pvs_d_update78(int* x) {
  int* result;
  int L86;
  L86 = 0;
  int res87;
  res87 = 0;
  if ( GC_count( x ) == 1 )
    result = x;
  else {
    result = GC_malloc(1000, sizeof(int));
    int i85;
    for(i85 = 0; i85 < 1000; i85++) {
      result[i85] = x[i85];
    }
  }
  result[L86] = res87;
  return result;
}

int* pvs_t288(int x) {
  mpq_t* set95;
  set95 = GC_malloc(1000, sizeof(mpq_t));
  int i94;
  for(i94 = 0; i94 < 1000; i94++) {
    mpq_init(set95[i94]);
  }
  int i93;
  for(i93 = 0; i93 < 1000; i93++) {
    mpq_set_d(set95[i93], (double) (x + i93) );
    mpq_canonicalize(set95[i93]);
  }
  int* result;
  result = (int*) GC( set95 );
  GC_free(set95);
  return result;
}

int* pvs_d_t289(int x) {
  mpq_t* set95;
  set95 = GC_malloc(1000, sizeof(mpq_t));
  int i94;
  for(i94 = 0; i94 < 1000; i94++) {
    mpq_init(set95[i94]);
  }
  int i93;
  for(i93 = 0; i93 < 1000; i93++) {
    mpq_set_d(set95[i93], (double) (x + i93) );
    mpq_canonicalize(set95[i93]);
  }
  int* result;
  result = (int*) GC( set95 );
  GC_free(set95);
  return result;
}

int* pvs_id96(int** t55798) {
  int** a;
  a = (int**) GC( t55798 );
  int* result;
  result = (int*) GC( a[0] );
  int i99;
  for(i99 = 0; i99 < 1000; i99++) {
    GC_free(a[i99]);
  }
  GC_free(a);
  return result;
}

int* pvs_d_id97(int** t55798) {
  int** a;
  a = (int**) GC( t55798 );
  int* result;
  result = (int*) GC( a[0] );
  int i99;
  for(i99 = 0; i99 < 1000; i99++) {
    GC_free(a[i99]);
  }
  GC_free(a);
  return result;
}

int** pvs_update100(int** x) {
  int** result;
  int L125;
  L125 = 1;
  int res126;
  res126 = 0;
  int L123;
  L123 = 0;
  int L128;
  L128 = 1;
  int* res129;
  res129 = GC_malloc(1000, sizeof(int));
  int i130;
  for(i130 = 0; i130 < 1000; i130++) {
    res129[i130] = i130;
  }
  if ( GC_count( x ) == 1 )
    result = x;
  else {
    result = GC_malloc(1000, sizeof(int*));
    int i122;
    for(i122 = 0; i122 < 1000; i122++) {
      result[i122] = (int*) GC( x[i122] );
    }
  }
  int* E124;
  if ( GC_count( result[L123] ) == 1 )
    E124 = result[L123];
  else {
    E124 = GC_malloc(1000, sizeof(int));
    int i127;
    for(i127 = 0; i127 < 1000; i127++) {
      E124[i127] = result[L123][i127];
    }
  }
  E124[L125] = res126;
  result[L128] = (int*) GC( res129 );
  GC_free(res129);
  return result;
}

int** pvs_d_update101(int** x) {
  int** result;
  int L125;
  L125 = 1;
  int res126;
  res126 = 0;
  int L123;
  L123 = 0;
  int L128;
  L128 = 1;
  int* res129;
  res129 = GC_malloc(1000, sizeof(int));
  int i130;
  for(i130 = 0; i130 < 1000; i130++) {
    res129[i130] = i130;
  }
  if ( GC_count( x ) == 1 )
    result = x;
  else {
    result = GC_malloc(1000, sizeof(int*));
    int i122;
    for(i122 = 0; i122 < 1000; i122++) {
      result[i122] = (int*) GC( x[i122] );
    }
  }
  int* E124;
  if ( GC_count( result[L123] ) == 1 )
    E124 = result[L123];
  else {
    E124 = GC_malloc(1000, sizeof(int));
    int i127;
    for(i127 = 0; i127 < 1000; i127++) {
      E124[i127] = result[L123][i127];
    }
  }
  E124[L125] = res126;
  result[L128] = (int*) GC( res129 );
  GC_free(res129);
  return result;
}