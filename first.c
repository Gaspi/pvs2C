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

void pvs_f389(mpq_t result, mpq_t x) {
  mpq_set(result, x);
  mpq_canonicalize(result);
}

void pvs_d_f390(mpq_t result, mpq_t x) {
  mpq_set(result, x);
  mpq_canonicalize(result);
}

void pvs_g391(mpq_t result, mpz_t x, mpq_t y) {
  mpq_t conv394;
  mpq_init(conv394);
  mpq_set_z(conv394, x);
  mpq_canonicalize(conv394);
  mpq_add(result, conv394, y);
  mpq_clear(conv394);
}

void pvs_d_g392(mpq_t result, mpz_t x, mpq_t y) {
  mpq_t conv394;
  mpq_init(conv394);
  mpq_set_z(conv394, x);
  mpq_canonicalize(conv394);
  mpq_add(result, conv394, y);
  mpq_clear(conv394);
}

void pvs_a395(mpz_t result) {
  mpz_t conv401;
  mpz_init(conv401);
  mpz_set_si(conv401, 1);
  mpq_t conv402;
  mpq_init(conv402);
  mpq_set_d(conv402, (double) 0 );
  mpq_canonicalize(conv402);
  mpq_t aux403;
  mpq_init(aux403);
  pvs_d_f390(aux403, conv402);
  mpq_clear(conv402);
  mpq_t set404;
  mpq_init(set404);
  pvs_d_g392(set404, conv401, aux403);
  mpq_clear(aux403);
  mpz_clear(conv401);
  mpq_get_num(result, set404);
  mpq_clear(set404);
}

void pvs_d_a396(mpz_t result) {
  mpz_t conv401;
  mpz_init(conv401);
  mpz_set_si(conv401, 1);
  mpq_t conv402;
  mpq_init(conv402);
  mpq_set_d(conv402, (double) 0 );
  mpq_canonicalize(conv402);
  mpq_t aux403;
  mpq_init(aux403);
  pvs_d_f390(aux403, conv402);
  mpq_clear(conv402);
  mpq_t set404;
  mpq_init(set404);
  pvs_d_g392(set404, conv401, aux403);
  mpq_clear(aux403);
  mpz_clear(conv401);
  mpq_get_num(result, set404);
  mpq_clear(set404);
}

void pvs_adda405(mpz_t result, mpz_t i) {
  mpz_t aux408;
  mpz_init(aux408);
  pvs_a395(aux408);
  mpz_add(result, aux408, i);
  mpz_clear(aux408);
}

void pvs_d_adda406(mpz_t result, mpz_t i) {
  mpz_t aux408;
  mpz_init(aux408);
  pvs_a395(aux408);
  mpz_add(result, aux408, i);
  mpz_clear(aux408);
}

void pvs_foo409(mpz_t result, mpz_t x) {
  mpq_t conv423;
  mpq_init(conv423);
  mpq_set_d(conv423, (double) 1 );
  mpq_canonicalize(conv423);
  mpz_t conv424;
  mpz_init(conv424);
  mpz_set_si(conv424, 0);
  int aux425;
  int aux425 = (mpz_cmp(x, (conv424)) == 0);
  mpz_clear(conv424);
  mpq_t aux433;
  mpq_init(aux433);
  if((aux425 && (TRUE && (TRUE  FALSE)))) {
    mpz_t conv426;
    mpz_init(conv426);
    mpz_set_si(conv426, 1);
    mpz_t aux427;
    mpz_init(aux427);
    mpz_add(aux427, x, conv426);
    mpz_clear(conv426);
    mpq_t conv428;
    mpq_init(conv428);
    mpq_set_z(conv428, aux427);
    mpq_canonicalize(conv428);
    mpq_t conv429;
    mpq_init(conv429);
    mpq_set_d(conv429, (double) 3 );
    mpq_canonicalize(conv429);
    int aux430;
    int aux430 = (mpq_cmp(conv428, conv429) > 0);
    mpq_clear(conv429);
    mpz_clear(aux427);
    mpq_clear(conv428);
    mpq_t aux431;
    mpq_init(aux431);
    if(aux430) {
      mpq_set_d(aux431, (double) 0 );
      mpq_canonicalize(aux431);
    } else {
      mpq_set_d(aux431, (double) 8 );
      mpq_canonicalize(aux431);
    }
    pvsTimes(aux433, 7, aux431);
    mpq_clear(aux431);
  } else {
    mpq_t aux432;
    mpq_init(aux432);
    if((1 < 1)) {
      mpq_set_d(aux432, (double) 6 );
      mpq_canonicalize(aux432);
    } else {
      mpq_set_d(aux432, (double) 3 );
      mpq_canonicalize(aux432);
    }
    pvsSub(aux433, 8, aux432);
    mpq_clear(aux432);
  }
  mpq_t set434;
  mpq_init(set434);
  mpq_add(set434, conv423, aux433);
  mpq_clear(aux433);
  mpq_clear(conv423);
  mpq_get_num(result, set434);
  mpq_clear(set434);
}

