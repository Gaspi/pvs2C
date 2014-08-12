// ---------------------------------------------
//        C file generated from draft.pvs
// ---------------------------------------------
//   Make sure to link GC.c and GMP in compilation:
//      gcc -o draft draft.c GC.c -lgmp
//      ./draft
// ---------------------------------------------

#include<stdio.h>
#include<gmp.h>
#include "GC.h"
#include "draft.h"

#define TRUE 1
#define FALSE 0

int main(void) {
  GC_start();
  printf("Executing draft ...\n");
  // Insert code here
  GC_quit();
  return 0;
}


pair2510 pvs_a2508() {
  pair2510 result;
  result = GC_malloc(1, sizeof( struct struct_pair2510 ) );
  mpz_init( result->y );
  result->x = 2;
  mpz_set_si(result->y, (long) 12);
  return result;
}

pair2510 pvs_a_d2509() {
  pair2510 result;
  result = GC_malloc(1, sizeof( struct struct_pair2510 ) );
  mpz_init( result->y );
  result->x = 2;
  mpz_set_si(result->y, (long) 12);
  return result;
}

int pvs_first2511(pair2510 a) {
  int result;
  result = a->x;
  if( GC_count( a ) == 1 ) {
    mpz_clear(a->y);
  }
  GC_free(a);
  return result;
}

int pvs_first_d2512(pair2510 a) {
  int result;
  result = a->x;
  if( GC_count( a ) == 1 ) {
    mpz_clear(a->y);
  }
  GC_free(a);
  return result;
}

pair2510 pvs_zero2513(pair2510 a) {
  pair2510 result;
  if ( GC_count( a ) == 1 )
    result = a;
  else {
    result = GC_malloc(1, sizeof( struct struct_pair2510 ));
    mpz_init( result->y );
    mpz_set(result->y, a->y);
    result->x = a->x;
  }
  result->x = 0;
  int res2515;
  return result;
}

pair2510 pvs_zero_d2514(pair2510 a) {
  a->x = 0;
  int res2516;
  pair2510 result;
  return a;
}

unsigned long int pvs_a2517() {
  return (unsigned long int) 2;
}

unsigned long int pvs_a_d2518() {
  return (unsigned long int) 2;
}

int pvs_b2519() {
  return (3 + 1);
}

int pvs_b_d2520() {
  return (3 + 1);
}

void pvs_c2521(mpz_t result) {
  mpz_set_si(result, (long) (3 * (1 + 2)));
}

void pvs_c_d2522(mpz_t result) {
  mpz_set_si(result, (long) (3 * (1 + 2)));
}

int pvs_incr2523(int x) {
  return (x + 1);
}

int pvs_incr_d2524(int x) {
  return (x + 1);
}

int pvs_zero2525(mpz_t x) {
  mpz_clear(x);
  int result;
  return 0;
}

int pvs_zero_d2526(mpz_t x) {
  mpz_clear(x);
  int result;
  return 0;
}

int pvs_f2527(int a, int b) {
  mpz_t conv2529;
  mpz_init( conv2529 );
  mpz_set_si(conv2529, (long) b);
  int result;
  result = (int) (pvs_zero_d2526( conv2529 ) * pvs_incr_d2524( a ));
  mpz_clear(conv2529);
  return result;
}

int pvs_f_d2528(int a, int b) {
  mpz_t conv2530;
  mpz_init( conv2530 );
  mpz_set_si(conv2530, (long) b);
  int result;
  result = (int) (pvs_zero_d2526( conv2530 ) * pvs_incr_d2524( a ));
  mpz_clear(conv2530);
  return result;
}

int pvs_f2531(int x) {
  if (((x <= 1) && 1)) {
    if (((x == 0) || (x < 0))) {
      return 0;
    } else {
      return x;
    }
  } else {
    if ((x > 10)) {
      return 10;
    } else {
      return (x - 5);
    }
  }
}

int pvs_f_d2532(int x) {
  if (((x <= 1) && 1)) {
    if (((x == 0) || (x < 0))) {
      return 0;
    } else {
      return x;
    }
  } else {
    if ((x > 10)) {
      return 10;
    } else {
      return (x - 5);
    }
  }
}

int pvs_t2539(int x) {
  return x;
}

int pvs_t_d2540(int x) {
  return x;
}

int* pvs_id22541(int* t103946) {
  return t103946;
}

int* pvs_id2_d2542(int* t103946) {
  return t103946;
}

int* pvs_f2545(int x) {
  int* result;
  result = GC_malloc(1000, sizeof(int) );
  int i2547;
  for(i2547 = 0; i2547 < 1000; i2547++) {
    result[i2547] = pvs_t_d2540( i2547 );
  }
  return result;
}

