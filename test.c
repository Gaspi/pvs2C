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


void pvs_adda47(mpz_t result, mpz_t i) {
  mpz_t c;
  mpz_init(c);
  mpz_set_si(c, (long) *3*);
  mpz_set(result, c);
  mpz_clear(c);
}

void pvs_adda_d48(mpz_t result, mpz_t i) {
  mpz_t c;
  mpz_init(c);
  mpz_set_si(c, (long) *3*);
  mpz_set(result, c);
  mpz_clear(c);
}

void pvs_f49(mpz_t result, int a, int b) {
  mpz_set_si(result, (long) (a + b));
}

void pvs_f_d50(mpz_t result, int a, int b) {
  mpz_set_si(result, (long) (a + b));
}

void pvs_incr51(mpz_t result, mpz_t x) {
  mpz_t a;
  mpz_init(a);
  mpz_set(a, x);
  mpz_add_ui(result, a, (unsigned long) *1*);
  mpz_clear(a);
}

void pvs_incr_d52(mpz_t result, mpz_t x) {
  mpz_t a;
  mpz_init(a);
  mpz_set(a, x);
  mpz_add_ui(result, a, (unsigned long) *1*);
  mpz_clear(a);
}

void pvs_norm53(mpz_t result, mpz_t x, mpz_t y) {
  mpz_t aux55;
  mpz_init(aux55);
  mpz_mul(aux55, x, x);
  mpz_t aux56;
  mpz_init(aux56);
  mpz_mul(aux56, y, y);
  mpz_add(result, aux55, aux56);
  mpz_clear(aux55);
  mpz_clear(aux56);
}

void pvs_norm_d54(mpz_t result, mpz_t x, mpz_t y) {
  mpz_t aux57;
  mpz_init(aux57);
  mpz_mul(aux57, x, x);
  mpz_t aux58;
  mpz_init(aux58);
  mpz_mul(aux58, y, y);
  mpz_add(result, aux57, aux58);
  mpz_clear(aux57);
  mpz_clear(aux58);
}

void pvs_g59(mpz_t result, int a) {
  pvs_f_d50(result, a, a);
}

void pvs_g_d60(mpz_t result, int a) {
  pvs_f_d50(result, a, a);
}

int pvs_b61() {
  return 1;
}

int pvs_b_d62() {
  return 1;
}

int pvs_bar63(mpz_t n) {
  int if70;
  mpz_t aux65;
  mpz_init(aux65);
  mpz_add_ui(aux65, n, (unsigned long) *3*);
  mpz_t conv66;
  mpz_set_si(conv66, (long) *6*);
  mpz_t conv67;
  mpz_set_si(conv67, (long) *12*);
  if (((mpz_cmp(aux65, conv66) > 0) && (mpz_cmp(n, conv67) < 0))) {
    mpz_t conv68;
    mpz_set_si(conv68, (long) *6*);
    if70 = (mpz_cmp(n, conv68) == 0);
    mpz_clear(conv68);
  } else {
    mpz_t conv69;
    mpz_set_si(conv69, (long) *5*);
    if70 = (mpz_cmp(n, conv69) < 0);
    mpz_clear(conv69);
  }
  mpz_clear(aux65);
  mpz_clear(conv66);
  mpz_clear(conv67);
  int result;
  result = if70;
  return result;
}

int pvs_bar_d64(mpz_t n) {
  int if76;
  mpz_t aux71;
  mpz_init(aux71);
  mpz_add_ui(aux71, n, (unsigned long) *3*);
  mpz_t conv72;
  mpz_set_si(conv72, (long) *6*);
  mpz_t conv73;
  mpz_set_si(conv73, (long) *12*);
  if (((mpz_cmp(aux71, conv72) > 0) && (mpz_cmp(n, conv73) < 0))) {
    mpz_t conv74;
    mpz_set_si(conv74, (long) *6*);
    if76 = (mpz_cmp(n, conv74) == 0);
    mpz_clear(conv74);
  } else {
    mpz_t conv75;
    mpz_set_si(conv75, (long) *5*);
    if76 = (mpz_cmp(n, conv75) < 0);
    mpz_clear(conv75);
  }
  mpz_clear(aux71);
  mpz_clear(conv72);
  mpz_clear(conv73);
  int result;
  result = if76;
  return result;
}

