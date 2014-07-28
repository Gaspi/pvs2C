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


void pvs_adda929(mpz_t result, mpz_t i) {
  mpz_t c;
  mpz_init(c);
  mpz_set_si(c, (long) *3*);
  mpz_set(result, c);
  mpz_clear(c);
}

void pvs_adda_d930(mpz_t result, mpz_t i) {
  mpz_t c;
  mpz_init(c);
  mpz_set_si(c, (long) *3*);
  mpz_set(result, c);
  mpz_clear(c);
}

void pvs_f931(mpz_t result, int a, int b) {
  mpz_set_si(result, (long) (a + b));
}

void pvs_f_d932(mpz_t result, int a, int b) {
  mpz_set_si(result, (long) (a + b));
}

void pvs_incr933(mpz_t result, mpz_t x) {
  mpz_t a;
  mpz_init(a);
  mpz_set(a, x);
  mpz_add_ui(result, a, (unsigned long) *1*);
  mpz_clear(a);
}

void pvs_incr_d934(mpz_t result, mpz_t x) {
  mpz_t a;
  mpz_init(a);
  mpz_set(a, x);
  mpz_add_ui(result, a, (unsigned long) *1*);
  mpz_clear(a);
}

void pvs_norm935(mpz_t result, mpz_t x, mpz_t y) {
  mpz_t aux937;
  mpz_init(aux937);
  mpz_mul(aux937, x, x);
  mpz_t aux938;
  mpz_init(aux938);
  mpz_mul(aux938, y, y);
  mpz_add(result, aux937, aux938);
  mpz_clear(aux937);
  mpz_clear(aux938);
}

void pvs_norm_d936(mpz_t result, mpz_t x, mpz_t y) {
  mpz_t aux939;
  mpz_init(aux939);
  mpz_mul(aux939, x, x);
  mpz_t aux940;
  mpz_init(aux940);
  mpz_mul(aux940, y, y);
  mpz_add(result, aux939, aux940);
  mpz_clear(aux939);
  mpz_clear(aux940);
}

void pvs_g941(mpz_t result, int a) {
  pvs_f_d932(result, a, a);
}

void pvs_g_d942(mpz_t result, int a) {
  pvs_f_d932(result, a, a);
}

int pvs_b943() {
  return 1;
}

int pvs_b_d944() {
  return 1;
}

int pvs_bar945(mpz_t n) {
  int if952;
  mpz_t aux947;
  mpz_init(aux947);
  mpz_add_ui(aux947, n, (unsigned long) *3*);
  mpz_t conv948;
  mpz_set_si(conv948, (long) *6*);
  mpz_t conv949;
  mpz_set_si(conv949, (long) *12*);
  if (((mpz_cmp(aux947, conv948) > 0) && (mpz_cmp(n, conv949) < 0))) {
    mpz_t conv950;
    mpz_set_si(conv950, (long) *6*);
    if952 = (mpz_cmp(n, conv950) == 0);
    mpz_clear(conv950);
  } else {
    mpz_t conv951;
    mpz_set_si(conv951, (long) *5*);
    if952 = (mpz_cmp(n, conv951) < 0);
    mpz_clear(conv951);
  }
  mpz_clear(aux947);
  mpz_clear(conv948);
  mpz_clear(conv949);
  int result;
  result = if952;
  return result;
}

int pvs_bar_d946(mpz_t n) {
  int if958;
  mpz_t aux953;
  mpz_init(aux953);
  mpz_add_ui(aux953, n, (unsigned long) *3*);
  mpz_t conv954;
  mpz_set_si(conv954, (long) *6*);
  mpz_t conv955;
  mpz_set_si(conv955, (long) *12*);
  if (((mpz_cmp(aux953, conv954) > 0) && (mpz_cmp(n, conv955) < 0))) {
    mpz_t conv956;
    mpz_set_si(conv956, (long) *6*);
    if958 = (mpz_cmp(n, conv956) == 0);
    mpz_clear(conv956);
  } else {
    mpz_t conv957;
    mpz_set_si(conv957, (long) *5*);
    if958 = (mpz_cmp(n, conv957) < 0);
    mpz_clear(conv957);
  }
  mpz_clear(aux953);
  mpz_clear(conv954);
  mpz_clear(conv955);
  int result;
  result = if958;
  return result;
}

