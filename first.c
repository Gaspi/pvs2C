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

int pvs_f422(int x) {
  int result;
  result = x;
  return result;
}

int pvs_d_f423(int x) {
  int result;
  result = x;
  return result;
}

void pvs_g424(mpq_t result, mpz_t x, mpq_t y) {
  mpq_t conv429;
  mpq_init(conv429);
  mpq_set_z(conv429, x);
  mpq_canonicalize(conv429);
  mpq_t aux430;
  mpq_init(aux430);
  mpq_add(aux430, conv429, y);
  mpq_clear(conv429);
  mpz_set_si(mpq_numref(~a), (long) 5);
  mpz_set_si(mpq_denref(~a), (long) 10);
  mpq_t aux431;
  mpq_init(aux431);
  mpq_canonicalize(aux431);
  mpq_add(result, aux430, aux431);
  mpq_clear(aux430);
  mpq_clear(aux431);
}

void pvs_d_g425(mpq_t result, mpz_t x, mpq_t y) {
  mpq_t conv429;
  mpq_init(conv429);
  mpq_set_z(conv429, x);
  mpq_canonicalize(conv429);
  mpq_t aux430;
  mpq_init(aux430);
  mpq_add(aux430, conv429, y);
  mpq_clear(conv429);
  mpz_set_si(mpq_numref(~a), (long) 5);
  mpz_set_si(mpq_denref(~a), (long) 10);
  mpq_t aux431;
  mpq_init(aux431);
  mpq_canonicalize(aux431);
  mpq_add(result, aux430, aux431);
  mpq_clear(aux430);
  mpq_clear(aux431);
}

void pvs_a432(mpz_t result) {
  mpz_t conv437;
  mpz_init(conv437);
  mpz_set_si(conv437, (long) 1);
  mpq_t conv438;
  mpq_init(conv438);
  mpq_set_d(conv438, (double) pvs_d_f423(0) );
  mpq_canonicalize(conv438);
  mpq_t set439;
  mpq_init(set439);
  pvs_d_g425(set439, conv437, conv438);
  mpz_clear(conv437);
  mpq_clear(conv438);
  mpq_get_num(result, set439);
  mpq_clear(set439);
}

void pvs_d_a433(mpz_t result) {
  mpz_t conv437;
  mpz_init(conv437);
  mpz_set_si(conv437, (long) 1);
  mpq_t conv438;
  mpq_init(conv438);
  mpq_set_d(conv438, (double) pvs_d_f423(0) );
  mpq_canonicalize(conv438);
  mpq_t set439;
  mpq_init(set439);
  pvs_d_g425(set439, conv437, conv438);
  mpz_clear(conv437);
  mpq_clear(conv438);
  mpq_get_num(result, set439);
  mpq_clear(set439);
}

void pvs_adda440(mpz_t result, mpz_t i) {
  mpz_t aux443;
  mpz_init(aux443);
  pvs_a432(aux443);
  mpz_add(result, aux443, i);
  mpz_clear(aux443);
}

void pvs_d_adda441(mpz_t result, mpz_t i) {
  mpz_t aux443;
  mpz_init(aux443);
  pvs_a432(aux443);
  mpz_add(result, aux443, i);
  mpz_clear(aux443);
}

void pvs_b444(mpq_t result) {
  if(TRUE) {
    mpz_set_si(mpq_numref(~a), (long) 1);
  } else {
    mpz_set_si(mpq_numref(~a), (long) 2);
  }
  if(FALSE) {
    mpz_set_si(mpq_denref(~a), (long) 2);
  } else {
    mpz_set_si(mpq_denref(~a), (long) 3);
  }
  mpq_canonicalize(result);
}

void pvs_d_b445(mpq_t result) {
  if(TRUE) {
    mpz_set_si(mpq_numref(~a), (long) 1);
  } else {
    mpz_set_si(mpq_numref(~a), (long) 2);
  }
  if(FALSE) {
    mpz_set_si(mpq_denref(~a), (long) 2);
  } else {
    mpz_set_si(mpq_denref(~a), (long) 3);
  }
  mpq_canonicalize(result);
}

