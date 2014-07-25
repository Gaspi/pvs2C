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
  printf("Executing foo ...\n");
  return 0;
}


int* pvs_id166(int* #A#) {
  return *#A#*;
}

!int* pvs_id_d167(!int* #A#) {
  return *#A#*;
}

!int* pvs_zero168(int* A) {
  !int* #result#;
  if ( GC_count( *A* ) == 1 )
    #result# = GC( *A* );
  else {
    #result# = GC_malloc(1000, sizeof(int) );
    int i198;
    for(i198 = 0; i198 < 1000; i198++) {
      #result#[i198] = *A*[i198];
    }
  }
  #result#[0] = 0;
  return *#result#*;
}

!int* pvs_zero_d169(!int* #A#) {
  #A#[0] = 0;
  return *#A#*;
}

!int* pvs_f174(int* A) {
  !int* #result#;
  int* B;
  B = (int*) GC( pvs_id166(A) );
  int res177;
  res177 = *B*[*0*];
  if ( GC_count( *A* ) == 1 )
    #result# = GC( *A* );
  else {
    #result# = GC_malloc(1000, sizeof(int) );
    int i199;
    for(i199 = 0; i199 < 1000; i199++) {
      #result#[i199] = *A*[i199];
    }
  }
  #result#[0] = res177;
  return *#result#*;
}

!int* pvs_f_d175(int* A) {
  !int* #result#;
  int* B;
  B = (int*) GC( pvs_id166(A) );
  int res179;
  res179 = *B*[*0*];
  if ( GC_count( *A* ) == 1 )
    #result# = GC( *A* );
  else {
    #result# = GC_malloc(1000, sizeof(int) );
    int i200;
    for(i200 = 0; i200 < 1000; i200++) {
      #result#[i200] = *A*[i200];
    }
  }
  #result#[0] = res179;
  return *#result#*;
}

!int* pvs_g180(int* A) {
  !int* #result#;
  int* B;
  B = (int*) GC( pvs_zero168(A) );
  int res183;
  res183 = *B*[*0*];
  if ( GC_count( *A* ) == 1 )
    #result# = GC( *A* );
  else {
    #result# = GC_malloc(1000, sizeof(int) );
    int i201;
    for(i201 = 0; i201 < 1000; i201++) {
      #result#[i201] = *A*[i201];
    }
  }
  #result#[0] = res183;
  return *#result#*;
}

!int* pvs_g_d181(!int* #A#) {
  int* B;
  B = (int*) GC( pvs_zero168(#A#) );
  int res185;
  res185 = *B*[*0*];
  #A#[0] = res185;
  return *#A#*;
}

!int* pvs_h186(int* A) {
  !int* #result#;
  int* B;
  B = (int*) GC( pvs_id166(*A*) );
  int res189;
  res189 = B[*0*];
  if ( GC_count( *B* ) == 1 )
    #result# = GC( *B* );
  else {
    #result# = GC_malloc(1000, sizeof(int) );
    int i202;
    for(i202 = 0; i202 < 1000; i202++) {
      #result#[i202] = *B*[i202];
    }
  }
  #result#[0] = res189;
  return *#result#*;
}

!int* pvs_h_d187(!int* #A#) {
  !int* #B#;
  #B# = (int*) GC( pvs_id_d167(*#A#*) );
  int res191;
  res191 = #B#[*0*];
  #B#[0] = res191;
  return *#B#*;
}

!int* pvs_i192(int* A) {
  !int* #B#;
  #B# = (int*) GC( pvs_zero168(*A*) );
  int res195;
  res195 = #B#[*0*];
  #B#[0] = res195;
  return *#B#*;
}

!int* pvs_i_d193(!int* #A#) {
  !int* #B#;
  #B# = (int*) GC( pvs_zero_d169(*#A#*) );
  int res197;
  res197 = #B#[*0*];
  #B#[0] = res197;
  return *#B#*;
}