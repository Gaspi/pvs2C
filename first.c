// ---------------------------------------------
//        C file generated from first.pvs
// ---------------------------------------------
//   Make sure to link GMP in compilation:
//      gcc -o first first.c -lgmp
//      ./first
// ---------------------------------------------

#include<stdio.h>
#include<gmp.h>
#include "first.h"

#define TRUE 1
#define FALSE 0

int main(void) {
  printf("Executing first ...\n");
  return 0;
}


int pvs_f814(int x) {
  int result;
  result = x;
  return result;
}

int pvs_d_f815(int x) {
  int result;
  result = x;
  return result;
}

void pvs_g816(mpq_t result, mpz_t x, mpq_t y) {
  mpq_t conv821;
  mpq_init(conv821);
  mpq_set_z(conv821, x);
  mpq_canonicalize(conv821);
  mpq_t aux822;
  mpq_init(aux822);
  mpq_add(aux822, conv821, y);
  mpq_clear(conv821);
  mpq_t aux823;
  mpq_init(aux823);
  mpz_set_si(mpq_numref(aux823), (long) 5);
  mpz_set_si(mpq_denref(aux823), (long) 10);
  mpq_canonicalize(aux823);
  mpq_add(result, aux822, aux823);
  mpq_clear(aux822);
  mpq_clear(aux823);
}

void pvs_d_g817(mpq_t result, mpz_t x, mpq_t y) {
  mpq_t conv821;
  mpq_init(conv821);
  mpq_set_z(conv821, x);
  mpq_canonicalize(conv821);
  mpq_t aux822;
  mpq_init(aux822);
  mpq_add(aux822, conv821, y);
  mpq_clear(conv821);
  mpq_t aux823;
  mpq_init(aux823);
  mpz_set_si(mpq_numref(aux823), (long) 5);
  mpz_set_si(mpq_denref(aux823), (long) 10);
  mpq_canonicalize(aux823);
  mpq_add(result, aux822, aux823);
  mpq_clear(aux822);
  mpq_clear(aux823);
}

void pvs_a824(mpz_t result) {
  mpz_t conv829;
  mpz_init(conv829);
  mpz_set_si(conv829, (long) 1);
  mpq_t conv830;
  mpq_init(conv830);
  mpq_set_d(conv830, (double) pvs_d_f815(0) );
  mpq_canonicalize(conv830);
  mpq_t set831;
  mpq_init(set831);
  pvs_d_g817(set831, conv829, conv830);
  mpz_clear(conv829);
  mpq_clear(conv830);
  mpq_get_num(result, set831);
  mpq_clear(set831);
}

void pvs_d_a825(mpz_t result) {
  mpz_t conv829;
  mpz_init(conv829);
  mpz_set_si(conv829, (long) 1);
  mpq_t conv830;
  mpq_init(conv830);
  mpq_set_d(conv830, (double) pvs_d_f815(0) );
  mpq_canonicalize(conv830);
  mpq_t set831;
  mpq_init(set831);
  pvs_d_g817(set831, conv829, conv830);
  mpz_clear(conv829);
  mpq_clear(conv830);
  mpq_get_num(result, set831);
  mpq_clear(set831);
}

void pvs_adda832(mpz_t result, mpz_t i) {
  mpz_t aux835;
  mpz_init(aux835);
  pvs_a824(aux835);
  mpz_add(result, aux835, i);
  mpz_clear(aux835);
}

void pvs_d_adda833(mpz_t result, mpz_t i) {
  mpz_t aux835;
  mpz_init(aux835);
  pvs_a824(aux835);
  mpz_add(result, aux835, i);
  mpz_clear(aux835);
}

void pvs_b836(mpq_t result) {
  if(TRUE) {
    mpz_set_si(mpq_numref(result), (long) 1);
  } else {
    mpz_set_si(mpq_numref(result), (long) 2);
  }
  if(FALSE) {
    mpz_set_si(mpq_denref(result), (long) 2);
  } else {
    mpz_set_si(mpq_denref(result), (long) 3);
  }
  mpq_canonicalize(result);
}

void pvs_d_b837(mpq_t result) {
  if(TRUE) {
    mpz_set_si(mpq_numref(result), (long) 1);
  } else {
    mpz_set_si(mpq_numref(result), (long) 2);
  }
  if(FALSE) {
    mpz_set_si(mpq_denref(result), (long) 2);
  } else {
    mpz_set_si(mpq_denref(result), (long) 3);
  }
  mpq_canonicalize(result);
}

