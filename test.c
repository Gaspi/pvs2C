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


void pvs_adda2454(mpz_t result, mpz_t i) {
  mpz_t c;
  mpz_init( c );
  mpz_set_si(c, (long) 3);
  mpz_set(result, c);
  mpz_clear(c);
  mpz_clear(i);
}

void pvs_adda_d2455(mpz_t result, mpz_t i) {
  mpz_t c;
  mpz_init( c );
  mpz_set_si(c, (long) 3);
  mpz_set(result, c);
  mpz_clear(c);
  mpz_clear(i);
}

void pvs_f2456(mpz_t result, int a, int b) {
  mpz_set_si(result, (long) (a + b));
}

void pvs_f_d2457(mpz_t result, int a, int b) {
  mpz_set_si(result, (long) (a + b));
}

void pvs_incr2458(mpz_t result, mpz_t x) {
  mpz_t a;
  mpz_init( a );
  mpz_set(a, x);
  mpz_add_ui( result , a , (unsigned long int) 1 );
  mpz_clear(x);
  mpz_clear(a);
}

void pvs_incr_d2459(mpz_t result, mpz_t x) {
  mpz_t a;
  mpz_init( a );
  mpz_set(a, x);
  mpz_add_ui( result , a , (unsigned long int) 1 );
  mpz_clear(x);
  mpz_clear(a);
}

void pvs_norm2460(mpz_t result, mpz_t x, mpz_t y) {
  mpz_t aux2462;
  mpz_init( aux2462 );
  mpz_mul( aux2462 , x , x );
  mpz_t aux2463;
  mpz_init( aux2463 );
  mpz_mul( aux2463 , y , y );
  mpz_add( result , aux2462 , aux2463 );
  mpz_clear(x);
  mpz_clear(y);
  mpz_clear(aux2462);
  mpz_clear(aux2463);
}

void pvs_norm_d2461(mpz_t result, mpz_t x, mpz_t y) {
  mpz_t aux2464;
  mpz_init( aux2464 );
  mpz_mul( aux2464 , x , x );
  mpz_t aux2465;
  mpz_init( aux2465 );
  mpz_mul( aux2465 , y , y );
  mpz_add( result , aux2464 , aux2465 );
  mpz_clear(x);
  mpz_clear(y);
  mpz_clear(aux2464);
  mpz_clear(aux2465);
}

void pvs_g2466(mpz_t result, int a) {
  pvs_f_d2457( result , a , a );
}

void pvs_g_d2467(mpz_t result, int a) {
  pvs_f_d2457( result , a , a );
}

int pvs_b2468() {
  return 1;
}

int pvs_b_d2469() {
  return 1;
}

int pvs_bar2470(mpz_t n) {
  mpz_t aux2472;
  mpz_init( aux2472 );
  mpz_add_ui( aux2472 , n , (unsigned long int) 3 );
  mpz_t conv2473;
  mpz_init( conv2473 );
  mpz_set_si(conv2473, (long) 6);
  mpz_t conv2474;
  mpz_init( conv2474 );
  mpz_set_si(conv2474, (long) 12);
  int if2477;
  if (((mpz_cmp(aux2472, conv2473) > 0) && (mpz_cmp(n, conv2474) < 0))) {
    mpz_t conv2475;
    mpz_init( conv2475 );
    mpz_set_si(conv2475, (long) 6);
    if2477 = (mpz_cmp(n, conv2475) == 0);
    mpz_clear(conv2475);
  } else {
    mpz_t conv2476;
    mpz_init( conv2476 );
    mpz_set_si(conv2476, (long) 5);
    if2477 = (mpz_cmp(n, conv2476) < 0);
    mpz_clear(conv2476);
  }
  mpz_clear(aux2472);
  mpz_clear(conv2473);
  mpz_clear(conv2474);
  mpz_clear(n);
  int result;
  return if2477;
}

int pvs_bar_d2471(mpz_t n) {
  mpz_t aux2478;
  mpz_init( aux2478 );
  mpz_add_ui( aux2478 , n , (unsigned long int) 3 );
  mpz_t conv2479;
  mpz_init( conv2479 );
  mpz_set_si(conv2479, (long) 6);
  mpz_t conv2480;
  mpz_init( conv2480 );
  mpz_set_si(conv2480, (long) 12);
  int if2483;
  if (((mpz_cmp(aux2478, conv2479) > 0) && (mpz_cmp(n, conv2480) < 0))) {
    mpz_t conv2481;
    mpz_init( conv2481 );
    mpz_set_si(conv2481, (long) 6);
    if2483 = (mpz_cmp(n, conv2481) == 0);
    mpz_clear(conv2481);
  } else {
    mpz_t conv2482;
    mpz_init( conv2482 );
    mpz_set_si(conv2482, (long) 5);
    if2483 = (mpz_cmp(n, conv2482) < 0);
    mpz_clear(conv2482);
  }
  mpz_clear(aux2478);
  mpz_clear(conv2479);
  mpz_clear(conv2480);
  mpz_clear(n);
  int result;
  return if2483;
}

