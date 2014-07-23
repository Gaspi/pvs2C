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

struct struct_pair668 {
  mpz_t y;
  int x;
};
typedef (struct struct_pair668)* pair668;


!pair668 pvs_a666() {
  !pair668 result;
  result = GC_malloc(1, sizeof( struct_pair668 ) );
  mpz_init(result->y);
  result->x = 2;
  mpz_set_si(result->y, (long) 12);
  return *result*;
}

!pair668 pvs_a_d667() {
  !pair668 result;
  result = GC_malloc(1, sizeof( struct_pair668 ) );
  mpz_init(result->y);
  result->x = 2;
  mpz_set_si(result->y, (long) 12);
  return *result*;
}

int pvs_first669(pair668 a) {
  int result;
  result = *a*->x;
  return result;
}

int pvs_first_d670(!pair668 a) {
  int result;
  result = *a*->x;
  return result;
}

!pair668 pvs_zero671(pair668 a) {
  !pair668 result;
  int res673;
  res673 = 0;
  if ( GC_count( *a* ) == 1 )
    result = GC( *a* );
  else {
    result = GC_malloc(1, sizeof(pair668));
    mpz_set(result->y, *a*->y);
    result->x = *a*->x;
  }
  result->x = res673;
  return *result*;
}

!pair668 pvs_zero_d672(!pair668 a) {
  int res674;
  res674 = 0;
  a->x = res674;
  return *a*;
}

unsigned long int pvs_a675() {
  unsigned long int result;
  result = (unsigned long) 2;
  return result;
}

unsigned long int pvs_a_d676() {
  unsigned long int result;
  result = (unsigned long) 2;
  return result;
}

int pvs_b677() {
  int result;
  result = (3 + 1);
  return result;
}

int pvs_b_d678() {
  int result;
  result = (3 + 1);
  return result;
}

void pvs_c679() {
  mpz_set_si(result, (long) (3 * (1 + 2)));
}

void pvs_c_d680() {
  mpz_set_si(result, (long) (3 * (1 + 2)));
}

int pvs_incr681(int x) {
  int result;
  result = (x + 1);
  return result;
}

int pvs_incr_d682(int x) {
  int result;
  result = (x + 1);
  return result;
}

int pvs_zero683(mpz_t x) {
  int result;
  result = 0;
  return result;
}

int pvs_zero_d684(mpz_t x) {
  int result;
  result = 0;
  return result;
}

int pvs_f685(int a, int b) {
  mpz_t conv687;
  mpz_set_si(conv687, (long) b);
  int result;
  result = (int) (pvs_zero683(conv687) * pvs_incr681(a));
  mpz_clear(conv687);
  return result;
}

int pvs_f_d686(int a, int b) {
  mpz_t conv688;
  mpz_set_si(conv688, (long) b);
  int result;
  result = (int) (pvs_zero683(conv688) * pvs_incr681(a));
  mpz_clear(conv688);
  return result;
}

int pvs_f689(int x) {
  int if693;
  if (((x <= 1) && 1)) {
    int if691;
    if (((x == 0) || (x < 0))) {
      if691 = 0;
    } else {
      if691 = x;
    }
    if693 = if691;
  } else {
    int if692;
    if ((x > 10)) {
      if692 = 10;
    } else {
      if692 = (x - 5);
    }
    if693 = if692;
  }
  int result;
  result = if693;
  return result;
}

int pvs_f_d690(int x) {
  int if696;
  if (((x <= 1) && 1)) {
    int if694;
    if (((x == 0) || (x < 0))) {
      if694 = 0;
    } else {
      if694 = x;
    }
    if696 = if694;
  } else {
    int if695;
    if ((x > 10)) {
      if695 = 10;
    } else {
      if695 = (x - 5);
    }
    if696 = if695;
  }
  int result;
  result = if696;
  return result;
}

int pvs_t697(int x) {
  int result;
  result = x;
  return result;
}

int pvs_t_d698(int x) {
  int result;
  result = x;
  return result;
}

int* pvs_id2699(int* t56904) {
  return *t56904*;
}

!int* pvs_id2_d700(!int* t56904) {
  return *t56904*;
}

!int* pvs_f701(int x) {
  !int* result;
  result = GC_malloc(1000, sizeof(int) );
  int i703;
  for(i703 = 0; i703 < 1000; i703++) {
    result[i703] = pvs_t697(i703);
  }
  return *result*;
}

!int* pvs_f_d702(int x) {
  !int* result;
  result = GC_malloc(1000, sizeof(int) );
  int i704;
  for(i704 = 0; i704 < 1000; i704++) {
    result[i704] = pvs_t697(i704);
  }
  return *result*;
}

