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


void pvs_f948(mpz_t result, int a, int b) {
  mpz_set_si(result, (long) (a + b));
}

void pvs_d_f949(mpz_t result, int a, int b) {
  mpz_set_si(result, (long) (a + b));
}

void pvs_g950(mpz_t result, int a) {
  pvs_d_f949(result, a, a);
}

void pvs_d_g951(mpz_t result, int a) {
  pvs_d_f949(result, a, a);
}

int pvs_b952() {
  int result;
  result = TRUE;
  return result;
}

int pvs_d_b953() {
  int result;
  result = TRUE;
  return result;
}

int pvs_bar954(mpz_t n) {
  int if963;
  mpz_t conv961;
  mpz_init(conv961);
  mpz_set_si(conv961, (long) 12);
  if((isEven((aux960)) && (mpz_cmp(n, conv961) < 0))) {
    mpz_t conv962;
    mpz_init(conv962);
    mpz_set_si(conv962, (long) 6);
    if963 = (mpz_cmp(n, conv962) == 0);
    mpz_clear(conv962);
  } else {
    if963 = isEven((n));
  }
  mpz_clear(conv961);
  int result;
  result = if963;
  return result;
}

int pvs_d_bar955(mpz_t n) {
  int if963;
  mpz_t conv961;
  mpz_init(conv961);
  mpz_set_si(conv961, (long) 12);
  if((isEven((aux960)) && (mpz_cmp(n, conv961) < 0))) {
    mpz_t conv962;
    mpz_init(conv962);
    mpz_set_si(conv962, (long) 6);
    if963 = (mpz_cmp(n, conv962) == 0);
    mpz_clear(conv962);
  } else {
    if963 = isEven((n));
  }
  mpz_clear(conv961);
  int result;
  result = if963;
  return result;
}

void pvs_adda964(mpz_t result, mpz_t i) {
  mpz_t c = conv967;
  mpz_set(result, c);
}

void pvs_d_adda965(mpz_t result, mpz_t i) {
  mpz_t c = conv967;
  mpz_set(result, c);
}

void pvs_foo968(mpz_t result, mpz_t x) {
  mpz_t if973;
  mpz_init(if973);
  mpz_t conv972;
  mpz_init(conv972);
  mpz_set_si(conv972, (long) 0);
  if((mpz_cmp(x, conv972) == 0)) {
    mpz_set_si(if973, (long) 1);
  } else {
    mpz_add_ui(if973, x, (unsigned long) 3);
  }
  mpz_clear(conv972);
  mpz_add_ui(result, if973, (unsigned long) 1);
  mpz_clear(if973);
}

void pvs_d_foo969(mpz_t result, mpz_t x) {
  mpz_t if973;
  mpz_init(if973);
  mpz_t conv972;
  mpz_init(conv972);
  mpz_set_si(conv972, (long) 0);
  if((mpz_cmp(x, conv972) == 0)) {
    mpz_set_si(if973, (long) 1);
  } else {
    mpz_add_ui(if973, x, (unsigned long) 3);
  }
  mpz_clear(conv972);
  mpz_add_ui(result, if973, (unsigned long) 1);
  mpz_clear(if973);
}

void pvs_add2974(mpz_t result, mpz_t a) {
  mpz_t c = aux983;
  mpz_t d = conv984;
  mpz_t aux985;
  mpz_init(aux985);
  mpz_add(aux985, c, d);
  mpz_add_ui(result, aux985, (unsigned long) 1);
  mpz_clear(aux985);
}

void pvs_d_add2975(mpz_t result, mpz_t a) {
  mpz_t c = aux983;
  mpz_t d = conv984;
  mpz_t aux985;
  mpz_init(aux985);
  mpz_add(aux985, c, d);
  mpz_add_ui(result, aux985, (unsigned long) 1);
  mpz_clear(aux985);
}

void pvs_f986(mpz_t result, mpz_t x) {
  mpz_t x: int = conv989;
  mpz_add_ui(result, x#0, (unsigned long) 2);
}

void pvs_d_f987(mpz_t result, mpz_t x) {
  mpz_t x: int = conv989;
  mpz_add_ui(result, x#0, (unsigned long) 2);
}

void pvs_factorial990(mpz_t result, mpz_t n) {
  mpz_t conv995;
  mpz_init(conv995);
  mpz_set_si(conv995, (long) 0);
  if((mpz_cmp(n, conv995) == 0)) {
    mpz_set_si(result, (long) 1);
  } else {
    mpz_t aux997;
    mpz_init(aux997);
    mpz_t aux996;
    mpz_init(aux996);
    mpz_sub_ui(aux996, n, (unsigned long) 1);
    pvs_d_factorial991(aux997, aux996);
    mpz_clear(aux996);
    mpz_mul(result, n, aux997);
    mpz_clear(aux997);
  }
  mpz_clear(conv995);
}

void pvs_d_factorial991(mpz_t result, mpz_t n) {
  mpz_t conv995;
  mpz_init(conv995);
  mpz_set_si(conv995, (long) 0);
  if((mpz_cmp(n, conv995) == 0)) {
    mpz_set_si(result, (long) 1);
  } else {
    mpz_t aux997;
    mpz_init(aux997);
    mpz_t aux996;
    mpz_init(aux996);
    mpz_sub_ui(aux996, n, (unsigned long) 1);
    pvs_d_factorial991(aux997, aux996);
    mpz_clear(aux996);
    mpz_mul(result, n, aux997);
    mpz_clear(aux997);
  }
  mpz_clear(conv995);
}