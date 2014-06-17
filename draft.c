// ---------------------------------------------
//        C file generated from draft.pvs
// ---------------------------------------------
//   Make sure to link GMP in compilation:
//      gcc -o draft draft.c -lgmp
//      ./draft
// ---------------------------------------------

#include<stdio.h>
#include<gmp.h>
#include "draft.h"

#define TRUE 1
#define FALSE 0

int main(void) {
  printf("Executing draft ...\n");
  return 0;
}


mpq_t fun242(void *env) {
  mpq_t x = (mpq_t) env[1];
  int i = (int) env[0];
  mpq_t if241;
  mpq_init(if241);
  if((i == 0)) {
    mpq_set_d(if241, (double) 1 );
    mpq_canonicalize(if241);
  } else {
    mpz_t conv237;
    mpz_init(conv237);
    mpz_set_si(conv237, (long) 1);
    mpz_t aux238;
    mpz_init(aux238);
    mpz_ui_sub(aux238, (unsigned long) i, conv237);
    mpz_clear(conv237);
    pvsClosure aux239;
    aux239 = malloc( sizeof(pvsClosure) );
    pvs_pow235(aux239, ( (int) mpz_get_si(aux238) ));
    mpz_clear(aux238);
    mpq_t aux240;
    mpq_init(aux240);
    aux239(aux240, x);
    free(aux239);
    mpq_mul(if241, x, aux240);
    mpq_clear(aux240);
  }
  mpq_clear(if241);
  return if241;
}

mpq_t fun249(void *env) {
  mpq_t x = (mpq_t) env[1];
  int i = (int) env[0];
  mpq_t if248;
  mpq_init(if248);
  if((i == 0)) {
    mpq_set_d(if248, (double) 1 );
    mpq_canonicalize(if248);
  } else {
    mpz_t conv244;
    mpz_init(conv244);
    mpz_set_si(conv244, (long) 1);
    mpz_t aux245;
    mpz_init(aux245);
    mpz_ui_sub(aux245, (unsigned long) i, conv244);
    mpz_clear(conv244);
    pvsClosure aux246;
    aux246 = malloc( sizeof(pvsClosure) );
    pvs_pow235(aux246, ( (int) mpz_get_si(aux245) ));
    mpz_clear(aux245);
    mpq_t aux247;
    mpq_init(aux247);
    aux246(aux247, x);
    free(aux246);
    mpq_mul(if248, x, aux247);
    mpq_clear(aux247);
  }
  mpq_clear(if248);
  return if248;
}

mpq_t fun261(void *env) {
  mpq_t x = (mpq_t) env[1];
  pvsClosure f = (pvsClosure) env[0];
  mpq_t conv253;
  mpq_init(conv253);
  mpq_set_d(conv253, (double) 1 );
  mpq_canonicalize(conv253);
  int aux254;
  aux254 = (mpq_cmp(x, conv253) >= 0);
  mpq_clear(conv253);
  mpq_t if260;
  mpq_init(if260);
  if(aux254) {
    mpq_set_d(if260, (double) 0 );
    mpq_canonicalize(if260);
  } else {
    mpq_t aux255;
    mpq_init(aux255);
    f(aux255, x);
    mpq_t aux256;
    mpq_init(aux256);
    pvs_eps233(aux256);
    mpq_t aux257;
    mpq_init(aux257);
    mpq_add(aux257, x, aux256);
    mpq_clear(aux256);
    pvsClosure aux258;
    aux258 = malloc( sizeof(pvsClosure) );
    pvs_sum251(aux258, f);
    mpq_t aux259;
    mpq_init(aux259);
    aux258(aux259, aux257);
    mpq_clear(aux257);
    free(aux258);
    mpq_add(if260, aux255, aux259);
    mpq_clear(aux255);
    mpq_clear(aux259);
  }
  mpq_clear(if260);
  return if260;
}

