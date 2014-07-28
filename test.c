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


void pvs_adda479(mpz_t result, mpz_t i) {
  mpz_t c;
  mpz_init(c);
  mpz_set_si(c, (long) *3*);
  mpz_set(result, c);
  mpz_clear(c);
}

void pvs_adda_d480(mpz_t result, mpz_t i) {
  mpz_t c;
  mpz_init(c);
  mpz_set_si(c, (long) *3*);
  mpz_set(result, c);
  mpz_clear(c);
}

void pvs_f481(mpz_t result, int a, int b) {
  mpz_set_si(result, (long) (a + b));
}

void pvs_f_d482(mpz_t result, int a, int b) {
  mpz_set_si(result, (long) (a + b));
}

void pvs_incr483(mpz_t result, mpz_t x) {
  mpz_t a;
  mpz_init(a);
  mpz_set(a, x);
  mpz_add_ui(result, a, (unsigned long) *1*);
  mpz_clear(a);
}

void pvs_incr_d484(mpz_t result, mpz_t x) {
  mpz_t a;
  mpz_init(a);
  mpz_set(a, x);
  mpz_add_ui(result, a, (unsigned long) *1*);
  mpz_clear(a);
}

void pvs_norm485(mpz_t result, mpz_t x, mpz_t y) {
  mpz_t aux487;
  mpz_init(aux487);
  mpz_mul(aux487, x, x);
  mpz_t aux488;
  mpz_init(aux488);
  mpz_mul(aux488, y, y);
  mpz_add(result, aux487, aux488);
  mpz_clear(aux487);
  mpz_clear(aux488);
}

void pvs_norm_d486(mpz_t result, mpz_t x, mpz_t y) {
  mpz_t aux489;
  mpz_init(aux489);
  mpz_mul(aux489, x, x);
  mpz_t aux490;
  mpz_init(aux490);
  mpz_mul(aux490, y, y);
  mpz_add(result, aux489, aux490);
  mpz_clear(aux489);
  mpz_clear(aux490);
}

void pvs_g491(mpz_t result, int a) {
  pvs_f_d482(result, a, a);
}

void pvs_g_d492(mpz_t result, int a) {
  pvs_f_d482(result, a, a);
}

int pvs_b493() {
  return 1;
}

int pvs_b_d494() {
  return 1;
}

int pvs_bar495(mpz_t n) {
  int if502;
  mpz_t aux497;
  mpz_init(aux497);
  mpz_add_ui(aux497, n, (unsigned long) *3*);
  mpz_t conv498;
  mpz_set_si(conv498, (long) *6*);
  mpz_t conv499;
  mpz_set_si(conv499, (long) *12*);
  if (((mpz_cmp(aux497, conv498) > 0) && (mpz_cmp(n, conv499) < 0))) {
    mpz_t conv500;
    mpz_set_si(conv500, (long) *6*);
    if502 = (mpz_cmp(n, conv500) == 0);
    mpz_clear(conv500);
  } else {
    mpz_t conv501;
    mpz_set_si(conv501, (long) *5*);
    if502 = (mpz_cmp(n, conv501) < 0);
    mpz_clear(conv501);
  }
  mpz_clear(aux497);
  mpz_clear(conv498);
  mpz_clear(conv499);
  int result;
  result = if502;
  return result;
}

int pvs_bar_d496(mpz_t n) {
  int if508;
  mpz_t aux503;
  mpz_init(aux503);
  mpz_add_ui(aux503, n, (unsigned long) *3*);
  mpz_t conv504;
  mpz_set_si(conv504, (long) *6*);
  mpz_t conv505;
  mpz_set_si(conv505, (long) *12*);
  if (((mpz_cmp(aux503, conv504) > 0) && (mpz_cmp(n, conv505) < 0))) {
    mpz_t conv506;
    mpz_set_si(conv506, (long) *6*);
    if508 = (mpz_cmp(n, conv506) == 0);
    mpz_clear(conv506);
  } else {
    mpz_t conv507;
    mpz_set_si(conv507, (long) *5*);
    if508 = (mpz_cmp(n, conv507) < 0);
    mpz_clear(conv507);
  }
  mpz_clear(aux503);
  mpz_clear(conv504);
  mpz_clear(conv505);
  int result;
  result = if508;
  return result;
}

