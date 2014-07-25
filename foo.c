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


int* pvs_id981(int* #A#) {
  return *#A#*;
}

!int* pvs_id_d982(!int* #A#) {
  return *#A#*;
}

!int* pvs_zero983(int* A) {
  !int* #result#;
  if ( GC_count( *A* ) == 1 )
    #result# = GC( *A* );
  else {
    #result# = GC_malloc(1000, sizeof(int) );
    int i1013;
    for(i1013 = 0; i1013 < 1000; i1013++) {
      #result#[i1013] = *A*[i1013];
    }
  }
  #result#[0] = 0;
  return *#result#*;
}

!int* pvs_zero_d984(!int* #A#) {
  #A#[0] = 0;
  return *#A#*;
}

!int* pvs_f989(int* A) {
  !int* #result#;
  int* B;
  B = (int*) GC( pvs_id981(*A*) );
  int res992;
  res992 = B[*0*];
  if ( GC_count( *B* ) == 1 )
    #result# = GC( *B* );
  else {
    #result# = GC_malloc(1000, sizeof(int) );
    int i1014;
    for(i1014 = 0; i1014 < 1000; i1014++) {
      #result#[i1014] = *B*[i1014];
    }
  }
  #result#[0] = res992;
  return *#result#*;
}

!int* pvs_f_d990(!int* #A#) {
  !int* #B#;
  #B# = (int*) GC( pvs_id_d982(*#A#*) );
  int res994;
  res994 = #B#[*0*];
  #B#[0] = res994;
  return *#B#*;
}

!int* pvs_g995(int* A) {
  !int* #B#;
  #B# = (int*) GC( pvs_zero983(*A*) );
  int res998;
  res998 = #B#[*0*];
  #B#[0] = res998;
  return *#B#*;
}

!int* pvs_g_d996(!int* #A#) {
  !int* #B#;
  #B# = (int*) GC( pvs_zero_d984(*#A#*) );
  int res1000;
  res1000 = #B#[*0*];
  #B#[0] = res1000;
  return *#B#*;
}

!int* pvs_h1001(int* A) {
  !int* #result#;
  int* B;
  B = (int*) GC( pvs_zero983(A) );
  int res1004;
  res1004 = *B*[*0*];
  if ( GC_count( *A* ) == 1 )
    #result# = GC( *A* );
  else {
    #result# = GC_malloc(1000, sizeof(int) );
    int i1015;
    for(i1015 = 0; i1015 < 1000; i1015++) {
      #result#[i1015] = *A*[i1015];
    }
  }
  #result#[0] = res1004;
  return *#result#*;
}

!int* pvs_h_d1002(!int* #A#) {
  int* B;
  B = (int*) GC( pvs_zero983(#A#) );
  int res1006;
  res1006 = *B*[*0*];
  #A#[0] = res1006;
  return *#A#*;
}

!int* pvs_i1007(int* A) {
  !int* #result#;
  int* B;
  B = (int*) GC( pvs_id981(A) );
  int res1010;
  res1010 = *B*[*0*];
  if ( GC_count( *A* ) == 1 )
    #result# = GC( *A* );
  else {
    #result# = GC_malloc(1000, sizeof(int) );
    int i1016;
    for(i1016 = 0; i1016 < 1000; i1016++) {
      #result#[i1016] = *A*[i1016];
    }
  }
  #result#[0] = res1010;
  return *#result#*;
}

!int* pvs_i_d1008(int* A) {
  !int* #result#;
  int* B;
  B = (int*) GC( pvs_id981(A) );
  int res1012;
  res1012 = *B*[*0*];
  if ( GC_count( *A* ) == 1 )
    #result# = GC( *A* );
  else {
    #result# = GC_malloc(1000, sizeof(int) );
    int i1017;
    for(i1017 = 0; i1017 < 1000; i1017++) {
      #result#[i1017] = *A*[i1017];
    }
  }
  #result#[0] = res1012;
  return *#result#*;
}