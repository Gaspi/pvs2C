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


!pair535 pvs_a533() {
  !pair535 #result#;
  #result# = GC_malloc(1, sizeof( struct struct_pair535 ) );
  mpz_init(#result#->y);
  #result#->x = *2*;
  mpz_set_si(#result#->y, (long) *12*);
  return *#result#*;
}

!pair535 pvs_a_d534() {
  !pair535 #result#;
  #result# = GC_malloc(1, sizeof( struct struct_pair535 ) );
  mpz_init(#result#->y);
  #result#->x = *2*;
  mpz_set_si(#result#->y, (long) *12*);
  return *#result#*;
}

int pvs_first536(pair535 a) {
  int result;
  result = *a*->x;
  return result;
}

int pvs_first_d537(pair535 a) {
  int result;
  result = *a*->x;
  return result;
}

!pair535 pvs_zero538(pair535 a) {
  !pair535 #result#;
  if ( GC_count( *a* ) == 1 )
    #result# = GC( *a* );
  else {
    #result# = GC_malloc(1, sizeof( struct struct_pair535 ));
    mpz_set(#result#->y, *a*->y);
    #result#->x = *a*->x;
  }
  #result#->x = 0;
  return *#result#*;
}

!pair535 pvs_zero_d539(!pair535 #a#) {
  #a#->x = 0;
  return *#a#*;
}

unsigned long int pvs_a542() {
  unsigned long int result;
  result = (unsigned long) *2*;
  return result;
}

unsigned long int pvs_a_d543() {
  unsigned long int result;
  result = (unsigned long) *2*;
  return result;
}

int pvs_b544() {
  int result;
  result = (*3* + *1*);
  return result;
}

int pvs_b_d545() {
  int result;
  result = (*3* + *1*);
  return result;
}

void pvs_c546(mpz_t result) {
  mpz_set_si(result, (long) (*3* * (*1* + *2*)));
}

void pvs_c_d547(mpz_t result) {
  mpz_set_si(result, (long) (*3* * (*1* + *2*)));
}

int pvs_incr548(int x) {
  int result;
  result = (x + *1*);
  return result;
}

int pvs_incr_d549(int x) {
  int result;
  result = (x + *1*);
  return result;
}

int pvs_zero550(mpz_t x) {
  return 0;
}

int pvs_zero_d551(mpz_t x) {
  return 0;
}

int pvs_f552(int a, int b) {
  mpz_t conv554;
  mpz_set_si(conv554, (long) b);
  int result;
  result = (int) (pvs_zero_d551(conv554) * pvs_incr_d549(a));
  mpz_clear(conv554);
  return result;
}

int pvs_f_d553(int a, int b) {
  mpz_t conv555;
  mpz_set_si(conv555, (long) b);
  int result;
  result = (int) (pvs_zero_d551(conv555) * pvs_incr_d549(a));
  mpz_clear(conv555);
  return result;
}

int pvs_f556(int x) {
  int if560;
  if (((x <= *1*) && *1*)) {
    int if558;
    if (((x == *0*) || (x < *0*))) {
      if558 = *0*;
    } else {
      if558 = x;
    }
    if560 = if558;
  } else {
    int if559;
    if ((x > *10*)) {
      if559 = *10*;
    } else {
      if559 = (x - *5*);
    }
    if560 = if559;
  }
  int result;
  result = if560;
  return result;
}

int pvs_f_d557(int x) {
  int if563;
  if (((x <= *1*) && *1*)) {
    int if561;
    if (((x == *0*) || (x < *0*))) {
      if561 = *0*;
    } else {
      if561 = x;
    }
    if563 = if561;
  } else {
    int if562;
    if ((x > *10*)) {
      if562 = *10*;
    } else {
      if562 = (x - *5*);
    }
    if563 = if562;
  }
  int result;
  result = if563;
  return result;
}

int pvs_t564(int x) {
  int result;
  result = x;
  return result;
}

int pvs_t_d565(int x) {
  int result;
  result = x;
  return result;
}

int* pvs_id2566(int* #t57045#) {
  return *#t57045#*;
}

!int* pvs_id2_d567(!int* #t57045#) {
  return *#t57045#*;
}

!int* pvs_f568(int x) {
  !int* #result#;
  #result# = GC_malloc(1000, sizeof(int) );
  int i570;
  for(i570 = 0; i570 < 1000; i570++) {
    #result#[i570] = pvs_t_d565(i570);
  }
  return *#result#*;
}

!int* pvs_f_d569(int x) {
  !int* #result#;
  #result# = GC_malloc(1000, sizeof(int) );
  int i571;
  for(i571 = 0; i571 < 1000; i571++) {
    #result#[i571] = pvs_t_d565(i571);
  }
  return *#result#*;
}

!int* pvs_update572(int* x) {
  !int* #result#;
  if ( GC_count( *x* ) == 1 )
    #result# = GC( *x* );
  else {
    #result# = GC_malloc(1000, sizeof(int) );
    int i608;
    for(i608 = 0; i608 < 1000; i608++) {
      #result#[i608] = *x*[i608];
    }
  }
  #result#[0] = 0;
  return *#result#*;
}

!int* pvs_update_d573(!int* #x#) {
  #x#[0] = 0;
  return *#x#*;
}

!int* pvs_t2578(int x) {
  !mpq_t* #set581#;
  #set581# = GC_malloc(1000, sizeof(mpq_t) );
  int i580;
  for(i580 = 0; i580 < 1000; i580++) {
    mpq_init(#set581#[i580]);
    mpq_set_d(#set581#[i580], (double) (x + i580) );
    mpq_canonicalize(#set581#[i580]);
  }
  !int* #result#;
  #result# = (int*) GC( *#set581#* );
  if( GC_count( #set581# ) == 1 ) {
    int i609;
    for(i609 = 0; i609 < 1000; i609++) {
      mpq_clear(#set581#[i609]);
    }
  }
  GC_free(#set581#);
  return *#result#*;
}

!int* pvs_t2_d579(int x) {
  !mpq_t* #set583#;
  #set583# = GC_malloc(1000, sizeof(mpq_t) );
  int i582;
  for(i582 = 0; i582 < 1000; i582++) {
    mpq_init(#set583#[i582]);
    mpq_set_d(#set583#[i582], (double) (x + i582) );
    mpq_canonicalize(#set583#[i582]);
  }
  !int* #result#;
  #result# = (int*) GC( *#set583#* );
  if( GC_count( #set583# ) == 1 ) {
    int i610;
    for(i610 = 0; i610 < 1000; i610++) {
      mpq_clear(#set583#[i610]);
    }
  }
  GC_free(#set583#);
  return *#result#*;
}

int* pvs_id584(int** #t57045#) {
  int* #result#;
  #result# = (int*) GC( *#t57045#*[*0*] );
  if( GC_count( #t57045# ) == 1 ) {
    int i611;
    for(i611 = 0; i611 < 1000; i611++) {
      GC_free(#t57045#[i611]);
    }
  }
  GC_free(#t57045#);
  return *#result#*;
}

int* pvs_id_d585(int** #t57045#) {
  int* #result#;
  #result# = (int*) GC( *#t57045#*[*0*] );
  if( GC_count( #t57045# ) == 1 ) {
    int i613;
    for(i613 = 0; i613 < 1000; i613++) {
      GC_free(#t57045#[i613]);
    }
  }
  GC_free(#t57045#);
  return *#result#*;
}

!int* pvs_te586() {
  !int* #aux589#;
  #aux589# = GC_malloc(1000, sizeof(int) );
  int i588;
  for(i588 = 0; i588 < 1000; i588++) {
    #aux589#[i588] = pvs_t_d565(i588);
  }
  !int* #result#;
  #result# = (int*) GC( pvs_update_d573(pvs_update_d573(*#aux589#*)) );
  GC_free(#aux589#);
  return *#result#*;
}

!int* pvs_te_d587() {
  !int* #aux591#;
  #aux591# = GC_malloc(1000, sizeof(int) );
  int i590;
  for(i590 = 0; i590 < 1000; i590++) {
    #aux591#[i590] = pvs_t_d565(i590);
  }
  !int* #result#;
  #result# = (int*) GC( pvs_update_d573(pvs_update_d573(*#aux591#*)) );
  GC_free(#aux591#);
  return *#result#*;
}

!int** pvs_update592(int** x) {
  !int** #result#;
  !int* #res599#;
  #res599# = GC_malloc(1000, sizeof(int) );
  int i600;
  for(i600 = 0; i600 < 1000; i600++) {
    #res599#[i600] = i600;
  }
  if ( GC_count( *x* ) == 1 )
    #result# = GC( *x* );
  else {
    #result# = GC_malloc(1000, sizeof(int*) );
    int i617;
    for(i617 = 0; i617 < 1000; i617++) {
      if ( GC_count( *x*[i617] ) == 1 )
        #result#[i617] = GC( *x*[i617] );
      else {
        #result#[i617] = GC_malloc(1000, sizeof(int) );
        int i618;
        for(i618 = 0; i618 < 1000; i618++) {
          #result#[i617][i618] = *x*[i617][i618];
        }
      }
    }
  }
  !int* #E595#;
  #E595# = GC_malloc(1000, sizeof(int) );
  int i619;
  for(i619 = 0; i619 < 1000; i619++) {
    #E595#[i619] = #result#[0][i619];
  }
  #E595#[1] = 0;
  #result#[0] = (int*) GC( *#E595#* );
  #result#[1] = (int*) GC( *#res599#* );
  GC_free(#res599#);
  return *#result#*;
}

!int** pvs_update_d593(!int** #x#) {
  !int* #res606#;
  #res606# = GC_malloc(1000, sizeof(int) );
  int i607;
  for(i607 = 0; i607 < 1000; i607++) {
    #res606#[i607] = i607;
  }
  !int* #E602#;
  #E602# = GC_malloc(1000, sizeof(int) );
  int i621;
  for(i621 = 0; i621 < 1000; i621++) {
    #E602#[i621] = #x#[0][i621];
  }
  #E602#[1] = 0;
  #x#[0] = (int*) GC( *#E602#* );
  #x#[1] = (int*) GC( *#res606#* );
  GC_free(#res606#);
  return *#x#*;
}