void pvs_d_foo410(mpz_t result, mpz_t x) {
  mpq_t conv423;
  mpq_init(conv423);
  mpq_set_d(conv423, (double) 1 );
  mpq_canonicalize(conv423);
  mpz_t conv424;
  mpz_init(conv424);
  mpz_set_si(conv424, 0);
  int aux425;
  int aux425 = (mpz_cmp(x, (conv424)) == 0);
  mpz_clear(conv424);
  mpq_t aux433;
  mpq_init(aux433);
  if((aux425 && (TRUE && (TRUE  FALSE)))) {
    mpz_t conv426;
    mpz_init(conv426);
    mpz_set_si(conv426, 1);
    mpz_t aux427;
    mpz_init(aux427);
    mpz_add(aux427, x, conv426);
    mpz_clear(conv426);
    mpq_t conv428;
    mpq_init(conv428);
    mpq_set_z(conv428, aux427);
    mpq_canonicalize(conv428);
    mpq_t conv429;
    mpq_init(conv429);
    mpq_set_d(conv429, (double) 3 );
    mpq_canonicalize(conv429);
    int aux430;
    int aux430 = (mpq_cmp(conv428, conv429) > 0);
    mpq_clear(conv429);
    mpz_clear(aux427);
    mpq_clear(conv428);
    mpq_t aux431;
    mpq_init(aux431);
    if(aux430) {
      mpq_set_d(aux431, (double) 0 );
      mpq_canonicalize(aux431);
    } else {
      mpq_set_d(aux431, (double) 8 );
      mpq_canonicalize(aux431);
    }
    pvsTimes(aux433, 7, aux431);
    mpq_clear(aux431);
  } else {
    mpq_t aux432;
    mpq_init(aux432);
    if((1 < 1)) {
      mpq_set_d(aux432, (double) 6 );
      mpq_canonicalize(aux432);
    } else {
      mpq_set_d(aux432, (double) 3 );
      mpq_canonicalize(aux432);
    }
    pvsSub(aux433, 8, aux432);
    mpq_clear(aux432);
  }
  mpq_t set434;
  mpq_init(set434);
  mpq_add(set434, conv423, aux433);
  mpq_clear(aux433);
  mpq_clear(conv423);
  mpq_get_num(result, set434);
  mpq_clear(set434);
}

void pvs_add2435(mpz_t result, mpz_t a) {
  mpq_t conv448;
  mpq_init(conv448);
  mpq_set_z(conv448, a);
  mpq_canonicalize(conv448);
  mpz_t conv449;
  mpz_init(conv449);
  mpz_set_si(conv449, 1);
  int aux450;
  int aux450 = (mpz_cmp(a, (conv449)) == 0);
  mpz_clear(conv449);
  mpq_t aux451;
  mpq_init(aux451);
  if(aux450) {
    mpq_set_d(aux451, (double) 1 );
    mpq_canonicalize(aux451);
  } else {
    mpq_set_d(aux451, (double) 0 );
    mpq_canonicalize(aux451);
  }
  mpq_t aux452;
  mpq_init(aux452);
  mpq_add(aux452, conv448, aux451);
  mpq_clear(aux451);
  mpq_clear(conv448);
  mpz_t conv453;
  mpz_init(conv453);
  mpq_get_num(conv453, aux452);
  mpz_t conv454;
  mpz_init(conv454);
  mpz_set_si(conv454, 2);
  mpz_t c = conv453;
  mpz_t d = conv454;
  mpz_t aux455;
  mpz_init(aux455);
  mpz_add(aux455, c, d);
  mpq_t conv456;
  mpq_init(conv456);
  mpq_set_z(conv456, aux455);
  mpq_canonicalize(conv456);
  mpq_t conv457;
  mpq_init(conv457);
  mpq_set_d(conv457, (double) 1 );
  mpq_canonicalize(conv457);
  mpq_t set458;
  mpq_init(set458);
  mpq_add(set458, conv456, conv457);
  mpq_clear(conv457);
  mpz_clear(aux455);
  mpq_clear(conv456);
  mpz_clear(conv454);
  mpq_clear(aux452);
  mpz_clear(conv453);
  mpq_get_num(result, set458);
  mpq_clear(set458);
}