void pvs_foo77(mpz_t result, mpz_t x) {
  mpz_t if80;
  mpz_init(if80);
  mpz_t conv79;
  mpz_set_si(conv79, (long) *0*);
  if ((mpz_cmp(x, conv79) == 0)) {
    mpz_set_si(if80, (long) *1*);
  } else {
    mpz_add_ui(if80, x, (unsigned long) *3*);
  }
  mpz_clear(conv79);
  mpz_add_ui(result, if80, (unsigned long) *1*);
  mpz_clear(if80);
}

void pvs_foo_d78(mpz_t result, mpz_t x) {
  mpz_t if82;
  mpz_init(if82);
  mpz_t conv81;
  mpz_set_si(conv81, (long) *0*);
  if ((mpz_cmp(x, conv81) == 0)) {
    mpz_set_si(if82, (long) *1*);
  } else {
    mpz_add_ui(if82, x, (unsigned long) *3*);
  }
  mpz_clear(conv81);
  mpz_add_ui(result, if82, (unsigned long) *1*);
  mpz_clear(if82);
}

void pvs_add283(mpz_t result, mpz_t a) {
  mpz_t c;
  mpz_init(c);
  mpz_t if86;
  mpz_init(if86);
  mpz_t conv85;
  mpz_set_si(conv85, (long) *1*);
  if ((mpz_cmp(a, conv85) == 0)) {
    mpz_set_si(if86, (long) *1*);
  } else {
    mpz_set_si(if86, (long) *0*);
  }
  mpz_clear(conv85);
  mpz_add(c, a, if86);
  mpz_t d;
  mpz_init(d);
  mpz_set_si(d, (long) *2*);
  mpz_t aux87;
  mpz_init(aux87);
  mpz_add(aux87, c, d);
  mpz_add_ui(result, aux87, (unsigned long) *1*);
  mpz_clear(aux87);
  mpz_clear(if86);
  mpz_clear(c);
  mpz_clear(d);
}

void pvs_add2_d84(mpz_t result, mpz_t a) {
  mpz_t c;
  mpz_init(c);
  mpz_t if89;
  mpz_init(if89);
  mpz_t conv88;
  mpz_set_si(conv88, (long) *1*);
  if ((mpz_cmp(a, conv88) == 0)) {
    mpz_set_si(if89, (long) *1*);
  } else {
    mpz_set_si(if89, (long) *0*);
  }
  mpz_clear(conv88);
  mpz_add(c, a, if89);
  mpz_t d;
  mpz_init(d);
  mpz_set_si(d, (long) *2*);
  mpz_t aux90;
  mpz_init(aux90);
  mpz_add(aux90, c, d);
  mpz_add_ui(result, aux90, (unsigned long) *1*);
  mpz_clear(aux90);
  mpz_clear(if89);
  mpz_clear(c);
  mpz_clear(d);
}

void pvs_f91(mpz_t result, mpz_t x) {
  mpz_t y;
  mpz_init(y);
  mpz_set_si(y, (long) *12*);
  mpz_add_ui(result, y, (unsigned long) *2*);
  mpz_clear(y);
}

void pvs_f_d92(mpz_t result, mpz_t x) {
  mpz_t y;
  mpz_init(y);
  mpz_set_si(y, (long) *12*);
  mpz_add_ui(result, y, (unsigned long) *2*);
  mpz_clear(y);
}

void pvs_factorial93(mpz_t result, mpz_t n) {
  mpz_t conv95;
  mpz_set_si(conv95, (long) *0*);
  if ((mpz_cmp(n, conv95) == 0)) {
    mpz_set_si(result, (long) *1*);
  } else {
    mpz_t aux97;
    mpz_init(aux97);
    mpz_t aux96;
    mpz_init(aux96);
    mpz_sub_ui(aux96, n, (unsigned long) *1*);
    pvs_factorial_d94(aux97, aux96);
    mpz_clear(aux96);
    mpz_mul(result, n, aux97);
    mpz_clear(aux97);
  }
  mpz_clear(conv95);
}

void pvs_factorial_d94(mpz_t result, mpz_t n) {
  mpz_t conv98;
  mpz_set_si(conv98, (long) *0*);
  if ((mpz_cmp(n, conv98) == 0)) {
    mpz_set_si(result, (long) *1*);
  } else {
    mpz_t aux100;
    mpz_init(aux100);
    mpz_t aux99;
    mpz_init(aux99);
    mpz_sub_ui(aux99, n, (unsigned long) *1*);
    pvs_factorial_d94(aux100, aux99);
    mpz_clear(aux99);
    mpz_mul(result, n, aux100);
    mpz_clear(aux100);
  }
  mpz_clear(conv98);
}