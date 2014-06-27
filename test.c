// ---------------------------------------------
//        C file generated from test.pvs
// ---------------------------------------------
//   Make sure to link GC.c and GMP in compilation:
//      gcc -o test test.c GC/GC.c -lgmp
//      ./test
// ---------------------------------------------

#include<stdio.h>
#include<gmp.h>
#include"GC.h"
#include "test.h"

#define TRUE 1
#define FALSE 0

int main(void) {
  printf("Executing test ...\n");
  return 0;
}


void pvs_f338(mpz_t result, int a, int b) {
  mpz_set_si(result, (long) (a + b));
}

void pvs_d_f339(mpz_t result, int a, int b) {
  mpz_set_si(result, (long) (a + b));
}

void pvs_g340(mpz_t result, int a) {
  pvs_d_f339(result, a, a);
}

void pvs_d_g341(mpz_t result, int a) {
  pvs_d_f339(result, a, a);
}

int pvs_b342() {
  int result;
  result = TRUE;
  return result;
}

int pvs_d_b343() {
  int result;
  result = TRUE;
  return result;
}

int pvs_bar344(mpz_t n) {
  int if357;
  mpz_t aux352;
  mpz_init(aux352);
  mpz_add_ui(aux352, n, (unsigned long) 3);
  mpz_t conv353;
  mpz_init(conv353);
  mpz_set_si(conv353, (long) 6);
  mpz_t conv354;
  mpz_init(conv354);
  mpz_set_si(conv354, (long) 12);
  if(((mpz_cmp(aux352, conv353) > 0) && (mpz_cmp(n, conv354) < 0))) {
    mpz_t conv355;
    mpz_init(conv355);
    mpz_set_si(conv355, (long) 6);
    if357 = (mpz_cmp(n, conv355) == 0);
    mpz_clear(conv355);
  } else {
    mpz_t conv356;
    mpz_init(conv356);
    mpz_set_si(conv356, (long) 5);
    if357 = (mpz_cmp(n, conv356) < 0);
    mpz_clear(conv356);
  }
  mpz_clear(aux352);
  mpz_clear(conv353);
  mpz_clear(conv354);
  int result;
  result = if357;
  return result;
}

int pvs_d_bar345(mpz_t n) {
  int if357;
  mpz_t aux352;
  mpz_init(aux352);
  mpz_add_ui(aux352, n, (unsigned long) 3);
  mpz_t conv353;
  mpz_init(conv353);
  mpz_set_si(conv353, (long) 6);
  mpz_t conv354;
  mpz_init(conv354);
  mpz_set_si(conv354, (long) 12);
  if(((mpz_cmp(aux352, conv353) > 0) && (mpz_cmp(n, conv354) < 0))) {
    mpz_t conv355;
    mpz_init(conv355);
    mpz_set_si(conv355, (long) 6);
    if357 = (mpz_cmp(n, conv355) == 0);
    mpz_clear(conv355);
  } else {
    mpz_t conv356;
    mpz_init(conv356);
    mpz_set_si(conv356, (long) 5);
    if357 = (mpz_cmp(n, conv356) < 0);
    mpz_clear(conv356);
  }
  mpz_clear(aux352);
  mpz_clear(conv353);
  mpz_clear(conv354);
  int result;
  result = if357;
  return result;
}

void pvs_adda358(mpz_t result, mpz_t i) {
  mpz_t c;
  mpz_init(c);
  mpz_set_si(c, (long) 3);
  mpz_set(result, c);
  mpz_clear(c);
}

void pvs_d_adda359(mpz_t result, mpz_t i) {
  mpz_t c;
  mpz_init(c);
  mpz_set_si(c, (long) 3);
  mpz_set(result, c);
  mpz_clear(c);
}

void pvs_foo360(mpz_t result, mpz_t x) {
  mpz_t if365;
  mpz_init(if365);
  mpz_t conv364;
  mpz_init(conv364);
  mpz_set_si(conv364, (long) 0);
  if((mpz_cmp(x, conv364) == 0)) {
    mpz_set_si(if365, (long) 1);
  } else {
    mpz_add_ui(if365, x, (unsigned long) 3);
  }
  mpz_clear(conv364);
  mpz_add_ui(result, if365, (unsigned long) 1);
  mpz_clear(if365);
}