mpq_t fun271(void *env) {
  mpq_t x = (mpq_t) env[1];
  pvsClosure f = (pvsClosure) env[0];
  mpq_t conv263;
  mpq_init(conv263);
  mpq_set_d(conv263, (double) 1 );
  mpq_canonicalize(conv263);
  int aux264;
  aux264 = (mpq_cmp(x, conv263) >= 0);
  mpq_clear(conv263);
  mpq_t if270;
  mpq_init(if270);
  if(aux264) {
    mpq_set_d(if270, (double) 0 );
    mpq_canonicalize(if270);
  } else {
    mpq_t aux265;
    mpq_init(aux265);
    f(aux265, x);
    mpq_t aux266;
    mpq_init(aux266);
    pvs_eps233(aux266);
    mpq_t aux267;
    mpq_init(aux267);
    mpq_add(aux267, x, aux266);
    mpq_clear(aux266);
    pvsClosure aux268;
    aux268 = malloc( sizeof(pvsClosure) );
    pvs_sum251(aux268, f);
    mpq_t aux269;
    mpq_init(aux269);
    aux268(aux269, aux267);
    mpq_clear(aux267);
    free(aux268);
    mpq_add(if270, aux265, aux269);
    mpq_clear(aux265);
    mpq_clear(aux269);
  }
  mpq_clear(if270);
  return if270;
}

void pvs_eps233(mpq_t result) {
  mpz_set_si(mpq_numref(result), (long) 1);
  mpz_set_si(mpq_denref(result), (long) 100);
  mpq_canonicalize(result);
}

void pvs_d_eps234(mpq_t result) {
  mpz_set_si(mpq_numref(result), (long) 1);
  mpz_set_si(mpq_denref(result), (long) 100);
  mpq_canonicalize(result);
}

void pvs_pow235(pvsClosure result, int i) {
  void env250[2];
  env250[0] = i;
  makeClosure(result, fun249, env250);
}

void pvs_d_pow236(pvsClosure result, int i) {
  void env250[2];
  env250[0] = i;
  makeClosure(result, fun249, env250);
}

void pvs_sum251(pvsClosure result, pvsClosure f) {
  void env272[2];
  env272[0] = f;
  makeClosure(result, fun271, env272);
}

void pvs_d_sum252(pvsClosure result, pvsClosure f) {
  void env272[2];
  env272[0] = f;
  makeClosure(result, fun271, env272);
}

void pvs_integrate_xn273(mpq_t result, int n) {
  pvsClosure aux279;
  aux279 = malloc( sizeof(pvsClosure) );
  pvs_d_pow236(aux279, n);
  pvsClosure f: [rat -> rat] = aux279;
  pvsClosure aux280;
  aux280 = malloc( sizeof(pvsClosure) );
  pvs_d_sum252(aux280, f);
  pvsClosure s: [rat -> rat] = aux280;
  mpq_t aux281;
  mpq_init(aux281);
  s56279(aux281, 0);
  mpq_t aux282;
  mpq_init(aux282);
  pvs_eps233(aux282);
  mpq_mul(result, aux281, aux282);
  free(aux279);
  free(aux280);
  mpq_clear(aux281);
  mpq_clear(aux282);
}

void pvs_d_integrate_xn274(mpq_t result, int n) {
  pvsClosure aux279;
  aux279 = malloc( sizeof(pvsClosure) );
  pvs_d_pow236(aux279, n);
  pvsClosure f: [rat -> rat] = aux279;
  pvsClosure aux280;
  aux280 = malloc( sizeof(pvsClosure) );
  pvs_d_sum252(aux280, f);
  pvsClosure s: [rat -> rat] = aux280;
  mpq_t aux281;
  mpq_init(aux281);
  s56279(aux281, 0);
  mpq_t aux282;
  mpq_init(aux282);
  pvs_eps233(aux282);
  mpq_mul(result, aux281, aux282);
  free(aux279);
  free(aux280);
  mpq_clear(aux281);
  mpq_clear(aux282);
}