void pvs_d_add2436(mpz_t result, mpz_t a) {
  mpq_t conv448;
  mpq_init(conv448);
  mpq_set_z(conv448, a);
  mpq_canonicalize(conv448);
  mpz_t conv449;
  mpz_init(conv449);
  mpz_set_si(conv449, 1);
  int aux450;
  int aux450 = (mpz_cmp(a, (conv449)) == 0);
  mpz_clear(conv449);
  mpq_t aux451;
  mpq_init(aux451);
  if(aux450) {
    mpq_set_d(aux451, (double) 1 );
    mpq_canonicalize(aux451);
  } else {
    mpq_set_d(aux451, (double) 0 );
    mpq_canonicalize(aux451);
  }
  mpq_t aux452;
  mpq_init(aux452);
  mpq_add(aux452, conv448, aux451);
  mpq_clear(aux451);
  mpq_clear(conv448);
  mpz_t conv453;
  mpz_init(conv453);
  mpq_get_num(conv453, aux452);
  mpz_t conv454;
  mpz_init(conv454);
  mpz_set_si(conv454, 2);
  mpz_t c = conv453;
  mpz_t d = conv454;
  mpz_t aux455;
  mpz_init(aux455);
  mpz_add(aux455, c, d);
  mpq_t conv456;
  mpq_init(conv456);
  mpq_set_z(conv456, aux455);
  mpq_canonicalize(conv456);
  mpq_t conv457;
  mpq_init(conv457);
  mpq_set_d(conv457, (double) 1 );
  mpq_canonicalize(conv457);
  mpq_t set458;
  mpq_init(set458);
  mpq_add(set458, conv456, conv457);
  mpq_clear(conv457);
  mpz_clear(aux455);
  mpq_clear(conv456);
  mpz_clear(conv454);
  mpq_clear(aux452);
  mpz_clear(conv453);
  mpq_get_num(result, set458);
  mpq_clear(set458);
}

void pvs_factorial459(mpz_t result, mpz_t n) {
  mpz_t conv467;
  mpz_init(conv467);
  mpz_set_si(conv467, 0);
  int aux468;
  int aux468 = (mpz_cmp(n, (conv467)) == 0);
  mpz_clear(conv467);
  mpq_t set472;
  mpq_init(set472);
  if(aux468) {
    mpq_set_d(set472, (double) 1 );
    mpq_canonicalize(set472);
  } else {
    mpq_t aux469;
    mpq_init(aux469);
    pvsSub(aux469, n, 1);
    mpz_t conv470;
    mpz_init(conv470);
    mpq_get_num(conv470, aux469);
    mpz_t aux471;
    mpz_init(aux471);
    pvs_d_factorial460(aux471, conv470);
    mpq_clear(aux469);
    mpz_clear(conv470);
    pvsTimes(set472, n, aux471);
    mpz_clear(aux471);
  }
  mpq_get_num(result, set472);
  mpq_clear(set472);
}

void pvs_d_factorial460(mpz_t result, mpz_t n) {
  mpz_t conv467;
  mpz_init(conv467);
  mpz_set_si(conv467, 0);
  int aux468;
  int aux468 = (mpz_cmp(n, (conv467)) == 0);
  mpz_clear(conv467);
  mpq_t set472;
  mpq_init(set472);
  if(aux468) {
    mpq_set_d(set472, (double) 1 );
    mpq_canonicalize(set472);
  } else {
    mpq_t aux469;
    mpq_init(aux469);
    pvsSub(aux469, n, 1);
    mpz_t conv470;
    mpz_init(conv470);
    mpq_get_num(conv470, aux469);
    mpz_t aux471;
    mpz_init(aux471);
    pvs_d_factorial460(aux471, conv470);
    mpq_clear(aux469);
    mpz_clear(conv470);
    pvsTimes(set472, n, aux471);
    mpz_clear(aux471);
  }
  mpq_get_num(result, set472);
  mpq_clear(set472);
}

