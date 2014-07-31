// ---------------------------------------------
//        C file generated from benchmark.pvs
// ---------------------------------------------
//   Make sure to link GC.c and GMP in compilation:
//      gcc -o benchmark benchmark.c GC.c -lgmp
//      ./benchmark
// ---------------------------------------------

#include<stdio.h>
#include<gmp.h>
#include "GC.h"
#include "benchmark.h"

#define TRUE 1
#define FALSE 0

int main(void) {
  GC_start();
  printf("Executing benchmark ...\n");
  // Insert code here
  GC_quit();
  return 0;
}


uli* pvs_init485(uli* A, int i, uli v) {
  uli* B;
  if ( GC_count( A ) == 1 )
    B = A;
  else {
    B = GC_malloc(1000, sizeof(uli) );
    int i635;
    for(i635 = 0; i635 < 1000; i635++) {
      B[i635] = A[i635];
    }
  }
  B[i] = v;
  if ((i >= 999)) {
    return B;
  } else {
    return pvs_init_d486( B , (i + 1) , ((12345 * v) % 59557) );
  }
}

uli* pvs_init_d486(uli* A, int i, uli v) {
  A[i] = v;
  if ((i >= 999)) {
    return A;
  } else {
    return pvs_init_d486( A , (i + 1) , ((12345 * v) % 59557) );
  }
}

uli pvs_J511(int k) {
  return (uli) (999 - k);
}

uli pvs_J_d512(int k) {
  return (uli) (999 - k);
}

uli pvs_Z513(int x) {
  return (uli) 0;
}

uli pvs_Z_d514(int x) {
  return (uli) 0;
}

uli* pvs_T515() {
  uli* aux518;
  aux518 = GC_malloc(1000, sizeof(uli) );
  int i517;
  for(i517 = 0; i517 < 1000; i517++) {
    aux518[i517] = pvs_Z_d514( i517 );
  }
  return pvs_init_d486( aux518 , 0 , (uli) 9876 );
}

uli* pvs_T_d516() {
  uli* aux520;
  aux520 = GC_malloc(1000, sizeof(uli) );
  int i519;
  for(i519 = 0; i519 < 1000; i519++) {
    aux520[i519] = pvs_Z_d514( i519 );
  }
  return pvs_init_d486( aux520 , 0 , (uli) 9876 );
}

uli* pvs_insert523(uli* A, uli v, int i) {
  uli* result;
  if (((i == 0) || (v >= A[(i - 1)]))) {
    if ( GC_count( A ) == 1 )
      result = A;
    else {
      result = GC_malloc(1000, sizeof(uli) );
      int i636;
      for(i636 = 0; i636 < 1000; i636++) {
        result[i636] = A[i636];
      }
    }
    result[i] = v;
    uli res526;
    int L525;
    return result;
  } else {
    uli res528;
    res528 = A[(i - 1)];
    uli* aux529;
    if ( GC_count( A ) == 1 )
      aux529 = A;
    else {
      aux529 = GC_malloc(1000, sizeof(uli) );
      int i637;
      for(i637 = 0; i637 < 1000; i637++) {
        aux529[i637] = A[i637];
      }
    }
    aux529[i] = res528;
    int L527;
    return pvs_insert_d524( aux529 , v , (i - 1) );
  }
}

uli* pvs_insert_d524(uli* A, uli v, int i) {
  if (((i == 0) || (v >= A[(i - 1)]))) {
    A[i] = v;
    int L530;
    uli res531;
    return A;
  } else {
    uli res533;
    res533 = A[(i - 1)];
    A[i] = res533;
    int L532;
    uli* aux534;
    return pvs_insert_d524( A , v , (i - 1) );
  }
}

uli* pvs_insort_rec617(uli* A, int n) {
  if ((n < 1000)) {
    uli An;
    An = A[n];
    return pvs_insort_rec_d618( pvs_insert523( A , An , n ) , (n + 1) );
  } else {
    return A;
  }
}

uli* pvs_insort_rec_d618(uli* A, int n) {
  if ((n < 1000)) {
    uli An;
    An = A[n];
    return pvs_insort_rec_d618( pvs_insert_d524( A , An , n ) , (n + 1) );
  } else {
    return A;
  }
}

uli* pvs_insort621(uli* A) {
  return pvs_insort_rec617( A , 0 );
}

uli* pvs_insort_d622(uli* A) {
  return pvs_insort_rec_d618( A , 0 );
}

uli pvs_tsort625() {
  return pvs_insort_d622( pvs_T_d516() )[0];
}

uli pvs_tsort_d626() {
  return pvs_insort_d622( pvs_T_d516() )[0];
}

uli pvs_jsort627() {
  uli* aux630;
  aux630 = GC_malloc(1000, sizeof(uli) );
  int i629;
  for(i629 = 0; i629 < 1000; i629++) {
    aux630[i629] = pvs_J_d512( i629 );
  }
  return pvs_insort_d622( aux630 )[0];
}

uli pvs_jsort_d628() {
  uli* aux632;
  aux632 = GC_malloc(1000, sizeof(uli) );
  int i631;
  for(i631 = 0; i631 < 1000; i631++) {
    aux632[i631] = pvs_J_d512( i631 );
  }
  return pvs_insort_d622( aux632 )[0];
}