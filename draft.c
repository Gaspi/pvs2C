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
  GC.start();
  printf("Executing draft ...\n");
  // Insert code here
  GC.quit();
  return 0;
}


!pair841 pvs_a839() {
  !pair841 #result#;
  #result# = GC_malloc(1, sizeof( struct struct_pair841 ) );
  mpz_init(#result#->y);
  #result#->x = *2*;
  mpz_set_si(#result#->y, (long) *12*);
  return *#result#*;
}

!pair841 pvs_a_d840() {
  !pair841 #result#;
  #result# = GC_malloc(1, sizeof( struct struct_pair841 ) );
  mpz_init(#result#->y);
  #result#->x = *2*;
  mpz_set_si(#result#->y, (long) *12*);
  return *#result#*;
}

int pvs_first842(pair841 a) {
  int result;
  result = *a*->x;
  return result;
}

int pvs_first_d843(pair841 a) {
  int result;
  result = *a*->x;
  return result;
}

!pair841 pvs_zero844(pair841 a) {
  !pair841 #result#;
  if ( GC_count( *a* ) == 1 )
    #result# = GC( *a* );
  else {
    #result# = GC_malloc(1, sizeof( struct struct_pair841 ));
    mpz_set(#result#->y, *a*->y);
    #result#->x = *a*->x;
  }
  #result#->x = 0;
  return *#result#*;
}

!pair841 pvs_zero_d845(!pair841 #a#) {
  #a#->x = 0;
  return *#a#*;
}

unsigned long int pvs_a848() {
  unsigned long int result;
  result = (unsigned long) *2*;
  return result;
}

unsigned long int pvs_a_d849() {
  unsigned long int result;
  result = (unsigned long) *2*;
  return result;
}

int pvs_b850() {
  int result;
  result = (*3* + *1*);
  return result;
}

int pvs_b_d851() {
  int result;
  result = (*3* + *1*);
  return result;
}

void pvs_c852(mpz_t result) {
  mpz_set_si(result, (long) (*3* * (*1* + *2*)));
}

void pvs_c_d853(mpz_t result) {
  mpz_set_si(result, (long) (*3* * (*1* + *2*)));
}

int pvs_incr854(int x) {
  int result;
  result = (x + *1*);
  return result;
}

int pvs_incr_d855(int x) {
  int result;
  result = (x + *1*);
  return result;
}

int pvs_zero856(mpz_t x) {
  return 0;
}

int pvs_zero_d857(mpz_t x) {
  return 0;
}

int pvs_f858(int a, int b) {
  mpz_t conv860;
  mpz_set_si(conv860, (long) b);
  int result;
  result = (int) (pvs_zero_d857(conv860) * pvs_incr_d855(a));
  mpz_clear(conv860);
  return result;
}

int pvs_f_d859(int a, int b) {
  mpz_t conv861;
  mpz_set_si(conv861, (long) b);
  int result;
  result = (int) (pvs_zero_d857(conv861) * pvs_incr_d855(a));
  mpz_clear(conv861);
  return result;
}

int pvs_f862(int x) {
  int if866;
  if (((x <= *1*) && *1*)) {
    int if864;
    if (((x == *0*) || (x < *0*))) {
      if864 = *0*;
    } else {
      if864 = x;
    }
    if866 = if864;
  } else {
    int if865;
    if ((x > *10*)) {
      if865 = *10*;
    } else {
      if865 = (x - *5*);
    }
    if866 = if865;
  }
  int result;
  result = if866;
  return result;
}

int pvs_f_d863(int x) {
  int if869;
  if (((x <= *1*) && *1*)) {
    int if867;
    if (((x == *0*) || (x < *0*))) {
      if867 = *0*;
    } else {
      if867 = x;
    }
    if869 = if867;
  } else {
    int if868;
    if ((x > *10*)) {
      if868 = *10*;
    } else {
      if868 = (x - *5*);
    }
    if869 = if868;
  }
  int result;
  result = if869;
  return result;
}

int pvs_t870(int x) {
  int result;
  result = x;
  return result;
}

int pvs_t_d871(int x) {
  int result;
  result = x;
  return result;
}

int* pvs_id2872(int* #t57045#) {
  return *#t57045#*;
}

!int* pvs_id2_d873(!int* #t57045#) {
  return *#t57045#*;
}

!int* pvs_f874(int x) {
  !int* #result#;
  #result# = GC_malloc(1000, sizeof(int) );
  int i876;
  for(i876 = 0; i876 < 1000; i876++) {
    #result#[i876] = pvs_t_d871(i876);
  }
  return *#result#*;
}

!int* pvs_f_d875(int x) {
  !int* #result#;
  #result# = GC_malloc(1000, sizeof(int) );
  int i877;
  for(i877 = 0; i877 < 1000; i877++) {
    #result#[i877] = pvs_t_d871(i877);
  }
  return *#result#*;
}

!int* pvs_update878(int* x) {
  !int* #result#;
  if ( GC_count( *x* ) == 1 )
    #result# = GC( *x* );
  else {
    #result# = GC_malloc(1000, sizeof(int) );
    int i914;
    for(i914 = 0; i914 < 1000; i914++) {
      #result#[i914] = *x*[i914];
    }
  }
  #result#[0] = 0;
  return *#result#*;
}

!int* pvs_update_d879(!int* #x#) {
  #x#[0] = 0;
  return *#x#*;
}

!int* pvs_t2884(int x) {
  !mpq_t* #set887#;
  #set887# = GC_malloc(1000, sizeof(mpq_t) );
  int i886;
  for(i886 = 0; i886 < 1000; i886++) {
    mpq_init(#set887#[i886]);
    mpq_set_d(#set887#[i886], (double) (x + i886) );
    mpq_canonicalize(#set887#[i886]);
  }
  !int* #result#;
  #result# = (int*) GC( *#set887#* );
  if( GC_count( #set887# ) == 1 ) {
    int i915;
    for(i915 = 0; i915 < 1000; i915++) {
      mpq_clear(#set887#[i915]);
    }
  }
  GC_free(#set887#);
  return *#result#*;
}

!int* pvs_t2_d885(int x) {
  !mpq_t* #set889#;
  #set889# = GC_malloc(1000, sizeof(mpq_t) );
  int i888;
  for(i888 = 0; i888 < 1000; i888++) {
    mpq_init(#set889#[i888]);
    mpq_set_d(#set889#[i888], (double) (x + i888) );
    mpq_canonicalize(#set889#[i888]);
  }
  !int* #result#;
  #result# = (int*) GC( *#set889#* );
  if( GC_count( #set889# ) == 1 ) {
    int i916;
    for(i916 = 0; i916 < 1000; i916++) {
      mpq_clear(#set889#[i916]);
    }
  }
  GC_free(#set889#);
  return *#result#*;
}

int* pvs_id890(int** #t57045#) {
  int* #result#;
  #result# = (int*) GC( *#t57045#*[*0*] );
  if( GC_count( #t57045# ) == 1 ) {
    int i917;
    for(i917 = 0; i917 < 1000; i917++) {
      GC_free(#t57045#[i917]);
    }
  }
  GC_free(#t57045#);
  return *#result#*;
}

int* pvs_id_d891(int** #t57045#) {
  int* #result#;
  #result# = (int*) GC( *#t57045#*[*0*] );
  if( GC_count( #t57045# ) == 1 ) {
    int i919;
    for(i919 = 0; i919 < 1000; i919++) {
      GC_free(#t57045#[i919]);
    }
  }
  GC_free(#t57045#);
  return *#result#*;
}

!int* pvs_te892() {
  !int* #aux895#;
  #aux895# = GC_malloc(1000, sizeof(int) );
  int i894;
  for(i894 = 0; i894 < 1000; i894++) {
    #aux895#[i894] = pvs_t_d871(i894);
  }
  !int* #result#;
  #result# = (int*) GC( pvs_update_d879(pvs_update_d879(*#aux895#*)) );
  GC_free(#aux895#);
  return *#result#*;
}

!int* pvs_te_d893() {
  !int* #aux897#;
  #aux897# = GC_malloc(1000, sizeof(int) );
  int i896;
  for(i896 = 0; i896 < 1000; i896++) {
    #aux897#[i896] = pvs_t_d871(i896);
  }
  !int* #result#;
  #result# = (int*) GC( pvs_update_d879(pvs_update_d879(*#aux897#*)) );
  GC_free(#aux897#);
  return *#result#*;
}

!int** pvs_update898(int** x) {
  !int** #result#;
  !int* #res905#;
  #res905# = GC_malloc(1000, sizeof(int) );
  int i906;
  for(i906 = 0; i906 < 1000; i906++) {
    #res905#[i906] = i906;
  }
  if ( GC_count( *x* ) == 1 )
    #result# = GC( *x* );
  else {
    #result# = GC_malloc(1000, sizeof(int*) );
    int i923;
    for(i923 = 0; i923 < 1000; i923++) {
      if ( GC_count( *x*[i923] ) == 1 )
        #result#[i923] = GC( *x*[i923] );
      else {
        #result#[i923] = GC_malloc(1000, sizeof(int) );
        int i924;
        for(i924 = 0; i924 < 1000; i924++) {
          #result#[i923][i924] = *x*[i923][i924];
        }
      }
    }
  }
  !int* #E901#;
  #E901# = GC_malloc(1000, sizeof(int) );
  int i925;
  for(i925 = 0; i925 < 1000; i925++) {
    #E901#[i925] = #result#[0][i925];
  }
  #E901#[1] = 0;
  #result#[0] = (int*) GC( *#E901#* );
  #result#[1] = (int*) GC( *#res905#* );
  GC_free(#res905#);
  return *#result#*;
}

!int** pvs_update_d899(!int** #x#) {
  !int* #res912#;
  #res912# = GC_malloc(1000, sizeof(int) );
  int i913;
  for(i913 = 0; i913 < 1000; i913++) {
    #res912#[i913] = i913;
  }
  !int* #E908#;
  #E908# = GC_malloc(1000, sizeof(int) );
  int i927;
  for(i927 = 0; i927 < 1000; i927++) {
    #E908#[i927] = #x#[0][i927];
  }
  #E908#[1] = 0;
  #x#[0] = (int*) GC( *#E908#* );
  #x#[1] = (int*) GC( *#res912#* );
  GC_free(#res912#);
  return *#x#*;
}