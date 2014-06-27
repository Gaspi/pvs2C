// ---------------------------------------------
//        C file generated from draft.pvs
// ---------------------------------------------
//   Make sure to link GC.c and GMP in compilation:
//      gcc -o draft draft.c GC/GC.c -lgmp
//      ./draft
// ---------------------------------------------

#include<stdio.h>
#include<gmp.h>
#include"GC.h"
#include "draft.h"

#define TRUE 1
#define FALSE 0

int main(void) {
  printf("Executing draft ...\n");
  return 0;
}


unsigned long int pvs_a594() {
  unsigned long int result;
  result = (unsigned long) 2;
  return result;
}

unsigned long int pvs_d_a595() {
  unsigned long int result;
  result = (unsigned long) 2;
  return result;
}

int pvs_b596() {
  int result;
  result = (3 + 1);
  return result;
}

int pvs_d_b597() {
  int result;
  result = (3 + 1);
  return result;
}

void pvs_c598(mpz_t result) {
  mpz_set_si(result, (long) (3 * (1 + 2)));
}

void pvs_d_c599(mpz_t result) {
  mpz_set_si(result, (long) (3 * (1 + 2)));
}

int pvs_incr600(int x) {
  int result;
  result = (x + 1);
  return result;
}

int pvs_d_incr601(int x) {
  int result;
  result = (x + 1);
  return result;
}

int pvs_zero602(mpz_t x) {
  int result;
  result = 0;
  return result;
}

int pvs_d_zero603(mpz_t x) {
  int result;
  result = 0;
  return result;
}

int pvs_f604(int a, int b) {
  mpz_t conv607;
  mpz_init(conv607);
  mpz_set_si(conv607, (long) b);
  int result;
  result = (int) (pvs_d_zero603(conv607) * pvs_d_incr601(a));
  mpz_clear(conv607);
  return result;
}

int pvs_d_f605(int a, int b) {
  mpz_t conv607;
  mpz_init(conv607);
  mpz_set_si(conv607, (long) b);
  int result;
  result = (int) (pvs_d_zero603(conv607) * pvs_d_incr601(a));
  mpz_clear(conv607);
  return result;
}

int pvs_f608(int x) {
  int if615;
  if((x <= 1)) {
    int if613;
    if((x == 0)) {
      if613 = 0;
    } else {
      if613 = x;
    }
    if615 = if613;
  } else {
    int if614;
    if((x > 10)) {
      if614 = 10;
    } else {
      if614 = (x + 5);
    }
    if615 = if614;
  }
  int result;
  result = if615;
  return result;
}

int pvs_d_f609(int x) {
  int if615;
  if((x <= 1)) {
    int if613;
    if((x == 0)) {
      if613 = 0;
    } else {
      if613 = x;
    }
    if615 = if613;
  } else {
    int if614;
    if((x > 10)) {
      if614 = 10;
    } else {
      if614 = (x + 5);
    }
    if615 = if614;
  }
  int result;
  result = if615;
  return result;
}

int pvs_t616(int x) {
  int result;
  result = x;
  return result;
}

int pvs_d_t617(int x) {
  int result;
  result = x;
  return result;
}

int* pvs_f618(int x) {
  int* result;
  result = GC_malloc(1000, sizeof(int));
  int i621;
  for(i621 = 0; i621 < 1000; i621++) {
    result[i621] = pvs_d_t617(i621);
  }
  return result;
}

int* pvs_d_f619(int x) {
  int* result;
  result = GC_malloc(1000, sizeof(int));
  int i621;
  for(i621 = 0; i621 < 1000; i621++) {
    result[i621] = pvs_d_t617(i621);
  }
  return result;
}

int* pvs_update622(int* x) {
  int* result;
  int L631;
  L631 = 0;
  int res632;
  res632 = 0;
  if ( GC_count( x ) == 1 )
    result = x;
  else {
    result = GC_malloc(1000, sizeof(int));
    int i630;
    for(i630 = 0; i630 < 1000; i630++) {
      result[i630] = x[i630];
    }
  }
  result[L631] = res632;
  return result;
}