void pvs_foo838(mpz_t result, mpz_t x) {
  mpz_t conv848;
  mpz_init(conv848);
  mpz_set_si(conv848, (long) 0);
  int aux849;
  aux849 = (mpz_cmp(x, conv848) == 0);
  mpz_clear(conv848);
  mpz_t if855;
  mpz_init(if855);
  if((aux849 && (TRUE && (TRUE || FALSE)))) {
    mpz_t aux850;
    mpz_init(aux850);
    mpz_add_ui(aux850, x, (unsigned long) 1);
    mpz_t conv851;
    mpz_init(conv851);
    mpz_set_si(conv851, (long) 3);
    int aux852;
    aux852 = (mpz_cmp(aux850, conv851) > 0);
    mpz_clear(aux850);
    mpz_clear(conv851);
    mpz_t if853;
    mpz_init(if853);
    if(aux852) {
      mpz_set_si(if853, (long) 0);
    } else {
      mpz_set_si(if853, (long) 8);
    }
    mpz_mul_ui(if855, if853, (unsigned long) 7);
    mpz_clear(if853);
  } else {
    mpz_t if854;
    mpz_init(if854);
    if((1 < 1)) {
      mpz_set_si(if854, (long) 6);
    } else {
      mpz_set_si(if854, (long) 3);
    }
    mpz_ui_sub(if855, (unsigned long) 8, if854);
    mpz_clear(if854);
  }
  mpz_add_ui(result, if855, (unsigned long) 1);
  mpz_clear(if855);
}

void pvs_d_foo839(mpz_t result, mpz_t x) {
  mpz_t conv848;
  mpz_init(conv848);
  mpz_set_si(conv848, (long) 0);
  int aux849;
  aux849 = (mpz_cmp(x, conv848) == 0);
  mpz_clear(conv848);
  mpz_t if855;
  mpz_init(if855);
  if((aux849 && (TRUE && (TRUE || FALSE)))) {
    mpz_t aux850;
    mpz_init(aux850);
    mpz_add_ui(aux850, x, (unsigned long) 1);
    mpz_t conv851;
    mpz_init(conv851);
    mpz_set_si(conv851, (long) 3);
    int aux852;
    aux852 = (mpz_cmp(aux850, conv851) > 0);
    mpz_clear(aux850);
    mpz_clear(conv851);
    mpz_t if853;
    mpz_init(if853);
    if(aux852) {
      mpz_set_si(if853, (long) 0);
    } else {
      mpz_set_si(if853, (long) 8);
    }
    mpz_mul_ui(if855, if853, (unsigned long) 7);
    mpz_clear(if853);
  } else {
    mpz_t if854;
    mpz_init(if854);
    if((1 < 1)) {
      mpz_set_si(if854, (long) 6);
    } else {
      mpz_set_si(if854, (long) 3);
    }
    mpz_ui_sub(if855, (unsigned long) 8, if854);
    mpz_clear(if854);
  }
  mpz_add_ui(result, if855, (unsigned long) 1);
  mpz_clear(if855);
}

void pvs_add2856(mpz_t result, mpz_t a) {
  mpz_t conv864;
  mpz_init(conv864);
  mpz_set_si(conv864, (long) 1);
  int aux865;
  aux865 = (mpz_cmp(a, conv864) == 0);
  mpz_clear(conv864);
  mpz_t if866;
  mpz_init(if866);
  if(aux865) {
    mpz_set_si(if866, (long) 1);
  } else {
    mpz_set_si(if866, (long) 0);
  }
  mpz_t aux867;
  mpz_init(aux867);
  mpz_add(aux867, a, if866);
  mpz_clear(if866);
  mpz_t conv868;
  mpz_init(conv868);
  mpz_set_si(conv868, (long) 2);
  mpz_t c = aux867;
  mpz_t d = conv868;
  mpz_t aux869;
  mpz_init(aux869);
  mpz_add(aux869, c, d);
  mpz_add_ui(result, aux869, (unsigned long) 1);
  mpz_clear(aux867);
  mpz_clear(conv868);
  mpz_clear(aux869);
}

void pvs_d_add2857(mpz_t result, mpz_t a) {
  mpz_t conv864;
  mpz_init(conv864);
  mpz_set_si(conv864, (long) 1);
  int aux865;
  aux865 = (mpz_cmp(a, conv864) == 0);
  mpz_clear(conv864);
  mpz_t if866;
  mpz_init(if866);
  if(aux865) {
    mpz_set_si(if866, (long) 1);
  } else {
    mpz_set_si(if866, (long) 0);
  }
  mpz_t aux867;
  mpz_init(aux867);
  mpz_add(aux867, a, if866);
  mpz_clear(if866);
  mpz_t conv868;
  mpz_init(conv868);
  mpz_set_si(conv868, (long) 2);
  mpz_t c = aux867;
  mpz_t d = conv868;
  mpz_t aux869;
  mpz_init(aux869);
  mpz_add(aux869, c, d);
  mpz_add_ui(result, aux869, (unsigned long) 1);
  mpz_clear(aux867);
  mpz_clear(conv868);
  mpz_clear(aux869);
}

