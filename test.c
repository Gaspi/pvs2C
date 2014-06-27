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


void pvs_f257(mpz_t result, int a, int b) {
  mpz_set_si(result, (long) (a + b));
}

void pvs_d_f258(mpz_t result, int a, int b) {
  mpz_set_si(result, (long) (a + b));
}

void pvs_g259(mpz_t result, int a) {
  pvs_d_f258(result, a, a);
}

void pvs_d_g260(mpz_t result, int a) {
  pvs_d_f258(result, a, a);
}

int pvs_b261() {
  int result;
  result = TRUE;
  return result;
}

int pvs_d_b262() {
  int result;
  result = TRUE;
  return result;
}

int pvs_bar263(mpz_t n) {
  int if276;
  mpz_t aux271;
  mpz_init(aux271);
  mpz_add_ui(aux271, n, (unsigned long) 3);
  mpz_t conv272;
  mpz_init(conv272);
  mpz_set_si(conv272, (long) 6);
  mpz_t conv273;
  mpz_init(conv273);
  mpz_set_si(conv273, (long) 12);
  if(((mpz_cmp(aux271, conv272) > 0) && (mpz_cmp(n, conv273) < 0))) {
    mpz_t conv274;
    mpz_init(conv274);
    mpz_set_si(conv274, (long) 6);
    if276 = (mpz_cmp(n, conv274) == 0);
    mpz_clear(conv274);
  } else {
    mpz_t conv275;
    mpz_init(conv275);
    mpz_set_si(conv275, (long) 5);
    if276 = (mpz_cmp(n, conv275) < 0);
    mpz_clear(conv275);
  }
  mpz_clear(aux271);
  mpz_clear(conv272);
  mpz_clear(conv273);
  int result;
  result = if276;
  return result;
}

int pvs_d_bar264(mpz_t n) {
  int if276;
  mpz_t aux271;
  mpz_init(aux271);
  mpz_add_ui(aux271, n, (unsigned long) 3);
  mpz_t conv272;
  mpz_init(conv272);
  mpz_set_si(conv272, (long) 6);
  mpz_t conv273;
  mpz_init(conv273);
  mpz_set_si(conv273, (long) 12);
  if(((mpz_cmp(aux271, conv272) > 0) && (mpz_cmp(n, conv273) < 0))) {
    mpz_t conv274;
    mpz_init(conv274);
    mpz_set_si(conv274, (long) 6);
    if276 = (mpz_cmp(n, conv274) == 0);
    mpz_clear(conv274);
  } else {
    mpz_t conv275;
    mpz_init(conv275);
    mpz_set_si(conv275, (long) 5);
    if276 = (mpz_cmp(n, conv275) < 0);
    mpz_clear(conv275);
  }
  mpz_clear(aux271);
  mpz_clear(conv272);
  mpz_clear(conv273);
  int result;
  result = if276;
  return result;
}

void pvs_adda277(mpz_t result, mpz_t i) {
  mpz_t c;
  mpz_init(c);
  mpz_set_si(c, (long) 3);
  mpz_set(result, c);
  mpz_clear(c);
}

void pvs_d_adda278(mpz_t result, mpz_t i) {
  mpz_t c;
  mpz_init(c);
  mpz_set_si(c, (long) 3);
  mpz_set(result, c);
  mpz_clear(c);
}

void pvs_foo279(mpz_t result, mpz_t x) {
  mpz_t if284;
  mpz_init(if284);
  mpz_t conv283;
  mpz_init(conv283);
  mpz_set_si(conv283, (long) 0);
  if((mpz_cmp(x, conv283) == 0)) {
    mpz_set_si(if284, (long) 1);
  } else {
    mpz_add_ui(if284, x, (unsigned long) 3);
  }
  mpz_clear(conv283);
  mpz_add_ui(result, if284, (unsigned long) 1);
  mpz_clear(if284);
}

