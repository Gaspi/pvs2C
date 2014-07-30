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


int* pvs_id1816(int* A) {
  return A;
}

int* pvs_id_d1817(int* A) {
  return A;
}

int* pvs_zero1820(int* A) {
  int* result;
  if ( GC_count( A ) == 1 )
    result = A;
  else {
    result = GC_malloc(1000, sizeof(int) );
    int i1910;
    for(i1910 = 0; i1910 < 1000; i1910++) {
      result[i1910] = A[i1910];
    }
  }
  result[0] = 0;
  int L1822;
  int res1823;
  return result;
}

int* pvs_zero_d1821(int* A) {
  A[0] = 0;
  int res1825;
  int L1824;
  int* result;
  return A;
}

int* pvs_f1838(int* A) {
  int* B;
  B = (int*) pvs_id1816( A );
  int res1841;
  res1841 = B[0];
  int* result;
  if ( GC_count( B ) == 1 )
    result = B;
  else {
    result = GC_malloc(1000, sizeof(int) );
    int i1911;
    for(i1911 = 0; i1911 < 1000; i1911++) {
      result[i1911] = B[i1911];
    }
  }
  result[0] = res1841;
  int L1840;
  return result;
}

int* pvs_f_d1839(int* A) {
  int* B;
  B = (int*) pvs_id_d1817( A );
  int res1843;
  res1843 = B[0];
  B[0] = res1843;
  int* result;
  int L1842;
  return B;
}

int* pvs_g1858(int* A) {
  int* B;
  B = (int*) pvs_zero1820( A );
  int res1861;
  res1861 = B[0];
  B[0] = res1861;
  int* result;
  int L1860;
  return B;
}

int* pvs_g_d1859(int* A) {
  int* B;
  B = (int*) pvs_zero_d1821( A );
  int res1863;
  res1863 = B[0];
  B[0] = res1863;
  int* result;
  int L1862;
  return B;
}

int* pvs_h1873(int* A) {
  int* B;
  B = (int*) pvs_zero1820( GC( A ) );
  int res1876;
  res1876 = B[0];
  int* result;
  if ( GC_count( A ) == 1 )
    result = A;
  else {
    result = GC_malloc(1000, sizeof(int) );
    int i1912;
    for(i1912 = 0; i1912 < 1000; i1912++) {
      result[i1912] = A[i1912];
    }
  }
  result[0] = res1876;
  int L1875;
  return result;
}

int* pvs_h_d1874(int* A) {
  int* B;
  B = (int*) pvs_zero1820( GC( A ) );
  int res1878;
  res1878 = B[0];
  A[0] = res1878;
  int L1877;
  int* result;
  return A;
}

int* pvs_i1892(int* A) {
  int* B;
  B = (int*) pvs_id1816( GC( A ) );
  int res1895;
  res1895 = B[0];
  int* result;
  if ( GC_count( A ) == 1 )
    result = A;
  else {
    result = GC_malloc(1000, sizeof(int) );
    int i1913;
    for(i1913 = 0; i1913 < 1000; i1913++) {
      result[i1913] = A[i1913];
    }
  }
  result[0] = res1895;
  int L1894;
  return result;
}

int* pvs_i_d1893(int* A) {
  int* B;
  B = (int*) pvs_id1816( GC( A ) );
  int res1897;
  res1897 = B[0];
  int* result;
  if ( GC_count( A ) == 1 )
    result = A;
  else {
    result = GC_malloc(1000, sizeof(int) );
    int i1914;
    for(i1914 = 0; i1914 < 1000; i1914++) {
      result[i1914] = A[i1914];
    }
  }
  result[0] = res1897;
  int L1896;
  return result;
}