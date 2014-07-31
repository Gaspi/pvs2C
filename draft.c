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
  GC_start();
  printf("Executing draft ...\n");
  // Insert code here
  GC_quit();
  return 0;
}


!pair103 pvs_a101() {
  !pair103 #result#;
  #result# = GC_malloc(1, sizeof( struct struct_pair103 ) );
  mpz_init( #result#->y );
  #result#->x = *2*;
  mpz_set_si(#result#->y, (long) *12*);
  return *#result#*;
}

!pair103 pvs_a_d102() {
  !pair103 #result#;
  #result# = GC_malloc(1, sizeof( struct struct_pair103 ) );
  mpz_init( #result#->y );
  #result#->x = *2*;
  mpz_set_si(#result#->y, (long) *12*);
  return *#result#*;
}

int pvs_first104(pair103 a) {
  int *result*;
  *result* = *a*->x;
  if( GC_count( a ) == 1 ) {
    mpz_clear(a->y);
  }
  GC_free(a);
  return *result*;
}

int pvs_first_d105(pair103 a) {
  int *result*;
  *result* = *a*->x;
  if( GC_count( a ) == 1 ) {
    mpz_clear(a->y);
  }
  GC_free(a);
  return *result*;
}

!pair103 pvs_zero106(pair103 a) {
  !pair103 #result#;
  if ( GC_count( *a* ) == 1 )
    #result# = *a*;
  else {
    #result# = GC_malloc(1, sizeof( struct struct_pair103 ));
    mpz_init( #result#->y );
    mpz_set(#result#->y, *a*->y);
    #result#->x = *a*->x;
  }
  #result#->x = 0;
  int *res108*;
  return *#result#*;
}

!pair103 pvs_zero_d107(!pair103 #a#) {
  #a#->x = 0;
  int *res109*;
  pair103 *#result#*;
  return *#a#*;
}

uli pvs_a110() {
  return (uli) *2*;
}

uli pvs_a_d111() {
  return (uli) *2*;
}

int pvs_b112() {
  return (*3* + *1*);
}

int pvs_b_d113() {
  return (*3* + *1*);
}

!void pvs_c114(mpz_t result) {
  mpz_set_si(result, (long) (*3* * (*1* + *2*)));
}

!void pvs_c_d115(mpz_t result) {
  mpz_set_si(result, (long) (*3* * (*1* + *2*)));
}

int pvs_incr116(int *x*) {
  return (*x* + *1*);
}

int pvs_incr_d117(int *x*) {
  return (*x* + *1*);
}

int pvs_zero118(mpz_t x) {
  mpz_clear(x);
  int *result*;
  return 0;
}

int pvs_zero_d119(mpz_t x) {
  mpz_clear(x);
  int *result*;
  return 0;
}

int pvs_f120(int *a*, int *b*) {
  mpz_t conv122;
  mpz_init( conv122 );
  mpz_set_si(conv122, (long) *b*);
  int *result*;
  *result* = (int) (pvs_zero_d119( conv122 ) * pvs_incr_d117( *a* ));
  mpz_clear(conv122);
  return *result*;
}

int pvs_f_d121(int *a*, int *b*) {
  mpz_t conv123;
  mpz_init( conv123 );
  mpz_set_si(conv123, (long) *b*);
  int *result*;
  *result* = (int) (pvs_zero_d119( conv123 ) * pvs_incr_d117( *a* ));
  mpz_clear(conv123);
  return *result*;
}

int pvs_f124(int *x*) {
  if (((*x* <= *1*) && *1*)) {
    if (((*x* == *0*) || (*x* < *0*))) {
      return *0*;
    } else {
      return *x*;
    }
  } else {
    if ((*x* > *10*)) {
      return *10*;
    } else {
      return (*x* - *5*);
    }
  }
}

int pvs_f_d125(int *x*) {
  if (((*x* <= *1*) && *1*)) {
    if (((*x* == *0*) || (*x* < *0*))) {
      return *0*;
    } else {
      return *x*;
    }
  } else {
    if ((*x* > *10*)) {
      return *10*;
    } else {
      return (*x* - *5*);
    }
  }
}

int pvs_t132(int *x*) {
  return *x*;
}

int pvs_t_d133(int *x*) {
  return *x*;
}

int* pvs_id2134(int* #t59375#) {
  return *#t59375#*;
}

!int* pvs_id2_d135(!int* #t59375#) {
  return *#t59375#*;
}

!int* pvs_f138(int *x*) {
  !int* #result#;
  #result# = GC_malloc(1000, sizeof(int) );
  int *i140*;
  for(*i140* = 0; *i140* < 1000; *i140*++) {
    #result#[*i140*] = pvs_t_d133( **i140** );
  }
  return *#result#*;
}

!int* pvs_f_d139(int *x*) {
  !int* #result#;
  #result# = GC_malloc(1000, sizeof(int) );
  int *i141*;
  for(*i141* = 0; *i141* < 1000; *i141*++) {
    #result#[*i141*] = pvs_t_d133( **i141** );
  }
  return *#result#*;
}

!int* pvs_update142(int* x) {
  !int* #result#;
  if ( GC_count( *x* ) == 1 )
    #result# = *x*;
  else {
    #result# = GC_malloc(1000, sizeof(int) );
    int *i296*;
    for(*i296* = 0; *i296* < 1000; *i296*++) {
      #result#[*i296*] = *x*[*i296*];
    }
  }
  #result#[0] = 0;
  int *L144*;
  int *res145*;
  return *#result#*;
}

!int* pvs_update_d143(!int* #x#) {
  #x#[0] = 0;
  int *res147*;
  int *L146*;
  int* *#result#*;
  return *#x#*;
}

!int* pvs_t2160(int *x*) {
  !int* #result#;
  #result# = GC_malloc(1000, sizeof(int) );
  int *i162*;
  for(*i162* = 0; *i162* < 1000; *i162*++) {
    #result#[*i162*] = (*x* + **i162**);
  }
  return *#result#*;
}

!int* pvs_t2_d161(int *x*) {
  !int* #result#;
  #result# = GC_malloc(1000, sizeof(int) );
  int *i163*;
  for(*i163* = 0; *i163* < 1000; *i163*++) {
    #result#[*i163*] = (*x* + **i163**);
  }
  return *#result#*;
}

int* pvs_id164(int** #t59375#) {
  int* #result#;
  #result# = (int*) *#t59375#*[*0*];
  if( GC_count( #t59375# ) == 1 ) {
    int *i297*;
    for(*i297* = 0; *i297* < 1000; *i297*++) {
      GC_free(#t59375#[*i297*]);
    }
  }
  GC_free(#t59375#);
  int** *a*;
  return *#result#*;
}

int* pvs_id_d165(int** #t59375#) {
  int* #result#;
  #result# = (int*) *#t59375#*[*0*];
  if( GC_count( #t59375# ) == 1 ) {
    int *i299*;
    for(*i299* = 0; *i299* < 1000; *i299*++) {
      GC_free(#t59375#[*i299*]);
    }
  }
  GC_free(#t59375#);
  int** *a*;
  return *#result#*;
}

!int* pvs_te196() {
  !int* #aux199#;
  #aux199# = GC_malloc(1000, sizeof(int) );
  int *i198*;
  for(*i198* = 0; *i198* < 1000; *i198*++) {
    #aux199#[*i198*] = pvs_t_d133( **i198** );
  }
  return pvs_update_d143( pvs_update_d143( *#aux199#* ) );
}

!int* pvs_te_d197() {
  !int* #aux201#;
  #aux201# = GC_malloc(1000, sizeof(int) );
  int *i200*;
  for(*i200* = 0; *i200* < 1000; *i200*++) {
    #aux201#[*i200*] = pvs_t_d133( **i200** );
  }
  return pvs_update_d143( pvs_update_d143( *#aux201#* ) );
}

!int** pvs_update204(int** x) {
  !int* #res211#;
  #res211# = GC_malloc(1000, sizeof(int) );
  int *i212*;
  for(*i212* = 0; *i212* < 1000; *i212*++) {
    #res211#[*i212*] = **i212**;
  }
  !int** #result#;
  if ( GC_count( *x* ) == 1 )
    #result# = *x*;
  else {
    #result# = GC_malloc(1000, sizeof(int*) );
    int *i301*;
    for(*i301* = 0; *i301* < 1000; *i301*++) {
      #result#[*i301*] = (int*) *x*[*i301*];
    }
  }
  !int* #E207#;
  #E207# = GC_malloc(1000, sizeof(int) );
  int *i302*;
  for(*i302* = 0; *i302* < 1000; *i302*++) {
    #E207#[*i302*] = #result#[0][*i302*];
  }
  #E207#[1] = 0;
  #result#[0] = (int*) *#E207#*;
  #result#[1] = (int*) *#res211#*;
  int *L206*;
  int *L208*;
  int *res209*;
  int *L210*;
  return *#result#*;
}

!int** pvs_update_d205(!int** #x#) {
  !int* #res218#;
  #res218# = GC_malloc(1000, sizeof(int) );
  int *i219*;
  for(*i219* = 0; *i219* < 1000; *i219*++) {
    #res218#[*i219*] = **i219**;
  }
  !int* #E214#;
  #E214# = GC_malloc(1000, sizeof(int) );
  int *i303*;
  for(*i303* = 0; *i303* < 1000; *i303*++) {
    #E214#[*i303*] = #x#[0][*i303*];
  }
  #E214#[1] = 0;
  #x#[0] = (int*) *#E214#*;
  #x#[1] = (int*) *#res218#*;
  int** *#result#*;
  int *L213*;
  int *L215*;
  int *res216*;
  int *L217*;
  return *#x#*;
}