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
struct pair892 {
  mpz_t y;
  int x;
};


struct pair892 pvs_a890() {
  struct pair892 result;
  mpz_init(result.y);
  result.x = 2;
  mpz_set_si(result.y, (long) 12);
  return result;
}

struct pair892 pvs_d_a891() {
  struct pair892 result;
  mpz_init(result.y);
  result.x = 2;
  mpz_set_si(result.y, (long) 12);
  return result;
}

int pvs_first893(struct pair892 a) {
  int result;
  result = a.x;
  return result;
}

int pvs_d_first894(struct pair892 a) {
  int result;
  result = a.x;
  return result;
}

struct pair892 pvs_zero895(struct pair892 a) {
  struct pair892 result;
  mpz_init(result.y);
  int res899;
  res899 = 0;
  mpz_set(result.y, a.y);
  result.x = a.x;
  result.x = res899;
  return result;
}

struct pair892 pvs_d_zero896(struct pair892 a) {
  struct pair892 result;
  mpz_init(result.y);
  int res899;
  res899 = 0;
  mpz_set(result.y, a.y);
  result.x = a.x;
  result.x = res899;
  return result;
}

unsigned long int pvs_a900() {
  unsigned long int result;
  result = (unsigned long) 2;
  return result;
}

unsigned long int pvs_d_a901() {
  unsigned long int result;
  result = (unsigned long) 2;
  return result;
}

int pvs_b902() {
  int result;
  result = (3 + 1);
  return result;
}

int pvs_d_b903() {
  int result;
  result = (3 + 1);
  return result;
}

void pvs_c904(mpz_t result) {
  mpz_set_si(result, (long) (3 * (1 + 2)));
}

void pvs_d_c905(mpz_t result) {
  mpz_set_si(result, (long) (3 * (1 + 2)));
}

int pvs_incr906(int x) {
  int result;
  result = (x + 1);
  return result;
}

int pvs_d_incr907(int x) {
  int result;
  result = (x + 1);
  return result;
}

int pvs_zero908(mpz_t x) {
  int result;
  result = 0;
  return result;
}

int pvs_d_zero909(mpz_t x) {
  int result;
  result = 0;
  return result;
}

int pvs_f910(int a, int b) {
  mpz_t conv913;
  mpz_init(conv913);
  mpz_set_si(conv913, (long) b);
  int result;
  result = (int) (pvs_d_zero909(conv913) * pvs_d_incr907(a));
  mpz_clear(conv913);
  return result;
}

int pvs_d_f911(int a, int b) {
  mpz_t conv913;
  mpz_init(conv913);
  mpz_set_si(conv913, (long) b);
  int result;
  result = (int) (pvs_d_zero909(conv913) * pvs_d_incr907(a));
  mpz_clear(conv913);
  return result;
}

int pvs_f914(int x) {
  int if921;
  if((x <= 1)) {
    int if919;
    if((x == 0)) {
      if919 = 0;
    } else {
      if919 = x;
    }
    if921 = if919;
  } else {
    int if920;
    if((x > 10)) {
      if920 = 10;
    } else {
      if920 = (x + 5);
    }
    if921 = if920;
  }
  int result;
  result = if921;
  return result;
}

int pvs_d_f915(int x) {
  int if921;
  if((x <= 1)) {
    int if919;
    if((x == 0)) {
      if919 = 0;
    } else {
      if919 = x;
    }
    if921 = if919;
  } else {
    int if920;
    if((x > 10)) {
      if920 = 10;
    } else {
      if920 = (x + 5);
    }
    if921 = if920;
  }
  int result;
  result = if921;
  return result;
}

int pvs_t922(int x) {
  int result;
  result = x;
  return result;
}

int pvs_d_t923(int x) {
  int result;
  result = x;
  return result;
}

int* pvs_id924(int* t55793) {
  int* result;
  result = (int*) GC( t55793 );
  return result;
}

int* pvs_d_id925(int* t55793) {
  int* result;
  result = (int*) GC( t55793 );
  return result;
}

int* pvs_f926(int x) {
  int* result;
  result = GC_malloc(1000, sizeof(int));
  int i929;
  for(i929 = 0; i929 < 1000; i929++) {
    result[i929] = pvs_d_t923(i929);
  }
  return result;
}

int* pvs_d_f927(int x) {
  int* result;
  result = GC_malloc(1000, sizeof(int));
  int i929;
  for(i929 = 0; i929 < 1000; i929++) {
    result[i929] = pvs_d_t923(i929);
  }
  return result;
}

