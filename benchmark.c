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


uli* pvs_init7259(uli* A, int i, uli v) {
  uli* result;
  uli* B;
  if ( GC_count( A ) == 1 )
    B = A;
  else {
    B = GC_malloc(1000, sizeof(uli) );
    int i7435;
    for(i7435 = 0; i7435 < 1000; i7435++) {
      B[i7435] = A[i7435];
    }
  }
  B[i] = v;
  if ((i >= 999)) {
    return B;
  } else {
    return pvs_init_d7260( B , (i + 1) , ((12345 * v) % 59557) );
  }
}

uli* pvs_init_d7260(uli* A, int i, uli v) {
  uli* result;
  A[i] = v;
  if ((i >= 999)) {
    return A;
  } else {
    return pvs_init_d7260( A , (i + 1) , ((12345 * v) % 59557) );
  }
}

uli pvs_J7285(int k) {
  return (uli) (999 - k);
}

uli pvs_J_d7286(int k) {
  return (uli) (999 - k);
}

uli pvs_Z7287(int x) {
  return (uli) 0;
}

uli pvs_Z_d7288(int x) {
  return (uli) 0;
}

uli* pvs_T7289() {
  uli* aux7292;
  aux7292 = GC_malloc(1000, sizeof(uli) );
  int i7291;
  for(i7291 = 0; i7291 < 1000; i7291++) {
    aux7292[i7291] = pvs_Z_d7288( i7291 );
  }
  return pvs_init_d7260( aux7292 , 0 , (uli) 9876 );
}

uli* pvs_T_d7290() {
  uli* aux7294;
  aux7294 = GC_malloc(1000, sizeof(uli) );
  int i7293;
  for(i7293 = 0; i7293 < 1000; i7293++) {
    aux7294[i7293] = pvs_Z_d7288( i7293 );
  }
  return pvs_init_d7260( aux7294 , 0 , (uli) 9876 );
}

uli* pvs_insert7297(uli* A, uli v, int i) {
  uli* result;
  if (((i == 0) || (v >= A[(i - 1)]))) {
    if ( GC_count( A ) == 1 )
      result = A;
    else {
      result = GC_malloc(1000, sizeof(uli) );
      int i7436;
      for(i7436 = 0; i7436 < 1000; i7436++) {
        result[i7436] = A[i7436];
      }
    }
    result[i] = v;
    return result;
  } else {
    uli* aux7303;
    uli res7302;
    res7302 = A[(i - 1)];
    if ( GC_count( A ) == 1 )
      aux7303 = A;
    else {
      aux7303 = GC_malloc(1000, sizeof(uli) );
      int i7437;
      for(i7437 = 0; i7437 < 1000; i7437++) {
        aux7303[i7437] = A[i7437];
      }
    }
    aux7303[i] = res7302;
    return pvs_insert_d7298( aux7303 , v , (i - 1) );
  }
}

uli* pvs_insert_d7298(uli* A, uli v, int i) {
  uli* result;
  if (((i == 0) || (v >= A[(i - 1)]))) {
    A[i] = v;
    return A;
  } else {
    uli res7307;
    res7307 = A[(i - 1)];
    A[i] = res7307;
    return pvs_insert_d7298( A , v , (i - 1) );
  }
}

uli* pvs_insort_rec7391(uli* A, int n) {
  uli* result;
  if ((n < 1000)) {
    result = (uli*) pvs_insort_rec_d7392( pvs_insert7297( GC( A ) , A[n] , n ) , (n + 1) );
    GC_free(A);
    return result;
  } else {
    return A;
  }
}

uli* pvs_insort_rec_d7392(uli* A, int n) {
  uli* result;
  if ((n < 1000)) {
    result = (uli*) pvs_insort_rec_d7392( pvs_insert7297( GC( A ) , A[n] , n ) , (n + 1) );
    GC_free(A);
    return result;
  } else {
    return A;
  }
}

uli* pvs_insort7421(uli* A) {
  return pvs_insort_rec7391( A , 0 );
}

uli* pvs_insort_d7422(uli* A) {
  return pvs_insort_rec_d7392( A , 0 );
}

uli pvs_tsort7425() {
  return pvs_insort_d7422( pvs_T_d7290() )[0];
}

uli pvs_tsort_d7426() {
  return pvs_insort_d7422( pvs_T_d7290() )[0];
}

uli pvs_jsort7427() {
  uli* aux7430;
  aux7430 = GC_malloc(1000, sizeof(uli) );
  int i7429;
  for(i7429 = 0; i7429 < 1000; i7429++) {
    aux7430[i7429] = pvs_J_d7286( i7429 );
  }
  return pvs_insort_d7422( aux7430 )[0];
}

uli pvs_jsort_d7428() {
  uli* aux7432;
  aux7432 = GC_malloc(1000, sizeof(uli) );
  int i7431;
  for(i7431 = 0; i7431 < 1000; i7431++) {
    aux7432[i7431] = pvs_J_d7286( i7431 );
  }
  return pvs_insort_d7422( aux7432 )[0];
}