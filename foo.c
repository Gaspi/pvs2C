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
  GC_start();
  printf("Executing foo ...\n");
  // Insert code here
  GC_quit();
  return 0;
}


void pvs_t900(mpz_t result, int* A) {
  int* B;
  B = (int*) GC( A );
  mpz_set_si(result, (long) (*B*[*0*] + *A*[*0*]));
  GC_free(B);
  GC_free(A);
}

void pvs_t_d901(mpz_t result, int* A) {
  int* B;
  B = (int*) GC( A );
  mpz_set_si(result, (long) (*B*[*0*] + *A*[*0*]));
  GC_free(B);
  GC_free(A);
}

int* pvs_id902(int* #A#) {
  return *#A#*;
}

!int* pvs_id_d903(!int* #A#) {
  return *#A#*;
}

!int* pvs_zero904(int* A) {
  !int* #result#;
  if ( GC_count( *A* ) == 1 )
    #result# = GC( *A* );
  else {
    #result# = GC_malloc(1000, sizeof(int) );
    int i938;
    for(i938 = 0; i938 < 1000; i938++) {
      #result#[i938] = *A*[i938];
    }
  }
  #result#[0] = 0;
  GC_free(A);
  return *#result#*;
}

!int* pvs_zero_d905(!int* #A#) {
  #A#[0] = 0;
  return *#A#*;
}

!int* pvs_f910(int* A) {
  !int* #result#;
  int* B;
  B = (int*) pvs_id902( GC(*A*) );
  int res913;
  res913 = B[*0*];
  if ( GC_count( *B* ) == 1 )
    #result# = GC( *B* );
  else {
    #result# = GC_malloc(1000, sizeof(int) );
    int i940;
    for(i940 = 0; i940 < 1000; i940++) {
      #result#[i940] = *B*[i940];
    }
  }
  #result#[0] = res913;
  GC_free(A);
  return *#result#*;
}

!int* pvs_f_d911(!int* #A#) {
  !int* #B#;
  #B# = (int*) pvs_id_d903( GC(*#A#*) );
  int res915;
  res915 = #B#[*0*];
  #B#[0] = res915;
  GC_free(#A#);
  return *#B#*;
}

!int* pvs_g916(int* A) {
  !int* #B#;
  #B# = (int*) pvs_zero904( GC(*A*) );
  int res919;
  res919 = #B#[*0*];
  #B#[0] = res919;
  GC_free(A);
  return *#B#*;
}

!int* pvs_g_d917(!int* #A#) {
  !int* #B#;
  #B# = (int*) pvs_zero_d905( GC(*#A#*) );
  int res921;
  res921 = #B#[*0*];
  #B#[0] = res921;
  GC_free(#A#);
  return *#B#*;
}

!int* pvs_h922(int* A) {
  !int* #result#;
  int* B;
  B = (int*) pvs_zero904( GC(A) );
  int res925;
  res925 = *B*[*0*];
  if ( GC_count( *A* ) == 1 )
    #result# = GC( *A* );
  else {
    #result# = GC_malloc(1000, sizeof(int) );
    int i945;
    for(i945 = 0; i945 < 1000; i945++) {
      #result#[i945] = *A*[i945];
    }
  }
  #result#[0] = res925;
  GC_free(A);
  return *#result#*;
}

!int* pvs_h_d923(!int* #A#) {
  int* B;
  B = (int*) pvs_zero904( GC(#A#) );
  int res927;
  res927 = *B*[*0*];
  #A#[0] = res927;
  return *#A#*;
}

!int* pvs_i928(int* A) {
  !int* #result#;
  int* B;
  B = (int*) pvs_id902( GC(A) );
  int res931;
  res931 = *B*[*0*];
  if ( GC_count( *A* ) == 1 )
    #result# = GC( *A* );
  else {
    #result# = GC_malloc(1000, sizeof(int) );
    int i947;
    for(i947 = 0; i947 < 1000; i947++) {
      #result#[i947] = *A*[i947];
    }
  }
  #result#[0] = res931;
  GC_free(A);
  return *#result#*;
}

!int* pvs_i_d929(int* A) {
  !int* #result#;
  int* B;
  B = (int*) pvs_id902( GC(A) );
  int res933;
  res933 = *B*[*0*];
  if ( GC_count( *A* ) == 1 )
    #result# = GC( *A* );
  else {
    #result# = GC_malloc(1000, sizeof(int) );
    int i949;
    for(i949 = 0; i949 < 1000; i949++) {
      #result#[i949] = *A*[i949];
    }
  }
  #result#[0] = res933;
  GC_free(A);
  return *#result#*;
}