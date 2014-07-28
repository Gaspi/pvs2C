// ---------------------------------------------
//        C file generated from foo.pvs
// ---------------------------------------------
//   Make sure to link GC.c and GMP in compilation:
//      gcc -o foo foo.c GC.c -lgmp
//      ./foo
// ---------------------------------------------

#include<stdio.h>
#include<gmp.h>
#include "GC.h"
#include "foo.h"

#define TRUE 1
#define FALSE 0

int main(void) {
  GC.start();
  printf("Executing foo ...\n");
  // Insert code here
  GC.quit();
  return 0;
}


void pvs_fu240(mpz_t result, mpz_t x) {
  mpz_t x#0;
  mpz_init(x#0);
  mpz_set_si(x#0, (long) *2*);
  mpz_set(result, x#0);
  mpz_clear(x#0);
}

void pvs_fu_d241(mpz_t result, mpz_t x) {
  mpz_t x#0;
  mpz_init(x#0);
  mpz_set_si(x#0, (long) *2*);
  mpz_set(result, x#0);
  mpz_clear(x#0);
}

int* pvs_id242(int* #A#) {
  return *#A#*;
}

!int* pvs_id_d243(!int* #A#) {
  return *#A#*;
}

!int* pvs_zero244(int* A) {
  !int* #result#;
  if ( GC_count( *A* ) == 1 )
    #result# = GC( *A* );
  else {
    #result# = GC_malloc(1000, sizeof(int) );
    int i274;
    for(i274 = 0; i274 < 1000; i274++) {
      #result#[i274] = *A*[i274];
    }
  }
  #result#[0] = 0;
  return *#result#*;
}

!int* pvs_zero_d245(!int* #A#) {
  #A#[0] = 0;
  return *#A#*;
}

!int* pvs_f250(int* A) {
  !int* #result#;
  int* B;
  B = (int*) GC( pvs_id242(*A*) );
  int res253;
  res253 = B[*0*];
  if ( GC_count( *B* ) == 1 )
    #result# = GC( *B* );
  else {
    #result# = GC_malloc(1000, sizeof(int) );
    int i275;
    for(i275 = 0; i275 < 1000; i275++) {
      #result#[i275] = *B*[i275];
    }
  }
  #result#[0] = res253;
  return *#result#*;
}

!int* pvs_f_d251(!int* #A#) {
  !int* #B#;
  #B# = (int*) GC( pvs_id_d243(*#A#*) );
  int res255;
  res255 = #B#[*0*];
  #B#[0] = res255;
  return *#B#*;
}

!int* pvs_g256(int* A) {
  !int* #B#;
  #B# = (int*) GC( pvs_zero244(*A*) );
  int res259;
  res259 = #B#[*0*];
  #B#[0] = res259;
  return *#B#*;
}

!int* pvs_g_d257(!int* #A#) {
  !int* #B#;
  #B# = (int*) GC( pvs_zero_d245(*#A#*) );
  int res261;
  res261 = #B#[*0*];
  #B#[0] = res261;
  return *#B#*;
}

!int* pvs_h262(int* A) {
  !int* #result#;
  int* B;
  B = (int*) GC( pvs_zero244(A) );
  int res265;
  res265 = *B*[*0*];
  if ( GC_count( *A* ) == 1 )
    #result# = GC( *A* );
  else {
    #result# = GC_malloc(1000, sizeof(int) );
    int i276;
    for(i276 = 0; i276 < 1000; i276++) {
      #result#[i276] = *A*[i276];
    }
  }
  #result#[0] = res265;
  return *#result#*;
}

!int* pvs_h_d263(!int* #A#) {
  int* B;
  B = (int*) GC( pvs_zero244(#A#) );
  int res267;
  res267 = *B*[*0*];
  #A#[0] = res267;
  return *#A#*;
}

!int* pvs_i268(int* A) {
  !int* #result#;
  int* B;
  B = (int*) GC( pvs_id242(A) );
  int res271;
  res271 = *B*[*0*];
  if ( GC_count( *A* ) == 1 )
    #result# = GC( *A* );
  else {
    #result# = GC_malloc(1000, sizeof(int) );
    int i277;
    for(i277 = 0; i277 < 1000; i277++) {
      #result#[i277] = *A*[i277];
    }
  }
  #result#[0] = res271;
  return *#result#*;
}

!int* pvs_i_d269(int* A) {
  !int* #result#;
  int* B;
  B = (int*) GC( pvs_id242(A) );
  int res273;
  res273 = *B*[*0*];
  if ( GC_count( *A* ) == 1 )
    #result# = GC( *A* );
  else {
    #result# = GC_malloc(1000, sizeof(int) );
    int i278;
    for(i278 = 0; i278 < 1000; i278++) {
      #result#[i278] = *A*[i278];
    }
  }
  #result#[0] = res273;
  return *#result#*;
}