void pvs_foo2484(mpz_t result, mpz_t x) {
  mpz_t conv2486;
  mpz_init( conv2486 );
  mpz_set_si(conv2486, (long) 0);
  mpz_t if2487;
  mpz_init( if2487 );
  if ((mpz_cmp(x, conv2486) == 0)) {
    mpz_set_si(if2487, (long) 1);
  } else {
    mpz_add_ui( if2487 , x , (unsigned long int) 3 );
  }
  mpz_clear(conv2486);
  mpz_add_ui( result , if2487 , (unsigned long int) 1 );
  mpz_clear(x);
  mpz_clear(if2487);
}

void pvs_foo_d2485(mpz_t result, mpz_t x) {
  mpz_t conv2488;
  mpz_init( conv2488 );
  mpz_set_si(conv2488, (long) 0);
  mpz_t if2489;
  mpz_init( if2489 );
  if ((mpz_cmp(x, conv2488) == 0)) {
    mpz_set_si(if2489, (long) 1);
  } else {
    mpz_add_ui( if2489 , x , (unsigned long int) 3 );
  }
  mpz_clear(conv2488);
  mpz_add_ui( result , if2489 , (unsigned long int) 1 );
  mpz_clear(x);
  mpz_clear(if2489);
}

void pvs_add22490(mpz_t result, mpz_t a) {
  mpz_t conv2492;
  mpz_init( conv2492 );
  mpz_set_si(conv2492, (long) 1);
  mpz_t if2493;
  mpz_init( if2493 );
  if ((mpz_cmp(a, conv2492) == 0)) {
    mpz_set_si(if2493, (long) 1);
  } else {
    mpz_set_si(if2493, (long) 0);
  }
  mpz_clear(conv2492);
  mpz_t c;
  mpz_init( c );
  mpz_add( c , a , if2493 );
  mpz_t d;
  mpz_init( d );
  mpz_set_si(d, (long) 2);
  mpz_t aux2494;
  mpz_init( aux2494 );
  mpz_add( aux2494 , c , d );
  mpz_add_ui( result , aux2494 , (unsigned long int) 1 );
  mpz_clear(a);
  mpz_clear(aux2494);
  mpz_clear(if2493);
  mpz_clear(c);
  mpz_clear(d);
}

void pvs_add2_d2491(mpz_t result, mpz_t a) {
  mpz_t conv2495;
  mpz_init( conv2495 );
  mpz_set_si(conv2495, (long) 1);
  mpz_t if2496;
  mpz_init( if2496 );
  if ((mpz_cmp(a, conv2495) == 0)) {
    mpz_set_si(if2496, (long) 1);
  } else {
    mpz_set_si(if2496, (long) 0);
  }
  mpz_clear(conv2495);
  mpz_t c;
  mpz_init( c );
  mpz_add( c , a , if2496 );
  mpz_t d;
  mpz_init( d );
  mpz_set_si(d, (long) 2);
  mpz_t aux2497;
  mpz_init( aux2497 );
  mpz_add( aux2497 , c , d );
  mpz_add_ui( result , aux2497 , (unsigned long int) 1 );
  mpz_clear(a);
  mpz_clear(aux2497);
  mpz_clear(if2496);
  mpz_clear(c);
  mpz_clear(d);
}

void pvs_f2498(mpz_t result, mpz_t x) {
  mpz_t y;
  mpz_init( y );
  mpz_set_si(y, (long) 12);
  mpz_add_ui( result , y , (unsigned long int) 2 );
  mpz_clear(x);
  mpz_clear(y);
}

void pvs_f_d2499(mpz_t result, mpz_t x) {
  mpz_t y;
  mpz_init( y );
  mpz_set_si(y, (long) 12);
  mpz_add_ui( result , y , (unsigned long int) 2 );
  mpz_clear(x);
  mpz_clear(y);
}

void pvs_factorial2500(mpz_t result, mpz_t n) {
  mpz_t conv2502;
  mpz_init( conv2502 );
  mpz_set_si(conv2502, (long) 0);
  if ((mpz_cmp(n, conv2502) == 0)) {
    mpz_set_si(result, (long) 1);
  } else {
    mpz_t aux2503;
    mpz_init( aux2503 );
    mpz_sub_ui( aux2503 , n , (unsigned long int) 1 );
    mpz_t aux2504;
    mpz_init( aux2504 );
    pvs_factorial_d2501( aux2504 , aux2503 );
    mpz_clear(aux2503);
    mpz_mul( result , n , aux2504 );
    mpz_clear(aux2504);
  }
  mpz_clear(n);
  mpz_clear(conv2502);
}

void pvs_factorial_d2501(mpz_t result, mpz_t n) {
  mpz_t conv2505;
  mpz_init( conv2505 );
  mpz_set_si(conv2505, (long) 0);
  if ((mpz_cmp(n, conv2505) == 0)) {
    mpz_set_si(result, (long) 1);
  } else {
    mpz_t aux2506;
    mpz_init( aux2506 );
    mpz_sub_ui( aux2506 , n , (unsigned long int) 1 );
    mpz_t aux2507;
    mpz_init( aux2507 );
    pvs_factorial_d2501( aux2507 , aux2506 );
    mpz_clear(aux2506);
    mpz_mul( result , n , aux2507 );
    mpz_clear(aux2507);
  }
  mpz_clear(n);
  mpz_clear(conv2505);
}