/*
C file generated from first.pvs
Make sure to link GMP and PVS.c in compilation:
    gcc -o first first.c -lgmp
    ./first
*/

#include<stdio.h>
#include<gmp.h>
#include "first.h"

#define TRUE 1
#define FALSE 0

int main(void) {
  printf("Executing first ...\n");
  return 0;
}

void pvs_f47(mpq_t result, mpq_t x) {
  mpq_set(result, x);
  mpq_canonicalize(result);
}

void pvs_d_f48(mpq_t result, mpq_t x) {
  mpq_set(result, x);
  mpq_canonicalize(result);
}

void pvs_g49(mpq_t result, mpz_t x, mpq_t y) {
  mpq_t conv54;
  mpq_init(conv54);
  mpq_set_z(conv54, x);
  mpq_canonicalize(conv54);
  mpq_t aux55;
  mpq_init(aux55);
  mpq_add(aux55, conv54, y);
  mpq_clear(conv54);
  mpq_t aux56;
  mpq_init(aux56);
  mpz_set_si(mpq_numref(aux56), (long) 5);
  mpz_set_si(mpq_denref(aux56), (long) 10);
  mpq_canonicalize(aux56);
  mpq_add(result, aux55, aux56);
  mpq_clear(aux56);
  mpq_clear(aux55);
}

void pvs_d_g50(mpq_t result, mpz_t x, mpq_t y) {
  mpq_t conv54;
  mpq_init(conv54);
  mpq_set_z(conv54, x);
  mpq_canonicalize(conv54);
  mpq_t aux55;
  mpq_init(aux55);
  mpq_add(aux55, conv54, y);
  mpq_clear(conv54);
  mpq_t aux56;
  mpq_init(aux56);
  mpz_set_si(mpq_numref(aux56), (long) 5);
  mpz_set_si(mpq_denref(aux56), (long) 10);
  mpq_canonicalize(aux56);
  mpq_add(result, aux55, aux56);
  mpq_clear(aux56);
  mpq_clear(aux55);
}

void pvs_a57(mpz_t result) {
  mpz_t conv63;
  mpz_init(conv63);
  mpz_set_si(conv63, (long) 1);
  mpq_t conv64;
  mpq_init(conv64);
  mpq_set_d(conv64, (double) 0 );
  mpq_canonicalize(conv64);
  mpq_t aux65;
  mpq_init(aux65);
  pvs_d_f48(aux65, conv64);
  mpq_clear(conv64);
  mpq_t set66;
  mpq_init(set66);
  pvs_d_g50(set66, conv63, aux65);
  mpq_clear(aux65);
  mpz_clear(conv63);
  mpq_get_num(result, set66);
  mpq_clear(set66);
}

void pvs_d_a58(mpz_t result) {
  mpz_t conv63;
  mpz_init(conv63);
  mpz_set_si(conv63, (long) 1);
  mpq_t conv64;
  mpq_init(conv64);
  mpq_set_d(conv64, (double) 0 );
  mpq_canonicalize(conv64);
  mpq_t aux65;
  mpq_init(aux65);
  pvs_d_f48(aux65, conv64);
  mpq_clear(conv64);
  mpq_t set66;
  mpq_init(set66);
  pvs_d_g50(set66, conv63, aux65);
  mpq_clear(aux65);
  mpz_clear(conv63);
  mpq_get_num(result, set66);
  mpq_clear(set66);
}

void pvs_adda67(mpz_t result, mpz_t i) {
  mpz_t aux70;
  mpz_init(aux70);
  pvs_a57(aux70);
  mpz_add(result, aux70, i);
  mpz_clear(aux70);
}

void pvs_d_adda68(mpz_t result, mpz_t i) {
  mpz_t aux70;
  mpz_init(aux70);
  pvs_a57(aux70);
  mpz_add(result, aux70, i);
  mpz_clear(aux70);
}

