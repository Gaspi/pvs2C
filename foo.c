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


int* pvs_id1699(int* #A#) {
  return *#A#*;
}

!int* pvs_id_d1700(!int* #A#) {
  return *#A#*;
}

!int* pvs_zero1703(int* A) {
  !int* #result#;
  if ( GC_count( *A* ) == 1 )
    #result# = *A*;
  else {
    #result# = GC_malloc(1000, sizeof(int) );
    int i1843;
    for(i1843 = 0; i1843 < 1000; i1843++) {
      #result#[i1843] = *A*[i1843];
    }
  }
  #result#[0] = 0;
  GC_free(A);
  return *#result#*;
}

!int* pvs_zero_d1704(!int* #A#) {
  #A#[0] = 0;
  return *#A#*;
}

!int* pvs_f1729(int* A) {
  !int* #result#;
  int* B;
  B = (int*) pvs_id1699( *A* );
  int res1732;
  res1732 = B[*0*];
  if ( GC_count( *B* ) == 1 )
    #result# = *B*;
  else {
    #result# = GC_malloc(1000, sizeof(int) );
    int i1845;
    for(i1845 = 0; i1845 < 1000; i1845++) {
      #result#[i1845] = *B*[i1845];
    }
  }
  #result#[0] = res1732;
  GC_free(A);
  return *#result#*;
}

!int* pvs_f_d1730(!int* #A#) {
  !int* #B#;
  #B# = (int*) pvs_id_d1700( *#A#* );
  int res1734;
  res1734 = #B#[*0*];
  #B#[0] = res1734;
  GC_free(#A#);
  return *#B#*;
}

!int* pvs_g1761(int* A) {
  !int* #B#;
  #B# = (int*) pvs_zero1703( *A* );
  int res1764;
  res1764 = #B#[*0*];
  #B#[0] = res1764;
  GC_free(A);
  return *#B#*;
}

!int* pvs_g_d1762(!int* #A#) {
  !int* #B#;
  #B# = (int*) pvs_zero_d1704( *#A#* );
  int res1766;
  res1766 = #B#[*0*];
  #B#[0] = res1766;
  GC_free(#A#);
  return *#B#*;
}

!int* pvs_h1789(int* A) {
  !int* #result#;
  int* B;
  B = (int*) pvs_zero1703( GC( A ) );
  int res1792;
  res1792 = *B*[*0*];
  if ( GC_count( *A* ) == 1 )
    #result# = *A*;
  else {
    #result# = GC_malloc(1000, sizeof(int) );
    int i1850;
    for(i1850 = 0; i1850 < 1000; i1850++) {
      #result#[i1850] = *A*[i1850];
    }
  }
  #result#[0] = res1792;
  GC_free(A);
  return *#result#*;
}

!int* pvs_h_d1790(!int* #A#) {
  int* B;
  B = (int*) pvs_zero1703( GC( #A# ) );
  int res1794;
  res1794 = *B*[*0*];
  #A#[0] = res1794;
  return *#A#*;
}

!int* pvs_i1817(int* A) {
  !int* #result#;
  int* B;
  B = (int*) pvs_id1699( GC( A ) );
  int res1820;
  res1820 = *B*[*0*];
  if ( GC_count( *A* ) == 1 )
    #result# = *A*;
  else {
    #result# = GC_malloc(1000, sizeof(int) );
    int i1852;
    for(i1852 = 0; i1852 < 1000; i1852++) {
      #result#[i1852] = *A*[i1852];
    }
  }
  #result#[0] = res1820;
  GC_free(A);
  return *#result#*;
}

!int* pvs_i_d1818(int* A) {
  !int* #result#;
  int* B;
  B = (int*) pvs_id1699( GC( A ) );
  int res1822;
  res1822 = *B*[*0*];
  if ( GC_count( *A* ) == 1 )
    #result# = *A*;
  else {
    #result# = GC_malloc(1000, sizeof(int) );
    int i1854;
    for(i1854 = 0; i1854 < 1000; i1854++) {
      #result#[i1854] = *A*[i1854];
    }
  }
  #result#[0] = res1822;
  GC_free(A);
  return *#result#*;
}