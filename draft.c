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


unsigned long int pvs_a544() {
  unsigned long int result;
  result = (unsigned long) 2;
  return result;
}

unsigned long int pvs_d_a545() {
  unsigned long int result;
  result = (unsigned long) 2;
  return result;
}

int pvs_b546() {
  int result;
  result = (3 + 1);
  return result;
}

int pvs_d_b547() {
  int result;
  result = (3 + 1);
  return result;
}

void pvs_c548(mpz_t result) {
  mpz_set_si(result, (long) (3 * (1 + 2)));
}

void pvs_d_c549(mpz_t result) {
  mpz_set_si(result, (long) (3 * (1 + 2)));
}

int pvs_incr550(int x) {
  int result;
  result = (x + 1);
  return result;
}

int pvs_d_incr551(int x) {
  int result;
  result = (x + 1);
  return result;
}

int pvs_zero552(mpz_t x) {
  int result;
  result = 0;
  return result;
}

int pvs_d_zero553(mpz_t x) {
  int result;
  result = 0;
  return result;
}

int pvs_f554(int a, int b) {
  mpz_t conv557;
  mpz_init(conv557);
  mpz_set_si(conv557, (long) b);
  int result;
  result = (int) (pvs_d_zero553(conv557) * pvs_d_incr551(a));
  mpz_clear(conv557);
  return result;
}

int pvs_d_f555(int a, int b) {
  mpz_t conv557;
  mpz_init(conv557);
  mpz_set_si(conv557, (long) b);
  int result;
  result = (int) (pvs_d_zero553(conv557) * pvs_d_incr551(a));
  mpz_clear(conv557);
  return result;
}

int pvs_f558(int x) {
  int if565;
  if((x <= 1)) {
    int if563;
    if((x == 0)) {
      if563 = 0;
    } else {
      if563 = x;
    }
    if565 = if563;
  } else {
    int if564;
    if((x > 10)) {
      if564 = 10;
    } else {
      if564 = (x + 5);
    }
    if565 = if564;
  }
  int result;
  result = if565;
  return result;
}

int pvs_d_f559(int x) {
  int if565;
  if((x <= 1)) {
    int if563;
    if((x == 0)) {
      if563 = 0;
    } else {
      if563 = x;
    }
    if565 = if563;
  } else {
    int if564;
    if((x > 10)) {
      if564 = 10;
    } else {
      if564 = (x + 5);
    }
    if565 = if564;
  }
  int result;
  result = if565;
  return result;
}

int pvs_t566(int x) {
  int result;
  result = x;
  return result;
}

int pvs_d_t567(int x) {
  int result;
  result = x;
  return result;
}

int* pvs_id568(int* t58582) {
  int* result;
  result = (int*) GC( t58582 );
  return result;
}

int* pvs_d_id569(int* t58582) {
  int* result;
  result = (int*) GC( t58582 );
  return result;
}

int* pvs_f570(int x) {
  int* result;
  result = GC_malloc(1000, sizeof(int));
  int i573;
  for(i573 = 0; i573 < 1000; i573++) {
    result[i573] = pvs_d_t567(i573);
  }
  return result;
}

int* pvs_d_f571(int x) {
  int* result;
  result = GC_malloc(1000, sizeof(int));
  int i573;
  for(i573 = 0; i573 < 1000; i573++) {
    result[i573] = pvs_d_t567(i573);
  }
  return result;
}

int* pvs_update574(int* x) {
  int* result;
  int L583;
  L583 = 0;
  int res584;
  res584 = 0;
  if ( GC_count( x ) == 1 )
    result = x;
  else {
    result = GC_malloc(1000, sizeof(int));
    int i582;
    for(i582 = 0; i582 < 1000; i582++) {
      result[i582] = x[i582];
    }
  }
  result[L583] = res584;
  return result;
}

int* pvs_d_update575(int* x) {
  int* result;
  int L583;
  L583 = 0;
  int res584;
  res584 = 0;
  if ( GC_count( x ) == 1 )
    result = x;
  else {
    result = GC_malloc(1000, sizeof(int));
    int i582;
    for(i582 = 0; i582 < 1000; i582++) {
      result[i582] = x[i582];
    }
  }
  result[L583] = res584;
  return result;
}

