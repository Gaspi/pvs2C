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


unsigned long int* pvs_init722(unsigned long int* A, int i, unsigned long int v) {
  unsigned long int* B;
  if ( GC_count( A ) == 1 )
    B = A;
  else {
    B = GC_malloc(20000, sizeof(unsigned long int) );
    int i872;
    for(i872 = 0; i872 < 20000; i872++) {
      B[i872] = A[i872];
    }
  }
  B[i] = v;
  if ((i >= 999)) {
    return B;
  } else {
    return pvs_init_d723( B , (i + 1) , ((12345 * v) % 59557) );
  }
}

unsigned long int* pvs_init_d723(unsigned long int* A, int i, unsigned long int v) {
  A[i] = v;
  if ((i >= 999)) {
    return A;
  } else {
    return pvs_init_d723( A , (i + 1) , ((12345 * v) % 59557) );
  }
}

unsigned long int pvs_J748(int k) {
  return (unsigned long int) (999 - k);
}

unsigned long int pvs_J_d749(int k) {
  return (unsigned long int) (999 - k);
}

unsigned long int pvs_Z750(int x) {
  return (unsigned long int) 0;
}

unsigned long int pvs_Z_d751(int x) {
  return (unsigned long int) 0;
}

unsigned long int* pvs_T752() {
  unsigned long int* aux755;
  aux755 = GC_malloc(20000, sizeof(unsigned long int) );
  int i754;
  for(i754 = 0; i754 < 20000; i754++) {
    aux755[i754] = pvs_Z_d751( i754 );
  }
  return pvs_init_d723( aux755 , 0 , (unsigned long int) 9876 );
}

unsigned long int* pvs_T_d753() {
  unsigned long int* aux757;
  aux757 = GC_malloc(20000, sizeof(unsigned long int) );
  int i756;
  for(i756 = 0; i756 < 20000; i756++) {
    aux757[i756] = pvs_Z_d751( i756 );
  }
  return pvs_init_d723( aux757 , 0 , (unsigned long int) 9876 );
}

unsigned long int* pvs_insert760(unsigned long int* A, unsigned long int v, int i) {
  unsigned long int* result;
  if (((i == 0) || (v >= A[(i - 1)]))) {
    if ( GC_count( A ) == 1 )
      result = A;
    else {
      result = GC_malloc(20000, sizeof(unsigned long int) );
      int i873;
      for(i873 = 0; i873 < 20000; i873++) {
        result[i873] = A[i873];
      }
    }
    result[i] = v;
    return result;
  } else {
    unsigned long int res765;
    res765 = A[(i - 1)];
    unsigned long int* aux766;
    if ( GC_count( A ) == 1 )
      aux766 = A;
    else {
      aux766 = GC_malloc(20000, sizeof(unsigned long int) );
      int i874;
      for(i874 = 0; i874 < 20000; i874++) {
        aux766[i874] = A[i874];
      }
    }
    aux766[i] = res765;
    return pvs_insert_d761( aux766 , v , (i - 1) );
  }
}

unsigned long int* pvs_insert_d761(unsigned long int* A, unsigned long int v, int i) {
  if (((i == 0) || (v >= A[(i - 1)]))) {
    A[i] = v;
    return A;
  } else {
    unsigned long int res770;
    res770 = A[(i - 1)];
    A[i] = res770;
    return pvs_insert_d761( A , v , (i - 1) );
  }
}

unsigned long int* pvs_insort_rec854(unsigned long int* A, int n) {
  if ((n < 1000)) {
    unsigned long int An;
    An = A[n];
    return pvs_insort_rec_d855( pvs_insert760( A , An , n ) , (n + 1) );
  } else {
    return A;
  }
}

unsigned long int* pvs_insort_rec_d855(unsigned long int* A, int n) {
  if ((n < 1000)) {
    unsigned long int An;
    An = A[n];
    return pvs_insort_rec_d855( pvs_insert_d761( A , An , n ) , (n + 1) );
  } else {
    return A;
  }
}

unsigned long int* pvs_insort858(unsigned long int* A) {
  return pvs_insort_rec854( A , 0 );
}

unsigned long int* pvs_insort_d859(unsigned long int* A) {
  return pvs_insort_rec_d855( A , 0 );
}

unsigned long int pvs_tsort862() {
  return pvs_insort_d859( pvs_T_d753() )[0];
}

unsigned long int pvs_tsort_d863() {
  return pvs_insort_d859( pvs_T_d753() )[0];
}

unsigned long int pvs_jsort864() {
  unsigned long int* aux867;
  aux867 = GC_malloc(20000, sizeof(unsigned long int) );
  int i866;
  for(i866 = 0; i866 < 20000; i866++) {
    aux867[i866] = pvs_J_d749( i866 );
  }
  return pvs_insort_d859( aux867 )[0];
}

unsigned long int pvs_jsort_d865() {
  unsigned long int* aux869;
  aux869 = GC_malloc(20000, sizeof(unsigned long int) );
  int i868;
  for(i868 = 0; i868 < 20000; i868++) {
    aux869[i868] = pvs_J_d749( i868 );
  }
  return pvs_insort_d859( aux869 )[0];
}