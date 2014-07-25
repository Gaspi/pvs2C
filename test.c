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
  printf("Executing test ...\n");
  return 0;
}


void pvs_adda1680(mpz_t result, mpz_t i) {
  mpz_t c;
  mpz_init(c);
  mpz_set_si(c, (long) *3*);
  mpz_set(result, c);
  mpz_clear(c);
}

void pvs_adda_d1681(mpz_t result, mpz_t i) {
  mpz_t c;
  mpz_init(c);
  mpz_set_si(c, (long) *3*);
  mpz_set(result, c);
  mpz_clear(c);
}

void pvs_f1682(mpz_t result, int a, int b) {
  mpz_set_si(result, (long) (a + b));
}

void pvs_f_d1683(mpz_t result, int a, int b) {
  mpz_set_si(result, (long) (a + b));
}

void pvs_incr1684(mpz_t result, mpz_t x) {
  mpz_t a;
  mpz_init(a);
  mpz_set(a, x);
  mpz_add_ui(result, a, (unsigned long) *1*);
  mpz_clear(a);
}

void pvs_incr_d1685(mpz_t result, mpz_t x) {
  mpz_t a;
  mpz_init(a);
  mpz_set(a, x);
  mpz_add_ui(result, a, (unsigned long) *1*);
  mpz_clear(a);
}

void pvs_norm1686(mpz_t result, mpz_t x, mpz_t y) {
  mpz_t aux1688;
  mpz_init(aux1688);
  mpz_mul(aux1688, x, x);
  mpz_t aux1689;
  mpz_init(aux1689);
  mpz_mul(aux1689, y, y);
  mpz_add(result, aux1688, aux1689);
  mpz_clear(aux1688);
  mpz_clear(aux1689);
}

void pvs_norm_d1687(mpz_t result, mpz_t x, mpz_t y) {
  mpz_t aux1690;
  mpz_init(aux1690);
  mpz_mul(aux1690, x, x);
  mpz_t aux1691;
  mpz_init(aux1691);
  mpz_mul(aux1691, y, y);
  mpz_add(result, aux1690, aux1691);
  mpz_clear(aux1690);
  mpz_clear(aux1691);
}

void pvs_g1692(mpz_t result, int a) {
  pvs_f_d1683(result, a, a);
}

void pvs_g_d1693(mpz_t result, int a) {
  pvs_f_d1683(result, a, a);
}

int pvs_b1694() {
  return 1;
}

int pvs_b_d1695() {
  return 1;
}

int pvs_bar1696(mpz_t n) {
  int if1703;
  mpz_t aux1698;
  mpz_init(aux1698);
  mpz_add_ui(aux1698, n, (unsigned long) *3*);
  mpz_t conv1699;
  mpz_set_si(conv1699, (long) *6*);
  mpz_t conv1700;
  mpz_set_si(conv1700, (long) *12*);
  if (((mpz_cmp(aux1698, conv1699) > 0) && (mpz_cmp(n, conv1700) < 0))) {
    mpz_t conv1701;
    mpz_set_si(conv1701, (long) *6*);
    if1703 = (mpz_cmp(n, conv1701) == 0);
    mpz_clear(conv1701);
  } else {
    mpz_t conv1702;
    mpz_set_si(conv1702, (long) *5*);
    if1703 = (mpz_cmp(n, conv1702) < 0);
    mpz_clear(conv1702);
  }
  mpz_clear(aux1698);
  mpz_clear(conv1699);
  mpz_clear(conv1700);
  int result;
  result = if1703;
  return result;
}

int pvs_bar_d1697(mpz_t n) {
  int if1709;
  mpz_t aux1704;
  mpz_init(aux1704);
  mpz_add_ui(aux1704, n, (unsigned long) *3*);
  mpz_t conv1705;
  mpz_set_si(conv1705, (long) *6*);
  mpz_t conv1706;
  mpz_set_si(conv1706, (long) *12*);
  if (((mpz_cmp(aux1704, conv1705) > 0) && (mpz_cmp(n, conv1706) < 0))) {
    mpz_t conv1707;
    mpz_set_si(conv1707, (long) *6*);
    if1709 = (mpz_cmp(n, conv1707) == 0);
    mpz_clear(conv1707);
  } else {
    mpz_t conv1708;
    mpz_set_si(conv1708, (long) *5*);
    if1709 = (mpz_cmp(n, conv1708) < 0);
    mpz_clear(conv1708);
  }
  mpz_clear(aux1704);
  mpz_clear(conv1705);
  mpz_clear(conv1706);
  int result;
  result = if1709;
  return result;
}