int* pvs_update930(int* x) {
  int* result;
  int L939;
  L939 = 0;
  int res940;
  res940 = 0;
  if ( GC_count( x ) == 1 )
    result = x;
  else {
    result = GC_malloc(1000, sizeof(int));
    int i938;
    for(i938 = 0; i938 < 1000; i938++) {
      result[i938] = x[i938];
    }
  }
  result[L939] = res940;
  return result;
}

int* pvs_d_update931(int* x) {
  int* result;
  int L939;
  L939 = 0;
  int res940;
  res940 = 0;
  if ( GC_count( x ) == 1 )
    result = x;
  else {
    result = GC_malloc(1000, sizeof(int));
    int i938;
    for(i938 = 0; i938 < 1000; i938++) {
      result[i938] = x[i938];
    }
  }
  result[L939] = res940;
  return result;
}

int* pvs_t2941(int x) {
  mpq_t* set948;
  set948 = GC_malloc(1000, sizeof(mpq_t));
  int i947;
  for(i947 = 0; i947 < 1000; i947++) {
    mpq_init(set948[i947]);
  }
  int i946;
  for(i946 = 0; i946 < 1000; i946++) {
    mpq_set_d(set948[i946], (double) (x + i946) );
    mpq_canonicalize(set948[i946]);
  }
  int* result;
  result = (int*) GC( set948 );
  GC_free(set948);
  return result;
}

int* pvs_d_t2942(int x) {
  mpq_t* set948;
  set948 = GC_malloc(1000, sizeof(mpq_t));
  int i947;
  for(i947 = 0; i947 < 1000; i947++) {
    mpq_init(set948[i947]);
  }
  int i946;
  for(i946 = 0; i946 < 1000; i946++) {
    mpq_set_d(set948[i946], (double) (x + i946) );
    mpq_canonicalize(set948[i946]);
  }
  int* result;
  result = (int*) GC( set948 );
  GC_free(set948);
  return result;
}

int* pvs_id949(int** t55793) {
  int** a;
  a = (int**) GC( t55793 );
  int* result;
  result = (int*) GC( a[0] );
  int i952;
  for(i952 = 0; i952 < 1000; i952++) {
    GC_free(a[i952]);
  }
  GC_free(a);
  return result;
}

int* pvs_d_id950(int** t55793) {
  int** a;
  a = (int**) GC( t55793 );
  int* result;
  result = (int*) GC( a[0] );
  int i952;
  for(i952 = 0; i952 < 1000; i952++) {
    GC_free(a[i952]);
  }
  GC_free(a);
  return result;
}

int** pvs_update953(int** x) {
  int** result;
  int L978;
  L978 = 1;
  int res979;
  res979 = 0;
  int L976;
  L976 = 0;
  int L981;
  L981 = 1;
  int* res982;
  res982 = GC_malloc(1000, sizeof(int));
  int i983;
  for(i983 = 0; i983 < 1000; i983++) {
    res982[i983] = i983;
  }
  if ( GC_count( x ) == 1 )
    result = x;
  else {
    result = GC_malloc(1000, sizeof(int*));
    int i975;
    for(i975 = 0; i975 < 1000; i975++) {
      result[i975] = (int*) GC( x[i975] );
    }
  }
  int* E977;
  if ( GC_count( result[L976] ) == 1 )
    E977 = result[L976];
  else {
    E977 = GC_malloc(1000, sizeof(int));
    int i980;
    for(i980 = 0; i980 < 1000; i980++) {
      E977[i980] = result[L976][i980];
    }
  }
  E977[L978] = res979;
  result[L981] = (int*) GC( res982 );
  GC_free(res982);
  return result;
}

int** pvs_d_update954(int** x) {
  int** result;
  int L978;
  L978 = 1;
  int res979;
  res979 = 0;
  int L976;
  L976 = 0;
  int L981;
  L981 = 1;
  int* res982;
  res982 = GC_malloc(1000, sizeof(int));
  int i983;
  for(i983 = 0; i983 < 1000; i983++) {
    res982[i983] = i983;
  }
  if ( GC_count( x ) == 1 )
    result = x;
  else {
    result = GC_malloc(1000, sizeof(int*));
    int i975;
    for(i975 = 0; i975 < 1000; i975++) {
      result[i975] = (int*) GC( x[i975] );
    }
  }
  int* E977;
  if ( GC_count( result[L976] ) == 1 )
    E977 = result[L976];
  else {
    E977 = GC_malloc(1000, sizeof(int));
    int i980;
    for(i980 = 0; i980 < 1000; i980++) {
      E977[i980] = result[L976][i980];
    }
  }
  E977[L978] = res979;
  result[L981] = (int*) GC( res982 );
  GC_free(res982);
  return result;
}