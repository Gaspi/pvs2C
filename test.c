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
  GC.start();
  printf("Executing test ...\n");
  // Insert code here
  GC.quit();
  return 0;
}


void pvs_adda247(mpz_t result, mpz_t i) {
  mpz_t c;
  mpz_init(c);
  mpz_set_si(c, (long) *3*);
  mpz_set(result, c);
  mpz_clear(c);
  mpz_clear(i);
}

void pvs_adda_d248(mpz_t result, mpz_t i) {
  mpz_t c;
  mpz_init(c);
  mpz_set_si(c, (long) *3*);
  mpz_set(result, c);
  mpz_clear(c);
  mpz_clear(i);
}

void pvs_f249(mpz_t result, int a, int b) {
  mpz_set_si(result, (long) (a + b));
}

void pvs_f_d250(mpz_t result, int a, int b) {
  mpz_set_si(result, (long) (a + b));
}

void pvs_incr251(mpz_t result, mpz_t x) {
  mpz_t a;
  mpz_init(a);
  mpz_set(a, x);
  mpz_add_ui(result, a, (unsigned long) *1*);
  mpz_clear(x);
  mpz_clear(a);
}

void pvs_incr_d252(mpz_t result, mpz_t x) {
  mpz_t a;
  mpz_init(a);
  mpz_set(a, x);
  mpz_add_ui(result, a, (unsigned long) *1*);
  mpz_clear(x);
  mpz_clear(a);
}

void pvs_norm253(mpz_t result, mpz_t x, mpz_t y) {
  mpz_t aux255;
  mpz_init(aux255);
  mpz_mul(aux255, x, x);
  mpz_t aux256;
  mpz_init(aux256);
  mpz_mul(aux256, y, y);
  mpz_add(result, aux255, aux256);
  mpz_clear(x);
  mpz_clear(y);
  mpz_clear(aux255);
  mpz_clear(aux256);
}

void pvs_norm_d254(mpz_t result, mpz_t x, mpz_t y) {
  mpz_t aux257;
  mpz_init(aux257);
  mpz_mul(aux257, x, x);
  mpz_t aux258;
  mpz_init(aux258);
  mpz_mul(aux258, y, y);
  mpz_add(result, aux257, aux258);
  mpz_clear(x);
  mpz_clear(y);
  mpz_clear(aux257);
  mpz_clear(aux258);
}

void pvs_g259(mpz_t result, int a) {
  pvs_f_d250(result, a, a);
}

void pvs_g_d260(mpz_t result, int a) {
  pvs_f_d250(result, a, a);
}

int pvs_b261() {
  return 1;
}

int pvs_b_d262() {
  return 1;
}

int pvs_bar263(mpz_t n) {
  int if270;
  mpz_t aux265;
  mpz_init(aux265);
  mpz_add_ui(aux265, n, (unsigned long) *3*);
  mpz_t conv266;
  mpz_set_si(conv266, (long) *6*);
  mpz_t conv267;
  mpz_set_si(conv267, (long) *12*);
  if (((mpz_cmp(aux265, conv266) > 0) && (mpz_cmp(n, conv267) < 0))) {
    mpz_t conv268;
    mpz_set_si(conv268, (long) *6*);
    if270 = (mpz_cmp(n, conv268) == 0);
    mpz_clear(conv268);
  } else {
    mpz_t conv269;
    mpz_set_si(conv269, (long) *5*);
    if270 = (mpz_cmp(n, conv269) < 0);
    mpz_clear(conv269);
  }
  mpz_clear(aux265);
  mpz_clear(conv266);
  mpz_clear(conv267);
  int result;
  result = if270;
  mpz_clear(n);
  return result;
}

int pvs_bar_d264(mpz_t n) {
  int if276;
  mpz_t aux271;
  mpz_init(aux271);
  mpz_add_ui(aux271, n, (unsigned long) *3*);
  mpz_t conv272;
  mpz_set_si(conv272, (long) *6*);
  mpz_t conv273;
  mpz_set_si(conv273, (long) *12*);
  if (((mpz_cmp(aux271, conv272) > 0) && (mpz_cmp(n, conv273) < 0))) {
    mpz_t conv274;
    mpz_set_si(conv274, (long) *6*);
    if276 = (mpz_cmp(n, conv274) == 0);
    mpz_clear(conv274);
  } else {
    mpz_t conv275;
    mpz_set_si(conv275, (long) *5*);
    if276 = (mpz_cmp(n, conv275) < 0);
    mpz_clear(conv275);
  }
  mpz_clear(aux271);
  mpz_clear(conv272);
  mpz_clear(conv273);
  int result;
  result = if276;
  mpz_clear(n);
  return result;
}