void pvs_factorial870(mpz_t result, mpz_t n) {
  mpz_t conv876;
  mpz_init(conv876);
  mpz_set_si(conv876, (long) 0);
  int aux877;
  aux877 = (mpz_cmp(n, conv876) == 0);
  mpz_clear(conv876);
  if(aux877) {
    mpz_set_si(result, (long) 1);
  } else {
    mpz_t aux878;
    mpz_init(aux878);
    mpz_sub_ui(aux878, n, (unsigned long) 1);
    mpz_t aux879;
    mpz_init(aux879);
    pvs_d_factorial871(aux879, aux878);
    mpz_clear(aux878);
    mpz_mul(result, n, aux879);
    mpz_clear(aux879);
  }
}

void pvs_d_factorial871(mpz_t result, mpz_t n) {
  mpz_t conv876;
  mpz_init(conv876);
  mpz_set_si(conv876, (long) 0);
  int aux877;
  aux877 = (mpz_cmp(n, conv876) == 0);
  mpz_clear(conv876);
  if(aux877) {
    mpz_set_si(result, (long) 1);
  } else {
    mpz_t aux878;
    mpz_init(aux878);
    mpz_sub_ui(aux878, n, (unsigned long) 1);
    mpz_t aux879;
    mpz_init(aux879);
    pvs_d_factorial871(aux879, aux878);
    mpz_clear(aux878);
    mpz_mul(result, n, aux879);
    mpz_clear(aux879);
  }
}

void pvs_binomial880(mpz_t result, mpz_t a, mpz_t b) {
  mpz_t conv891;
  mpz_init(conv891);
  mpz_set_si(conv891, (long) 0);
  int aux892;
  aux892 = (mpz_cmp(b, conv891) == 0);
  mpz_clear(conv891);
  if(aux892) {
    mpz_set_si(result, (long) 1);
  } else {
    mpz_t conv893;
    mpz_init(conv893);
    mpz_set_si(conv893, (long) 0);
    int aux894;
    aux894 = (mpz_cmp(a, conv893) == 0);
    mpz_clear(conv893);
    if(aux894) {
      mpz_set_si(result, (long) 0);
    } else {
      mpz_t aux895;
      mpz_init(aux895);
      mpz_sub_ui(aux895, a, (unsigned long) 1);
      mpz_t aux896;
      mpz_init(aux896);
      mpz_sub_ui(aux896, b, (unsigned long) 1);
      mpz_t aux897;
      mpz_init(aux897);
      pvs_d_binomial881(aux897, aux895, aux896);
      mpz_clear(aux895);
      mpz_clear(aux896);
      mpz_t aux898;
      mpz_init(aux898);
      mpz_sub_ui(aux898, a, (unsigned long) 1);
      mpz_t aux899;
      mpz_init(aux899);
      pvs_d_binomial881(aux899, aux898, b);
      mpz_clear(aux898);
      mpz_add(result, aux897, aux899);
      mpz_clear(aux897);
      mpz_clear(aux899);
    }
  }
}

void pvs_d_binomial881(mpz_t result, mpz_t a, mpz_t b) {
  mpz_t conv891;
  mpz_init(conv891);
  mpz_set_si(conv891, (long) 0);
  int aux892;
  aux892 = (mpz_cmp(b, conv891) == 0);
  mpz_clear(conv891);
  if(aux892) {
    mpz_set_si(result, (long) 1);
  } else {
    mpz_t conv893;
    mpz_init(conv893);
    mpz_set_si(conv893, (long) 0);
    int aux894;
    aux894 = (mpz_cmp(a, conv893) == 0);
    mpz_clear(conv893);
    if(aux894) {
      mpz_set_si(result, (long) 0);
    } else {
      mpz_t aux895;
      mpz_init(aux895);
      mpz_sub_ui(aux895, a, (unsigned long) 1);
      mpz_t aux896;
      mpz_init(aux896);
      mpz_sub_ui(aux896, b, (unsigned long) 1);
      mpz_t aux897;
      mpz_init(aux897);
      pvs_d_binomial881(aux897, aux895, aux896);
      mpz_clear(aux895);
      mpz_clear(aux896);
      mpz_t aux898;
      mpz_init(aux898);
      mpz_sub_ui(aux898, a, (unsigned long) 1);
      mpz_t aux899;
      mpz_init(aux899);
      pvs_d_binomial881(aux899, aux898, b);
      mpz_clear(aux898);
      mpz_add(result, aux897, aux899);
      mpz_clear(aux897);
      mpz_clear(aux899);
    }
  }
}