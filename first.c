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

void pvs_f263(mpq_t result, mpq_t x) {
  mpq_set(result, x);
  mpq_canonicalize(result);
}

void pvs_d_f264(mpq_t result, mpq_t x) {
  mpq_set(result, x);
  mpq_canonicalize(result);
}

void pvs_g265(mpq_t result, mpz_t x, mpq_t y) {
  mpq_t conv270;
  mpq_init(conv270);
  mpq_set_z(conv270, x);
  mpq_canonicalize(conv270);
  mpq_t aux271;
  mpq_init(aux271);
  mpq_add(aux271, conv270, y);
  mpq_clear(conv270);
  mpq_t aux272;
  mpq_init(aux272);
  mpz_set_si(mpq_numref(aux272), (long) 5);
  mpz_set_si(mpq_denref(aux272), (long) 10);
  mpq_canonicalize(aux272);
  mpq_add(result, aux271, aux272);
  mpq_clear(aux272);
  mpq_clear(aux271);
}

void pvs_d_g266(mpq_t result, mpz_t x, mpq_t y) {
  mpq_t conv270;
  mpq_init(conv270);
  mpq_set_z(conv270, x);
  mpq_canonicalize(conv270);
  mpq_t aux271;
  mpq_init(aux271);
  mpq_add(aux271, conv270, y);
  mpq_clear(conv270);
  mpq_t aux272;
  mpq_init(aux272);
  mpz_set_si(mpq_numref(aux272), (long) 5);
  mpz_set_si(mpq_denref(aux272), (long) 10);
  mpq_canonicalize(aux272);
  mpq_add(result, aux271, aux272);
  mpq_clear(aux272);
  mpq_clear(aux271);
}

void pvs_a273(mpz_t result) {
  mpz_t conv279;
  mpz_init(conv279);
  mpz_set_si(conv279, (long) 1);
  mpq_t conv280;
  mpq_init(conv280);
  mpq_set_d(conv280, (double) 0 );
  mpq_canonicalize(conv280);
  mpq_t aux281;
  mpq_init(aux281);
  pvs_d_f264(aux281, conv280);
  mpq_clear(conv280);
  mpq_t set282;
  mpq_init(set282);
  pvs_d_g266(set282, conv279, aux281);
  mpq_clear(aux281);
  mpz_clear(conv279);
  mpq_get_num(result, set282);
  mpq_clear(set282);
}

void pvs_d_a274(mpz_t result) {
  mpz_t conv279;
  mpz_init(conv279);
  mpz_set_si(conv279, (long) 1);
  mpq_t conv280;
  mpq_init(conv280);
  mpq_set_d(conv280, (double) 0 );
  mpq_canonicalize(conv280);
  mpq_t aux281;
  mpq_init(aux281);
  pvs_d_f264(aux281, conv280);
  mpq_clear(conv280);
  mpq_t set282;
  mpq_init(set282);
  pvs_d_g266(set282, conv279, aux281);
  mpq_clear(aux281);
  mpz_clear(conv279);
  mpq_get_num(result, set282);
  mpq_clear(set282);
}

void pvs_adda283(mpz_t result, mpz_t i) {
  mpz_t aux286;
  mpz_init(aux286);
  pvs_a273(aux286);
  mpz_add(result, aux286, i);
  mpz_clear(aux286);
}

void pvs_d_adda284(mpz_t result, mpz_t i) {
  mpz_t aux286;
  mpz_init(aux286);
  pvs_a273(aux286);
  mpz_add(result, aux286, i);
  mpz_clear(aux286);
}