void pvs_foo1710(mpz_t result, mpz_t x) {
  mpz_t if1713;
  mpz_init(if1713);
  mpz_t conv1712;
  mpz_set_si(conv1712, (long) *0*);
  if ((mpz_cmp(x, conv1712) == 0)) {
    mpz_set_si(if1713, (long) *1*);
  } else {
    mpz_add_ui(if1713, x, (unsigned long) *3*);
  }
  mpz_clear(conv1712);
  mpz_add_ui(result, if1713, (unsigned long) *1*);
  mpz_clear(if1713);
}

void pvs_foo_d1711(mpz_t result, mpz_t x) {
  mpz_t if1715;
  mpz_init(if1715);
  mpz_t conv1714;
  mpz_set_si(conv1714, (long) *0*);
  if ((mpz_cmp(x, conv1714) == 0)) {
    mpz_set_si(if1715, (long) *1*);
  } else {
    mpz_add_ui(if1715, x, (unsigned long) *3*);
  }
  mpz_clear(conv1714);
  mpz_add_ui(result, if1715, (unsigned long) *1*);
  mpz_clear(if1715);
}

void pvs_add21716(mpz_t result, mpz_t a) {
  mpz_t c;
  mpz_init(c);
  mpz_t if1719;
  mpz_init(if1719);
  mpz_t conv1718;
  mpz_set_si(conv1718, (long) *1*);
  if ((mpz_cmp(a, conv1718) == 0)) {
    mpz_set_si(if1719, (long) *1*);
  } else {
    mpz_set_si(if1719, (long) *0*);
  }
  mpz_clear(conv1718);
  mpz_add(c, a, if1719);
  mpz_t d;
  mpz_init(d);
  mpz_set_si(d, (long) *2*);
  mpz_t aux1720;
  mpz_init(aux1720);
  mpz_add(aux1720, c, d);
  mpz_add_ui(result, aux1720, (unsigned long) *1*);
  mpz_clear(aux1720);
  mpz_clear(if1719);
  mpz_clear(c);
  mpz_clear(d);
}

void pvs_add2_d1717(mpz_t result, mpz_t a) {
  mpz_t c;
  mpz_init(c);
  mpz_t if1722;
  mpz_init(if1722);
  mpz_t conv1721;
  mpz_set_si(conv1721, (long) *1*);
  if ((mpz_cmp(a, conv1721) == 0)) {
    mpz_set_si(if1722, (long) *1*);
  } else {
    mpz_set_si(if1722, (long) *0*);
  }
  mpz_clear(conv1721);
  mpz_add(c, a, if1722);
  mpz_t d;
  mpz_init(d);
  mpz_set_si(d, (long) *2*);
  mpz_t aux1723;
  mpz_init(aux1723);
  mpz_add(aux1723, c, d);
  mpz_add_ui(result, aux1723, (unsigned long) *1*);
  mpz_clear(aux1723);
  mpz_clear(if1722);
  mpz_clear(c);
  mpz_clear(d);
}

void pvs_f1724(mpz_t result, mpz_t x) {
  mpz_t y;
  mpz_init(y);
  mpz_set_si(y, (long) *12*);
  mpz_add_ui(result, y, (unsigned long) *2*);
  mpz_clear(y);
}

void pvs_f_d1725(mpz_t result, mpz_t x) {
  mpz_t y;
  mpz_init(y);
  mpz_set_si(y, (long) *12*);
  mpz_add_ui(result, y, (unsigned long) *2*);
  mpz_clear(y);
}

void pvs_factorial1726(mpz_t result, mpz_t n) {
  mpz_t conv1728;
  mpz_set_si(conv1728, (long) *0*);
  if ((mpz_cmp(n, conv1728) == 0)) {
    mpz_set_si(result, (long) *1*);
  } else {
    mpz_t aux1730;
    mpz_init(aux1730);
    mpz_t aux1729;
    mpz_init(aux1729);
    mpz_sub_ui(aux1729, n, (unsigned long) *1*);
    pvs_factorial_d1727(aux1730, aux1729);
    mpz_clear(aux1729);
    mpz_mul(result, n, aux1730);
    mpz_clear(aux1730);
  }
  mpz_clear(conv1728);
}

void pvs_factorial_d1727(mpz_t result, mpz_t n) {
  mpz_t conv1731;
  mpz_set_si(conv1731, (long) *0*);
  if ((mpz_cmp(n, conv1731) == 0)) {
    mpz_set_si(result, (long) *1*);
  } else {
    mpz_t aux1733;
    mpz_init(aux1733);
    mpz_t aux1732;
    mpz_init(aux1732);
    mpz_sub_ui(aux1732, n, (unsigned long) *1*);
    pvs_factorial_d1727(aux1733, aux1732);
    mpz_clear(aux1732);
    mpz_mul(result, n, aux1733);
    mpz_clear(aux1733);
  }
  mpz_clear(conv1731);
}