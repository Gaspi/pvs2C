// ---------------------------------------------
//        C file generated from test.pvs
// ---------------------------------------------
//   Make sure to link GC.c and GMP in compilation:
//      gcc -o test test.c GC.c -lgmp
//      ./test
// ---------------------------------------------

#include<stdio.h>
#include<gmp.h>
#include "GC.h"
#include "test.h"

#define TRUE 1
#define FALSE 0

int main(void) {
  printf("Executing test ...\n");
  return 0;
}


void pvs_f371(mpz_t result, int a, int b) {
  mpz_set_si(result, (long) (a + b));
}

void pvs_f_d372(mpz_t result, int a, int b) {
  mpz_set_si(result, (long) (a + b));
}

void pvs_g373(mpz_t result, int a) {
  pvs_f371(result, a, a);
}

void pvs_g_d374(mpz_t result, int a) {
  pvs_f371(result, a, a);
}

int pvs_b375() {
  int result;
  result = 1;
  return result;
}

int pvs_b_d376() {
  int result;
  result = 1;
  return result;
}

int pvs_bar377(mpz_t n) {
  int if383;
  mpz_t conv379;
  mpz_set_si(conv379, (long) 6);
  mpz_t conv380;
  mpz_set_si(conv380, (long) 12);
  if (((mpz_cmp(mpz_add_ui(if383, n, (unsigned long) 3), conv379) > 0) && (mpz_cmp(n, conv380) < 0))) {
    mpz_t conv381;
    mpz_set_si(conv381, (long) 6);
    if383 = (mpz_cmp(if383, n, conv381) == 0);
    mpz_clear(conv381);
  } else {
    mpz_t conv382;
    mpz_set_si(conv382, (long) 5);
    if383 = (mpz_cmp(n, conv382) < 0);
    mpz_clear(conv382);
  }
  mpz_clear(conv379);
  mpz_clear(conv380);
  int result;
  result = if383;
  return result;
}

int pvs_bar_d378(mpz_t n) {
  int if388;
  mpz_t conv384;
  mpz_set_si(conv384, (long) 6);
  mpz_t conv385;
  mpz_set_si(conv385, (long) 12);
  if (((mpz_cmp(mpz_add_ui(if388, n, (unsigned long) 3), conv384) > 0) && (mpz_cmp(n, conv385) < 0))) {
    mpz_t conv386;
    mpz_set_si(conv386, (long) 6);
    if388 = (mpz_cmp(if388, n, conv386) == 0);
    mpz_clear(conv386);
  } else {
    mpz_t conv387;
    mpz_set_si(conv387, (long) 5);
    if388 = (mpz_cmp(n, conv387) < 0);
    mpz_clear(conv387);
  }
  mpz_clear(conv384);
  mpz_clear(conv385);
  int result;
  result = if388;
  return result;
}

void pvs_adda389(mpz_t result, mpz_t i) {
  mpz_t c;
  mpz_init(c);
  mpz_set_si(c, (long) 3);
  mpz_set(result, c);
  mpz_clear(c);
}

void pvs_adda_d390(mpz_t result, mpz_t i) {
  mpz_t c;
  mpz_init(c);
  mpz_set_si(c, (long) 3);
  mpz_set(result, c);
  mpz_clear(c);
}

void pvs_foo391(mpz_t result, mpz_t x) {
  mpz_t if394;
  mpz_init(if394);
  mpz_t conv393;
  mpz_set_si(conv393, (long) 0);
  if ((mpz_cmp(if394, x, conv393) == 0)) {
    mpz_set_si(if394, (long) 1);
  } else {
    mpz_set(if394, mpz_add_ui(if394, x, (unsigned long) 3));
  }
  mpz_clear(conv393);
  mpz_set(result, mpz_add_ui(~a, if394, (unsigned long) 1));
  mpz_clear(if394);
}

