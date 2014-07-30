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


void pvs_adda1581(mpz_t result, mpz_t i) {
  mpz_t c;
  mpz_init( c );
  mpz_set_si(c, (long) 3);
  mpz_set(result, c);
  mpz_clear(c);
  mpz_clear(i);
}

void pvs_adda_d1582(mpz_t result, mpz_t i) {
  mpz_t c;
  mpz_init( c );
  mpz_set_si(c, (long) 3);
  mpz_set(result, c);
  mpz_clear(c);
  mpz_clear(i);
}

void pvs_f1583(mpz_t result, int a, int b) {
  mpz_set_si(result, (long) (a + b));
}

void pvs_f_d1584(mpz_t result, int a, int b) {
  mpz_set_si(result, (long) (a + b));
}

void pvs_incr1585(mpz_t result, mpz_t x) {
  mpz_t a;
  mpz_init( a );
  mpz_set(a, x);
  mpz_add_ui( result , a , (uli) 1 );
  mpz_clear(x);
  mpz_clear(a);
}

void pvs_incr_d1586(mpz_t result, mpz_t x) {
  mpz_t a;
  mpz_init( a );
  mpz_set(a, x);
  mpz_add_ui( result , a , (uli) 1 );
  mpz_clear(x);
  mpz_clear(a);
}

void pvs_norm1587(mpz_t result, mpz_t x, mpz_t y) {
  mpz_t aux1589;
  mpz_init( aux1589 );
  mpz_mul( aux1589 , x , x );
  mpz_t aux1590;
  mpz_init( aux1590 );
  mpz_mul( aux1590 , y , y );
  mpz_add( result , aux1589 , aux1590 );
  mpz_clear(x);
  mpz_clear(y);
  mpz_clear(aux1589);
  mpz_clear(aux1590);
}

void pvs_norm_d1588(mpz_t result, mpz_t x, mpz_t y) {
  mpz_t aux1591;
  mpz_init( aux1591 );
  mpz_mul( aux1591 , x , x );
  mpz_t aux1592;
  mpz_init( aux1592 );
  mpz_mul( aux1592 , y , y );
  mpz_add( result , aux1591 , aux1592 );
  mpz_clear(x);
  mpz_clear(y);
  mpz_clear(aux1591);
  mpz_clear(aux1592);
}

void pvs_g1593(mpz_t result, int a) {
  pvs_f_d1584( result , a , a );
}

void pvs_g_d1594(mpz_t result, int a) {
  pvs_f_d1584( result , a , a );
}

int pvs_b1595() {
  return 1;
}

int pvs_b_d1596() {
  return 1;
}

int pvs_bar1597(mpz_t n) {
  mpz_t aux1599;
  mpz_init( aux1599 );
  mpz_add_ui( aux1599 , n , (uli) 3 );
  mpz_t conv1600;
  mpz_init( conv1600 );
  mpz_set_si(conv1600, (long) 6);
  mpz_t conv1601;
  mpz_init( conv1601 );
  mpz_set_si(conv1601, (long) 12);
  int if1604;
  if (((mpz_cmp(aux1599, conv1600) > 0) && (mpz_cmp(n, conv1601) < 0))) {
    mpz_t conv1602;
    mpz_init( conv1602 );
    mpz_set_si(conv1602, (long) 6);
    if1604 = (mpz_cmp(n, conv1602) == 0);
    mpz_clear(conv1602);
  } else {
    mpz_t conv1603;
    mpz_init( conv1603 );
    mpz_set_si(conv1603, (long) 5);
    if1604 = (mpz_cmp(n, conv1603) < 0);
    mpz_clear(conv1603);
  }
  mpz_clear(aux1599);
  mpz_clear(conv1600);
  mpz_clear(conv1601);
  mpz_clear(n);
  int result;
  return if1604;
}

int pvs_bar_d1598(mpz_t n) {
  mpz_t aux1605;
  mpz_init( aux1605 );
  mpz_add_ui( aux1605 , n , (uli) 3 );
  mpz_t conv1606;
  mpz_init( conv1606 );
  mpz_set_si(conv1606, (long) 6);
  mpz_t conv1607;
  mpz_init( conv1607 );
  mpz_set_si(conv1607, (long) 12);
  int if1610;
  if (((mpz_cmp(aux1605, conv1606) > 0) && (mpz_cmp(n, conv1607) < 0))) {
    mpz_t conv1608;
    mpz_init( conv1608 );
    mpz_set_si(conv1608, (long) 6);
    if1610 = (mpz_cmp(n, conv1608) == 0);
    mpz_clear(conv1608);
  } else {
    mpz_t conv1609;
    mpz_init( conv1609 );
    mpz_set_si(conv1609, (long) 5);
    if1610 = (mpz_cmp(n, conv1609) < 0);
    mpz_clear(conv1609);
  }
  mpz_clear(aux1605);
  mpz_clear(conv1606);
  mpz_clear(conv1607);
  mpz_clear(n);
  int result;
  return if1610;
}