void pvs_foo446(mpz_t result, mpz_t x) {
  mpz_t conv460;
  mpz_init(conv460);
  mpz_set_si(conv460, (long) 1);
  mpz_t conv461;
  mpz_init(conv461);
  mpz_set_si(conv461, (long) 0);
  int aux462;
  aux462 = (mpz_cmp(x, conv461) == 0);
  mpz_clear(conv461);
  mpz_t if471;
  mpz_init(if471);
  if((aux462 && (TRUE && (TRUE || FALSE)))) {
    mpz_t conv463;
    mpz_init(conv463);
    mpz_set_si(conv463, (long) 7);
    mpz_t conv464;
    mpz_init(conv464);
    mpz_set_si(conv464, (long) 1);
    mpz_t aux465;
    mpz_init(aux465);
    mpz_add(aux465, x, conv464);
    mpz_clear(conv464);
    mpz_t conv466;
    mpz_init(conv466);
    mpz_set_si(conv466, (long) 3);
    int aux467;
    aux467 = (mpz_cmp(aux465, conv466) > 0);
    mpz_clear(aux465);
    mpz_clear(conv466);
    mpz_t if468;
    mpz_init(if468);
    if(aux467) {
      mpz_set_si(if468, (long) 0);
    } else {
      mpz_set_si(if468, (long) 8);
    }
    mpz_mul(if471, conv463, if468);
    mpz_clear(conv463);
    mpz_clear(if468);
  } else {
    mpz_t conv469;
    mpz_init(conv469);
    mpz_set_si(conv469, (long) 8);
    mpz_t if470;
    mpz_init(if470);
    if((1 < 1)) {
      mpz_set_si(if470, (long) 6);
    } else {
      mpz_set_si(if470, (long) 3);
    }
    mpz_sub(if471, conv469, if470);
    mpz_clear(conv469);
    mpz_clear(if470);
  }
  mpz_add(result, conv460, if471);
  mpz_clear(conv460);
  mpz_clear(if471);
}

void pvs_d_foo447(mpz_t result, mpz_t x) {
  mpz_t conv460;
  mpz_init(conv460);
  mpz_set_si(conv460, (long) 1);
  mpz_t conv461;
  mpz_init(conv461);
  mpz_set_si(conv461, (long) 0);
  int aux462;
  aux462 = (mpz_cmp(x, conv461) == 0);
  mpz_clear(conv461);
  mpz_t if471;
  mpz_init(if471);
  if((aux462 && (TRUE && (TRUE || FALSE)))) {
    mpz_t conv463;
    mpz_init(conv463);
    mpz_set_si(conv463, (long) 7);
    mpz_t conv464;
    mpz_init(conv464);
    mpz_set_si(conv464, (long) 1);
    mpz_t aux465;
    mpz_init(aux465);
    mpz_add(aux465, x, conv464);
    mpz_clear(conv464);
    mpz_t conv466;
    mpz_init(conv466);
    mpz_set_si(conv466, (long) 3);
    int aux467;
    aux467 = (mpz_cmp(aux465, conv466) > 0);
    mpz_clear(aux465);
    mpz_clear(conv466);
    mpz_t if468;
    mpz_init(if468);
    if(aux467) {
      mpz_set_si(if468, (long) 0);
    } else {
      mpz_set_si(if468, (long) 8);
    }
    mpz_mul(if471, conv463, if468);
    mpz_clear(conv463);
    mpz_clear(if468);
  } else {
    mpz_t conv469;
    mpz_init(conv469);
    mpz_set_si(conv469, (long) 8);
    mpz_t if470;
    mpz_init(if470);
    if((1 < 1)) {
      mpz_set_si(if470, (long) 6);
    } else {
      mpz_set_si(if470, (long) 3);
    }
    mpz_sub(if471, conv469, if470);
    mpz_clear(conv469);
    mpz_clear(if470);
  }
  mpz_add(result, conv460, if471);
  mpz_clear(conv460);
  mpz_clear(if471);
}