int* pvs_d_update623(int* x) {
  int* result;
  int L631;
  L631 = 0;
  int res632;
  res632 = 0;
  if ( GC_count( x ) == 1 )
    result = x;
  else {
    result = GC_malloc(1000, sizeof(int));
    int i630;
    for(i630 = 0; i630 < 1000; i630++) {
      result[i630] = x[i630];
    }
  }
  result[L631] = res632;
  return result;
}

int* pvs_t2633(int x) {
  mpq_t* set640;
  set640 = GC_malloc(1000, sizeof(mpq_t));
  int i639;
  for(i639 = 0; i639 < 1000; i639++) {
    mpq_init(set640[i639]);
  }
  int i638;
  for(i638 = 0; i638 < 1000; i638++) {
    mpq_set_d(set640[i638], (double) (x + i638) );
    mpq_canonicalize(set640[i638]);
  }
  int* result;
  result = (int*) GC( set640 );
  GC_free(set640);
  return result;
}

int* pvs_d_t2634(int x) {
  mpq_t* set640;
  set640 = GC_malloc(1000, sizeof(mpq_t));
  int i639;
  for(i639 = 0; i639 < 1000; i639++) {
    mpq_init(set640[i639]);
  }
  int i638;
  for(i638 = 0; i638 < 1000; i638++) {
    mpq_set_d(set640[i638], (double) (x + i638) );
    mpq_canonicalize(set640[i638]);
  }
  int* result;
  result = (int*) GC( set640 );
  GC_free(set640);
  return result;
}

int** pvs_update641(int** x) {
  int** result;
  int L666;
  L666 = 1;
  int res667;
  res667 = 0;
  int L664;
  L664 = 0;
  int L669;
  L669 = 1;
  int* res670;
  res670 = GC_malloc(1000, sizeof(int));
  int i671;
  for(i671 = 0; i671 < 1000; i671++) {
    res670[i671] = i671;
  }
  if ( GC_count( x ) == 1 )
    result = x;
  else {
    result = GC_malloc(1000, sizeof(int*));
    int i663;
    for(i663 = 0; i663 < 1000; i663++) {
      result[i663] = (int*) GC( x[i663] );
    }
  }
  int* E665;
  if ( GC_count( result[L664] ) == 1 )
    E665 = result[L664];
  else {
    E665 = GC_malloc(1000, sizeof(int*));
    int i668;
    for(i668 = 0; i668 < 1000; i668++) {
      E665[i668] = (int*) GC( result[L664][i668] );
    }
  }
  E665[L666] = res667;
  result[L669] = (int*) GC( res670 );
  GC_free(res670);
  return result;
}

int** pvs_d_update642(int** x) {
  int** result;
  int L666;
  L666 = 1;
  int res667;
  res667 = 0;
  int L664;
  L664 = 0;
  int L669;
  L669 = 1;
  int* res670;
  res670 = GC_malloc(1000, sizeof(int));
  int i671;
  for(i671 = 0; i671 < 1000; i671++) {
    res670[i671] = i671;
  }
  if ( GC_count( x ) == 1 )
    result = x;
  else {
    result = GC_malloc(1000, sizeof(int*));
    int i663;
    for(i663 = 0; i663 < 1000; i663++) {
      result[i663] = (int*) GC( x[i663] );
    }
  }
  int* E665;
  if ( GC_count( result[L664] ) == 1 )
    E665 = result[L664];
  else {
    E665 = GC_malloc(1000, sizeof(int*));
    int i668;
    for(i668 = 0; i668 < 1000; i668++) {
      E665[i668] = (int*) GC( result[L664][i668] );
    }
  }
  E665[L666] = res667;
  result[L669] = (int*) GC( res670 );
  GC_free(res670);
  return result;
}