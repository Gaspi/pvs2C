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


uli* pvs_init1635(uli* A, int i, uli v) {
  uli* B;
  if ( GC_count( A ) == 1 )
    B = A;
  else {
    B = GC_malloc(1000, sizeof(uli) );
    int i1811;
    for(i1811 = 0; i1811 < 1000; i1811++) {
      B[i1811] = A[i1811];
    }
  }
  B[i] = v;
  if ((i >= 999)) {
    return B;
  } else {
    return pvs_init_d1636( B , (i + 1) , ((12345 * v) % 59557) );
  }
}

uli* pvs_init_d1636(uli* A, int i, uli v) {
  A[i] = v;
  if ((i >= 999)) {
    return A;
  } else {
    return pvs_init_d1636( A , (i + 1) , ((12345 * v) % 59557) );
  }
}

uli pvs_J1661(int k) {
  return (uli) (999 - k);
}

uli pvs_J_d1662(int k) {
  return (uli) (999 - k);
}

uli pvs_Z1663(int x) {
  return (uli) 0;
}

uli pvs_Z_d1664(int x) {
  return (uli) 0;
}

uli* pvs_T1665() {
  uli* aux1668;
  aux1668 = GC_malloc(1000, sizeof(uli) );
  int i1667;
  for(i1667 = 0; i1667 < 1000; i1667++) {
    aux1668[i1667] = pvs_Z_d1664( i1667 );
  }
  return pvs_init_d1636( aux1668 , 0 , (uli) 9876 );
}

uli* pvs_T_d1666() {
  uli* aux1670;
  aux1670 = GC_malloc(1000, sizeof(uli) );
  int i1669;
  for(i1669 = 0; i1669 < 1000; i1669++) {
    aux1670[i1669] = pvs_Z_d1664( i1669 );
  }
  return pvs_init_d1636( aux1670 , 0 , (uli) 9876 );
}

uli* pvs_insert1673(uli* A, uli v, int i) {
  uli* result;
  if (((i == 0) || (v >= A[(i - 1)]))) {
    if ( GC_count( A ) == 1 )
      result = A;
    else {
      result = GC_malloc(1000, sizeof(uli) );
      int i1812;
      for(i1812 = 0; i1812 < 1000; i1812++) {
        result[i1812] = A[i1812];
      }
    }
    result[i] = v;
    uli res1676;
    int L1675;
    return result;
  } else {
    uli res1678;
    res1678 = A[(i - 1)];
    uli* aux1679;
    if ( GC_count( A ) == 1 )
      aux1679 = A;
    else {
      aux1679 = GC_malloc(1000, sizeof(uli) );
      int i1813;
      for(i1813 = 0; i1813 < 1000; i1813++) {
        aux1679[i1813] = A[i1813];
      }
    }
    aux1679[i] = res1678;
    int L1677;
    return pvs_insert_d1674( aux1679 , v , (i - 1) );
  }
}

uli* pvs_insert_d1674(uli* A, uli v, int i) {
  if (((i == 0) || (v >= A[(i - 1)]))) {
    A[i] = v;
    int L1680;
    uli res1681;
    return A;
  } else {
    uli res1683;
    res1683 = A[(i - 1)];
    A[i] = res1683;
    int L1682;
    uli* aux1684;
    return pvs_insert_d1674( A , v , (i - 1) );
  }
}

uli* pvs_insort_rec1767(uli* A, int n) {
  uli* result;
  if ((n < 1000)) {
    result = (uli*) pvs_insort_rec_d1768( pvs_insert1673( GC( A ) , A[n] , n ) , (n + 1) );
    GC_free(A);
    return result;
  } else {
    return A;
  }
}

uli* pvs_insort_rec_d1768(uli* A, int n) {
  uli* result;
  if ((n < 1000)) {
    result = (uli*) pvs_insort_rec_d1768( pvs_insert1673( GC( A ) , A[n] , n ) , (n + 1) );
    GC_free(A);
    return result;
  } else {
    return A;
  }
}

uli* pvs_insort1797(uli* A) {
  return pvs_insort_rec1767( A , 0 );
}

uli* pvs_insort_d1798(uli* A) {
  return pvs_insort_rec_d1768( A , 0 );
}

uli pvs_tsort1801() {
  return pvs_insort_d1798( pvs_T_d1666() )[0];
}

uli pvs_tsort_d1802() {
  return pvs_insort_d1798( pvs_T_d1666() )[0];
}

uli pvs_jsort1803() {
  uli* aux1806;
  aux1806 = GC_malloc(1000, sizeof(uli) );
  int i1805;
  for(i1805 = 0; i1805 < 1000; i1805++) {
    aux1806[i1805] = pvs_J_d1662( i1805 );
  }
  return pvs_insort_d1798( aux1806 )[0];
}

uli pvs_jsort_d1804() {
  uli* aux1808;
  aux1808 = GC_malloc(1000, sizeof(uli) );
  int i1807;
  for(i1807 = 0; i1807 < 1000; i1807++) {
    aux1808[i1807] = pvs_J_d1662( i1807 );
  }
  return pvs_insort_d1798( aux1808 )[0];
}