int* pvs_t2585(int x) {
  mpq_t* set592;
  set592 = GC_malloc(1000, sizeof(mpq_t));
  int i591;
  for(i591 = 0; i591 < 1000; i591++) {
    mpq_init(set592[i591]);
  }
  int i590;
  for(i590 = 0; i590 < 1000; i590++) {
    mpq_set_d(set592[i590], (double) (x + i590) );
    mpq_canonicalize(set592[i590]);
  }
  int* result;
  result = (int*) GC( set592 );
  GC_free(set592);
  return result;
}

int* pvs_d_t2586(int x) {
  mpq_t* set592;
  set592 = GC_malloc(1000, sizeof(mpq_t));
  int i591;
  for(i591 = 0; i591 < 1000; i591++) {
    mpq_init(set592[i591]);
  }
  int i590;
  for(i590 = 0; i590 < 1000; i590++) {
    mpq_set_d(set592[i590], (double) (x + i590) );
    mpq_canonicalize(set592[i590]);
  }
  int* result;
  result = (int*) GC( set592 );
  GC_free(set592);
  return result;
}

int* pvs_id593(int** t58582) {
  int** a;
  a = (int**) GC( t58582 );
  int* result;
  result = (int*) GC( a[0] );
  int i596;
  for(i596 = 0; i596 < 1000; i596++) {
    GC_free(a[i596]);
  }
  GC_free(a);
  return result;
}

int* pvs_d_id594(int** t58582) {
  int** a;
  a = (int**) GC( t58582 );
  
  int* result;
  result = (int*) GC( a[0] );
  int i596;
  for(i596 = 0; i596 < 1000; i596++) {
    GC_free(a[i596]);
  }
  if ( GC_free(a) == 0 ) free(a);
  return result;
}

int** pvs_update597(int** x) {
  int** result;
  int L622;
  L622 = 1;
  int res623;
  res623 = 0;
  int L620;
  L620 = 0;
  int L625;
  L625 = 1;
  int* res626;
  res626 = GC_malloc(1000, sizeof(int));
  int i627;
  for(i627 = 0; i627 < 1000; i627++) {
    res626[i627] = i627;
  }
  if ( GC_count( x ) == 1 )
    result = x;
  else {
    result = GC_malloc(1000, sizeof(int*));
    int i619;
    for(i619 = 0; i619 < 1000; i619++) {
      result[i619] = (int*) GC( x[i619] );
    }
  }
  int* E621;
  if ( GC_count( result[L620] ) == 1 )
    E621 = result[L620];
  else {
    E621 = GC_malloc(1000, sizeof(int));
    int i624;
    for(i624 = 0; i624 < 1000; i624++) {
      E621[i624] = result[L620][i624];
    }
  }
  E621[L622] = res623;
  result[L625] = (int*) GC( res626 );
  GC_free(res626);
  return result;
}

int** pvs_d_update598(int** x) {
  int** result;
  int L622;
  L622 = 1;
  int res623;
  res623 = 0;
  int L620;
  L620 = 0;
  int L625;
  L625 = 1;
  int* res626;
  res626 = GC_malloc(1000, sizeof(int));
  int i627;
  for(i627 = 0; i627 < 1000; i627++) {
    res626[i627] = i627;
  }
  if ( GC_count( x ) == 1 )
    result = x;
  else {
    result = GC_malloc(1000, sizeof(int*));
    int i619;
    for(i619 = 0; i619 < 1000; i619++) {
      result[i619] = (int*) GC( x[i619] );
    }
  }
  int* E621;
  if ( GC_count( result[L620] ) == 1 )
    E621 = result[L620];
  else {
    E621 = GC_malloc(1000, sizeof(int));
    int i624;
    for(i624 = 0; i624 < 1000; i624++) {
      E621[i624] = result[L620][i624];
    }
  }
  E621[L622] = res623;
  result[L625] = (int*) GC( res626 );
  GC_free(res626);
  return result;
}
