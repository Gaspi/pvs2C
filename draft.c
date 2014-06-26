// ---------------------------------------------
//        C file generated from draft.pvs
// ---------------------------------------------
//   Make sure to link GMP in compilation:
//      gcc -o draft draft.c -lgmp
//      ./draft
// ---------------------------------------------

#include<stdio.h>
#include<gmp.h>
#include "draft.h"

#define TRUE 1
#define FALSE 0

int main(void) {
  printf("Executing draft ...\n");
  return 0;
}


unsigned long int pvs_a792() {
  unsigned long int result;
  result = (unsigned long) 2;
  return result;
}

unsigned long int pvs_d_a793() {
  unsigned long int result;
  result = (unsigned long) 2;
  return result;
}

int pvs_b794() {
  int result;
  result = (3 + 1);
  return result;
}

int pvs_d_b795() {
  int result;
  result = (3 + 1);
  return result;
}

void pvs_c796(mpz_t result) {
  mpz_set_si(result, (long) (3 * (1 + 2)));
}

void pvs_d_c797(mpz_t result) {
  mpz_set_si(result, (long) (3 * (1 + 2)));
}

int pvs_incr798(int x) {
  int result;
  result = (x + 1);
  return result;
}

int pvs_d_incr799(int x) {
  int result;
  result = (x + 1);
  return result;
}

int pvs_zero800(mpz_t x) {
  int result;
  result = 0;
  return result;
}

int pvs_d_zero801(mpz_t x) {
  int result;
  result = 0;
  return result;
}

int pvs_f802(int a, int b) {
  mpz_t conv805;
  mpz_init(conv805);
  mpz_set_si(conv805, (long) b);
  int result;
  result = (int) (pvs_d_zero801(conv805) * pvs_d_incr799(a));
  mpz_clear(conv805);
  return result;
}

int pvs_d_f803(int a, int b) {
  mpz_t conv805;
  mpz_init(conv805);
  mpz_set_si(conv805, (long) b);
  int result;
  result = (int) (pvs_d_zero801(conv805) * pvs_d_incr799(a));
  mpz_clear(conv805);
  return result;
}

int pvs_f806(int x) {
  int if813;
  if((x <= 1)) {
    int if811;
    if(x == 0)) {
      if811 = 0;
    } else {
      if811 = x;
    }
    if813 = if811;
  } else {
    int if812;
    if((x > 10)) {
      if812 = 10;
    } else {
      if812 = (x + 5);
    }
    if813 = if812;
  }
  int result;
  result = if813;
  return result;
}

int pvs_d_f807(int x) {
  int if813;
  if((x <= 1)) {
    int if811;
    if(x == 0)) {
      if811 = 0;
    } else {
      if811 = x;
    }
    if813 = if811;
  } else {
    int if812;
    if((x > 10)) {
      if812 = 10;
    } else {
      if812 = (x + 5);
    }
    if813 = if812;
  }
  int result;
  result = if813;
  return result;
}

int pvs_t814(int x) {
  int result;
  result = x;
  return result;
}

int pvs_d_t815(int x) {
  int result;
  result = x;
  return result;
}

int* pvs_f816(int x) {
  int* result;
  result = GC_malloc( 1000 * sizeof(int) );
  for(int i819 = 0; i819 < 1000; i819++) {
    result[i819] = pvs_d_t815(i819);
  }
  return result;
}

int* pvs_d_f817(int x) {
  int* result;
  result = GC_malloc( 1000 * sizeof(int) );
  for(int i819 = 0; i819 < 1000; i819++) {
    result[i819] = pvs_d_t815(i819);
  }
  return result;
}

int* pvs_update820(int* x) {
  int* result;
  int L829;
  L829 = 0;
  int res830;
  res830 = 0;
  if ( GC_count( x ) == 1 )
    result = x;
  else {
    result = GC_malloc( 1000 * sizeof(int) );
    for(int i828 = 0; i828 < 1000; i828++)
      result[i828] = x[i828];
    }
  }
  result[L829] = res830;
  return result;
}

int* pvs_d_update821(int* x) {
  int* result;
  int L829;
  L829 = 0;
  int res830;
  res830 = 0;
  if ( GC_count( x ) == 1 )
    result = x;
  else {
    result = GC_malloc( 1000 * sizeof(int) );
    for(int i828 = 0; i828 < 1000; i828++)
      result[i828] = x[i828];
    }
  }
  result[L829] = res830;
  return result;
}

int* pvs_t2831(int x) {
  mpq_t* set838;
  set838 = GC_malloc( 1000 * sizeof(mpq_t) );
  for(int i837 = 0; i837 < 1000; i837++) {
    mpq_init(set838[i837]);
  }
  for(int i836 = 0; i836 < 1000; i836++) {
    set838[i836] = (x + i836);
  }
  int* result;
  result = (int*) GC( set838 );
  GC_free(set838);
  return result;
}

int* pvs_d_t2832(int x) {
  mpq_t* set838;
  set838 = GC_malloc( 1000 * sizeof(mpq_t) );
  for(int i837 = 0; i837 < 1000; i837++) {
    mpq_init(set838[i837]);
  }
  for(int i836 = 0; i836 < 1000; i836++) {
    set838[i836] = (x + i836);
  }
  int* result;
  result = (int*) GC( set838 );
  GC_free(set838);
  return result;
}

int** pvs_update839(int** x) {
  int** result;
  int L864;
  L864 = 1;
  int res865;
  res865 = 0;
  int L862;
  L862 = 0;
  int L867;
  L867 = 1;
  int* res868;
  res868 = GC_malloc( 1000 * sizeof(int) );
  for(int i869 = 0; i869 < 1000; i869++) {
    res868[i869] = i869;
  }
  if ( GC_count( x ) == 1 )
    result = x;
  else {
    result = GC_malloc( 1000 * sizeof(int*) );
    for(int i861 = 0; i861 < 1000; i861++)
      result[i861] = (int*) GC( x[i861] );
    }
  }
  int* E863;
  if ( GC_count( result[L862] ) == 1 )
    E863 = result[L862];
  else {
    E863 = GC_malloc( 1000 * sizeof(int*) );
    for(int i866 = 0; i866 < 1000; i866++)
      E863[i866] = (int*) GC( result[L862][i866] );
    }
  }
  E863[L864] = res865;
  result[L867] = (int*) GC( res868 );
  GC_free(res868);
  return result;
}

int** pvs_d_update840(int** x) {
  int** result;
  int L864;
  L864 = 1;
  int res865;
  res865 = 0;
  int L862;
  L862 = 0;
  int L867;
  L867 = 1;
  int* res868;
  res868 = GC_malloc( 1000 * sizeof(int) );
  for(int i869 = 0; i869 < 1000; i869++) {
    res868[i869] = i869;
  }
  if ( GC_count( x ) == 1 )
    result = x;
  else {
    result = GC_malloc( 1000 * sizeof(int*) );
    for(int i861 = 0; i861 < 1000; i861++)
      result[i861] = (int*) GC( x[i861] );
    }
  }
  int* E863;
  if ( GC_count( result[L862] ) == 1 )
    E863 = result[L862];
  else {
    E863 = GC_malloc( 1000 * sizeof(int*) );
    for(int i866 = 0; i866 < 1000; i866++)
      E863[i866] = (int*) GC( result[L862][i866] );
    }
  }
  E863[L864] = res865;
  result[L867] = (int*) GC( res868 );
  GC_free(res868);
  return result;
}