void pvs_d_foo280(mpz_t result, mpz_t x) {
  mpz_t if284;
  mpz_init(if284);
  mpz_t conv283;
  mpz_init(conv283);
  mpz_set_si(conv283, (long) 0);
  if((mpz_cmp(x, conv283) == 0)) {
    mpz_set_si(if284, (long) 1);
  } else {
    mpz_add_ui(if284, x, (unsigned long) 3);
  }
  mpz_clear(conv283);
  mpz_add_ui(result, if284, (unsigned long) 1);
  mpz_clear(if284);
}

void pvs_add2285(mpz_t result, mpz_t a) {
  mpz_t c;
  mpz_init(c);
  mpz_t if291;
  mpz_init(if291);
  mpz_t conv290;
  mpz_init(conv290);
  mpz_set_si(conv290, (long) 1);
  if((mpz_cmp(a, conv290) == 0)) {
    mpz_set_si(if291, (long) 1);
  } else {
    mpz_set_si(if291, (long) 0);
  }
  mpz_clear(conv290);
  mpz_add(c, a, if291);
  mpz_t d;
  mpz_init(d);
  mpz_set_si(d, (long) 2);
  mpz_t aux292;
  mpz_init(aux292);
  mpz_add(aux292, c, d);
  mpz_add_ui(result, aux292, (unsigned long) 1);
  mpz_clear(aux292);
  mpz_clear(if291);
  mpz_clear(c);
  mpz_clear(d);
}

void pvs_d_add2286(mpz_t result, mpz_t a) {
  mpz_t c;
  mpz_init(c);
  mpz_t if291;
  mpz_init(if291);
  mpz_t conv290;
  mpz_init(conv290);
  mpz_set_si(conv290, (long) 1);
  if((mpz_cmp(a, conv290) == 0)) {
    mpz_set_si(if291, (long) 1);
  } else {
    mpz_set_si(if291, (long) 0);
  }
  mpz_clear(conv290);
  mpz_add(c, a, if291);
  mpz_t d;
  mpz_init(d);
  mpz_set_si(d, (long) 2);
  mpz_t aux292;
  mpz_init(aux292);
  mpz_add(aux292, c, d);
  mpz_add_ui(result, aux292, (unsigned long) 1);
  mpz_clear(aux292);
  mpz_clear(if291);
  mpz_clear(c);
  mpz_clear(d);
}

void pvs_f293(mpz_t result, mpz_t x) {
  mpz_t y;
  mpz_init(y);
  mpz_set_si(y, (long) 12);
  mpz_add_ui(result, y, (unsigned long) 2);
  mpz_clear(y);
}

void pvs_d_f294(mpz_t result, mpz_t x) {
  mpz_t y;
  mpz_init(y);
  mpz_set_si(y, (long) 12);
  mpz_add_ui(result, y, (unsigned long) 2);
  mpz_clear(y);
}

void pvs_factorial295(mpz_t result, mpz_t n) {
  mpz_t conv300;
  mpz_init(conv300);
  mpz_set_si(conv300, (long) 0);
  if((mpz_cmp(n, conv300) == 0)) {
    mpz_set_si(result, (long) 1);
  } else {
    mpz_t aux302;
    mpz_init(aux302);
    mpz_t aux301;
    mpz_init(aux301);
    mpz_sub_ui(aux301, n, (unsigned long) 1);
    pvs_d_factorial296(aux302, aux301);
    mpz_clear(aux301);
    mpz_mul(result, n, aux302);
    mpz_clear(aux302);
  }
  mpz_clear(conv300);
}

void pvs_d_factorial296(mpz_t result, mpz_t n) {
  mpz_t conv300;
  mpz_init(conv300);
  mpz_set_si(conv300, (long) 0);
  if((mpz_cmp(n, conv300) == 0)) {
    mpz_set_si(result, (long) 1);
  } else {
    mpz_t aux302;
    mpz_init(aux302);
    mpz_t aux301;
    mpz_init(aux301);
    mpz_sub_ui(aux301, n, (unsigned long) 1);
    pvs_d_factorial296(aux302, aux301);
    mpz_clear(aux301);
    mpz_mul(result, n, aux302);
    mpz_clear(aux302);
  }
  mpz_clear(conv300);
}