void pvs_binomial473(mpz_t result, mpz_t a, mpz_t b) {
  mpz_t conv489;
  mpz_init(conv489);
  mpz_set_si(conv489, 0);
  int aux490;
  int aux490 = (mpz_cmp(b, (conv489)) == 0);
  mpz_clear(conv489);
  mpq_t set502;
  mpq_init(set502);
  if(aux490) {
    mpq_set_d(set502, (double) 1 );
    mpq_canonicalize(set502);
  } else {
    mpz_t conv491;
    mpz_init(conv491);
    mpz_set_si(conv491, 0);
    int aux492;
    int aux492 = (mpz_cmp(a, (conv491)) == 0);
    mpz_clear(conv491);
    if(aux492) {
      mpq_set_d(set502, (double) 0 );
      mpq_canonicalize(set502);
    } else {
      mpq_t aux493;
      mpq_init(aux493);
      pvsSub(aux493, a, 1);
      mpz_t conv494;
      mpz_init(conv494);
      mpq_get_num(conv494, aux493);
      mpq_t aux495;
      mpq_init(aux495);
      pvsSub(aux495, b, 1);
      mpz_t conv496;
      mpz_init(conv496);
      mpq_get_num(conv496, aux495);
      mpz_t aux497;
      mpz_init(aux497);
      pvs_d_binomial474(aux497, conv494, conv496);
      mpq_clear(aux495);
      mpz_clear(conv496);
      mpq_clear(aux493);
      mpz_clear(conv494);
      mpq_t aux498;
      mpq_init(aux498);
      pvsSub(aux498, a, 1);
      mpz_t conv499;
      mpz_init(conv499);
      mpq_get_num(conv499, aux498);
      mpz_t aux500;
      mpz_init(aux500);
      pvs_d_binomial474(aux500, conv499, b);
      mpq_clear(aux498);
      mpz_clear(conv499);
      mpz_t set501;
      mpz_init(set501);
      mpz_add(set501, aux497, aux500);
      mpz_clear(aux500);
      mpz_clear(aux497);
      mpq_set_z(set502, set501);
      mpq_canonicalize(set502);
      mpz_clear(set501);
    }
  }
  mpq_get_num(result, set502);
  mpq_clear(set502);
}

void pvs_d_binomial474(mpz_t result, mpz_t a, mpz_t b) {
  mpz_t conv489;
  mpz_init(conv489);
  mpz_set_si(conv489, 0);
  int aux490;
  int aux490 = (mpz_cmp(b, (conv489)) == 0);
  mpz_clear(conv489);
  mpq_t set502;
  mpq_init(set502);
  if(aux490) {
    mpq_set_d(set502, (double) 1 );
    mpq_canonicalize(set502);
  } else {
    mpz_t conv491;
    mpz_init(conv491);
    mpz_set_si(conv491, 0);
    int aux492;
    int aux492 = (mpz_cmp(a, (conv491)) == 0);
    mpz_clear(conv491);
    if(aux492) {
      mpq_set_d(set502, (double) 0 );
      mpq_canonicalize(set502);
    } else {
      mpq_t aux493;
      mpq_init(aux493);
      pvsSub(aux493, a, 1);
      mpz_t conv494;
      mpz_init(conv494);
      mpq_get_num(conv494, aux493);
      mpq_t aux495;
      mpq_init(aux495);
      pvsSub(aux495, b, 1);
      mpz_t conv496;
      mpz_init(conv496);
      mpq_get_num(conv496, aux495);
      mpz_t aux497;
      mpz_init(aux497);
      pvs_d_binomial474(aux497, conv494, conv496);
      mpq_clear(aux495);
      mpz_clear(conv496);
      mpq_clear(aux493);
      mpz_clear(conv494);
      mpq_t aux498;
      mpq_init(aux498);
      pvsSub(aux498, a, 1);
      mpz_t conv499;
      mpz_init(conv499);
      mpq_get_num(conv499, aux498);
      mpz_t aux500;
      mpz_init(aux500);
      pvs_d_binomial474(aux500, conv499, b);
      mpq_clear(aux498);
      mpz_clear(conv499);
      mpz_t set501;
      mpz_init(set501);
      mpz_add(set501, aux497, aux500);
      mpz_clear(aux500);
      mpz_clear(aux497);
      mpq_set_z(set502, set501);
      mpq_canonicalize(set502);
      mpz_clear(set501);
    }
  }
  mpq_get_num(result, set502);
  mpq_clear(set502);
}