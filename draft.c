// ---------------------------------------------
//        C file generated from draft.pvs
// ---------------------------------------------
//   Make sure to link GC.c and GMP in compilation:
//      gcc -o draft draft.c GC.c -lgmp
//      ./draft
// ---------------------------------------------

#include<stdio.h>
#include<gmp.h>
#include "GC.h"
#include "draft.h"

#define TRUE 1
#define FALSE 0

int main(void) {
  printf("Executing draft ...\n");
  return 0;
}


pair1736 pvs_a1734() {
  !pair1736 #result#;
  #result# = GC_malloc(1, sizeof( struct struct_pair1736 ) );
  mpz_init(#result#->y);
  #result#->x = *2*;
  mpz_set_si(#result#->y, (long) *12*);
  return *#result#*;
}

pair1736 pvs_a_d1735() {
  !pair1736 #result#;
  #result# = GC_malloc(1, sizeof( struct struct_pair1736 ) );
  mpz_init(#result#->y);
  #result#->x = *2*;
  mpz_set_si(#result#->y, (long) *12*);
  return *#result#*;
}

int pvs_first1737(pair1736 a) {
  int result;
  result = *a*->x;
  return result;
}

int pvs_first_d1738(pair1736 a) {
  int result;
  result = *a*->x;
  return result;
}

pair1736 pvs_zero1739(pair1736 a) {
  !pair1736 #result#;
  if ( GC_count( *a* ) == 1 )
    #result# = GC( *a* );
  else {
    #result# = GC_malloc(1, sizeof( struct struct_pair1736 ));
    mpz_set(#result#->y, *a*->y);
    #result#->x = *a*->x;
  }
  #result#->x = 0;
  return *#result#*;
}

pair1736 pvs_zero_d1740(!pair1736 #a#) {
  #a#->x = 0;
  return *#a#*;
}

unsigned long int pvs_a1743() {
  unsigned long int result;
  result = (unsigned long) *2*;
  return result;
}

unsigned long int pvs_a_d1744() {
  unsigned long int result;
  result = (unsigned long) *2*;
  return result;
}

int pvs_b1745() {
  int result;
  result = (*3* + *1*);
  return result;
}

int pvs_b_d1746() {
  int result;
  result = (*3* + *1*);
  return result;
}

void pvs_c1747(mpz_t result) {
  mpz_set_si(result, (long) (*3* * (*1* + *2*)));
}

void pvs_c_d1748(mpz_t result) {
  mpz_set_si(result, (long) (*3* * (*1* + *2*)));
}

int pvs_incr1749(int x) {
  int result;
  result = (x + *1*);
  return result;
}

int pvs_incr_d1750(int x) {
  int result;
  result = (x + *1*);
  return result;
}

int pvs_zero1751(mpz_t x) {
  return 0;
}

int pvs_zero_d1752(mpz_t x) {
  return 0;
}

int pvs_f1753(int a, int b) {
  mpz_t conv1755;
  mpz_set_si(conv1755, (long) b);
  int result;
  result = (int) (pvs_zero_d1752(conv1755) * pvs_incr_d1750(a));
  mpz_clear(conv1755);
  return result;
}

int pvs_f_d1754(int a, int b) {
  mpz_t conv1756;
  mpz_set_si(conv1756, (long) b);
  int result;
  result = (int) (pvs_zero_d1752(conv1756) * pvs_incr_d1750(a));
  mpz_clear(conv1756);
  return result;
}

int pvs_f1757(int x) {
  int if1761;
  if (((x <= *1*) && *1*)) {
    int if1759;
    if (((x == *0*) || (x < *0*))) {
      if1759 = *0*;
    } else {
      if1759 = x;
    }
    if1761 = if1759;
  } else {
    int if1760;
    if ((x > *10*)) {
      if1760 = *10*;
    } else {
      if1760 = (x - *5*);
    }
    if1761 = if1760;
  }
  int result;
  result = if1761;
  return result;
}

int pvs_f_d1758(int x) {
  int if1764;
  if (((x <= *1*) && *1*)) {
    int if1762;
    if (((x == *0*) || (x < *0*))) {
      if1762 = *0*;
    } else {
      if1762 = x;
    }
    if1764 = if1762;
  } else {
    int if1763;
    if ((x > *10*)) {
      if1763 = *10*;
    } else {
      if1763 = (x - *5*);
    }
    if1764 = if1763;
  }
  int result;
  result = if1764;
  return result;
}

int pvs_t1765(int x) {
  int result;
  result = x;
  return result;
}

int pvs_t_d1766(int x) {
  int result;
  result = x;
  return result;
}

int* pvs_id21767(int* #t56897#) {
  return *#t56897#*;
}

int* pvs_id2_d1768(!int* #t56897#) {
  return *#t56897#*;
}

int* pvs_f1769(int x) {
  !int* #result#;
  #result# = GC_malloc(1000, sizeof(int) );
  int i1771;
  for(i1771 = 0; i1771 < 1000; i1771++) {
    #result#[i1771] = pvs_t_d1766(i1771);
  }
  return *#result#*;
}

int* pvs_f_d1770(int x) {
  !int* #result#;
  #result# = GC_malloc(1000, sizeof(int) );
  int i1772;
  for(i1772 = 0; i1772 < 1000; i1772++) {
    #result#[i1772] = pvs_t_d1766(i1772);
  }
  return *#result#*;
}

int* pvs_update1773(int* x) {
  !int* #result#;
  if ( GC_count( *x* ) == 1 )
    #result# = GC( *x* );
  else {
    #result# = GC_malloc(1000, sizeof(int) );
    int i1809;
    for(i1809 = 0; i1809 < 1000; i1809++) {
      #result#[i1809] = *x*[i1809];
    }
  }
  #result#[0] = 0;
  return *#result#*;
}

int* pvs_update_d1774(!int* #x#) {
  #x#[0] = 0;
  return *#x#*;
}

int* pvs_t21779(int x) {
  !mpq_t* #set1782#;
  #set1782# = GC_malloc(1000, sizeof(mpq_t) );
  int i1781;
  for(i1781 = 0; i1781 < 1000; i1781++) {
    mpq_init(#set1782#[i1781]);
    mpq_set_d(#set1782#[i1781], (double) (x + i1781) );
    mpq_canonicalize(#set1782#[i1781]);
  }
  int* #result#;
  #result# = (int*) GC( *#set1782#* );
  if( GC_count( #set1782# ) == 1 ) {
    int i1810;
    for(i1810 = 0; i1810 < 1000; i1810++) {
      mpq_clear(#set1782#[i1810]);
    }
  }
  GC_free(#set1782#);
  return *#result#*;
}

int* pvs_t2_d1780(int x) {
  !mpq_t* #set1784#;
  #set1784# = GC_malloc(1000, sizeof(mpq_t) );
  int i1783;
  for(i1783 = 0; i1783 < 1000; i1783++) {
    mpq_init(#set1784#[i1783]);
    mpq_set_d(#set1784#[i1783], (double) (x + i1783) );
    mpq_canonicalize(#set1784#[i1783]);
  }
  int* #result#;
  #result# = (int*) GC( *#set1784#* );
  if( GC_count( #set1784# ) == 1 ) {
    int i1811;
    for(i1811 = 0; i1811 < 1000; i1811++) {
      mpq_clear(#set1784#[i1811]);
    }
  }
  GC_free(#set1784#);
  return *#result#*;
}

int* pvs_id1785(int** #t56897#) {
  int* #result#;
  #result# = (int*) GC( *#t56897#*[*0*] );
  if( GC_count( #t56897# ) == 1 ) {
    int i1812;
    for(i1812 = 0; i1812 < 1000; i1812++) {
      GC_free(#t56897#[i1812]);
    }
  }
  GC_free(#t56897#);
  return *#result#*;
}

int* pvs_id_d1786(int** #t56897#) {
  int* #result#;
  #result# = (int*) GC( *#t56897#*[*0*] );
  if( GC_count( #t56897# ) == 1 ) {
    int i1814;
    for(i1814 = 0; i1814 < 1000; i1814++) {
      GC_free(#t56897#[i1814]);
    }
  }
  GC_free(#t56897#);
  return *#result#*;
}

int* pvs_te1787() {
  !int* #aux1790#;
  #aux1790# = GC_malloc(1000, sizeof(int) );
  int i1789;
  for(i1789 = 0; i1789 < 1000; i1789++) {
    #aux1790#[i1789] = pvs_t_d1766(i1789);
  }
  int* #result#;
  #result# = (int*) GC( pvs_update_d1774(pvs_update_d1774(*#aux1790#*)) );
  GC_free(#aux1790#);
  return *#result#*;
}

int* pvs_te_d1788() {
  !int* #aux1792#;
  #aux1792# = GC_malloc(1000, sizeof(int) );
  int i1791;
  for(i1791 = 0; i1791 < 1000; i1791++) {
    #aux1792#[i1791] = pvs_t_d1766(i1791);
  }
  int* #result#;
  #result# = (int*) GC( pvs_update_d1774(pvs_update_d1774(*#aux1792#*)) );
  GC_free(#aux1792#);
  return *#result#*;
}

int** pvs_update1793(int** x) {
  !int** #result#;
  !int* #res1800#;
  #res1800# = GC_malloc(1000, sizeof(int) );
  int i1801;
  for(i1801 = 0; i1801 < 1000; i1801++) {
    #res1800#[i1801] = i1801;
  }
  if ( GC_count( *x* ) == 1 )
    #result# = GC( *x* );
  else {
    #result# = GC_malloc(1000, sizeof(int*) );
    int i1818;
    for(i1818 = 0; i1818 < 1000; i1818++) {
      if ( GC_count( *x*[i1818] ) == 1 )
        #result#[i1818] = GC( *x*[i1818] );
      else {
        #result#[i1818] = GC_malloc(1000, sizeof(int) );
        int i1819;
        for(i1819 = 0; i1819 < 1000; i1819++) {
          #result#[i1818][i1819] = *x*[i1818][i1819];
        }
      }
    }
  }
  !int* #E1796#;
  #E1796# = GC_malloc(1000, sizeof(int) );
  int i1820;
  for(i1820 = 0; i1820 < 1000; i1820++) {
    #E1796#[i1820] = #result#[0][i1820];
  }
  #E1796#[1] = 0;
  #result#[0] = (int*) GC( *#E1796#* );
  #result#[1] = (int*) GC( *#res1800#* );
  GC_free(#res1800#);
  return *#result#*;
}

int** pvs_update_d1794(!int** #x#) {
  !int* #res1807#;
  #res1807# = GC_malloc(1000, sizeof(int) );
  int i1808;
  for(i1808 = 0; i1808 < 1000; i1808++) {
    #res1807#[i1808] = i1808;
  }
  !int* #E1803#;
  #E1803# = GC_malloc(1000, sizeof(int) );
  int i1822;
  for(i1822 = 0; i1822 < 1000; i1822++) {
    #E1803#[i1822] = #x#[0][i1822];
  }
  #E1803#[1] = 0;
  #x#[0] = (int*) GC( *#E1803#* );
  #x#[1] = (int*) GC( *#res1807#* );
  GC_free(#res1807#);
  return *#x#*;
}