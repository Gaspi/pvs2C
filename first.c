/*
C file generated from first.pvs
Make sure to link GMP and PVS.c in compilation:
    gcc -o first first.c PVS.c -lgmp
    ./first
*/

#include<stdio.h>
#include "PVS.h"
#include "first.h"

#define TRUE 1
#define FALSE 0

int main(void) {
  printf("Executing first ...\n");
  return 0;
}

void pvs_f715(mpq_t result, mpq_t x) {
  copy_mpq_t(result, x);
}

void pvs_d_f716(mpq_t result, mpq_t x) {
  copy_mpq_t(result, x);
}

void pvs_g717(mpq_t result, mpz_t x, mpq_t y) {
  mpq_t conv720;
  mpq_init(conv720);
  mpq_t_from_mpz_t(conv720, x);
  mpq_add(result, conv720, y);
  mpq_clear(conv720);
}

void pvs_d_g718(mpq_t result, mpz_t x, mpq_t y) {
  mpq_t conv720;
  mpq_init(conv720);
  mpq_t_from_mpz_t(conv720, x);
  mpq_add(result, conv720, y);
  mpq_clear(conv720);
}

void pvs_a721(mpz_t result) {
  mpz_t conv727;
  mpz_init(conv727);
  mpz_t_from_int(conv727, 1);
  mpq_t conv728;
  mpq_init(conv728);
  mpq_t_from_int(conv728, 0);
  mpq_t aux729;
  mpq_init(aux729);
  pvs_d_f716(aux729, conv728);
  mpq_clear(conv728);
  mpq_t set730;
  mpq_init(set730);
  pvs_d_g718(set730, conv727, aux729);
  mpq_clear(aux729);
  mpz_clear(conv727);
  mpz_t_from_mpq_t(result, set730);
  mpq_clear(set730);
}

void pvs_d_a722(mpz_t result) {
  mpz_t conv727;
  mpz_init(conv727);
  mpz_t_from_int(conv727, 1);
  mpq_t conv728;
  mpq_init(conv728);
  mpq_t_from_int(conv728, 0);
  mpq_t aux729;
  mpq_init(aux729);
  pvs_d_f716(aux729, conv728);
  mpq_clear(conv728);
  mpq_t set730;
  mpq_init(set730);
  pvs_d_g718(set730, conv727, aux729);
  mpq_clear(aux729);
  mpz_clear(conv727);
  mpz_t_from_mpq_t(result, set730);
  mpq_clear(set730);
}

void pvs_adda731(mpz_t result, mpz_t i) {
  mpz_t aux736;
  mpz_init(aux736);
  pvs_a721(aux736);
  int conv737;
  conv737 = int_from_mpz_t(aux736);
  int conv738;
  conv738 = int_from_mpz_t(i);
  mpz_t_from_int(result, (conv737 + conv738));
  mpz_clear(aux736);
}

void pvs_d_adda732(mpz_t result, mpz_t i) {
  mpz_t aux736;
  mpz_init(aux736);
  pvs_a721(aux736);
  int conv737;
  conv737 = int_from_mpz_t(aux736);
  int conv738;
  conv738 = int_from_mpz_t(i);
  mpz_t_from_int(result, (conv737 + conv738));
  mpz_clear(aux736);
}

void pvs_foo739(mpz_t result, mpz_t x) {
  int conv748;
  conv748 = int_from_mpz_t(x);
  int aux754;
  if(((conv748 == 0) && (TRUE && (TRUE  FALSE)))) {
    int conv749;
    conv749 = int_from_mpz_t(x);
    int aux750;
    if(((conv749 + 1) > 3)) {
      aux750 = 0;
    } else {
      aux750 = 8;
    }
    int aux751;
    pvsTimes(aux751, 7, aux750);
    aux754 = aux751;
  } else {
    int aux752;
    if((1 < 1)) {
      aux752 = 6;
    } else {
      aux752 = 3;
    }
    int aux753;
    pvsSub(aux753, 8, aux752);
    aux754 = aux753;
  }
  mpz_t_from_int(result, (1 + aux754));
}