void pvs_b71(mpq_t result) {
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

void pvs_d_b72(mpq_t result) {
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

void pvs_foo73(mpz_t result, mpz_t x) {
  mpz_t conv87;
  mpz_init(conv87);
  mpz_set_si(conv87, (long) 1);
  mpz_t conv88;
  mpz_init(conv88);
  mpz_set_si(conv88, (long) 0);
  int aux89;
  aux89 = (mpz_cmp(x, (conv88)) == 0);
  mpz_clear(conv88);
  mpz_t if98;
  mpz_init(if98);
  if((aux89 && (TRUE && (TRUE || FALSE)))) {
    mpz_t conv90;
    mpz_init(conv90);
    mpz_set_si(conv90, (long) 7);
    mpz_t conv91;
    mpz_init(conv91);
    mpz_set_si(conv91, (long) 1);
    mpz_t aux92;
    mpz_init(aux92);
    mpz_add(aux92, x, conv91);
    mpz_clear(conv91);
    mpz_t conv93;
    mpz_init(conv93);
    mpz_set_si(conv93, (long) 3);
    int aux94;
    aux94 = (mpz_cmp(aux92, conv93) > 0);
    mpz_clear(conv93);
    mpz_clear(aux92);
    mpz_t if95;
    mpz_init(if95);
    if(aux94) {
      mpz_set_si(if95, (long) 0);
    } else {
      mpz_set_si(if95, (long) 8);
    }
    mpz_mul(if98, conv90, if95);
    mpz_clear(if95);
    mpz_clear(conv90);
  } else {
    mpz_t conv96;
    mpz_init(conv96);
    mpz_set_si(conv96, (long) 8);
    mpz_t if97;
    mpz_init(if97);
    if((1 < 1)) {
      mpz_set_si(if97, (long) 6);
    } else {
      mpz_set_si(if97, (long) 3);
    }
    mpz_sub(if98, conv96, if97);
    mpz_clear(if97);
    mpz_clear(conv96);
  }
  mpz_add(result, conv87, if98);
  mpz_clear(if98);
  mpz_clear(conv87);
}

void pvs_d_foo74(mpz_t result, mpz_t x) {
  mpz_t conv87;
  mpz_init(conv87);
  mpz_set_si(conv87, (long) 1);
  mpz_t conv88;
  mpz_init(conv88);
  mpz_set_si(conv88, (long) 0);
  int aux89;
  aux89 = (mpz_cmp(x, (conv88)) == 0);
  mpz_clear(conv88);
  mpz_t if98;
  mpz_init(if98);
  if((aux89 && (TRUE && (TRUE || FALSE)))) {
    mpz_t conv90;
    mpz_init(conv90);
    mpz_set_si(conv90, (long) 7);
    mpz_t conv91;
    mpz_init(conv91);
    mpz_set_si(conv91, (long) 1);
    mpz_t aux92;
    mpz_init(aux92);
    mpz_add(aux92, x, conv91);
    mpz_clear(conv91);
    mpz_t conv93;
    mpz_init(conv93);
    mpz_set_si(conv93, (long) 3);
    int aux94;
    aux94 = (mpz_cmp(aux92, conv93) > 0);
    mpz_clear(conv93);
    mpz_clear(aux92);
    mpz_t if95;
    mpz_init(if95);
    if(aux94) {
      mpz_set_si(if95, (long) 0);
    } else {
      mpz_set_si(if95, (long) 8);
    }
    mpz_mul(if98, conv90, if95);
    mpz_clear(if95);
    mpz_clear(conv90);
  } else {
    mpz_t conv96;
    mpz_init(conv96);
    mpz_set_si(conv96, (long) 8);
    mpz_t if97;
    mpz_init(if97);
    if((1 < 1)) {
      mpz_set_si(if97, (long) 6);
    } else {
      mpz_set_si(if97, (long) 3);
    }
    mpz_sub(if98, conv96, if97);
    mpz_clear(if97);
    mpz_clear(conv96);
  }
  mpz_add(result, conv87, if98);
  mpz_clear(if98);
  mpz_clear(conv87);
}

void pvs_add299(mpz_t result, mpz_t a) {
  mpz_t conv108;
  mpz_init(conv108);
  mpz_set_si(conv108, (long) 1);
  int aux109;
  aux109 = (mpz_cmp(a, (conv108)) == 0);
  mpz_clear(conv108);
  mpz_t if110;
  mpz_init(if110);
  if(aux109) {
    mpz_set_si(if110, (long) 1);
  } else {
    mpz_set_si(if110, (long) 0);
  }
  mpz_t aux111;
  mpz_init(aux111);
  mpz_add(aux111, a, if110);
  mpz_clear(if110);
  mpz_t conv112;
  mpz_init(conv112);
  mpz_set_si(conv112, (long) 2);
  mpz_t c = aux111;
  mpz_t d = conv112;
  mpz_t aux113;
  mpz_init(aux113);
  mpz_add(aux113, c, d);
  mpz_t conv114;
  mpz_init(conv114);
  mpz_set_si(conv114, (long) 1);
  mpz_add(result, aux113, conv114);
  mpz_clear(conv114);
  mpz_clear(aux113);
  mpz_clear(conv112);
  mpz_clear(aux111);
}

void pvs_d_add2100(mpz_t result, mpz_t a) {
  mpz_t conv108;
  mpz_init(conv108);
  mpz_set_si(conv108, (long) 1);
  int aux109;
  aux109 = (mpz_cmp(a, (conv108)) == 0);
  mpz_clear(conv108);
  mpz_t if110;
  mpz_init(if110);
  if(aux109) {
    mpz_set_si(if110, (long) 1);
  } else {
    mpz_set_si(if110, (long) 0);
  }
  mpz_t aux111;
  mpz_init(aux111);
  mpz_add(aux111, a, if110);
  mpz_clear(if110);
  mpz_t conv112;
  mpz_init(conv112);
  mpz_set_si(conv112, (long) 2);
  mpz_t c = aux111;
  mpz_t d = conv112;
  mpz_t aux113;
  mpz_init(aux113);
  mpz_add(aux113, c, d);
  mpz_t conv114;
  mpz_init(conv114);
  mpz_set_si(conv114, (long) 1);
  mpz_add(result, aux113, conv114);
  mpz_clear(conv114);
  mpz_clear(aux113);
  mpz_clear(conv112);
  mpz_clear(aux111);
}

void pvs_factorial115(mpz_t result, mpz_t n) {
  mpz_t conv122;
  mpz_init(conv122);
  mpz_set_si(conv122, (long) 0);
  int aux123;
  aux123 = (mpz_cmp(n, (conv122)) == 0);
  mpz_clear(conv122);
  if(aux123) {
    mpz_set_si(result, (long) 1);
  } else {
    mpz_t conv124;
    mpz_init(conv124);
    mpz_set_si(conv124, (long) 1);
    mpz_t aux125;
    mpz_init(aux125);
    mpz_sub(aux125, n, conv124);
    mpz_clear(conv124);
    mpz_t aux126;
    mpz_init(aux126);
    pvs_d_factorial116(aux126, aux125);
    mpz_clear(aux125);
    mpz_mul(result, n, aux126);
    mpz_clear(aux126);
  }
}

void pvs_d_factorial116(mpz_t result, mpz_t n) {
  mpz_t conv122;
  mpz_init(conv122);
  mpz_set_si(conv122, (long) 0);
  int aux123;
  aux123 = (mpz_cmp(n, (conv122)) == 0);
  mpz_clear(conv122);
  if(aux123) {
    mpz_set_si(result, (long) 1);
  } else {
    mpz_t conv124;
    mpz_init(conv124);
    mpz_set_si(conv124, (long) 1);
    mpz_t aux125;
    mpz_init(aux125);
    mpz_sub(aux125, n, conv124);
    mpz_clear(conv124);
    mpz_t aux126;
    mpz_init(aux126);
    pvs_d_factorial116(aux126, aux125);
    mpz_clear(aux125);
    mpz_mul(result, n, aux126);
    mpz_clear(aux126);
  }
}

void pvs_binomial127(mpz_t result, mpz_t a, mpz_t b) {
  mpz_t conv141;
  mpz_init(conv141);
  mpz_set_si(conv141, (long) 0);
  int aux142;
  aux142 = (mpz_cmp(b, (conv141)) == 0);
  mpz_clear(conv141);
  if(aux142) {
    mpz_set_si(result, (long) 1);
  } else {
    mpz_t conv143;
    mpz_init(conv143);
    mpz_set_si(conv143, (long) 0);
    int aux144;
    aux144 = (mpz_cmp(a, (conv143)) == 0);
    mpz_clear(conv143);
    if(aux144) {
      mpz_set_si(result, (long) 0);
    } else {
      mpz_t conv145;
      mpz_init(conv145);
      mpz_set_si(conv145, (long) 1);
      mpz_t aux146;
      mpz_init(aux146);
      mpz_sub(aux146, a, conv145);
      mpz_clear(conv145);
      mpz_t conv147;
      mpz_init(conv147);
      mpz_set_si(conv147, (long) 1);
      mpz_t aux148;
      mpz_init(aux148);
      mpz_sub(aux148, b, conv147);
      mpz_clear(conv147);
      mpz_t aux149;
      mpz_init(aux149);
      pvs_d_binomial128(aux149, aux146, aux148);
      mpz_clear(aux148);
      mpz_clear(aux146);
      mpz_t conv150;
      mpz_init(conv150);
      mpz_set_si(conv150, (long) 1);
      mpz_t aux151;
      mpz_init(aux151);
      mpz_sub(aux151, a, conv150);
      mpz_clear(conv150);
      mpz_t aux152;
      mpz_init(aux152);
      pvs_d_binomial128(aux152, aux151, b);
      mpz_clear(aux151);
      mpz_add(result, aux149, aux152);
      mpz_clear(aux152);
      mpz_clear(aux149);
    }
  }
}

void pvs_d_binomial128(mpz_t result, mpz_t a, mpz_t b) {
  mpz_t conv141;
  mpz_init(conv141);
  mpz_set_si(conv141, (long) 0);
  int aux142;
  aux142 = (mpz_cmp(b, (conv141)) == 0);
  mpz_clear(conv141);
  if(aux142) {
    mpz_set_si(result, (long) 1);
  } else {
    mpz_t conv143;
    mpz_init(conv143);
    mpz_set_si(conv143, (long) 0);
    int aux144;
    aux144 = (mpz_cmp(a, (conv143)) == 0);
    mpz_clear(conv143);
    if(aux144) {
      mpz_set_si(result, (long) 0);
    } else {
      mpz_t conv145;
      mpz_init(conv145);
      mpz_set_si(conv145, (long) 1);
      mpz_t aux146;
      mpz_init(aux146);
      mpz_sub(aux146, a, conv145);
      mpz_clear(conv145);
      mpz_t conv147;
      mpz_init(conv147);
      mpz_set_si(conv147, (long) 1);
      mpz_t aux148;
      mpz_init(aux148);
      mpz_sub(aux148, b, conv147);
      mpz_clear(conv147);
      mpz_t aux149;
      mpz_init(aux149);
      pvs_d_binomial128(aux149, aux146, aux148);
      mpz_clear(aux148);
      mpz_clear(aux146);
      mpz_t conv150;
      mpz_init(conv150);
      mpz_set_si(conv150, (long) 1);
      mpz_t aux151;
      mpz_init(aux151);
      mpz_sub(aux151, a, conv150);
      mpz_clear(conv150);
      mpz_t aux152;
      mpz_init(aux152);
      pvs_d_binomial128(aux152, aux151, b);
      mpz_clear(aux151);
      mpz_add(result, aux149, aux152);
      mpz_clear(aux152);
      mpz_clear(aux149);
    }
  }
}