void pvs_foo509(mpz_t result, mpz_t x) {
  mpz_t if512;
  mpz_init(if512);
  mpz_t conv511;
  mpz_set_si(conv511, (long) *0*);
  if ((mpz_cmp(x, conv511) == 0)) {
    mpz_set_si(if512, (long) *1*);
  } else {
    mpz_add_ui(if512, x, (unsigned long) *3*);
  }
  mpz_clear(conv511);
  mpz_add_ui(result, if512, (unsigned long) *1*);
  mpz_clear(if512);
}

void pvs_foo_d510(mpz_t result, mpz_t x) {
  mpz_t if514;
  mpz_init(if514);
  mpz_t conv513;
  mpz_set_si(conv513, (long) *0*);
  if ((mpz_cmp(x, conv513) == 0)) {
    mpz_set_si(if514, (long) *1*);
  } else {
    mpz_add_ui(if514, x, (unsigned long) *3*);
  }
  mpz_clear(conv513);
  mpz_add_ui(result, if514, (unsigned long) *1*);
  mpz_clear(if514);
}

void pvs_add2515(mpz_t result, mpz_t a) {
  mpz_t c;
  mpz_init(c);
  mpz_t if518;
  mpz_init(if518);
  mpz_t conv517;
  mpz_set_si(conv517, (long) *1*);
  if ((mpz_cmp(a, conv517) == 0)) {
    mpz_set_si(if518, (long) *1*);
  } else {
    mpz_set_si(if518, (long) *0*);
  }
  mpz_clear(conv517);
  mpz_add(c, a, if518);
  mpz_t d;
  mpz_init(d);
  mpz_set_si(d, (long) *2*);
  mpz_t aux519;
  mpz_init(aux519);
  mpz_add(aux519, c, d);
  mpz_add_ui(result, aux519, (unsigned long) *1*);
  mpz_clear(aux519);
  mpz_clear(if518);
  mpz_clear(c);
  mpz_clear(d);
}

void pvs_add2_d516(mpz_t result, mpz_t a) {
  mpz_t c;
  mpz_init(c);
  mpz_t if521;
  mpz_init(if521);
  mpz_t conv520;
  mpz_set_si(conv520, (long) *1*);
  if ((mpz_cmp(a, conv520) == 0)) {
    mpz_set_si(if521, (long) *1*);
  } else {
    mpz_set_si(if521, (long) *0*);
  }
  mpz_clear(conv520);
  mpz_add(c, a, if521);
  mpz_t d;
  mpz_init(d);
  mpz_set_si(d, (long) *2*);
  mpz_t aux522;
  mpz_init(aux522);
  mpz_add(aux522, c, d);
  mpz_add_ui(result, aux522, (unsigned long) *1*);
  mpz_clear(aux522);
  mpz_clear(if521);
  mpz_clear(c);
  mpz_clear(d);
}

void pvs_f523(mpz_t result, mpz_t x) {
  mpz_t y;
  mpz_init(y);
  mpz_set_si(y, (long) *12*);
  mpz_add_ui(result, y, (unsigned long) *2*);
  mpz_clear(y);
}

void pvs_f_d524(mpz_t result, mpz_t x) {
  mpz_t y;
  mpz_init(y);
  mpz_set_si(y, (long) *12*);
  mpz_add_ui(result, y, (unsigned long) *2*);
  mpz_clear(y);
}

void pvs_factorial525(mpz_t result, mpz_t n) {
  mpz_t conv527;
  mpz_set_si(conv527, (long) *0*);
  if ((mpz_cmp(n, conv527) == 0)) {
    mpz_set_si(result, (long) *1*);
  } else {
    mpz_t aux529;
    mpz_init(aux529);
    mpz_t aux528;
    mpz_init(aux528);
    mpz_sub_ui(aux528, n, (unsigned long) *1*);
    pvs_factorial_d526(aux529, aux528);
    mpz_clear(aux528);
    mpz_mul(result, n, aux529);
    mpz_clear(aux529);
  }
  mpz_clear(conv527);
}

void pvs_factorial_d526(mpz_t result, mpz_t n) {
  mpz_t conv530;
  mpz_set_si(conv530, (long) *0*);
  if ((mpz_cmp(n, conv530) == 0)) {
    mpz_set_si(result, (long) *1*);
  } else {
    mpz_t aux532;
    mpz_init(aux532);
    mpz_t aux531;
    mpz_init(aux531);
    mpz_sub_ui(aux531, n, (unsigned long) *1*);
    pvs_factorial_d526(aux532, aux531);
    mpz_clear(aux531);
    mpz_mul(result, n, aux532);
    mpz_clear(aux532);
  }
  mpz_clear(conv530);
}