void pvs_d_foo740(mpz_t result, mpz_t x) {
  int conv748;
  conv748 = int_from_mpz_t(x);
  int aux754;
  if(((conv748 == 0) && (TRUE && (TRUE  FALSE)))) {
    int conv749;
    conv749 = int_from_mpz_t(x);
    int aux750;
    if(((conv749 + 1) > 3)) {
      aux750 = 0;
    } else {
      aux750 = 8;
    }
    int aux751;
    pvsTimes(aux751, 7, aux750);
    aux754 = aux751;
  } else {
    int aux752;
    if((1 < 1)) {
      aux752 = 6;
    } else {
      aux752 = 3;
    }
    int aux753;
    pvsSub(aux753, 8, aux752);
    aux754 = aux753;
  }
  mpz_t_from_int(result, (1 + aux754));
}

void pvs_add2755(mpz_t result, mpz_t a) {
  int conv764;
  conv764 = int_from_mpz_t(a);
  int conv765;
  conv765 = int_from_mpz_t(a);
  int aux766;
  if((conv765 == 1)) {
    aux766 = 1;
  } else {
    aux766 = 0;
  }
  mpz_t conv767;
  mpz_init(conv767);
  mpz_t_from_int(conv767, (conv764 + aux766));
  mpz_t conv768;
  mpz_init(conv768);
  mpz_t_from_int(conv768, 2);
  mpz_t c = conv767;
  mpz_t d = conv768;
  int conv769;
  conv769 = int_from_mpz_t(c);
  int conv770;
  conv770 = int_from_mpz_t(d);
  mpz_t_from_int(result, ((conv769 + conv770) + 1));
  mpz_clear(conv768);
  mpz_clear(conv767);
}

void pvs_d_add2756(mpz_t result, mpz_t a) {
  int conv764;
  conv764 = int_from_mpz_t(a);
  int conv765;
  conv765 = int_from_mpz_t(a);
  int aux766;
  if((conv765 == 1)) {
    aux766 = 1;
  } else {
    aux766 = 0;
  }
  mpz_t conv767;
  mpz_init(conv767);
  mpz_t_from_int(conv767, (conv764 + aux766));
  mpz_t conv768;
  mpz_init(conv768);
  mpz_t_from_int(conv768, 2);
  mpz_t c = conv767;
  mpz_t d = conv768;
  int conv769;
  conv769 = int_from_mpz_t(c);
  int conv770;
  conv770 = int_from_mpz_t(d);
  mpz_t_from_int(result, ((conv769 + conv770) + 1));
  mpz_clear(conv768);
  mpz_clear(conv767);
}

void pvs_factorial771(mpz_t result, mpz_t n) {
  int conv782;
  conv782 = int_from_mpz_t(n);
  int set790;
  if((conv782 == 0)) {
    set790 = 1;
  } else {
    int conv783;
    conv783 = int_from_mpz_t(n);
    int conv784;
    conv784 = int_from_mpz_t(n);
    int aux785;
    pvsSub(aux785, conv784, 1);
    mpz_t conv786;
    mpz_init(conv786);
    mpz_t_from_int(conv786, aux785);
    mpz_t aux787;
    mpz_init(aux787);
    pvs_d_factorial772(aux787, conv786);
    mpz_clear(conv786);
    int conv788;
    conv788 = int_from_mpz_t(aux787);
    int aux789;
    pvsTimes(aux789, conv783, conv788);
    mpz_clear(aux787);
    set790 = aux789;
  }
  mpz_t_from_int(result, set790);
}

void pvs_d_factorial772(mpz_t result, mpz_t n) {
  int conv782;
  conv782 = int_from_mpz_t(n);
  int set790;
  if((conv782 == 0)) {
    set790 = 1;
  } else {
    int conv783;
    conv783 = int_from_mpz_t(n);
    int conv784;
    conv784 = int_from_mpz_t(n);
    int aux785;
    pvsSub(aux785, conv784, 1);
    mpz_t conv786;
    mpz_init(conv786);
    mpz_t_from_int(conv786, aux785);
    mpz_t aux787;
    mpz_init(aux787);
    pvs_d_factorial772(aux787, conv786);
    mpz_clear(conv786);
    int conv788;
    conv788 = int_from_mpz_t(aux787);
    int aux789;
    pvsTimes(aux789, conv783, conv788);
    mpz_clear(aux787);
    set790 = aux789;
  }
  mpz_t_from_int(result, set790);
}

