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
  mpz_init(#result#->y);
  #result#->x = *2*;
  mpz_set_si(#result#->y, (long) *12*);
  return *#result#*;
}

!pair103 pvs_a_d102() {
  !pair103 #result#;
  #result# = GC_malloc(1, sizeof( struct struct_pair103 ) );
  mpz_init(#result#->y);
  #result#->x = *2*;
  mpz_set_si(#result#->y, (long) *12*);
  return *#result#*;
}

int pvs_first104(pair103 a) {
  int result;
  result = *a*->x;
  if( GC_count( a ) == 1 ) {
    mpz_clear(a->y);
  }
  GC_free(a);
  return result;
}

int pvs_first_d105(pair103 a) {
  int result;
  result = *a*->x;
  if( GC_count( a ) == 1 ) {
    mpz_clear(a->y);
  }
  GC_free(a);
  return result;
}

!pair103 pvs_zero106(pair103 a) {
  !pair103 #result#;
  if ( GC_count( *a* ) == 1 )
    #result# = GC( *a* );
  else {
    #result# = GC_malloc(1, sizeof( struct struct_pair103 ));
    mpz_set(#result#->y, *a*->y);
    #result#->x = *a*->x;
  }
  #result#->x = 0;
  if( GC_count( a ) == 1 ) {
    mpz_clear(a->y);
  }
  GC_free(a);
  return *#result#*;
}

!pair103 pvs_zero_d107(!pair103 #a#) {
  #a#->x = 0;
  return *#a#*;
}

unsigned long int pvs_a110() {
  unsigned long int result;
  result = (unsigned long) *2*;
  return result;
}

unsigned long int pvs_a_d111() {
  unsigned long int result;
  result = (unsigned long) *2*;
  return result;
}

int pvs_b112() {
  int result;
  result = (*3* + *1*);
  return result;
}

int pvs_b_d113() {
  int result;
  result = (*3* + *1*);
  return result;
}

void pvs_c114(mpz_t result) {
  mpz_set_si(result, (long) (*3* * (*1* + *2*)));
}

void pvs_c_d115(mpz_t result) {
  mpz_set_si(result, (long) (*3* * (*1* + *2*)));
}

int pvs_incr116(int x) {
  int result;
  result = (x + *1*);
  return result;
}

int pvs_incr_d117(int x) {
  int result;
  result = (x + *1*);
  return result;
}

int pvs_zero118(mpz_t x) {
  mpz_clear(x);
  return 0;
}

int pvs_zero_d119(mpz_t x) {
  mpz_clear(x);
  return 0;
}

int pvs_f120(int a, int b) {
  mpz_t conv122;
  mpz_set_si(conv122, (long) b);
  int result;
  result = (int) (pvs_zero_d119( conv122 ) * pvs_incr_d117( a ));
  mpz_clear(conv122);
  return result;
}

int pvs_f_d121(int a, int b) {
  mpz_t conv123;
  mpz_set_si(conv123, (long) b);
  int result;
  result = (int) (pvs_zero_d119( conv123 ) * pvs_incr_d117( a ));
  mpz_clear(conv123);
  return result;
}

int pvs_f124(int x) {
  int if128;
  if (((x <= *1*) && *1*)) {
    int if126;
    if (((x == *0*) || (x < *0*))) {
      if126 = *0*;
    } else {
      if126 = x;
    }
    if128 = if126;
  } else {
    int if127;
    if ((x > *10*)) {
      if127 = *10*;
    } else {
      if127 = (x - *5*);
    }
    if128 = if127;
  }
  int result;
  result = if128;
  return result;
}

int pvs_f_d125(int x) {
  int if131;
  if (((x <= *1*) && *1*)) {
    int if129;
    if (((x == *0*) || (x < *0*))) {
      if129 = *0*;
    } else {
      if129 = x;
    }
    if131 = if129;
  } else {
    int if130;
    if ((x > *10*)) {
      if130 = *10*;
    } else {
      if130 = (x - *5*);
    }
    if131 = if130;
  }
  int result;
  result = if131;
  return result;
}

int pvs_t132(int x) {
  int result;
  result = x;
  return result;
}

int pvs_t_d133(int x) {
  int result;
  result = x;
  return result;
}

int* pvs_id2134(int* #t57190#) {
  return *#t57190#*;
}

!int* pvs_id2_d135(!int* #t57190#) {
  return *#t57190#*;
}

!int* pvs_f136(int x) {
  !int* #result#;
  #result# = GC_malloc(1000, sizeof(int) );
  int i138;
  for(i138 = 0; i138 < 1000; i138++) {
    #result#[i138] = pvs_t_d133( i138 );
  }
  return *#result#*;
}

!int* pvs_f_d137(int x) {
  !int* #result#;
  #result# = GC_malloc(1000, sizeof(int) );
  int i139;
  for(i139 = 0; i139 < 1000; i139++) {
    #result#[i139] = pvs_t_d133( i139 );
  }
  return *#result#*;
}

!int* pvs_update140(int* x) {
  !int* #result#;
  if ( GC_count( *x* ) == 1 )
    #result# = GC( *x* );
  else {
    #result# = GC_malloc(1000, sizeof(int) );
    int i176;
    for(i176 = 0; i176 < 1000; i176++) {
      #result#[i176] = *x*[i176];
    }
  }
  #result#[0] = 0;
  GC_free(x);
  return *#result#*;
}

!int* pvs_update_d141(!int* #x#) {
  #x#[0] = 0;
  return *#x#*;
}

!int* pvs_t2146(int x) {
  !mpq_t* #set149#;
  #set149# = GC_malloc(1000, sizeof(mpq_t) );
  int i148;
  for(i148 = 0; i148 < 1000; i148++) {
    mpq_init(#set149#[i148]);
    mpq_set_d(#set149#[i148], (double) (x + i148) );
    mpq_canonicalize(#set149#[i148]);
  }
  !int* #result#;
  #result# = (int*) GC( *#set149#* );
  if( GC_count( #set149# ) == 1 ) {
    int i178;
    for(i178 = 0; i178 < 1000; i178++) {
      mpq_clear(#set149#[i178]);
    }
  }
  GC_free(#set149#);
  return *#result#*;
}

!int* pvs_t2_d147(int x) {
  !mpq_t* #set151#;
  #set151# = GC_malloc(1000, sizeof(mpq_t) );
  int i150;
  for(i150 = 0; i150 < 1000; i150++) {
    mpq_init(#set151#[i150]);
    mpq_set_d(#set151#[i150], (double) (x + i150) );
    mpq_canonicalize(#set151#[i150]);
  }
  !int* #result#;
  #result# = (int*) GC( *#set151#* );
  if( GC_count( #set151# ) == 1 ) {
    int i179;
    for(i179 = 0; i179 < 1000; i179++) {
      mpq_clear(#set151#[i179]);
    }
  }
  GC_free(#set151#);
  return *#result#*;
}

int* pvs_id152(int** #t57190#) {
  int* #result#;
  #result# = (int*) GC( *#t57190#*[*0*] );
  if( GC_count( #t57190# ) == 1 ) {
    int i180;
    for(i180 = 0; i180 < 1000; i180++) {
      GC_free(#t57190#[i180]);
    }
  }
  GC_free(#t57190#);
  return *#result#*;
}

int* pvs_id_d153(int** #t57190#) {
  int* #result#;
  #result# = (int*) GC( *#t57190#*[*0*] );
  if( GC_count( #t57190# ) == 1 ) {
    int i182;
    for(i182 = 0; i182 < 1000; i182++) {
      GC_free(#t57190#[i182]);
    }
  }
  GC_free(#t57190#);
  return *#result#*;
}

!int* pvs_te154() {
  !int* #aux157#;
  #aux157# = GC_malloc(1000, sizeof(int) );
  int i156;
  for(i156 = 0; i156 < 1000; i156++) {
    #aux157#[i156] = pvs_t_d133( i156 );
  }
  !int* #result#;
  #result# = (int*) pvs_update_d141( pvs_update_d141( GC(*#aux157#*) ) );
  GC_free(#aux157#);
  return *#result#*;
}

!int* pvs_te_d155() {
  !int* #aux159#;
  #aux159# = GC_malloc(1000, sizeof(int) );
  int i158;
  for(i158 = 0; i158 < 1000; i158++) {
    #aux159#[i158] = pvs_t_d133( i158 );
  }
  !int* #result#;
  #result# = (int*) pvs_update_d141( pvs_update_d141( GC(*#aux159#*) ) );
  GC_free(#aux159#);
  return *#result#*;
}

!int** pvs_update160(int** x) {
  !int** #result#;
  !int* #res167#;
  #res167# = GC_malloc(1000, sizeof(int) );
  int i168;
  for(i168 = 0; i168 < 1000; i168++) {
    #res167#[i168] = i168;
  }
  if ( GC_count( *x* ) == 1 )
    #result# = GC( *x* );
  else {
    #result# = GC_malloc(1000, sizeof(int*) );
    int i186;
    for(i186 = 0; i186 < 1000; i186++) {
      if ( GC_count( *x*[i186] ) == 1 )
        #result#[i186] = GC( *x*[i186] );
      else {
        #result#[i186] = GC_malloc(1000, sizeof(int) );
        int i187;
        for(i187 = 0; i187 < 1000; i187++) {
          #result#[i186][i187] = *x*[i186][i187];
        }
      }
    }
  }
  !int* #E163#;
  #E163# = GC_malloc(1000, sizeof(int) );
  int i188;
  for(i188 = 0; i188 < 1000; i188++) {
    #E163#[i188] = #result#[0][i188];
  }
  #E163#[1] = 0;
  #result#[0] = (int*) GC( *#E163#* );
  #result#[1] = (int*) GC( *#res167#* );
  GC_free(#res167#);
  if( GC_count( x ) == 1 ) {
    int i190;
    for(i190 = 0; i190 < 1000; i190++) {
      GC_free(x[i190]);
    }
  }
  GC_free(x);
  return *#result#*;
}

!int** pvs_update_d161(!int** #x#) {
  !int* #res174#;
  #res174# = GC_malloc(1000, sizeof(int) );
  int i175;
  for(i175 = 0; i175 < 1000; i175++) {
    #res174#[i175] = i175;
  }
  !int* #E170#;
  #E170# = GC_malloc(1000, sizeof(int) );
  int i192;
  for(i192 = 0; i192 < 1000; i192++) {
    #E170#[i192] = #x#[0][i192];
  }
  #E170#[1] = 0;
  #x#[0] = (int*) GC( *#E170#* );
  #x#[1] = (int*) GC( *#res174#* );
  GC_free(#res174#);
  return *#x#*;
}