void pvs_b287(mpq_t result) {
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

void pvs_d_b288(mpq_t result) {
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

void pvs_foo289(mpz_t result, mpz_t x) {
  mpz_t conv303;
  mpz_init(conv303);
  mpz_set_si(conv303, (long) 1);
  mpz_t conv304;
  mpz_init(conv304);
  mpz_set_si(conv304, (long) 0);
  int aux305;
  aux305 = (mpz_cmp(x, (conv304)) == 0);
  mpz_clear(conv304);
  mpz_t if314;
  mpz_init(if314);
  if((aux305 && (TRUE && (TRUE || FALSE)))) {
    mpz_t conv306;
    mpz_init(conv306);
    mpz_set_si(conv306, (long) 7);
    mpz_t conv307;
    mpz_init(conv307);
    mpz_set_si(conv307, (long) 1);
    mpz_t aux308;
    mpz_init(aux308);
    mpz_add(aux308, x, conv307);
    mpz_clear(conv307);
    mpz_t conv309;
    mpz_init(conv309);
    mpz_set_si(conv309, (long) 3);
    int aux310;
    aux310 = (mpz_cmp(aux308, conv309) > 0);
    mpz_clear(conv309);
    mpz_clear(aux308);
    mpz_t if311;
    mpz_init(if311);
    if(aux310) {
      mpz_set_si(if311, (long) 0);
    } else {
      mpz_set_si(if311, (long) 8);
    }
    mpz_mul(if314, conv306, if311);
    mpz_clear(if311);
    mpz_clear(conv306);
  } else {
    mpz_t conv312;
    mpz_init(conv312);
    mpz_set_si(conv312, (long) 8);
    mpz_t if313;
    mpz_init(if313);
    if((1 < 1)) {
      mpz_set_si(if313, (long) 6);
    } else {
      mpz_set_si(if313, (long) 3);
    }
    mpz_sub(if314, conv312, if313);
    mpz_clear(if313);
    mpz_clear(conv312);
  }
  mpz_add(result, conv303, if314);
  mpz_clear(if314);
  mpz_clear(conv303);
}

void pvs_d_foo290(mpz_t result, mpz_t x) {
  mpz_t conv303;
  mpz_init(conv303);
  mpz_set_si(conv303, (long) 1);
  mpz_t conv304;
  mpz_init(conv304);
  mpz_set_si(conv304, (long) 0);
  int aux305;
  aux305 = (mpz_cmp(x, (conv304)) == 0);
  mpz_clear(conv304);
  mpz_t if314;
  mpz_init(if314);
  if((aux305 && (TRUE && (TRUE || FALSE)))) {
    mpz_t conv306;
    mpz_init(conv306);
    mpz_set_si(conv306, (long) 7);
    mpz_t conv307;
    mpz_init(conv307);
    mpz_set_si(conv307, (long) 1);
    mpz_t aux308;
    mpz_init(aux308);
    mpz_add(aux308, x, conv307);
    mpz_clear(conv307);
    mpz_t conv309;
    mpz_init(conv309);
    mpz_set_si(conv309, (long) 3);
    int aux310;
    aux310 = (mpz_cmp(aux308, conv309) > 0);
    mpz_clear(conv309);
    mpz_clear(aux308);
    mpz_t if311;
    mpz_init(if311);
    if(aux310) {
      mpz_set_si(if311, (long) 0);
    } else {
      mpz_set_si(if311, (long) 8);
    }
    mpz_mul(if314, conv306, if311);
    mpz_clear(if311);
    mpz_clear(conv306);
  } else {
    mpz_t conv312;
    mpz_init(conv312);
    mpz_set_si(conv312, (long) 8);
    mpz_t if313;
    mpz_init(if313);
    if((1 < 1)) {
      mpz_set_si(if313, (long) 6);
    } else {
      mpz_set_si(if313, (long) 3);
    }
    mpz_sub(if314, conv312, if313);
    mpz_clear(if313);
    mpz_clear(conv312);
  }
  mpz_add(result, conv303, if314);
  mpz_clear(if314);
  mpz_clear(conv303);
}

void pvs_add2315(mpz_t result, mpz_t a) {
  mpz_t conv324;
  mpz_init(conv324);
  mpz_set_si(conv324, (long) 1);
  int aux325;
  aux325 = (mpz_cmp(a, (conv324)) == 0);
  mpz_clear(conv324);
  mpz_t if326;
  mpz_init(if326);
  if(aux325) {
    mpz_set_si(if326, (long) 1);
  } else {
    mpz_set_si(if326, (long) 0);
  }
  mpz_t aux327;
  mpz_init(aux327);
  mpz_add(aux327, a, if326);
  mpz_clear(if326);
  mpz_t conv328;
  mpz_init(conv328);
  mpz_set_si(conv328, (long) 2);
  mpz_t c = aux327;
  mpz_t d = conv328;
  mpz_t aux329;
  mpz_init(aux329);
  mpz_add(aux329, c, d);
  mpz_t conv330;
  mpz_init(conv330);
  mpz_set_si(conv330, (long) 1);
  mpz_add(result, aux329, conv330);
  mpz_clear(conv330);
  mpz_clear(aux329);
  mpz_clear(conv328);
  mpz_clear(aux327);
}

void pvs_d_add2316(mpz_t result, mpz_t a) {
  mpz_t conv324;
  mpz_init(conv324);
  mpz_set_si(conv324, (long) 1);
  int aux325;
  aux325 = (mpz_cmp(a, (conv324)) == 0);
  mpz_clear(conv324);
  mpz_t if326;
  mpz_init(if326);
  if(aux325) {
    mpz_set_si(if326, (long) 1);
  } else {
    mpz_set_si(if326, (long) 0);
  }
  mpz_t aux327;
  mpz_init(aux327);
  mpz_add(aux327, a, if326);
  mpz_clear(if326);
  mpz_t conv328;
  mpz_init(conv328);
  mpz_set_si(conv328, (long) 2);
  mpz_t c = aux327;
  mpz_t d = conv328;
  mpz_t aux329;
  mpz_init(aux329);
  mpz_add(aux329, c, d);
  mpz_t conv330;
  mpz_init(conv330);
  mpz_set_si(conv330, (long) 1);
  mpz_add(result, aux329, conv330);
  mpz_clear(conv330);
  mpz_clear(aux329);
  mpz_clear(conv328);
  mpz_clear(aux327);
}

void pvs_factorial331(mpz_t result, mpz_t n) {
  mpz_t conv338;
  mpz_init(conv338);
  mpz_set_si(conv338, (long) 0);
  int aux339;
  aux339 = (mpz_cmp(n, (conv338)) == 0);
  mpz_clear(conv338);
  if(aux339) {
    mpz_set_si(result, (long) 1);
  } else {
    mpz_t conv340;
    mpz_init(conv340);
    mpz_set_si(conv340, (long) 1);
    mpz_t aux341;
    mpz_init(aux341);
    mpz_sub(aux341, n, conv340);
    mpz_clear(conv340);
    mpz_t aux342;
    mpz_init(aux342);
    pvs_d_factorial332(aux342, aux341);
    mpz_clear(aux341);
    mpz_mul(result, n, aux342);
    mpz_clear(aux342);
  }
}

void pvs_d_factorial332(mpz_t result, mpz_t n) {
  mpz_t conv338;
  mpz_init(conv338);
  mpz_set_si(conv338, (long) 0);
  int aux339;
  aux339 = (mpz_cmp(n, (conv338)) == 0);
  mpz_clear(conv338);
  if(aux339) {
    mpz_set_si(result, (long) 1);
  } else {
    mpz_t conv340;
    mpz_init(conv340);
    mpz_set_si(conv340, (long) 1);
    mpz_t aux341;
    mpz_init(aux341);
    mpz_sub(aux341, n, conv340);
    mpz_clear(conv340);
    mpz_t aux342;
    mpz_init(aux342);
    pvs_d_factorial332(aux342, aux341);
    mpz_clear(aux341);
    mpz_mul(result, n, aux342);
    mpz_clear(aux342);
  }
}

void pvs_binomial343(mpz_t result, mpz_t a, mpz_t b) {
  mpz_t conv357;
  mpz_init(conv357);
  mpz_set_si(conv357, (long) 0);
  int aux358;
  aux358 = (mpz_cmp(b, (conv357)) == 0);
  mpz_clear(conv357);
  if(aux358) {
    mpz_set_si(result, (long) 1);
  } else {
    mpz_t conv359;
    mpz_init(conv359);
    mpz_set_si(conv359, (long) 0);
    int aux360;
    aux360 = (mpz_cmp(a, (conv359)) == 0);
    mpz_clear(conv359);
    if(aux360) {
      mpz_set_si(result, (long) 0);
    } else {
      mpz_t conv361;
      mpz_init(conv361);
      mpz_set_si(conv361, (long) 1);
      mpz_t aux362;
      mpz_init(aux362);
      mpz_sub(aux362, a, conv361);
      mpz_clear(conv361);
      mpz_t conv363;
      mpz_init(conv363);
      mpz_set_si(conv363, (long) 1);
      mpz_t aux364;
      mpz_init(aux364);
      mpz_sub(aux364, b, conv363);
      mpz_clear(conv363);
      mpz_t aux365;
      mpz_init(aux365);
      pvs_d_binomial344(aux365, aux362, aux364);
      mpz_clear(aux364);
      mpz_clear(aux362);
      mpz_t conv366;
      mpz_init(conv366);
      mpz_set_si(conv366, (long) 1);
      mpz_t aux367;
      mpz_init(aux367);
      mpz_sub(aux367, a, conv366);
      mpz_clear(conv366);
      mpz_t aux368;
      mpz_init(aux368);
      pvs_d_binomial344(aux368, aux367, b);
      mpz_clear(aux367);
      mpz_add(result, aux365, aux368);
      mpz_clear(aux368);
      mpz_clear(aux365);
    }
  }
}

void pvs_d_binomial344(mpz_t result, mpz_t a, mpz_t b) {
  mpz_t conv357;
  mpz_init(conv357);
  mpz_set_si(conv357, (long) 0);
  int aux358;
  aux358 = (mpz_cmp(b, (conv357)) == 0);
  mpz_clear(conv357);
  if(aux358) {
    mpz_set_si(result, (long) 1);
  } else {
    mpz_t conv359;
    mpz_init(conv359);
    mpz_set_si(conv359, (long) 0);
    int aux360;
    aux360 = (mpz_cmp(a, (conv359)) == 0);
    mpz_clear(conv359);
    if(aux360) {
      mpz_set_si(result, (long) 0);
    } else {
      mpz_t conv361;
      mpz_init(conv361);
      mpz_set_si(conv361, (long) 1);
      mpz_t aux362;
      mpz_init(aux362);
      mpz_sub(aux362, a, conv361);
      mpz_clear(conv361);
      mpz_t conv363;
      mpz_init(conv363);
      mpz_set_si(conv363, (long) 1);
      mpz_t aux364;
      mpz_init(aux364);
      mpz_sub(aux364, b, conv363);
      mpz_clear(conv363);
      mpz_t aux365;
      mpz_init(aux365);
      pvs_d_binomial344(aux365, aux362, aux364);
      mpz_clear(aux364);
      mpz_clear(aux362);
      mpz_t conv366;
      mpz_init(conv366);
      mpz_set_si(conv366, (long) 1);
      mpz_t aux367;
      mpz_init(aux367);
      mpz_sub(aux367, a, conv366);
      mpz_clear(conv366);
      mpz_t aux368;
      mpz_init(aux368);
      pvs_d_binomial344(aux368, aux367, b);
      mpz_clear(aux367);
      mpz_add(result, aux365, aux368);
      mpz_clear(aux368);
      mpz_clear(aux365);
    }
  }
}