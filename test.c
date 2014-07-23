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


void pvs_f626(int a, int b) {
  mpz_set_si(result, (long) (a + b));
}

void pvs_f_d627(int a, int b) {
  mpz_set_si(result, (long) (a + b));
}

void pvs_g628(int a) {
  pvs_f626(result, a, a);
}

void pvs_g_d629(int a) {
  pvs_f626(result, a, a);
}

int pvs_b630() {
  int result;
  result = 1;
  return result;
}

int pvs_b_d631() {
  int result;
  result = 1;
  return result;
}

int pvs_bar632(mpz_t n) {
  int if638;
  mpz_t conv634;
  mpz_set_si(conv634, (long) 6);
  mpz_t conv635;
  mpz_set_si(conv635, (long) 12);
  if (((mpz_cmp(mpz_add_ui(if638, n, (unsigned long) 3), conv634) > 0) && (mpz_cmp(n, conv635) < 0))) {
    mpz_t conv636;
    mpz_set_si(conv636, (long) 6);
    if638 = (mpz_cmp(if638, n, conv636) == 0);
    mpz_clear(conv636);
  } else {
    mpz_t conv637;
    mpz_set_si(conv637, (long) 5);
    if638 = (mpz_cmp(n, conv637) < 0);
    mpz_clear(conv637);
  }
  mpz_clear(conv634);
  mpz_clear(conv635);
  int result;
  result = if638;
  return result;
}

int pvs_bar_d633(mpz_t n) {
  int if643;
  mpz_t conv639;
  mpz_set_si(conv639, (long) 6);
  mpz_t conv640;
  mpz_set_si(conv640, (long) 12);
  if (((mpz_cmp(mpz_add_ui(if643, n, (unsigned long) 3), conv639) > 0) && (mpz_cmp(n, conv640) < 0))) {
    mpz_t conv641;
    mpz_set_si(conv641, (long) 6);
    if643 = (mpz_cmp(if643, n, conv641) == 0);
    mpz_clear(conv641);
  } else {
    mpz_t conv642;
    mpz_set_si(conv642, (long) 5);
    if643 = (mpz_cmp(n, conv642) < 0);
    mpz_clear(conv642);
  }
  mpz_clear(conv639);
  mpz_clear(conv640);
  int result;
  result = if643;
  return result;
}

void pvs_adda644(mpz_t i) {
  mpz_t c;
  mpz_init(c);
  mpz_set_si(c, (long) 3);
  mpz_set(result, c);
  mpz_clear(c);
}

void pvs_adda_d645(mpz_t i) {
  mpz_t c;
  mpz_init(c);
  mpz_set_si(c, (long) 3);
  mpz_set(result, c);
  mpz_clear(c);
}

void pvs_foo646(mpz_t x) {
  mpz_t if649;
  mpz_init(if649);
  mpz_t conv648;
  mpz_set_si(conv648, (long) 0);
  if ((mpz_cmp(if649, x, conv648) == 0)) {
    mpz_set_si(if649, (long) 1);
  } else {
    mpz_set(if649, mpz_add_ui(if649, x, (unsigned long) 3));
  }
  mpz_clear(conv648);
  mpz_set(result, mpz_add_ui(~a, if649, (unsigned long) 1));
  mpz_clear(if649);
}

void pvs_foo_d647(mpz_t x) {
  mpz_t if651;
  mpz_init(if651);
  mpz_t conv650;
  mpz_set_si(conv650, (long) 0);
  if ((mpz_cmp(if651, x, conv650) == 0)) {
    mpz_set_si(if651, (long) 1);
  } else {
    mpz_set(if651, mpz_add_ui(if651, x, (unsigned long) 3));
  }
  mpz_clear(conv650);
  mpz_set(result, mpz_add_ui(~a, if651, (unsigned long) 1));
  mpz_clear(if651);
}

void pvs_add2652(mpz_t a) {
  mpz_t if655;
  mpz_init(if655);
  mpz_t conv654;
  mpz_set_si(conv654, (long) 1);
  if ((mpz_cmp(if655, a, conv654) == 0)) {
    mpz_set_si(if655, (long) 1);
  } else {
    mpz_set_si(if655, (long) 0);
  }
  mpz_clear(conv654);
  mpz_t c;
  mpz_init(c);
  mpz_set(c, mpz_add(~a, a, if655));
  mpz_clear(if655);
  mpz_t d;
  mpz_init(d);
  mpz_set_si(d, (long) 2);
  mpz_set(result, mpz_add_ui(~a, mpz_add(~a, c, d), (unsigned long) 1));
  mpz_clear(c);
  mpz_clear(d);
}

void pvs_add2_d653(mpz_t a) {
  mpz_t if657;
  mpz_init(if657);
  mpz_t conv656;
  mpz_set_si(conv656, (long) 1);
  if ((mpz_cmp(if657, a, conv656) == 0)) {
    mpz_set_si(if657, (long) 1);
  } else {
    mpz_set_si(if657, (long) 0);
  }
  mpz_clear(conv656);
  mpz_t c;
  mpz_init(c);
  mpz_set(c, mpz_add(~a, a, if657));
  mpz_clear(if657);
  mpz_t d;
  mpz_init(d);
  mpz_set_si(d, (long) 2);
  mpz_set(result, mpz_add_ui(~a, mpz_add(~a, c, d), (unsigned long) 1));
  mpz_clear(c);
  mpz_clear(d);
}

void pvs_f658(mpz_t x) {
  mpz_t y;
  mpz_init(y);
  mpz_set_si(y, (long) 12);
  mpz_set(result, mpz_add_ui(~a, y, (unsigned long) 2));
  mpz_clear(y);
}

void pvs_f_d659(mpz_t x) {
  mpz_t y;
  mpz_init(y);
  mpz_set_si(y, (long) 12);
  mpz_set(result, mpz_add_ui(~a, y, (unsigned long) 2));
  mpz_clear(y);
}

void pvs_factorial660(mpz_t n) {
  mpz_t conv662;
  mpz_set_si(conv662, (long) 0);
  if ((mpz_cmp(result, n, conv662) == 0)) {
    mpz_set_si(result, (long) 1);
  } else {
    mpz_t aux663;
    mpz_init(aux663);
    pvs_factorial660(aux663, mpz_sub_ui(aux663, n, (unsigned long) 1));
    mpz_set(result, mpz_mul(result, n, aux663));
    mpz_clear(aux663);
  }
  mpz_clear(conv662);
}

void pvs_factorial_d661(mpz_t n) {
  mpz_t conv664;
  mpz_set_si(conv664, (long) 0);
  if ((mpz_cmp(result, n, conv664) == 0)) {
    mpz_set_si(result, (long) 1);
  } else {
    mpz_t aux665;
    mpz_init(aux665);
    pvs_factorial660(aux665, mpz_sub_ui(aux665, n, (unsigned long) 1));
    mpz_set(result, mpz_mul(result, n, aux665));
    mpz_clear(aux665);
  }
  mpz_clear(conv664);
}