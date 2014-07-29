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


!pair109 pvs_a107() {
  !pair109 #result#;
  #result# = GC_malloc(1, sizeof( struct struct_pair109 ) );
  mpz_init(#result#->y);
  #result#->x = *2*;
  mpz_set_si(#result#->y, (long) *12*);
  return *#result#*;
}

!pair109 pvs_a_d108() {
  !pair109 #result#;
  #result# = GC_malloc(1, sizeof( struct struct_pair109 ) );
  mpz_init(#result#->y);
  #result#->x = *2*;
  mpz_set_si(#result#->y, (long) *12*);
  return *#result#*;
}

int pvs_first110(pair109 a) {
  int result;
  result = *a*->x;
  if( GC_count( a ) == 1 ) {
    mpz_clear(a->y);
  }
  GC_free(a);
  return result;
}

int pvs_first_d111(pair109 a) {
  int result;
  result = *a*->x;
  if( GC_count( a ) == 1 ) {
    mpz_clear(a->y);
  }
  GC_free(a);
  return result;
}

!pair109 pvs_zero112(pair109 a) {
  !pair109 #result#;
  if ( GC_count( *a* ) == 1 )
    #result# = GC( *a* );
  else {
    #result# = GC_malloc(1, sizeof( struct struct_pair109 ));
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

!pair109 pvs_zero_d113(!pair109 #a#) {
  #a#->x = 0;
  return *#a#*;
}

unsigned long int pvs_a116() {
  unsigned long int result;
  result = (unsigned long) *2*;
  return result;
}

unsigned long int pvs_a_d117() {
  unsigned long int result;
  result = (unsigned long) *2*;
  return result;
}

int pvs_b118() {
  int result;
  result = (*3* + *1*);
  return result;
}

int pvs_b_d119() {
  int result;
  result = (*3* + *1*);
  return result;
}

void pvs_c120(mpz_t result) {
  mpz_set_si(result, (long) (*3* * (*1* + *2*)));
}

void pvs_c_d121(mpz_t result) {
  mpz_set_si(result, (long) (*3* * (*1* + *2*)));
}

int pvs_incr122(int x) {
  int result;
  result = (x + *1*);
  return result;
}

int pvs_incr_d123(int x) {
  int result;
  result = (x + *1*);
  return result;
}

int pvs_zero124(mpz_t x) {
  mpz_clear(x);
  return 0;
}

int pvs_zero_d125(mpz_t x) {
  mpz_clear(x);
  return 0;
}

int pvs_f126(int a, int b) {
  mpz_t conv128;
  mpz_set_si(conv128, (long) b);
  int result;
  result = (int) (pvs_zero_d125(conv128) * pvs_incr_d123(a));
  mpz_clear(conv128);
  return result;
}

int pvs_f_d127(int a, int b) {
  mpz_t conv129;
  mpz_set_si(conv129, (long) b);
  int result;
  result = (int) (pvs_zero_d125(conv129) * pvs_incr_d123(a));
  mpz_clear(conv129);
  return result;
}

int pvs_f130(int x) {
  int if134;
  if (((x <= *1*) && *1*)) {
    int if132;
    if (((x == *0*) || (x < *0*))) {
      if132 = *0*;
    } else {
      if132 = x;
    }
    if134 = if132;
  } else {
    int if133;
    if ((x > *10*)) {
      if133 = *10*;
    } else {
      if133 = (x - *5*);
    }
    if134 = if133;
  }
  int result;
  result = if134;
  return result;
}

int pvs_f_d131(int x) {
  int if137;
  if (((x <= *1*) && *1*)) {
    int if135;
    if (((x == *0*) || (x < *0*))) {
      if135 = *0*;
    } else {
      if135 = x;
    }
    if137 = if135;
  } else {
    int if136;
    if ((x > *10*)) {
      if136 = *10*;
    } else {
      if136 = (x - *5*);
    }
    if137 = if136;
  }
  int result;
  result = if137;
  return result;
}

int pvs_t138(int x) {
  int result;
  result = x;
  return result;
}

int pvs_t_d139(int x) {
  int result;
  result = x;
  return result;
}

int* pvs_id2140(int* #t59439#) {
  return *#t59439#*;
}

!int* pvs_id2_d141(!int* #t59439#) {
  return *#t59439#*;
}

!int* pvs_f142(int x) {
  !int* #result#;
  #result# = GC_malloc(1000, sizeof(int) );
  int i144;
  for(i144 = 0; i144 < 1000; i144++) {
    #result#[i144] = pvs_t_d139(i144);
  }
  return *#result#*;
}

!int* pvs_f_d143(int x) {
  !int* #result#;
  #result# = GC_malloc(1000, sizeof(int) );
  int i145;
  for(i145 = 0; i145 < 1000; i145++) {
    #result#[i145] = pvs_t_d139(i145);
  }
  return *#result#*;
}

!int* pvs_update146(int* x) {
  !int* #result#;
  if ( GC_count( *x* ) == 1 )
    #result# = GC( *x* );
  else {
    #result# = GC_malloc(1000, sizeof(int) );
    int i182;
    for(i182 = 0; i182 < 1000; i182++) {
      #result#[i182] = *x*[i182];
    }
  }
  #result#[0] = 0;
  GC_free(x);
  return *#result#*;
}

!int* pvs_update_d147(!int* #x#) {
  #x#[0] = 0;
  return *#x#*;
}

!int* pvs_t2152(int x) {
  !mpq_t* #set155#;
  #set155# = GC_malloc(1000, sizeof(mpq_t) );
  int i154;
  for(i154 = 0; i154 < 1000; i154++) {
    mpq_init(#set155#[i154]);
    mpq_set_d(#set155#[i154], (double) (x + i154) );
    mpq_canonicalize(#set155#[i154]);
  }
  !int* #result#;
  #result# = (int*) GC( *#set155#* );
  if( GC_count( #set155# ) == 1 ) {
    int i184;
    for(i184 = 0; i184 < 1000; i184++) {
      mpq_clear(#set155#[i184]);
    }
  }
  GC_free(#set155#);
  return *#result#*;
}

!int* pvs_t2_d153(int x) {
  !mpq_t* #set157#;
  #set157# = GC_malloc(1000, sizeof(mpq_t) );
  int i156;
  for(i156 = 0; i156 < 1000; i156++) {
    mpq_init(#set157#[i156]);
    mpq_set_d(#set157#[i156], (double) (x + i156) );
    mpq_canonicalize(#set157#[i156]);
  }
  !int* #result#;
  #result# = (int*) GC( *#set157#* );
  if( GC_count( #set157# ) == 1 ) {
    int i185;
    for(i185 = 0; i185 < 1000; i185++) {
      mpq_clear(#set157#[i185]);
    }
  }
  GC_free(#set157#);
  return *#result#*;
}

int* pvs_id158(int** #t59439#) {
  int* #result#;
  #result# = (int*) GC( *#t59439#*[*0*] );
  if( GC_count( #t59439# ) == 1 ) {
    int i186;
    for(i186 = 0; i186 < 1000; i186++) {
      GC_free(#t59439#[i186]);
    }
  }
  GC_free(#t59439#);
  return *#result#*;
}

int* pvs_id_d159(int** #t59439#) {
  int* #result#;
  #result# = (int*) GC( *#t59439#*[*0*] );
  if( GC_count( #t59439# ) == 1 ) {
    int i188;
    for(i188 = 0; i188 < 1000; i188++) {
      GC_free(#t59439#[i188]);
    }
  }
  GC_free(#t59439#);
  return *#result#*;
}

!int* pvs_te160() {
  !int* #aux163#;
  #aux163# = GC_malloc(1000, sizeof(int) );
  int i162;
  for(i162 = 0; i162 < 1000; i162++) {
    #aux163#[i162] = pvs_t_d139(i162);
  }
  !int* #result#;
  #result# = (int*) GC( pvs_update_d147(pvs_update_d147(*#aux163#*)) );
  GC_free(#aux163#);
  return *#result#*;
}

!int* pvs_te_d161() {
  !int* #aux165#;
  #aux165# = GC_malloc(1000, sizeof(int) );
  int i164;
  for(i164 = 0; i164 < 1000; i164++) {
    #aux165#[i164] = pvs_t_d139(i164);
  }
  !int* #result#;
  #result# = (int*) GC( pvs_update_d147(pvs_update_d147(*#aux165#*)) );
  GC_free(#aux165#);
  return *#result#*;
}

!int** pvs_update166(int** x) {
  !int** #result#;
  !int* #res173#;
  #res173# = GC_malloc(1000, sizeof(int) );
  int i174;
  for(i174 = 0; i174 < 1000; i174++) {
    #res173#[i174] = i174;
  }
  if ( GC_count( *x* ) == 1 )
    #result# = GC( *x* );
  else {
    #result# = GC_malloc(1000, sizeof(int*) );
    int i192;
    for(i192 = 0; i192 < 1000; i192++) {
      if ( GC_count( *x*[i192] ) == 1 )
        #result#[i192] = GC( *x*[i192] );
      else {
        #result#[i192] = GC_malloc(1000, sizeof(int) );
        int i193;
        for(i193 = 0; i193 < 1000; i193++) {
          #result#[i192][i193] = *x*[i192][i193];
        }
      }
    }
  }
  !int* #E169#;
  #E169# = GC_malloc(1000, sizeof(int) );
  int i194;
  for(i194 = 0; i194 < 1000; i194++) {
    #E169#[i194] = #result#[0][i194];
  }
  #E169#[1] = 0;
  #result#[0] = (int*) GC( *#E169#* );
  #result#[1] = (int*) GC( *#res173#* );
  GC_free(#res173#);
  if( GC_count( x ) == 1 ) {
    int i196;
    for(i196 = 0; i196 < 1000; i196++) {
      GC_free(x[i196]);
    }
  }
  GC_free(x);
  return *#result#*;
}

!int** pvs_update_d167(!int** #x#) {
  !int* #res180#;
  #res180# = GC_malloc(1000, sizeof(int) );
  int i181;
  for(i181 = 0; i181 < 1000; i181++) {
    #res180#[i181] = i181;
  }
  !int* #E176#;
  #E176# = GC_malloc(1000, sizeof(int) );
  int i198;
  for(i198 = 0; i198 < 1000; i198++) {
    #E176#[i198] = #x#[0][i198];
  }
  #E176#[1] = 0;
  #x#[0] = (int*) GC( *#E176#* );
  #x#[1] = (int*) GC( *#res180#* );
  GC_free(#res180#);
  return *#x#*;
}