void pvs_binomial791(mpz_t result, mpz_t a, mpz_t b) {
  int conv811;
  conv811 = int_from_mpz_t(b);
  int set828;
  if((conv811 == 0)) {
    set828 = 1;
  } else {
    int conv812;
    conv812 = int_from_mpz_t(a);
    int aux827;
    if((conv812 == 0)) {
      aux827 = 0;
    } else {
      int conv813;
      conv813 = int_from_mpz_t(a);
      int aux814;
      pvsSub(aux814, conv813, 1);
      mpz_t conv815;
      mpz_init(conv815);
      mpz_t_from_int(conv815, aux814);
      int conv816;
      conv816 = int_from_mpz_t(b);
      int aux817;
      pvsSub(aux817, conv816, 1);
      mpz_t conv818;
      mpz_init(conv818);
      mpz_t_from_int(conv818, aux817);
      mpz_t aux819;
      mpz_init(aux819);
      pvs_d_binomial792(aux819, conv815, conv818);
      mpz_clear(conv818);
      mpz_clear(conv815);
      int conv820;
      conv820 = int_from_mpz_t(aux819);
      int conv821;
      conv821 = int_from_mpz_t(a);
      int aux822;
      pvsSub(aux822, conv821, 1);
      mpz_t conv823;
      mpz_init(conv823);
      mpz_t_from_int(conv823, aux822);
      mpz_t aux824;
      mpz_init(aux824);
      pvs_d_binomial792(aux824, conv823, b);
      mpz_clear(conv823);
      int conv825;
      conv825 = int_from_mpz_t(aux824);
      int aux826;
      int aux826 = (conv820 + conv825);
      mpz_clear(aux824);
      mpz_clear(aux819);
      aux827 = aux826;
    }
    set828 = aux827;
  }
  mpz_t_from_int(result, set828);
}

void pvs_d_binomial792(mpz_t result, mpz_t a, mpz_t b) {
  int conv811;
  conv811 = int_from_mpz_t(b);
  int set828;
  if((conv811 == 0)) {
    set828 = 1;
  } else {
    int conv812;
    conv812 = int_from_mpz_t(a);
    int aux827;
    if((conv812 == 0)) {
      aux827 = 0;
    } else {
      int conv813;
      conv813 = int_from_mpz_t(a);
      int aux814;
      pvsSub(aux814, conv813, 1);
      mpz_t conv815;
      mpz_init(conv815);
      mpz_t_from_int(conv815, aux814);
      int conv816;
      conv816 = int_from_mpz_t(b);
      int aux817;
      pvsSub(aux817, conv816, 1);
      mpz_t conv818;
      mpz_init(conv818);
      mpz_t_from_int(conv818, aux817);
      mpz_t aux819;
      mpz_init(aux819);
      pvs_d_binomial792(aux819, conv815, conv818);
      mpz_clear(conv818);
      mpz_clear(conv815);
      int conv820;
      conv820 = int_from_mpz_t(aux819);
      int conv821;
      conv821 = int_from_mpz_t(a);
      int aux822;
      pvsSub(aux822, conv821, 1);
      mpz_t conv823;
      mpz_init(conv823);
      mpz_t_from_int(conv823, aux822);
      mpz_t aux824;
      mpz_init(aux824);
      pvs_d_binomial792(aux824, conv823, b);
      mpz_clear(conv823);
      int conv825;
      conv825 = int_from_mpz_t(aux824);
      int aux826;
      int aux826 = (conv820 + conv825);
      mpz_clear(aux824);
      mpz_clear(aux819);
      aux827 = aux826;
    }
    set828 = aux827;
  }
  mpz_t_from_int(result, set828);
}