void pvs_foo1611(mpz_t result, mpz_t x) {
  mpz_t conv1613;
  mpz_init( conv1613 );
  mpz_set_si(conv1613, (long) 0);
  mpz_t if1614;
  mpz_init( if1614 );
  if ((mpz_cmp(x, conv1613) == 0)) {
    mpz_set_si(if1614, (long) 1);
  } else {
    mpz_add_ui( if1614 , x , (uli) 3 );
  }
  mpz_clear(conv1613);
  mpz_add_ui( result , if1614 , (uli) 1 );
  mpz_clear(x);
  mpz_clear(if1614);
}

void pvs_foo_d1612(mpz_t result, mpz_t x) {
  mpz_t conv1615;
  mpz_init( conv1615 );
  mpz_set_si(conv1615, (long) 0);
  mpz_t if1616;
  mpz_init( if1616 );
  if ((mpz_cmp(x, conv1615) == 0)) {
    mpz_set_si(if1616, (long) 1);
  } else {
    mpz_add_ui( if1616 , x , (uli) 3 );
  }
  mpz_clear(conv1615);
  mpz_add_ui( result , if1616 , (uli) 1 );
  mpz_clear(x);
  mpz_clear(if1616);
}

void pvs_add21617(mpz_t result, mpz_t a) {
  mpz_t conv1619;
  mpz_init( conv1619 );
  mpz_set_si(conv1619, (long) 1);
  mpz_t if1620;
  mpz_init( if1620 );
  if ((mpz_cmp(a, conv1619) == 0)) {
    mpz_set_si(if1620, (long) 1);
  } else {
    mpz_set_si(if1620, (long) 0);
  }
  mpz_clear(conv1619);
  mpz_t c;
  mpz_init( c );
  mpz_add( c , a , if1620 );
  mpz_t d;
  mpz_init( d );
  mpz_set_si(d, (long) 2);
  mpz_t aux1621;
  mpz_init( aux1621 );
  mpz_add( aux1621 , c , d );
  mpz_add_ui( result , aux1621 , (uli) 1 );
  mpz_clear(a);
  mpz_clear(aux1621);
  mpz_clear(if1620);
  mpz_clear(c);
  mpz_clear(d);
}

void pvs_add2_d1618(mpz_t result, mpz_t a) {
  mpz_t conv1622;
  mpz_init( conv1622 );
  mpz_set_si(conv1622, (long) 1);
  mpz_t if1623;
  mpz_init( if1623 );
  if ((mpz_cmp(a, conv1622) == 0)) {
    mpz_set_si(if1623, (long) 1);
  } else {
    mpz_set_si(if1623, (long) 0);
  }
  mpz_clear(conv1622);
  mpz_t c;
  mpz_init( c );
  mpz_add( c , a , if1623 );
  mpz_t d;
  mpz_init( d );
  mpz_set_si(d, (long) 2);
  mpz_t aux1624;
  mpz_init( aux1624 );
  mpz_add( aux1624 , c , d );
  mpz_add_ui( result , aux1624 , (uli) 1 );
  mpz_clear(a);
  mpz_clear(aux1624);
  mpz_clear(if1623);
  mpz_clear(c);
  mpz_clear(d);
}

void pvs_f1625(mpz_t result, mpz_t x) {
  mpz_t y;
  mpz_init( y );
  mpz_set_si(y, (long) 12);
  mpz_add_ui( result , y , (uli) 2 );
  mpz_clear(x);
  mpz_clear(y);
}

void pvs_f_d1626(mpz_t result, mpz_t x) {
  mpz_t y;
  mpz_init( y );
  mpz_set_si(y, (long) 12);
  mpz_add_ui( result , y , (uli) 2 );
  mpz_clear(x);
  mpz_clear(y);
}

void pvs_factorial1627(mpz_t result, mpz_t n) {
  mpz_t conv1629;
  mpz_init( conv1629 );
  mpz_set_si(conv1629, (long) 0);
  if ((mpz_cmp(n, conv1629) == 0)) {
    mpz_set_si(result, (long) 1);
  } else {
    mpz_t aux1630;
    mpz_init( aux1630 );
    mpz_sub_ui( aux1630 , n , (uli) 1 );
    mpz_t aux1631;
    mpz_init( aux1631 );
    pvs_factorial_d1628( aux1631 , aux1630 );
    mpz_clear(aux1630);
    mpz_mul( result , n , aux1631 );
    mpz_clear(aux1631);
  }
  mpz_clear(n);
  mpz_clear(conv1629);
}

void pvs_factorial_d1628(mpz_t result, mpz_t n) {
  mpz_t conv1632;
  mpz_init( conv1632 );
  mpz_set_si(conv1632, (long) 0);
  if ((mpz_cmp(n, conv1632) == 0)) {
    mpz_set_si(result, (long) 1);
  } else {
    mpz_t aux1633;
    mpz_init( aux1633 );
    mpz_sub_ui( aux1633 , n , (uli) 1 );
    mpz_t aux1634;
    mpz_init( aux1634 );
    pvs_factorial_d1628( aux1634 , aux1633 );
    mpz_clear(aux1633);
    mpz_mul( result , n , aux1634 );
    mpz_clear(aux1634);
  }
  mpz_clear(n);
  mpz_clear(conv1632);
}