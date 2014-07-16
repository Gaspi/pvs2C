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

struct pair724 {
  mpz_t y;
  int x;
};
typedef (struct pair724)* struct_pair724;


struct_pair724 pvs_a722() {
  struct_pair724 result;
  mpz_init(result->y);
  result->x = 2;
  mpz_set_si(result->y, (long) 12);
  return result;
}

struct_pair724 pvs_d_a723() {
  struct_pair724 result;
  mpz_init(result->y);
  result->x = 2;
  mpz_set_si(result->y, (long) 12);
  return result;
}

int pvs_first725(struct_pair724 a) {
  int result;
  result = a->x;
  return result;
}

int pvs_d_first726(struct_pair724 a) {
  int result;
  result = a->x;
  return result;
}

struct_pair724 pvs_zero727(struct_pair724 a) {
  struct_pair724 result;
  mpz_init(result->y);
  int res730;
  res730 = 0;
  result = GC_malloc(1, sizeof(struct_pair724));
  mpz_set(result->y, a->y);
  result->x = a->x;
  result->x = res730;
  return result;
}

struct_pair724 pvs_d_zero728(struct_pair724 a) {
  struct_pair724 result;
  mpz_init(result->y);
  int res730;
  res730 = 0;
  result = GC_malloc(1, sizeof(struct_pair724));
  mpz_set(result->y, a->y);
  result->x = a->x;
  result->x = res730;
  return result;
}

unsigned long int pvs_a731() {
  unsigned long int result;
  result = (unsigned long) 2;
  return result;
}

unsigned long int pvs_d_a732() {
  unsigned long int result;
  result = (unsigned long) 2;
  return result;
}

int pvs_b733() {
  int result;
  result = (3 + 1);
  return result;
}

int pvs_d_b734() {
  int result;
  result = (3 + 1);
  return result;
}

void pvs_c735(mpz_t result) {
  mpz_set_si(result, (long) (3 * (1 + 2)));
}

void pvs_d_c736(mpz_t result) {
  mpz_set_si(result, (long) (3 * (1 + 2)));
}

int pvs_incr737(int x) {
  int result;
  result = (x + 1);
  return result;
}

int pvs_d_incr738(int x) {
  int result;
  result = (x + 1);
  return result;
}

int pvs_zero739(mpz_t x) {
  int result;
  result = 0;
  return result;
}

int pvs_d_zero740(mpz_t x) {
  int result;
  result = 0;
  return result;
}

int pvs_f741(int a, int b) {
  mpz_t conv744;
  mpz_set_si(conv744, (long) b);
  int result;
  result = (int) (pvs_d_zero740(conv744) * pvs_d_incr738(a));
  mpz_clear(conv744);
  return result;
}

int pvs_d_f742(int a, int b) {
  mpz_t conv744;
  mpz_set_si(conv744, (long) b);
  int result;
  result = (int) (pvs_d_zero740(conv744) * pvs_d_incr738(a));
  mpz_clear(conv744);
  return result;
}

int pvs_f745(int x) {
  int if752;
  Unknown instruction  : if(((x <= 1) && 1)) {
  Unknown instruction  :   int if750;
  Unknown instruction  :   
  Unknown instruction  :   if(((x == 0) || (x < 0))) {
  Unknown instruction  :      = 0;
  Unknown instruction  :   } else {
  Unknown instruction  :      = x;
  Unknown instruction  :   }
  Unknown instruction  :    = if750;
  Unknown instruction  :   
  Unknown instruction  : } else {
  Unknown instruction  :   int if751;
  Unknown instruction  :   
  Unknown instruction  :   if((x > 10)) {
  Unknown instruction  :      = 10;
  Unknown instruction  :   } else {
  Unknown instruction  :      = (x - 5);
  Unknown instruction  :   }
  Unknown instruction  :    = if751;
  Unknown instruction  :   
  Unknown instruction  : }
  int result;
  result = if752;
  return result;
}

int pvs_d_f746(int x) {
  int if752;
  Unknown instruction  : if(((x <= 1) && 1)) {
  Unknown instruction  :   int if750;
  Unknown instruction  :   
  Unknown instruction  :   if(((x == 0) || (x < 0))) {
  Unknown instruction  :      = 0;
  Unknown instruction  :   } else {
  Unknown instruction  :      = x;
  Unknown instruction  :   }
  Unknown instruction  :    = if750;
  Unknown instruction  :   
  Unknown instruction  : } else {
  Unknown instruction  :   int if751;
  Unknown instruction  :   
  Unknown instruction  :   if((x > 10)) {
  Unknown instruction  :      = 10;
  Unknown instruction  :   } else {
  Unknown instruction  :      = (x - 5);
  Unknown instruction  :   }
  Unknown instruction  :    = if751;
  Unknown instruction  :   
  Unknown instruction  : }
  int result;
  result = if752;
  return result;
}

int pvs_t753(int x) {
  int result;
  result = x;
  return result;
}

int pvs_d_t754(int x) {
  int result;
  result = x;
  return result;
}

int* pvs_id2755(int* t57588) {
  int* result;
  result = (int*) GC( t57588 );
  return result;
}

int* pvs_d_id2756(int* t57588) {
  int* result;
  result = (int*) GC( t57588 );
  return result;
}

