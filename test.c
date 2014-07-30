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
  GC_start();
  printf("Executing test ...\n");
  // Insert code here
  GC_quit();
  return 0;
}


void pvs_adda6304(mpz_t result, mpz_t i) {
  mpz_t c;
  mpz_init(c);
  mpz_set_si(c, (long) 3);
  mpz_set(result, c);
  mpz_clear(c);
  mpz_clear(i);
}

void pvs_adda_d6305(mpz_t result, mpz_t i) {
  mpz_t c;
  mpz_init(c);
  mpz_set_si(c, (long) 3);
  mpz_set(result, c);
  mpz_clear(c);
  mpz_clear(i);
}

void pvs_f6306(mpz_t result, int a, int b) {
  mpz_set_si(result, (long) (a + b));
}

void pvs_f_d6307(mpz_t result, int a, int b) {
  mpz_set_si(result, (long) (a + b));
}

void pvs_incr6308(mpz_t result, mpz_t x) {
  mpz_t a;
  mpz_init(a);
  mpz_set(a, x);
  mpz_add_ui( result , a , (uli) 1 );
  mpz_clear(x);
  mpz_clear(a);
}

void pvs_incr_d6309(mpz_t result, mpz_t x) {
  mpz_t a;
  mpz_init(a);
  mpz_set(a, x);
  mpz_add_ui( result , a , (uli) 1 );
  mpz_clear(x);
  mpz_clear(a);
}

void pvs_norm6310(mpz_t result, mpz_t x, mpz_t y) {
  mpz_t aux6312;
  mpz_init(aux6312);
  mpz_mul( aux6312 , x , x );
  mpz_t aux6313;
  mpz_init(aux6313);
  mpz_mul( aux6313 , y , y );
  mpz_add( result , aux6312 , aux6313 );
  mpz_clear(x);
  mpz_clear(y);
  mpz_clear(aux6312);
  mpz_clear(aux6313);
}

void pvs_norm_d6311(mpz_t result, mpz_t x, mpz_t y) {
  mpz_t aux6314;
  mpz_init(aux6314);
  mpz_mul( aux6314 , x , x );
  mpz_t aux6315;
  mpz_init(aux6315);
  mpz_mul( aux6315 , y , y );
  mpz_add( result , aux6314 , aux6315 );
  mpz_clear(x);
  mpz_clear(y);
  mpz_clear(aux6314);
  mpz_clear(aux6315);
}

void pvs_g6316(mpz_t result, int a) {
  pvs_f_d6307( result , a , a );
}

void pvs_g_d6317(mpz_t result, int a) {
  pvs_f_d6307( result , a , a );
}

int pvs_b6318() {
  return 1;
}

int pvs_b_d6319() {
  return 1;
}

int pvs_bar6320(mpz_t n) {
  int if6327;
  mpz_t aux6322;
  mpz_init(aux6322);
  mpz_add_ui( aux6322 , n , (uli) 3 );
  mpz_t conv6323;
  mpz_set_si(conv6323, (long) 6);
  mpz_t conv6324;
  mpz_set_si(conv6324, (long) 12);
  if (((mpz_cmp(aux6322, conv6323) > 0) && (mpz_cmp(n, conv6324) < 0))) {
    mpz_t conv6325;
    mpz_set_si(conv6325, (long) 6);
    if6327 = (mpz_cmp(n, conv6325) == 0);
    mpz_clear(conv6325);
  } else {
    mpz_t conv6326;
    mpz_set_si(conv6326, (long) 5);
    if6327 = (mpz_cmp(n, conv6326) < 0);
    mpz_clear(conv6326);
  }
  mpz_clear(aux6322);
  mpz_clear(conv6323);
  mpz_clear(conv6324);
  mpz_clear(n);
  return if6327;
}

int pvs_bar_d6321(mpz_t n) {
  int if6333;
  mpz_t aux6328;
  mpz_init(aux6328);
  mpz_add_ui( aux6328 , n , (uli) 3 );
  mpz_t conv6329;
  mpz_set_si(conv6329, (long) 6);
  mpz_t conv6330;
  mpz_set_si(conv6330, (long) 12);
  if (((mpz_cmp(aux6328, conv6329) > 0) && (mpz_cmp(n, conv6330) < 0))) {
    mpz_t conv6331;
    mpz_set_si(conv6331, (long) 6);
    if6333 = (mpz_cmp(n, conv6331) == 0);
    mpz_clear(conv6331);
  } else {
    mpz_t conv6332;
    mpz_set_si(conv6332, (long) 5);
    if6333 = (mpz_cmp(n, conv6332) < 0);
    mpz_clear(conv6332);
  }
  mpz_clear(aux6328);
  mpz_clear(conv6329);
  mpz_clear(conv6330);
  mpz_clear(n);
  return if6333;
}