void pvs_foo277(mpz_t result, mpz_t x) {
  mpz_t if280;
  mpz_init(if280);
  mpz_t conv279;
  mpz_set_si(conv279, (long) *0*);
  if ((mpz_cmp(x, conv279) == 0)) {
    mpz_set_si(if280, (long) *1*);
  } else {
    mpz_add_ui(if280, x, (unsigned long) *3*);
  }
  mpz_clear(conv279);
  mpz_add_ui(result, if280, (unsigned long) *1*);
  mpz_clear(x);
  mpz_clear(if280);
}

void pvs_foo_d278(mpz_t result, mpz_t x) {
  mpz_t if282;
  mpz_init(if282);
  mpz_t conv281;
  mpz_set_si(conv281, (long) *0*);
  if ((mpz_cmp(x, conv281) == 0)) {
    mpz_set_si(if282, (long) *1*);
  } else {
    mpz_add_ui(if282, x, (unsigned long) *3*);
  }
  mpz_clear(conv281);
  mpz_add_ui(result, if282, (unsigned long) *1*);
  mpz_clear(x);
  mpz_clear(if282);
}

void pvs_add2283(mpz_t result, mpz_t a) {
  mpz_t c;
  mpz_init(c);
  mpz_t if286;
  mpz_init(if286);
  mpz_t conv285;
  mpz_set_si(conv285, (long) *1*);
  if ((mpz_cmp(a, conv285) == 0)) {
    mpz_set_si(if286, (long) *1*);
  } else {
    mpz_set_si(if286, (long) *0*);
  }
  mpz_clear(conv285);
  mpz_add(c, a, if286);
  mpz_t d;
  mpz_init(d);
  mpz_set_si(d, (long) *2*);
  mpz_t aux287;
  mpz_init(aux287);
  mpz_add(aux287, c, d);
  mpz_add_ui(result, aux287, (unsigned long) *1*);
  mpz_clear(a);
  mpz_clear(aux287);
  mpz_clear(if286);
  mpz_clear(c);
  mpz_clear(d);
}

void pvs_add2_d284(mpz_t result, mpz_t a) {
  mpz_t c;
  mpz_init(c);
  mpz_t if289;
  mpz_init(if289);
  mpz_t conv288;
  mpz_set_si(conv288, (long) *1*);
  if ((mpz_cmp(a, conv288) == 0)) {
    mpz_set_si(if289, (long) *1*);
  } else {
    mpz_set_si(if289, (long) *0*);
  }
  mpz_clear(conv288);
  mpz_add(c, a, if289);
  mpz_t d;
  mpz_init(d);
  mpz_set_si(d, (long) *2*);
  mpz_t aux290;
  mpz_init(aux290);
  mpz_add(aux290, c, d);
  mpz_add_ui(result, aux290, (unsigned long) *1*);
  mpz_clear(a);
  mpz_clear(aux290);
  mpz_clear(if289);
  mpz_clear(c);
  mpz_clear(d);
}

void pvs_f291(mpz_t result, mpz_t x) {
  mpz_t y;
  mpz_init(y);
  mpz_set_si(y, (long) *12*);
  mpz_add_ui(result, y, (unsigned long) *2*);
  mpz_clear(x);
  mpz_clear(y);
}

void pvs_f_d292(mpz_t result, mpz_t x) {
  mpz_t y;
  mpz_init(y);
  mpz_set_si(y, (long) *12*);
  mpz_add_ui(result, y, (unsigned long) *2*);
  mpz_clear(x);
  mpz_clear(y);
}

void pvs_factorial293(mpz_t result, mpz_t n) {
  mpz_t conv295;
  mpz_set_si(conv295, (long) *0*);
  if ((mpz_cmp(n, conv295) == 0)) {
    mpz_set_si(result, (long) *1*);
  } else {
    mpz_t aux297;
    mpz_init(aux297);
    mpz_t aux296;
    mpz_init(aux296);
    mpz_sub_ui(aux296, n, (unsigned long) *1*);
    pvs_factorial_d294(aux297, aux296);
    mpz_clear(aux296);
    mpz_mul(result, n, aux297);
    mpz_clear(aux297);
  }
  mpz_clear(n);
  mpz_clear(conv295);
}

void pvs_factorial_d294(mpz_t result, mpz_t n) {
  mpz_t conv298;
  mpz_set_si(conv298, (long) *0*);
  if ((mpz_cmp(n, conv298) == 0)) {
    mpz_set_si(result, (long) *1*);
  } else {
    mpz_t aux300;
    mpz_init(aux300);
    mpz_t aux299;
    mpz_init(aux299);
    mpz_sub_ui(aux299, n, (unsigned long) *1*);
    pvs_factorial_d294(aux300, aux299);
    mpz_clear(aux299);
    mpz_mul(result, n, aux300);
    mpz_clear(aux300);
  }
  mpz_clear(n);
  mpz_clear(conv298);
}