void pvs_foo_d392(mpz_t result, mpz_t x) {
  mpz_t if396;
  mpz_init(if396);
  mpz_t conv395;
  mpz_set_si(conv395, (long) 0);
  if ((mpz_cmp(if396, x, conv395) == 0)) {
    mpz_set_si(if396, (long) 1);
  } else {
    mpz_set(if396, mpz_add_ui(if396, x, (unsigned long) 3));
  }
  mpz_clear(conv395);
  mpz_set(result, mpz_add_ui(~a, if396, (unsigned long) 1));
  mpz_clear(if396);
}

void pvs_add2397(mpz_t result, mpz_t a) {
  mpz_t if400;
  mpz_init(if400);
  mpz_t conv399;
  mpz_set_si(conv399, (long) 1);
  if ((mpz_cmp(if400, a, conv399) == 0)) {
    mpz_set_si(if400, (long) 1);
  } else {
    mpz_set_si(if400, (long) 0);
  }
  mpz_clear(conv399);
  mpz_t c;
  mpz_init(c);
  mpz_set(c, mpz_add(~a, a, if400));
  mpz_clear(if400);
  mpz_t d;
  mpz_init(d);
  mpz_set_si(d, (long) 2);
  mpz_set(result, mpz_add_ui(~a, mpz_add(~a, c, d), (unsigned long) 1));
  mpz_clear(c);
  mpz_clear(d);
}

void pvs_add2_d398(mpz_t result, mpz_t a) {
  mpz_t if402;
  mpz_init(if402);
  mpz_t conv401;
  mpz_set_si(conv401, (long) 1);
  if ((mpz_cmp(if402, a, conv401) == 0)) {
    mpz_set_si(if402, (long) 1);
  } else {
    mpz_set_si(if402, (long) 0);
  }
  mpz_clear(conv401);
  mpz_t c;
  mpz_init(c);
  mpz_set(c, mpz_add(~a, a, if402));
  mpz_clear(if402);
  mpz_t d;
  mpz_init(d);
  mpz_set_si(d, (long) 2);
  mpz_set(result, mpz_add_ui(~a, mpz_add(~a, c, d), (unsigned long) 1));
  mpz_clear(c);
  mpz_clear(d);
}

void pvs_f403(mpz_t result, mpz_t x) {
  mpz_t y;
  mpz_init(y);
  mpz_set_si(y, (long) 12);
  mpz_set(result, mpz_add_ui(~a, y, (unsigned long) 2));
  mpz_clear(y);
}

void pvs_f_d404(mpz_t result, mpz_t x) {
  mpz_t y;
  mpz_init(y);
  mpz_set_si(y, (long) 12);
  mpz_set(result, mpz_add_ui(~a, y, (unsigned long) 2));
  mpz_clear(y);
}

void pvs_factorial405(mpz_t result, mpz_t n) {
  mpz_t conv407;
  mpz_set_si(conv407, (long) 0);
  if ((mpz_cmp(result, n, conv407) == 0)) {
    mpz_set_si(result, (long) 1);
  } else {
    mpz_t aux408;
    mpz_init(aux408);
    pvs_factorial405(aux408, mpz_sub_ui(aux408, n, (unsigned long) 1));
    mpz_set(result, mpz_mul(result, n, aux408));
    mpz_clear(aux408);
  }
  mpz_clear(conv407);
}

void pvs_factorial_d406(mpz_t result, mpz_t n) {
  mpz_t conv409;
  mpz_set_si(conv409, (long) 0);
  if ((mpz_cmp(result, n, conv409) == 0)) {
    mpz_set_si(result, (long) 1);
  } else {
    mpz_t aux410;
    mpz_init(aux410);
    pvs_factorial405(aux410, mpz_sub_ui(aux410, n, (unsigned long) 1));
    mpz_set(result, mpz_mul(result, n, aux410));
    mpz_clear(aux410);
  }
  mpz_clear(conv409);
}