void pvs_foo6334(mpz_t result, mpz_t x) {
  mpz_t if6337;
  mpz_init(if6337);
  mpz_t conv6336;
  mpz_set_si(conv6336, (long) 0);
  if ((mpz_cmp(x, conv6336) == 0)) {
    mpz_set_si(if6337, (long) 1);
  } else {
    mpz_add_ui( if6337 , x , (uli) 3 );
  }
  mpz_clear(conv6336);
  mpz_add_ui( result , if6337 , (uli) 1 );
  mpz_clear(x);
  mpz_clear(if6337);
}

void pvs_foo_d6335(mpz_t result, mpz_t x) {
  mpz_t if6339;
  mpz_init(if6339);
  mpz_t conv6338;
  mpz_set_si(conv6338, (long) 0);
  if ((mpz_cmp(x, conv6338) == 0)) {
    mpz_set_si(if6339, (long) 1);
  } else {
    mpz_add_ui( if6339 , x , (uli) 3 );
  }
  mpz_clear(conv6338);
  mpz_add_ui( result , if6339 , (uli) 1 );
  mpz_clear(x);
  mpz_clear(if6339);
}

void pvs_add26340(mpz_t result, mpz_t a) {
  mpz_t c;
  mpz_init(c);
  mpz_t if6343;
  mpz_init(if6343);
  mpz_t conv6342;
  mpz_set_si(conv6342, (long) 1);
  if ((mpz_cmp(a, conv6342) == 0)) {
    mpz_set_si(if6343, (long) 1);
  } else {
    mpz_set_si(if6343, (long) 0);
  }
  mpz_clear(conv6342);
  mpz_add( c , a , if6343 );
  mpz_t d;
  mpz_init(d);
  mpz_set_si(d, (long) 2);
  mpz_t aux6344;
  mpz_init(aux6344);
  mpz_add( aux6344 , c , d );
  mpz_add_ui( result , aux6344 , (uli) 1 );
  mpz_clear(a);
  mpz_clear(aux6344);
  mpz_clear(if6343);
  mpz_clear(c);
  mpz_clear(d);
}

void pvs_add2_d6341(mpz_t result, mpz_t a) {
  mpz_t c;
  mpz_init(c);
  mpz_t if6346;
  mpz_init(if6346);
  mpz_t conv6345;
  mpz_set_si(conv6345, (long) 1);
  if ((mpz_cmp(a, conv6345) == 0)) {
    mpz_set_si(if6346, (long) 1);
  } else {
    mpz_set_si(if6346, (long) 0);
  }
  mpz_clear(conv6345);
  mpz_add( c , a , if6346 );
  mpz_t d;
  mpz_init(d);
  mpz_set_si(d, (long) 2);
  mpz_t aux6347;
  mpz_init(aux6347);
  mpz_add( aux6347 , c , d );
  mpz_add_ui( result , aux6347 , (uli) 1 );
  mpz_clear(a);
  mpz_clear(aux6347);
  mpz_clear(if6346);
  mpz_clear(c);
  mpz_clear(d);
}

void pvs_f6348(mpz_t result, mpz_t x) {
  mpz_t y;
  mpz_init(y);
  mpz_set_si(y, (long) 12);
  mpz_add_ui( result , y , (uli) 2 );
  mpz_clear(x);
  mpz_clear(y);
}

void pvs_f_d6349(mpz_t result, mpz_t x) {
  mpz_t y;
  mpz_init(y);
  mpz_set_si(y, (long) 12);
  mpz_add_ui( result , y , (uli) 2 );
  mpz_clear(x);
  mpz_clear(y);
}

void pvs_factorial6350(mpz_t result, mpz_t n) {
  mpz_t conv6352;
  mpz_set_si(conv6352, (long) 0);
  if ((mpz_cmp(n, conv6352) == 0)) {
    mpz_set_si(result, (long) 1);
  } else {
    mpz_t aux6354;
    mpz_init(aux6354);
    mpz_t aux6353;
    mpz_init(aux6353);
    mpz_sub_ui( aux6353 , n , (uli) 1 );
    pvs_factorial_d6351( aux6354 , aux6353 );
    mpz_clear(aux6353);
    mpz_mul( result , n , aux6354 );
    mpz_clear(aux6354);
  }
  mpz_clear(n);
  mpz_clear(conv6352);
}

void pvs_factorial_d6351(mpz_t result, mpz_t n) {
  mpz_t conv6355;
  mpz_set_si(conv6355, (long) 0);
  if ((mpz_cmp(n, conv6355) == 0)) {
    mpz_set_si(result, (long) 1);
  } else {
    mpz_t aux6357;
    mpz_init(aux6357);
    mpz_t aux6356;
    mpz_init(aux6356);
    mpz_sub_ui( aux6356 , n , (uli) 1 );
    pvs_factorial_d6351( aux6357 , aux6356 );
    mpz_clear(aux6356);
    mpz_mul( result , n , aux6357 );
    mpz_clear(aux6357);
  }
  mpz_clear(n);
  mpz_clear(conv6355);
}