void pvs_add2472(mpz_t result, mpz_t a) {
  mpz_t conv481;
  mpz_init(conv481);
  mpz_set_si(conv481, (long) 1);
  int aux482;
  aux482 = (mpz_cmp(a, conv481) == 0);
  mpz_clear(conv481);
  mpz_t if483;
  mpz_init(if483);
  if(aux482) {
    mpz_set_si(if483, (long) 1);
  } else {
    mpz_set_si(if483, (long) 0);
  }
  mpz_t aux484;
  mpz_init(aux484);
  mpz_add(aux484, a, if483);
  mpz_clear(if483);
  mpz_t conv485;
  mpz_init(conv485);
  mpz_set_si(conv485, (long) 2);
  mpz_t c = aux484;
  mpz_t d = conv485;
  mpz_t aux486;
  mpz_init(aux486);
  mpz_add(aux486, c, d);
  mpz_t conv487;
  mpz_init(conv487);
  mpz_set_si(conv487, (long) 1);
  mpz_add(result, aux486, conv487);
  mpz_clear(aux484);
  mpz_clear(conv485);
  mpz_clear(aux486);
  mpz_clear(conv487);
}

void pvs_d_add2473(mpz_t result, mpz_t a) {
  mpz_t conv481;
  mpz_init(conv481);
  mpz_set_si(conv481, (long) 1);
  int aux482;
  aux482 = (mpz_cmp(a, conv481) == 0);
  mpz_clear(conv481);
  mpz_t if483;
  mpz_init(if483);
  if(aux482) {
    mpz_set_si(if483, (long) 1);
  } else {
    mpz_set_si(if483, (long) 0);
  }
  mpz_t aux484;
  mpz_init(aux484);
  mpz_add(aux484, a, if483);
  mpz_clear(if483);
  mpz_t conv485;
  mpz_init(conv485);
  mpz_set_si(conv485, (long) 2);
  mpz_t c = aux484;
  mpz_t d = conv485;
  mpz_t aux486;
  mpz_init(aux486);
  mpz_add(aux486, c, d);
  mpz_t conv487;
  mpz_init(conv487);
  mpz_set_si(conv487, (long) 1);
  mpz_add(result, aux486, conv487);
  mpz_clear(aux484);
  mpz_clear(conv485);
  mpz_clear(aux486);
  mpz_clear(conv487);
}

void pvs_factorial488(mpz_t result, mpz_t n) {
  mpz_t conv495;
  mpz_init(conv495);
  mpz_set_si(conv495, (long) 0);
  int aux496;
  aux496 = (mpz_cmp(n, conv495) == 0);
  mpz_clear(conv495);
  if(aux496) {
    mpz_set_si(result, (long) 1);
  } else {
    mpz_t conv497;
    mpz_init(conv497);
    mpz_set_si(conv497, (long) 1);
    mpz_t aux498;
    mpz_init(aux498);
    mpz_sub(aux498, n, conv497);
    mpz_clear(conv497);
    mpz_t aux499;
    mpz_init(aux499);
    pvs_d_factorial489(aux499, aux498);
    mpz_clear(aux498);
    mpz_mul(result, n, aux499);
    mpz_clear(aux499);
  }
}

void pvs_d_factorial489(mpz_t result, mpz_t n) {
  mpz_t conv495;
  mpz_init(conv495);
  mpz_set_si(conv495, (long) 0);
  int aux496;
  aux496 = (mpz_cmp(n, conv495) == 0);
  mpz_clear(conv495);
  if(aux496) {
    mpz_set_si(result, (long) 1);
  } else {
    mpz_t conv497;
    mpz_init(conv497);
    mpz_set_si(conv497, (long) 1);
    mpz_t aux498;
    mpz_init(aux498);
    mpz_sub(aux498, n, conv497);
    mpz_clear(conv497);
    mpz_t aux499;
    mpz_init(aux499);
    pvs_d_factorial489(aux499, aux498);
    mpz_clear(aux498);
    mpz_mul(result, n, aux499);
    mpz_clear(aux499);
  }
}