void pvs_foo959(mpz_t result, mpz_t x) {
  mpz_t if962;
  mpz_init(if962);
  mpz_t conv961;
  mpz_set_si(conv961, (long) *0*);
  if ((mpz_cmp(x, conv961) == 0)) {
    mpz_set_si(if962, (long) *1*);
  } else {
    mpz_add_ui(if962, x, (unsigned long) *3*);
  }
  mpz_clear(conv961);
  mpz_add_ui(result, if962, (unsigned long) *1*);
  mpz_clear(if962);
}

void pvs_foo_d960(mpz_t result, mpz_t x) {
  mpz_t if964;
  mpz_init(if964);
  mpz_t conv963;
  mpz_set_si(conv963, (long) *0*);
  if ((mpz_cmp(x, conv963) == 0)) {
    mpz_set_si(if964, (long) *1*);
  } else {
    mpz_add_ui(if964, x, (unsigned long) *3*);
  }
  mpz_clear(conv963);
  mpz_add_ui(result, if964, (unsigned long) *1*);
  mpz_clear(if964);
}

void pvs_add2965(mpz_t result, mpz_t a) {
  mpz_t c;
  mpz_init(c);
  mpz_t if968;
  mpz_init(if968);
  mpz_t conv967;
  mpz_set_si(conv967, (long) *1*);
  if ((mpz_cmp(a, conv967) == 0)) {
    mpz_set_si(if968, (long) *1*);
  } else {
    mpz_set_si(if968, (long) *0*);
  }
  mpz_clear(conv967);
  mpz_add(c, a, if968);
  mpz_t d;
  mpz_init(d);
  mpz_set_si(d, (long) *2*);
  mpz_t aux969;
  mpz_init(aux969);
  mpz_add(aux969, c, d);
  mpz_add_ui(result, aux969, (unsigned long) *1*);
  mpz_clear(aux969);
  mpz_clear(if968);
  mpz_clear(c);
  mpz_clear(d);
}

void pvs_add2_d966(mpz_t result, mpz_t a) {
  mpz_t c;
  mpz_init(c);
  mpz_t if971;
  mpz_init(if971);
  mpz_t conv970;
  mpz_set_si(conv970, (long) *1*);
  if ((mpz_cmp(a, conv970) == 0)) {
    mpz_set_si(if971, (long) *1*);
  } else {
    mpz_set_si(if971, (long) *0*);
  }
  mpz_clear(conv970);
  mpz_add(c, a, if971);
  mpz_t d;
  mpz_init(d);
  mpz_set_si(d, (long) *2*);
  mpz_t aux972;
  mpz_init(aux972);
  mpz_add(aux972, c, d);
  mpz_add_ui(result, aux972, (unsigned long) *1*);
  mpz_clear(aux972);
  mpz_clear(if971);
  mpz_clear(c);
  mpz_clear(d);
}

void pvs_f973(mpz_t result, mpz_t x) {
  mpz_t y;
  mpz_init(y);
  mpz_set_si(y, (long) *12*);
  mpz_add_ui(result, y, (unsigned long) *2*);
  mpz_clear(y);
}

void pvs_f_d974(mpz_t result, mpz_t x) {
  mpz_t y;
  mpz_init(y);
  mpz_set_si(y, (long) *12*);
  mpz_add_ui(result, y, (unsigned long) *2*);
  mpz_clear(y);
}

void pvs_factorial975(mpz_t result, mpz_t n) {
  mpz_t conv977;
  mpz_set_si(conv977, (long) *0*);
  if ((mpz_cmp(n, conv977) == 0)) {
    mpz_set_si(result, (long) *1*);
  } else {
    mpz_t aux979;
    mpz_init(aux979);
    mpz_t aux978;
    mpz_init(aux978);
    mpz_sub_ui(aux978, n, (unsigned long) *1*);
    pvs_factorial_d976(aux979, aux978);
    mpz_clear(aux978);
    mpz_mul(result, n, aux979);
    mpz_clear(aux979);
  }
  mpz_clear(conv977);
}

void pvs_factorial_d976(mpz_t result, mpz_t n) {
  mpz_t conv980;
  mpz_set_si(conv980, (long) *0*);
  if ((mpz_cmp(n, conv980) == 0)) {
    mpz_set_si(result, (long) *1*);
  } else {
    mpz_t aux982;
    mpz_init(aux982);
    mpz_t aux981;
    mpz_init(aux981);
    mpz_sub_ui(aux981, n, (unsigned long) *1*);
    pvs_factorial_d976(aux982, aux981);
    mpz_clear(aux981);
    mpz_mul(result, n, aux982);
    mpz_clear(aux982);
  }
  mpz_clear(conv980);
}