int* pvs_f_d2546(int x) {
  int* result;
  result = GC_malloc(1000, sizeof(int) );
  int i2548;
  for(i2548 = 0; i2548 < 1000; i2548++) {
    result[i2548] = pvs_t_d2540( i2548 );
  }
  return result;
}

int* pvs_update2549(int* x) {
  int* result;
  if ( GC_count( x ) == 1 )
    result = x;
  else {
    result = GC_malloc(1000, sizeof(int) );
    int i2703;
    for(i2703 = 0; i2703 < 1000; i2703++) {
      result[i2703] = x[i2703];
    }
  }
  result[0] = 0;
  int L2551;
  int res2552;
  return result;
}

int* pvs_update_d2550(int* x) {
  x[0] = 0;
  int res2554;
  int L2553;
  int* result;
  return x;
}

int* pvs_t22567(int x) {
  int* result;
  result = GC_malloc(1000, sizeof(int) );
  int i2569;
  for(i2569 = 0; i2569 < 1000; i2569++) {
    result[i2569] = (x + i2569);
  }
  return result;
}

int* pvs_t2_d2568(int x) {
  int* result;
  result = GC_malloc(1000, sizeof(int) );
  int i2570;
  for(i2570 = 0; i2570 < 1000; i2570++) {
    result[i2570] = (x + i2570);
  }
  return result;
}

int* pvs_id2571(int** t103946) {
  int* result;
  result = (int*) t103946[0];
  if( GC_count( t103946 ) == 1 ) {
    int i2704;
    for(i2704 = 0; i2704 < 1000; i2704++) {
      GC_free(t103946[i2704]);
    }
  }
  GC_free(t103946);
  int** a;
  return result;
}

int* pvs_id_d2572(int** t103946) {
  int* result;
  result = (int*) t103946[0];
  if( GC_count( t103946 ) == 1 ) {
    int i2706;
    for(i2706 = 0; i2706 < 1000; i2706++) {
      GC_free(t103946[i2706]);
    }
  }
  GC_free(t103946);
  int** a;
  return result;
}

int* pvs_te2603() {
  int* aux2606;
  aux2606 = GC_malloc(1000, sizeof(int) );
  int i2605;
  for(i2605 = 0; i2605 < 1000; i2605++) {
    aux2606[i2605] = pvs_t_d2540( i2605 );
  }
  return pvs_update_d2550( pvs_update_d2550( aux2606 ) );
}

int* pvs_te_d2604() {
  int* aux2608;
  aux2608 = GC_malloc(1000, sizeof(int) );
  int i2607;
  for(i2607 = 0; i2607 < 1000; i2607++) {
    aux2608[i2607] = pvs_t_d2540( i2607 );
  }
  return pvs_update_d2550( pvs_update_d2550( aux2608 ) );
}

int** pvs_update2611(int** x) {
  int* res2618;
  res2618 = GC_malloc(1000, sizeof(int) );
  int i2619;
  for(i2619 = 0; i2619 < 1000; i2619++) {
    res2618[i2619] = i2619;
  }
  int** result;
  if ( GC_count( x ) == 1 )
    result = x;
  else {
    result = GC_malloc(1000, sizeof(int*) );
    int i2708;
    for(i2708 = 0; i2708 < 1000; i2708++) {
      result[i2708] = (int*) x[i2708];
    }
  }
  int* E2614;
  E2614 = GC_malloc(1000, sizeof(int) );
  int i2709;
  for(i2709 = 0; i2709 < 1000; i2709++) {
    E2614[i2709] = result[0][i2709];
  }
  E2614[1] = 0;
  result[0] = (int*) E2614;
  result[1] = (int*) res2618;
  int L2613;
  int L2615;
  int res2616;
  int L2617;
  return result;
}

int** pvs_update_d2612(int** x) {
  int* res2625;
  res2625 = GC_malloc(1000, sizeof(int) );
  int i2626;
  for(i2626 = 0; i2626 < 1000; i2626++) {
    res2625[i2626] = i2626;
  }
  int* E2621;
  E2621 = GC_malloc(1000, sizeof(int) );
  int i2710;
  for(i2710 = 0; i2710 < 1000; i2710++) {
    E2621[i2710] = x[0][i2710];
  }
  E2621[1] = 0;
  x[0] = (int*) E2621;
  x[1] = (int*) res2625;
  int** result;
  int L2620;
  int L2622;
  int res2623;
  int L2624;
  return x;
}