void pvs_d_foo361(mpz_t result, mpz_t x) {
  mpz_t if365;
  mpz_init(if365);
  mpz_t conv364;
  mpz_init(conv364);
  mpz_set_si(conv364, (long) 0);
  if((mpz_cmp(x, conv364) == 0)) {
    mpz_set_si(if365, (long) 1);
  } else {
    mpz_add_ui(if365, x, (unsigned long) 3);
  }
  mpz_clear(conv364);
  mpz_add_ui(result, if365, (unsigned long) 1);
  mpz_clear(if365);
}

void pvs_add2366(mpz_t result, mpz_t a) {
  mpz_t c;
  mpz_init(c);
  mpz_t if372;
  mpz_init(if372);
  mpz_t conv371;
  mpz_init(conv371);
  mpz_set_si(conv371, (long) 1);
  if((mpz_cmp(a, conv371) == 0)) {
    mpz_set_si(if372, (long) 1);
  } else {
    mpz_set_si(if372, (long) 0);
  }
  mpz_clear(conv371);
  mpz_add(c, a, if372);
  mpz_t d;
  mpz_init(d);
  mpz_set_si(d, (long) 2);
  mpz_t aux373;
  mpz_init(aux373);
  mpz_add(aux373, c, d);
  mpz_add_ui(result, aux373, (unsigned long) 1);
  mpz_clear(aux373);
  mpz_clear(if372);
  mpz_clear(c);
  mpz_clear(d);
}

void pvs_d_add2367(mpz_t result, mpz_t a) {
  mpz_t c;
  mpz_init(c);
  mpz_t if372;
  mpz_init(if372);
  mpz_t conv371;
  mpz_init(conv371);
  mpz_set_si(conv371, (long) 1);
  if((mpz_cmp(a, conv371) == 0)) {
    mpz_set_si(if372, (long) 1);
  } else {
    mpz_set_si(if372, (long) 0);
  }
  mpz_clear(conv371);
  mpz_add(c, a, if372);
  mpz_t d;
  mpz_init(d);
  mpz_set_si(d, (long) 2);
  mpz_t aux373;
  mpz_init(aux373);
  mpz_add(aux373, c, d);
  mpz_add_ui(result, aux373, (unsigned long) 1);
  mpz_clear(aux373);
  mpz_clear(if372);
  mpz_clear(c);
  mpz_clear(d);
}

void pvs_f374(mpz_t result, mpz_t x) {
  mpz_t y;
  mpz_init(y);
  mpz_set_si(y, (long) 12);
  mpz_add_ui(result, y, (unsigned long) 2);
  mpz_clear(y);
}

void pvs_d_f375(mpz_t result, mpz_t x) {
  mpz_t y;
  mpz_init(y);
  mpz_set_si(y, (long) 12);
  mpz_add_ui(result, y, (unsigned long) 2);
  mpz_clear(y);
}

void pvs_factorial376(mpz_t result, mpz_t n) {
  mpz_t conv381;
  mpz_init(conv381);
  mpz_set_si(conv381, (long) 0);
  if((mpz_cmp(n, conv381) == 0)) {
    mpz_set_si(result, (long) 1);
  } else {
    mpz_t aux383;
    mpz_init(aux383);
    mpz_t aux382;
    mpz_init(aux382);
    mpz_sub_ui(aux382, n, (unsigned long) 1);
    pvs_d_factorial377(aux383, aux382);
    mpz_clear(aux382);
    mpz_mul(result, n, aux383);
    mpz_clear(aux383);
  }
  mpz_clear(conv381);
}

void pvs_d_factorial377(mpz_t result, mpz_t n) {
  mpz_t conv381;
  mpz_init(conv381);
  mpz_set_si(conv381, (long) 0);
  if((mpz_cmp(n, conv381) == 0)) {
    mpz_set_si(result, (long) 1);
  } else {
    mpz_t aux383;
    mpz_init(aux383);
    mpz_t aux382;
    mpz_init(aux382);
    mpz_sub_ui(aux382, n, (unsigned long) 1);
    pvs_d_factorial377(aux383, aux382);
    mpz_clear(aux382);
    mpz_mul(result, n, aux383);
    mpz_clear(aux383);
  }
  mpz_clear(conv381);
}