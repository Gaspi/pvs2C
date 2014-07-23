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

struct struct_pair413 {
  mpz_t y;
  int x;
};
typedef (struct struct_pair413)* pair413;


pair413 pvs_a411() {
  !pair413 #result#;
  #result# = GC_malloc(1, sizeof( struct_pair413 ) );
  mpz_init(#result#->y);
  #result#->x = 2;
  mpz_set_si(#result#->y, (long) 12);
  return *#result#*;
}

pair413 pvs_a_d412() {
  !pair413 #result#;
  #result# = GC_malloc(1, sizeof( struct_pair413 ) );
  mpz_init(#result#->y);
  #result#->x = 2;
  mpz_set_si(#result#->y, (long) 12);
  return *#result#*;
}

int pvs_first414(pair413 a) {
  int result;
  result = *a*->x;
  return result;
}

int pvs_first_d415(pair413 a) {
  int result;
  result = *a*->x;
  return result;
}

pair413 pvs_zero416(pair413 a) {
  !pair413 #result#;
  int res418;
  res418 = 0;
  if ( GC_count( *a* ) == 1 )
    #result# = GC( *a* );
  else {
    #result# = GC_malloc(1, sizeof(pair413));
    mpz_set(#result#->y, *a*->y);
    #result#->x = *a*->x;
  }
  #result#->x = res418;
  return *#result#*;
}

pair413 pvs_zero_d417(!pair413 #a#) {
  int res419;
  res419 = 0;
  #a#->x = res419;
  return *#a#*;
}

unsigned long int pvs_a420() {
  unsigned long int result;
  result = (unsigned long) 2;
  return result;
}

unsigned long int pvs_a_d421() {
  unsigned long int result;
  result = (unsigned long) 2;
  return result;
}

int pvs_b422() {
  int result;
  result = (3 + 1);
  return result;
}

int pvs_b_d423() {
  int result;
  result = (3 + 1);
  return result;
}

void pvs_c424(mpz_t result) {
  mpz_set_si(result, (long) (3 * (1 + 2)));
}

void pvs_c_d425(mpz_t result) {
  mpz_set_si(result, (long) (3 * (1 + 2)));
}

int pvs_incr426(int x) {
  int result;
  result = (x + 1);
  return result;
}

int pvs_incr_d427(int x) {
  int result;
  result = (x + 1);
  return result;
}

int pvs_zero428(mpz_t x) {
  int result;
  result = 0;
  return result;
}

int pvs_zero_d429(mpz_t x) {
  int result;
  result = 0;
  return result;
}

int pvs_f430(int a, int b) {
  mpz_t conv432;
  mpz_set_si(conv432, (long) b);
  int result;
  result = (int) (pvs_zero428(conv432) * pvs_incr426(a));
  mpz_clear(conv432);
  return result;
}

int pvs_f_d431(int a, int b) {
  mpz_t conv433;
  mpz_set_si(conv433, (long) b);
  int result;
  result = (int) (pvs_zero428(conv433) * pvs_incr426(a));
  mpz_clear(conv433);
  return result;
}

int pvs_f434(int x) {
  int if438;
  if (((x <= 1) && 1)) {
    int if436;
    if (((x == 0) || (x < 0))) {
      if436 = 0;
    } else {
      if436 = x;
    }
    if438 = if436;
  } else {
    int if437;
    if ((x > 10)) {
      if437 = 10;
    } else {
      if437 = (x - 5);
    }
    if438 = if437;
  }
  int result;
  result = if438;
  return result;
}

int pvs_f_d435(int x) {
  int if441;
  if (((x <= 1) && 1)) {
    int if439;
    if (((x == 0) || (x < 0))) {
      if439 = 0;
    } else {
      if439 = x;
    }
    if441 = if439;
  } else {
    int if440;
    if ((x > 10)) {
      if440 = 10;
    } else {
      if440 = (x - 5);
    }
    if441 = if440;
  }
  int result;
  result = if441;
  return result;
}

int pvs_t442(int x) {
  int result;
  result = x;
  return result;
}

int pvs_t_d443(int x) {
  int result;
  result = x;
  return result;
}

int* pvs_id2444(int* #t59703#) {
  return *#t59703#*;
}

int* pvs_id2_d445(!int* #t59703#) {
  return *#t59703#*;
}

int* pvs_f446(int x) {
  !int* #result#;
  #result# = GC_malloc(1000, sizeof(int) );
  int i448;
  for(i448 = 0; i448 < 1000; i448++) {
    #result#[i448] = pvs_t442(i448);
  }
  return *#result#*;
}

int* pvs_f_d447(int x) {
  !int* #result#;
  #result# = GC_malloc(1000, sizeof(int) );
  int i449;
  for(i449 = 0; i449 < 1000; i449++) {
    #result#[i449] = pvs_t442(i449);
  }
  return *#result#*;
}

int* pvs_update450(int* x) {
  !int* #result#;
  int L452;
  L452 = 0;
  int res453;
  res453 = 0;
  if ( GC_count( *x* ) == 1 )
    #result# = GC( *x* );
  else {
    #result# = GC_malloc(1000, sizeof(int) );
    int i486;
    for(i486 = 0; i486 < 1000; i486++) {
      #result#[i486] = *x*[i486];
    }
  }
  #result#[L452] = res453;
  return *#result#*;
}

int* pvs_update_d451(!int* #x#) {
  int L454;
  L454 = 0;
  int res455;
  res455 = 0;
  #x#[L454] = res455;
  return *#x#*;
}

int* pvs_t2456(int x) {
  !mpq_t* #set459#;
  #set459# = GC_malloc(1000, sizeof(mpq_t) );
  int i458;
  for(i458 = 0; i458 < 1000; i458++) {
    mpq_init(#set459#[i458]);
    mpq_set_d(#set459#[i458], (double) (x + i458) );
    mpq_canonicalize(#set459#[i458]);
  }
  return *#set459#*;
}

int* pvs_t2_d457(int x) {
  !mpq_t* #set461#;
  #set461# = GC_malloc(1000, sizeof(mpq_t) );
  int i460;
  for(i460 = 0; i460 < 1000; i460++) {
    mpq_init(#set461#[i460]);
    mpq_set_d(#set461#[i460], (double) (x + i460) );
    mpq_canonicalize(#set461#[i460]);
  }
  return *#set461#*;
}

int* pvs_id462(int** #t59703#) {
  int* #result#;
  #result# = (int*) GC( *#t59703#*[0] );
  if( GC_count( #t59703# ) == 1 ) {
    int i487;
    for(i487 = 0; i487 < 1000; i487++) {
      GC_free(#t59703#[i487]);
    }
  }
  GC_free(#t59703#);
  return *#result#*;
}

int* pvs_id_d463(int** #t59703#) {
  int* #result#;
  #result# = (int*) GC( *#t59703#*[0] );
  if( GC_count( #t59703# ) == 1 ) {
    int i489;
    for(i489 = 0; i489 < 1000; i489++) {
      GC_free(#t59703#[i489]);
    }
  }
  GC_free(#t59703#);
  return *#result#*;
}

int* pvs_te464() {
  !int* aux467;
  aux467 = GC_malloc(1000, sizeof(int) );
  int i466;
  for(i466 = 0; i466 < 1000; i466++) {
    aux467[i466] = pvs_t442(i466);
  }
  int* #result#;
  #result# = (int*) GC( pvs_update450(pvs_update450(*aux467*)) );
  GC_free(aux467);
  return *#result#*;
}

int* pvs_te_d465() {
  !int* aux469;
  aux469 = GC_malloc(1000, sizeof(int) );
  int i468;
  for(i468 = 0; i468 < 1000; i468++) {
    aux469[i468] = pvs_t442(i468);
  }
  int* #result#;
  #result# = (int*) GC( pvs_update450(pvs_update450(*aux469*)) );
  GC_free(aux469);
  return *#result#*;
}

int** pvs_update470(int** x) {
  !int** #result#;
  int L474;
  L474 = 1;
  int res475;
  res475 = 0;
  int L472;
  L472 = 0;
  int L476;
  L476 = 1;
  !int* #res477#;
  #res477# = GC_malloc(1000, sizeof(int) );
  int i478;
  for(i478 = 0; i478 < 1000; i478++) {
    #res477#[i478] = i478;
  }
  if ( GC_count( *x* ) == 1 )
    #result# = GC( *x* );
  else {
    #result# = GC_malloc(1000, sizeof(int*) );
    int i493;
    for(i493 = 0; i493 < 1000; i493++) {
      if ( GC_count( *x*[i493] ) == 1 )
        #result#[i493] = GC( *x*[i493] );
      else {
        #result#[i493] = GC_malloc(1000, sizeof(int) );
        int i494;
        for(i494 = 0; i494 < 1000; i494++) {
          #result#[i493][i494] = *x*[i493][i494];
        }
      }
    }
  }
  !int* #E473#;
  #E473# = GC_malloc(1000, sizeof(int) );
  int i495;
  for(i495 = 0; i495 < 1000; i495++) {
    #E473#[i495] = #result#[L472][i495];
  }
  #E473#[L474] = res475;
  #result#[L472] = (int*) GC( *#E473#* );
  #result#[L476] = (int*) GC( *#res477#* );
  GC_free(#res477#);
  return *#result#*;
}

int** pvs_update_d471(!int** #x#) {
  int L481;
  L481 = 1;
  int res482;
  res482 = 0;
  int L479;
  L479 = 0;
  int L483;
  L483 = 1;
  !int* #res484#;
  #res484# = GC_malloc(1000, sizeof(int) );
  int i485;
  for(i485 = 0; i485 < 1000; i485++) {
    #res484#[i485] = i485;
  }
  !int* #E480#;
  #E480# = GC_malloc(1000, sizeof(int) );
  int i497;
  for(i497 = 0; i497 < 1000; i497++) {
    #E480#[i497] = #x#[L479][i497];
  }
  #E480#[L481] = res482;
  #x#[L479] = (int*) GC( *#E480#* );
  #x#[L483] = (int*) GC( *#res484#* );
  GC_free(#res484#);
  return *#x#*;
}