!int* pvs_update705(int* x) {
  !int* result;
  int L707;
  L707 = 0;
  int res708;
  res708 = 0;
  if ( GC_count( *x* ) == 1 )
    result = GC( *x* );
  else {
    result = GC_malloc(1000, sizeof(int) );
    int i741;
    for(i741 = 0; i741 < 1000; i741++) {
      result[i741] = *x*[i741];
    }
  }
  result[L707] = res708;
  return *result*;
}

!int* pvs_update_d706(!int* x) {
  int L709;
  L709 = 0;
  int res710;
  res710 = 0;
  x[L709] = res710;
  return *x*;
}

!int* pvs_t2711(int x) {
  !mpq_t* set714;
  set714 = GC_malloc(1000, sizeof(mpq_t) );
  int i713;
  for(i713 = 0; i713 < 1000; i713++) {
    mpq_init(set714[i713]);
    mpq_set_d(set714[i713], (double) (x + i713) );
    mpq_canonicalize(set714[i713]);
  }
  return *set714*;
}

!int* pvs_t2_d712(int x) {
  !mpq_t* set716;
  set716 = GC_malloc(1000, sizeof(mpq_t) );
  int i715;
  for(i715 = 0; i715 < 1000; i715++) {
    mpq_init(set716[i715]);
    mpq_set_d(set716[i715], (double) (x + i715) );
    mpq_canonicalize(set716[i715]);
  }
  return *set716*;
}

int* pvs_id717(int** t56904) {
  int* result;
  result = (int*) GC( *t56904*[0] );
  if( GC_count( t56904 ) == 1 ) {
    int i742;
    for(i742 = 0; i742 < 1000; i742++) {
      GC_free(t56904[i742]);
    }
  }
  GC_free(t56904);
  return *result*;
}

int* pvs_id_d718(!int** t56904) {
  int* result;
  result = (int*) GC( *t56904*[0] );
  if( GC_count( t56904 ) == 1 ) {
    int i744;
    for(i744 = 0; i744 < 1000; i744++) {
      GC_free(t56904[i744]);
    }
  }
  GC_free(t56904);
  return *result*;
}

int* pvs_te719() {
  !int* aux722;
  aux722 = GC_malloc(1000, sizeof(int) );
  int i721;
  for(i721 = 0; i721 < 1000; i721++) {
    aux722[i721] = pvs_t697(i721);
  }
  int* result;
  result = (int*) GC( pvs_update705(pvs_update705(*aux722*)) );
  GC_free(aux722);
  return *result*;
}

int* pvs_te_d720() {
  !int* aux724;
  aux724 = GC_malloc(1000, sizeof(int) );
  int i723;
  for(i723 = 0; i723 < 1000; i723++) {
    aux724[i723] = pvs_t697(i723);
  }
  int* result;
  result = (int*) GC( pvs_update705(pvs_update705(*aux724*)) );
  GC_free(aux724);
  return *result*;
}

!int** pvs_update725(int** x) {
  !int** result;
  int L729;
  L729 = 1;
  int res730;
  res730 = 0;
  int L727;
  L727 = 0;
  int L731;
  L731 = 1;
  !int* res732;
  res732 = GC_malloc(1000, sizeof(int) );
  int i733;
  for(i733 = 0; i733 < 1000; i733++) {
    res732[i733] = i733;
  }
  if ( GC_count( *x* ) == 1 )
    result = GC( *x* );
  else {
    result = GC_malloc(1000, sizeof(int*) );
    int i748;
    for(i748 = 0; i748 < 1000; i748++) {
      if ( GC_count( *x*[i748] ) == 1 )
        result[i748] = GC( *x*[i748] );
      else {
        result[i748] = GC_malloc(1000, sizeof(int) );
        int i749;
        for(i749 = 0; i749 < 1000; i749++) {
          result[i748][i749] = *x*[i748][i749];
        }
      }
    }
  }
  !int* E728;
  E728 = GC_malloc(1000, sizeof(int) );
  int i750;
  for(i750 = 0; i750 < 1000; i750++) {
    E728[i750] = result[L727][i750];
  }
  E728[L729] = res730;
  result[L727] = (int*) GC( *E728* );
  result[L731] = (int*) GC( *res732* );
  GC_free(res732);
  return *result*;
}

!int** pvs_update_d726(!int** x) {
  int L736;
  L736 = 1;
  int res737;
  res737 = 0;
  int L734;
  L734 = 0;
  int L738;
  L738 = 1;
  !int* res739;
  res739 = GC_malloc(1000, sizeof(int) );
  int i740;
  for(i740 = 0; i740 < 1000; i740++) {
    res739[i740] = i740;
  }
  !int* E735;
  E735 = GC_malloc(1000, sizeof(int) );
  int i752;
  for(i752 = 0; i752 < 1000; i752++) {
    E735[i752] = x[L734][i752];
  }
  E735[L736] = res737;
  x[L734] = (int*) GC( *E735* );
  x[L738] = (int*) GC( *res739* );
  GC_free(res739);
  return *x*;
}