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


void pvs_adda798(mpz_t result, mpz_t i) {
  mpz_t c;
  mpz_init(c);
  mpz_set_si(c, (long) *3*);
  mpz_set(result, c);
  mpz_clear(c);
}

void pvs_adda_d799(mpz_t result, mpz_t i) {
  mpz_t c;
  mpz_init(c);
  mpz_set_si(c, (long) *3*);
  mpz_set(result, c);
  mpz_clear(c);
}

void pvs_f800(mpz_t result, int a, int b) {
  mpz_set_si(result, (long) (a + b));
}

void pvs_f_d801(mpz_t result, int a, int b) {
  mpz_set_si(result, (long) (a + b));
}

void pvs_incr802(mpz_t result, mpz_t x) {
  mpz_t a;
  mpz_init(a);
  mpz_set(a, x);
  mpz_add_ui(result, a, (unsigned long) *1*);
  mpz_clear(a);
}

void pvs_incr_d803(mpz_t result, mpz_t x) {
  mpz_t a;
  mpz_init(a);
  mpz_set(a, x);
  mpz_add_ui(result, a, (unsigned long) *1*);
  mpz_clear(a);
}

void pvs_norm804(mpz_t result, mpz_t x, mpz_t y) {
  mpz_t aux806;
  mpz_init(aux806);
  mpz_mul(aux806, x, x);
  mpz_t aux807;
  mpz_init(aux807);
  mpz_mul(aux807, y, y);
  mpz_add(result, aux806, aux807);
  mpz_clear(aux806);
  mpz_clear(aux807);
}

void pvs_norm_d805(mpz_t result, mpz_t x, mpz_t y) {
  mpz_t aux808;
  mpz_init(aux808);
  mpz_mul(aux808, x, x);
  mpz_t aux809;
  mpz_init(aux809);
  mpz_mul(aux809, y, y);
  mpz_add(result, aux808, aux809);
  mpz_clear(aux808);
  mpz_clear(aux809);
}

void pvs_g810(mpz_t result, int a) {
  pvs_f_d801(result, a, a);
}

void pvs_g_d811(mpz_t result, int a) {
  pvs_f_d801(result, a, a);
}

int pvs_b812() {
  return 1;
}

int pvs_b_d813() {
  return 1;
}

int pvs_bar814(mpz_t n) {
  int if821;
  mpz_t aux816;
  mpz_init(aux816);
  mpz_add_ui(aux816, n, (unsigned long) *3*);
  mpz_t conv817;
  mpz_set_si(conv817, (long) *6*);
  mpz_t conv818;
  mpz_set_si(conv818, (long) *12*);
  if (((mpz_cmp(aux816, conv817) > 0) && (mpz_cmp(n, conv818) < 0))) {
    mpz_t conv819;
    mpz_set_si(conv819, (long) *6*);
    if821 = (mpz_cmp(n, conv819) == 0);
    mpz_clear(conv819);
  } else {
    mpz_t conv820;
    mpz_set_si(conv820, (long) *5*);
    if821 = (mpz_cmp(n, conv820) < 0);
    mpz_clear(conv820);
  }
  mpz_clear(aux816);
  mpz_clear(conv817);
  mpz_clear(conv818);
  int result;
  result = if821;
  return result;
}

int pvs_bar_d815(mpz_t n) {
  int if827;
  mpz_t aux822;
  mpz_init(aux822);
  mpz_add_ui(aux822, n, (unsigned long) *3*);
  mpz_t conv823;
  mpz_set_si(conv823, (long) *6*);
  mpz_t conv824;
  mpz_set_si(conv824, (long) *12*);
  if (((mpz_cmp(aux822, conv823) > 0) && (mpz_cmp(n, conv824) < 0))) {
    mpz_t conv825;
    mpz_set_si(conv825, (long) *6*);
    if827 = (mpz_cmp(n, conv825) == 0);
    mpz_clear(conv825);
  } else {
    mpz_t conv826;
    mpz_set_si(conv826, (long) *5*);
    if827 = (mpz_cmp(n, conv826) < 0);
    mpz_clear(conv826);
  }
  mpz_clear(aux822);
  mpz_clear(conv823);
  mpz_clear(conv824);
  int result;
  result = if827;
  return result;
}