int* pvs_f757(int x) {
  int* result;
  result = GC_malloc(1000, sizeof(int) );
  int i760;
  for(i760 = 0; i760 < 1000; i760++) {
    result[i760] = pvs_d_t754(i760);
  }
  return result;
}

int* pvs_d_f758(int x) {
  int* result;
  result = GC_malloc(1000, sizeof(int) );
  int i760;
  for(i760 = 0; i760 < 1000; i760++) {
    result[i760] = pvs_d_t754(i760);
  }
  return result;
}

int* pvs_update761(int* x) {
  int* result;
  int L766;
  L766 = 0;
  int res767;
  res767 = 0;
  result = GC_malloc(1000, sizeof(int) );
  int i768;
  for(i768 = 0; i768 < 1000; i768++) {
    result[] = x[];
  }
  result[L766] = res767;
  return result;
}

int* pvs_d_update762(int* x) {
  int* result;
  int L766;
  L766 = 0;
  int res767;
  res767 = 0;
  result = GC_malloc(1000, sizeof(int) );
  int i768;
  for(i768 = 0; i768 < 1000; i768++) {
    result[] = x[];
  }
  result[L766] = res767;
  return result;
}

int* pvs_t2769(int x) {
  mpq_t* set774;
  set774 = GC_malloc(1000, sizeof(mpq_t) );
  int i773;
  for(i773 = 0; i773 < 1000; i773++) {
  mpq_init(set774[i773]);
    mpq_set_d(set774[i773], (double) (x + i773) );
    mpq_canonicalize(set774[i773]);
  }
  int* result;
  result = (int*) GC( set774 );
  GC_free(set774);
  return result;
}

int* pvs_d_t2770(int x) {
  mpq_t* set774;
  set774 = GC_malloc(1000, sizeof(mpq_t) );
  int i773;
  for(i773 = 0; i773 < 1000; i773++) {
  mpq_init(set774[i773]);
    mpq_set_d(set774[i773], (double) (x + i773) );
    mpq_canonicalize(set774[i773]);
  }
  int* result;
  result = (int*) GC( set774 );
  GC_free(set774);
  return result;
}

int* pvs_id775(int** t57588) {
  int** a;
  a = (int**) GC( t57588 );
  int* result;
  result = (int*) GC( a[0] );
  int 1000778;
  for(1000778 = 0; 1000778 < ~a[a]; 1000778++) {
    Unknown instruction  : GC_free(1000778);
  }
  GC_free(a);
  return result;
}

int* pvs_d_id776(int** t57588) {
  int** a;
  a = (int**) GC( t57588 );
  int* result;
  result = (int*) GC( a[0] );
  int 1000778;
  for(1000778 = 0; 1000778 < ~a[a]; 1000778++) {
    Unknown instruction  : GC_free(1000778);
  }
  GC_free(a);
  return result;
}

int* pvs_te779() {
  int* aux784;
  aux784 = GC_malloc(1000, sizeof(int) );
  int i783;
  for(i783 = 0; i783 < 1000; i783++) {
    aux784[i783] = pvs_d_t754(i783);
  }
  int* result;
  result = (int*) GC( pvs_d_update762(pvs_d_update762(aux784)) );
  GC_free(aux784);
  return result;
}

int* pvs_d_te780() {
  int* aux784;
  aux784 = GC_malloc(1000, sizeof(int) );
  int i783;
  for(i783 = 0; i783 < 1000; i783++) {
    aux784[i783] = pvs_d_t754(i783);
  }
  int* result;
  result = (int*) GC( pvs_d_update762(pvs_d_update762(aux784)) );
  GC_free(aux784);
  return result;
}

int** pvs_update785(int** x) {
  int** result;
  int L798;
  L798 = 1;
  int res799;
  res799 = 0;
  int L796;
  L796 = 0;
  int L800;
  L800 = 1;
  int* res801;
  res801 = GC_malloc(1000, sizeof(int) );
  int i802;
  for(i802 = 0; i802 < 1000; i802++) {
    res801[i802] = i802;
  }
  result = GC_malloc(1000, sizeof(int*) );
  int i803;
  for(i803 = 0; i803 < 1000; i803++) {
    result[] = (int*) GC( x[] );
  }
  int* E797;
  E797 = GC_malloc(1000, sizeof(int) );
  int i804;
  for(i804 = 0; i804 < 1000; i804++) {
    E797[] = result[L796][];
  }
  E797[L798] = res799;
  result[L796] = (int*) GC( E797 );
  result[L800] = (int*) GC( res801 );
  GC_free(res801);
  return result;
}

int** pvs_d_update786(int** x) {
  int** result;
  int L798;
  L798 = 1;
  int res799;
  res799 = 0;
  int L796;
  L796 = 0;
  int L800;
  L800 = 1;
  int* res801;
  res801 = GC_malloc(1000, sizeof(int) );
  int i802;
  for(i802 = 0; i802 < 1000; i802++) {
    res801[i802] = i802;
  }
  result = GC_malloc(1000, sizeof(int*) );
  int i803;
  for(i803 = 0; i803 < 1000; i803++) {
    result[] = (int*) GC( x[] );
  }
  int* E797;
  E797 = GC_malloc(1000, sizeof(int) );
  int i804;
  for(i804 = 0; i804 < 1000; i804++) {
    E797[] = result[L796][];
  }
  E797[L798] = res799;
  result[L796] = (int*) GC( E797 );
  result[L800] = (int*) GC( res801 );
  GC_free(res801);
  return result;
}