void pvs_binomial500(mpz_t result, mpz_t a, mpz_t b) {
  mpz_t conv514;
  mpz_init(conv514);
  mpz_set_si(conv514, (long) 0);
  int aux515;
  aux515 = (mpz_cmp(b, conv514) == 0);
  mpz_clear(conv514);
  if(aux515) {
    mpz_set_si(result, (long) 1);
  } else {
    mpz_t conv516;
    mpz_init(conv516);
    mpz_set_si(conv516, (long) 0);
    int aux517;
    aux517 = (mpz_cmp(a, conv516) == 0);
    mpz_clear(conv516);
    if(aux517) {
      mpz_set_si(result, (long) 0);
    } else {
      mpz_t conv518;
      mpz_init(conv518);
      mpz_set_si(conv518, (long) 1);
      mpz_t aux519;
      mpz_init(aux519);
      mpz_sub(aux519, a, conv518);
      mpz_clear(conv518);
      mpz_t conv520;
      mpz_init(conv520);
      mpz_set_si(conv520, (long) 1);
      mpz_t aux521;
      mpz_init(aux521);
      mpz_sub(aux521, b, conv520);
      mpz_clear(conv520);
      mpz_t aux522;
      mpz_init(aux522);
      pvs_d_binomial501(aux522, aux519, aux521);
      mpz_clear(aux519);
      mpz_clear(aux521);
      mpz_t conv523;
      mpz_init(conv523);
      mpz_set_si(conv523, (long) 1);
      mpz_t aux524;
      mpz_init(aux524);
      mpz_sub(aux524, a, conv523);
      mpz_clear(conv523);
      mpz_t aux525;
      mpz_init(aux525);
      pvs_d_binomial501(aux525, aux524, b);
      mpz_clear(aux524);
      mpz_add(result, aux522, aux525);
      mpz_clear(aux522);
      mpz_clear(aux525);
    }
  }
}

void pvs_d_binomial501(mpz_t result, mpz_t a, mpz_t b) {
  mpz_t conv514;
  mpz_init(conv514);
  mpz_set_si(conv514, (long) 0);
  int aux515;
  aux515 = (mpz_cmp(b, conv514) == 0);
  mpz_clear(conv514);
  if(aux515) {
    mpz_set_si(result, (long) 1);
  } else {
    mpz_t conv516;
    mpz_init(conv516);
    mpz_set_si(conv516, (long) 0);
    int aux517;
    aux517 = (mpz_cmp(a, conv516) == 0);
    mpz_clear(conv516);
    if(aux517) {
      mpz_set_si(result, (long) 0);
    } else {
      mpz_t conv518;
      mpz_init(conv518);
      mpz_set_si(conv518, (long) 1);
      mpz_t aux519;
      mpz_init(aux519);
      mpz_sub(aux519, a, conv518);
      mpz_clear(conv518);
      mpz_t conv520;
      mpz_init(conv520);
      mpz_set_si(conv520, (long) 1);
      mpz_t aux521;
      mpz_init(aux521);
      mpz_sub(aux521, b, conv520);
      mpz_clear(conv520);
      mpz_t aux522;
      mpz_init(aux522);
      pvs_d_binomial501(aux522, aux519, aux521);
      mpz_clear(aux519);
      mpz_clear(aux521);
      mpz_t conv523;
      mpz_init(conv523);
      mpz_set_si(conv523, (long) 1);
      mpz_t aux524;
      mpz_init(aux524);
      mpz_sub(aux524, a, conv523);
      mpz_clear(conv523);
      mpz_t aux525;
      mpz_init(aux525);
      pvs_d_binomial501(aux525, aux524, b);
      mpz_clear(aux524);
      mpz_add(result, aux522, aux525);
      mpz_clear(aux522);
      mpz_clear(aux525);
    }
  }
}