void pvs_foo828(mpz_t result, mpz_t x) {
  mpz_t if831;
  mpz_init(if831);
  mpz_t conv830;
  mpz_set_si(conv830, (long) *0*);
  if ((mpz_cmp(x, conv830) == 0)) {
    mpz_set_si(if831, (long) *1*);
  } else {
    mpz_add_ui(if831, x, (unsigned long) *3*);
  }
  mpz_clear(conv830);
  mpz_add_ui(result, if831, (unsigned long) *1*);
  mpz_clear(if831);
}

void pvs_foo_d829(mpz_t result, mpz_t x) {
  mpz_t if833;
  mpz_init(if833);
  mpz_t conv832;
  mpz_set_si(conv832, (long) *0*);
  if ((mpz_cmp(x, conv832) == 0)) {
    mpz_set_si(if833, (long) *1*);
  } else {
    mpz_add_ui(if833, x, (unsigned long) *3*);
  }
  mpz_clear(conv832);
  mpz_add_ui(result, if833, (unsigned long) *1*);
  mpz_clear(if833);
}

void pvs_add2834(mpz_t result, mpz_t a) {
  mpz_t c;
  mpz_init(c);
  mpz_t if837;
  mpz_init(if837);
  mpz_t conv836;
  mpz_set_si(conv836, (long) *1*);
  if ((mpz_cmp(a, conv836) == 0)) {
    mpz_set_si(if837, (long) *1*);
  } else {
    mpz_set_si(if837, (long) *0*);
  }
  mpz_clear(conv836);
  mpz_add(c, a, if837);
  mpz_t d;
  mpz_init(d);
  mpz_set_si(d, (long) *2*);
  mpz_t aux838;
  mpz_init(aux838);
  mpz_add(aux838, c, d);
  mpz_add_ui(result, aux838, (unsigned long) *1*);
  mpz_clear(aux838);
  mpz_clear(if837);
  mpz_clear(c);
  mpz_clear(d);
}

void pvs_add2_d835(mpz_t result, mpz_t a) {
  mpz_t c;
  mpz_init(c);
  mpz_t if840;
  mpz_init(if840);
  mpz_t conv839;
  mpz_set_si(conv839, (long) *1*);
  if ((mpz_cmp(a, conv839) == 0)) {
    mpz_set_si(if840, (long) *1*);
  } else {
    mpz_set_si(if840, (long) *0*);
  }
  mpz_clear(conv839);
  mpz_add(c, a, if840);
  mpz_t d;
  mpz_init(d);
  mpz_set_si(d, (long) *2*);
  mpz_t aux841;
  mpz_init(aux841);
  mpz_add(aux841, c, d);
  mpz_add_ui(result, aux841, (unsigned long) *1*);
  mpz_clear(aux841);
  mpz_clear(if840);
  mpz_clear(c);
  mpz_clear(d);
}

void pvs_f842(mpz_t result, mpz_t x) {
  mpz_t y;
  mpz_init(y);
  mpz_set_si(y, (long) *12*);
  mpz_add_ui(result, y, (unsigned long) *2*);
  mpz_clear(y);
}

void pvs_f_d843(mpz_t result, mpz_t x) {
  mpz_t y;
  mpz_init(y);
  mpz_set_si(y, (long) *12*);
  mpz_add_ui(result, y, (unsigned long) *2*);
  mpz_clear(y);
}

void pvs_factorial844(mpz_t result, mpz_t n) {
  mpz_t conv846;
  mpz_set_si(conv846, (long) *0*);
  if ((mpz_cmp(n, conv846) == 0)) {
    mpz_set_si(result, (long) *1*);
  } else {
    mpz_t aux848;
    mpz_init(aux848);
    mpz_t aux847;
    mpz_init(aux847);
    mpz_sub_ui(aux847, n, (unsigned long) *1*);
    pvs_factorial_d845(aux848, aux847);
    mpz_clear(aux847);
    mpz_mul(result, n, aux848);
    mpz_clear(aux848);
  }
  mpz_clear(conv846);
}

void pvs_factorial_d845(mpz_t result, mpz_t n) {
  mpz_t conv849;
  mpz_set_si(conv849, (long) *0*);
  if ((mpz_cmp(n, conv849) == 0)) {
    mpz_set_si(result, (long) *1*);
  } else {
    mpz_t aux851;
    mpz_init(aux851);
    mpz_t aux850;
    mpz_init(aux850);
    mpz_sub_ui(aux850, n, (unsigned long) *1*);
    pvs_factorial_d845(aux851, aux850);
    mpz_clear(aux850);
    mpz_mul(result, n, aux851);
    mpz_clear(aux851);
  }
  mpz_clear(conv849);
}