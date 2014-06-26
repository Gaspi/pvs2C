// ---------------------------------------------
//        C file generated from draft.pvs
// ---------------------------------------------
//   Make sure to link GMP in compilation:
//      gcc -o draft draft.c -lgmp
//      ./draft
// ---------------------------------------------

#include<stdio.h>
#include<gmp.h>
#include "draft.h"

#define TRUE 1
#define FALSE 0

int main(void) {
  printf("Executing draft ...\n");
  return 0;
}


unsigned long int pvs_a431() {
  unsigned long int result;
  result = (unsigned long) 2;
  return result;
}

unsigned long int pvs_d_a432() {
  unsigned long int result;
  result = (unsigned long) 2;
  return result;
}

int pvs_b433() {
  int result;
  result = (3 + 1);
  return result;
}

int pvs_d_b434() {
  int result;
  result = (3 + 1);
  return result;
}

void pvs_c435(mpz_t result) {
  mpz_t conv438;
  mpz_init(conv438);
  mpz_set_si(conv438, (long) 3);
  mpz_mul_ui(result, conv438, (unsigned long) (1 + 2));
  mpz_clear(conv438);
}

void pvs_d_c436(mpz_t result) {
  mpz_t conv438;
  mpz_init(conv438);
  mpz_set_si(conv438, (long) 3);
  mpz_mul_ui(result, conv438, (unsigned long) (1 + 2));
  mpz_clear(conv438);
}

int pvs_incr439(int x) {
  int result;
  result = (x + 1);
  return result;
}

int pvs_d_incr440(int x) {
  int result;
  result = (x + 1);
  return result;
}

int pvs_zero441(mpz_t x) {
  int result;
  result = 0;
  return result;
}

int pvs_d_zero442(mpz_t x) {
  int result;
  result = 0;
  return result;
}

int pvs_f443(int a, int b) {
  mpz_t aux450;
  mpz_init(aux450);
  mpz_t conv448;
  mpz_init(conv448);
  mpz_set_si(conv448, (long) b);
  mpz_t conv449;
  mpz_init(conv449);
  mpz_set_si(conv449, (long) pvs_d_zero442(conv448));
  mpz_clear(conv448);
  mpz_mul_ui(aux450, conv449, (unsigned long) pvs_d_incr440(a));
  mpz_clear(conv449);
  int result;
  result = ( (int) mpz_get_si(aux450) );
  mpz_clear(aux450);
  return result;
}

int pvs_d_f444(int a, int b) {
  mpz_t aux450;
  mpz_init(aux450);
  mpz_t conv448;
  mpz_init(conv448);
  mpz_set_si(conv448, (long) b);
  mpz_t conv449;
  mpz_init(conv449);
  mpz_set_si(conv449, (long) pvs_d_zero442(conv448));
  mpz_clear(conv448);
  mpz_mul_ui(aux450, conv449, (unsigned long) pvs_d_incr440(a));
  mpz_clear(conv449);
  int result;
  result = ( (int) mpz_get_si(aux450) );
  mpz_clear(aux450);
  return result;
}

int pvs_t451(int x) {
  int result;
  result = x;
  return result;
}

int pvs_d_t452(int x) {
  int result;
  result = x;
  return result;
}

int* pvs_f453(int x) {
  int* result;
  result = GC_malloc( 1000 * sizeof(int) );
  for(int i456 = 0; i456 < 1000; i456++) {
    result[i456] = pvs_d_t452(i456);
  }
  return result;
}

int* pvs_d_f454(int x) {
  int* result;
  result = GC_malloc( 1000 * sizeof(int) );
  for(int i456 = 0; i456 < 1000; i456++) {
    result[i456] = pvs_d_t452(i456);
  }
  return result;
}

int* pvs_update457(int* x) {
  int* result;
  int L466;
  L466 = 0;
  int res467;
  res467 = 0;
  if ( GC_count( x ) == 1 )
    result = x;
  else {
    result = GC_malloc( 1000 * sizeof(int) );
    for(int i465 = 0; i465 < 1000; i465++)
      result[i465] = x[i465];
    }
  }
  result[L466] = res467;
  return result;
}

int* pvs_d_update458(int* x) {
  int* result;
  int L466;
  L466 = 0;
  int res467;
  res467 = 0;
  if ( GC_count( x ) == 1 )
    result = x;
  else {
    result = GC_malloc( 1000 * sizeof(int) );
    for(int i465 = 0; i465 < 1000; i465++)
      result[i465] = x[i465];
    }
  }
  result[L466] = res467;
  return result;
}

int pvs_f468(int x) {
  int if475;
  if((x <= 1)) {
    int if473;
    if(x == 0)) {
      if473 = 0;
    } else {
      if473 = x;
    }
    if475 = if473;
  } else {
    int if474;
    if((x > 10)) {
      if474 = 10;
    } else {
      if474 = (x + 5);
    }
    if475 = if474;
  }
  int result;
  result = if475;
  return result;
}

int pvs_d_f469(int x) {
  int if475;
  if((x <= 1)) {
    int if473;
    if(x == 0)) {
      if473 = 0;
    } else {
      if473 = x;
    }
    if475 = if473;
  } else {
    int if474;
    if((x > 10)) {
      if474 = 10;
    } else {
      if474 = (x + 5);
    }
    if475 = if474;
  }
  int result;
  result = if475;
  return result;
}