// ---------------------------------------------
//        C file generated from arrays.pvs
// ---------------------------------------------
//   Make sure to link GMP in compilation:
//      gcc -o arrays arrays.c -lgmp
//      ./arrays
// ---------------------------------------------

#include<stdio.h>
#include<gmp.h>
#include "arrays.h"

#define TRUE 1
#define FALSE 0

int main(void) {
  printf("Executing arrays ...\n");
  return 0;
}


mpq_t fun224(void *env) {
  mpz_t y = (mpz_t) env[1];
  int x = (int) env[0];
  mpz_t conv219;
  mpz_init(conv219);
  mpz_set_si(conv219, (long) 0);
  int aux220;
  aux220 = (mpz_cmp(y, conv219) == 0);
  mpz_clear(conv219);
  mpz_t if221;
  mpz_init(if221);
  if(aux220) {
    mpz_set_si(if221, (long) 1);
  } else {
    mpz_set_si(if221, (long) 0);
  }
  mpz_t aux222;
  mpz_init(aux222);
  mpz_add_ui(aux222, if221, (unsigned long) x);
  mpz_clear(if221);
  mpq_t conv223;
  mpq_init(conv223);
  mpq_set_z(conv223, aux222);
  mpq_canonicalize(conv223);
  mpz_clear(aux222);
  mpq_clear(conv223);
  return conv223;
}

mpq_t fun231(void *env) {
  mpz_t y = (mpz_t) env[1];
  int x = (int) env[0];
  mpz_t conv226;
  mpz_init(conv226);
  mpz_set_si(conv226, (long) 0);
  int aux227;
  aux227 = (mpz_cmp(y, conv226) == 0);
  mpz_clear(conv226);
  mpz_t if228;
  mpz_init(if228);
  if(aux227) {
    mpz_set_si(if228, (long) 1);
  } else {
    mpz_set_si(if228, (long) 0);
  }
  mpz_t aux229;
  mpz_init(aux229);
  mpz_add_ui(aux229, if228, (unsigned long) x);
  mpz_clear(if228);
  mpq_t conv230;
  mpq_init(conv230);
  mpq_set_z(conv230, aux229);
  mpq_canonicalize(conv230);
  mpz_clear(aux229);
  mpq_clear(conv230);
  return conv230;
}

mpq_t fun329(void *env) {
  mpz_t x = (mpz_t) env[3];
  pvsClosure t = (pvsClosure) env[2];
  int x1 = (int) env[1];
  mpz_t y = (mpz_t) env[0];
  mpz_t if327;
  mpz_init(if327);
  if((mpz_cmp(x#0, y) == 0)) {
    mpz_set_si(if327, (long) 12);
  } else {
    pvsClosure aux326;
    aux326 = malloc( sizeof(pvsClosure) );
    t56092(aux326, x1);
    mpz_set_si(if327, (long) aux326(x#0));
    free(aux326);
  }
  mpq_t conv328;
  mpq_init(conv328);
  mpq_set_z(conv328, if327);
  mpq_canonicalize(conv328);
  mpz_clear(if327);
  mpq_clear(conv328);
  return conv328;
}

pvsClosure fun332(void *env) {
  int x1 = (int) env[3];
  pvsClosure t = (pvsClosure) env[2];
  mpz_t y = (mpz_t) env[1];
  int x = (int) env[0];
  pvsClosure if331;
  if331 = malloc( sizeof(pvsClosure) );
  if((x1 == x)) {
    void env330[4];
    env330[1] = x1;
    env330[0] = y;
    env330[3] = x;
    makeClosure(if331, fun329, env330);
  } else {
    t56092(if331, x1);
  }
  free(if331);
  return if331;
}

mpq_t fun338(void *env) {
  mpz_t x = (mpz_t) env[3];
  pvsClosure t = (pvsClosure) env[2];
  int x1 = (int) env[1];
  mpz_t y = (mpz_t) env[0];
  mpz_t if336;
  mpz_init(if336);
  if((mpz_cmp(x#0, y) == 0)) {
    mpz_set_si(if336, (long) 12);
  } else {
    pvsClosure aux335;
    aux335 = malloc( sizeof(pvsClosure) );
    t56092(aux335, x1);
    mpz_set_si(if336, (long) aux335(x#0));
    free(aux335);
  }
  mpq_t conv337;
  mpq_init(conv337);
  mpq_set_z(conv337, if336);
  mpq_canonicalize(conv337);
  mpz_clear(if336);
  mpq_clear(conv337);
  return conv337;
}

pvsClosure fun341(void *env) {
  int x1 = (int) env[3];
  pvsClosure t = (pvsClosure) env[2];
  mpz_t y = (mpz_t) env[1];
  int x = (int) env[0];
  pvsClosure if340;
  if340 = malloc( sizeof(pvsClosure) );
  if((x1 == x)) {
    void env339[4];
    env339[1] = x1;
    env339[0] = y;
    env339[3] = x;
    makeClosure(if340, fun338, env339);
  } else {
    t56092(if340, x1);
  }
  free(if340);
  return if340;
}

void pvs_a217(pvsClosure result, int x) {
  void env232[2];
  env232[0] = x;
  makeClosure(result, fun231, env232);
}

void pvs_d_a218(pvsClosure result, int x) {
  void env232[2];
  env232[0] = x;
  makeClosure(result, fun231, env232);
}

int pvs_b233(int x) {
  int result;
  result = x;
  return result;
}

int pvs_d_b234(int x) {
  int result;
  result = x;
  return result;
}

void pvs_incr235(int* result, int* t56092) {
  int L242;
  L242 = t56092[0];
  for(int i241 = 0; i241 < 10; i241++) {
    result[i241] = t56092[i241];
  }
  result[L242] = t56092[9];
}

void pvs_d_incr236(int* result, int* t56092) {
  int L242;
  L242 = t56092[0];
  for(int i241 = 0; i241 < 10; i241++) {
    result[i241] = t56092[i241];
  }
  result[L242] = t56092[9];
}

void pvs_decr243(int* result, int* t56092) {
  int L248;
  L248 = 0;
  for(int i247 = 0; i247 < 10; i247++) {
    result[i247] = pvs_d_b234(i247);
  }
  result[L248] = 1;
}

void pvs_d_decr244(int* result, int* t56092) {
  int L248;
  L248 = 0;
  for(int i247 = 0; i247 < 10; i247++) {
    result[i247] = pvs_d_b234(i247);
  }
  result[L248] = 1;
}

void pvs_sum249(int* result, int* T, int* U) {
  mpq_t* set258;
  set258 = malloc( 10 * sizeof(mpq_t) );
  for(int i259 = 0; i259 < 10; i259++) {
    mpq_init(set258[i259]);
  }
  for(int i256 = 0; i256 < 10; i256++) {
    mpz_t conv257;
    mpz_init(conv257);
    mpz_set_si(conv257, (long) T[i256]);
    mpz_add_ui(set258[i256], conv257, (unsigned long) U[i256]);
    mpz_clear(conv257);
  }
  for(int i260 = 0; i260 < 10; i260++) {
    result[i260] = ( (int) mpq_get_d(set258[i260]) );
  }
  free(set258);
}

void pvs_d_sum250(int* result, int* T, int* U) {
  mpq_t* set258;
  set258 = malloc( 10 * sizeof(mpq_t) );
  for(int i259 = 0; i259 < 10; i259++) {
    mpq_init(set258[i259]);
  }
  for(int i256 = 0; i256 < 10; i256++) {
    mpz_t conv257;
    mpz_init(conv257);
    mpz_set_si(conv257, (long) T[i256]);
    mpz_add_ui(set258[i256], conv257, (unsigned long) U[i256]);
    mpz_clear(conv257);
  }
  for(int i260 = 0; i260 < 10; i260++) {
    result[i260] = ( (int) mpq_get_d(set258[i260]) );
  }
  free(set258);
}

void pvs_foo261(int* result, int* t56092) {
  int L278;
  L278 = 0;
  mpz_t conv279;
  mpz_init(conv279);
  mpz_set_si(conv279, (long) 1);
  mpz_t aux280;
  mpz_init(aux280);
  mpz_add_ui(aux280, conv279, (unsigned long) t56092[9]);
  mpz_clear(conv279);
  int L281;
  L281 = t56092[0];
  mpz_t conv282;
  mpz_init(conv282);
  mpz_set_si(conv282, (long) 1);
  mpz_t aux283;
  mpz_init(aux283);
  mpz_add_ui(aux283, conv282, (unsigned long) t56092[0]);
  mpz_clear(conv282);
  for(int i277 = 0; i277 < 10; i277++) {
    result[i277] = t56092[i277];
  }
  result[L278] = ( (int) mpz_get_si(aux280) );
  result[L281] = ( (int) mpz_get_si(aux283) );
  mpz_clear(aux280);
  mpz_clear(aux283);
}

void pvs_d_foo262(int* result, int* t56092) {
  int L278;
  L278 = 0;
  mpz_t conv279;
  mpz_init(conv279);
  mpz_set_si(conv279, (long) 1);
  mpz_t aux280;
  mpz_init(aux280);
  mpz_add_ui(aux280, conv279, (unsigned long) t56092[9]);
  mpz_clear(conv279);
  int L281;
  L281 = t56092[0];
  mpz_t conv282;
  mpz_init(conv282);
  mpz_set_si(conv282, (long) 1);
  mpz_t aux283;
  mpz_init(aux283);
  mpz_add_ui(aux283, conv282, (unsigned long) t56092[0]);
  mpz_clear(conv282);
  for(int i277 = 0; i277 < 10; i277++) {
    result[i277] = t56092[i277];
  }
  result[L278] = ( (int) mpz_get_si(aux280) );
  result[L281] = ( (int) mpz_get_si(aux283) );
  mpz_clear(aux280);
  mpz_clear(aux283);
}

void pvs_bar284(int** result, int** t56092) {
  int L306;
  L306 = 0;
  int L308;
  L308 = 0;
  int** aux309;
  aux309 = malloc( 10 * sizeof(int*) );
  for(int i310 = 0; i310 < 10; i310++) {
    aux309[i310] = malloc( 12 * sizeof(int) );
  }
  for(int i304 = 0; i304 < 10; i304++) {
    for(int i305 = 0; i305 < 12; i305++) {
      aux309[i304][i305] = t56092[i304][i305];
    }
  }
  int* E307 = aux309[L306];
  E307[L308] = 0;
  int** a = aux309;
  for(int i311 = 0; i311 < 10; i311++) {
    for(int i312 = 0; i312 < 12; i312++) {
      result[i311][i312] = a[i311][i312];
    }
  }
  free(aux309);
}

void pvs_d_bar285(int** result, int** t56092) {
  int L306;
  L306 = 0;
  int L308;
  L308 = 0;
  int** aux309;
  aux309 = malloc( 10 * sizeof(int*) );
  for(int i310 = 0; i310 < 10; i310++) {
    aux309[i310] = malloc( 12 * sizeof(int) );
  }
  for(int i304 = 0; i304 < 10; i304++) {
    for(int i305 = 0; i305 < 12; i305++) {
      aux309[i304][i305] = t56092[i304][i305];
    }
  }
  int* E307 = aux309[L306];
  E307[L308] = 0;
  int** a = aux309;
  for(int i311 = 0; i311 < 10; i311++) {
    for(int i312 = 0; i312 < 12; i312++) {
      result[i311][i312] = a[i311][i312];
    }
  }
  free(aux309);
}

void pvs_test313(mpz_t* result, mpz_t* t56092) {
  int L322;
  L322 = 0;
  mpz_t conv323;
  mpz_init(conv323);
  mpz_set_si(conv323, (long) 12);
  for(int i321 = 0; i321 < 10; i321++) {
    mpz_set(result[i321], t56092[i321]);
  }
  mpz_set(result[L322], conv323);
  mpz_clear(conv323);
}

void pvs_d_test314(mpz_t* result, mpz_t* t56092) {
  int L322;
  L322 = 0;
  mpz_t conv323;
  mpz_init(conv323);
  mpz_set_si(conv323, (long) 12);
  for(int i321 = 0; i321 < 10; i321++) {
    mpz_set(result[i321], t56092[i321]);
  }
  mpz_set(result[L322], conv323);
  mpz_clear(conv323);
}

void pvs_set324(pvsClosure result, pvsClosure t56092, int x, mpz_t y) {
  void env342[4];
  env342[1] = y;
  env342[0] = x;
  pvsClosure aux343;
  aux343 = malloc( sizeof(pvsClosure) );
  makeClosure(aux343, fun341, env342);
  copy_pvsClosure(result, aux343);
  free(aux343);
}

void pvs_d_set325(pvsClosure result, pvsClosure t56092, int x, mpz_t y) {
  void env342[4];
  env342[1] = y;
  env342[0] = x;
  pvsClosure aux343;
  aux343 = malloc( sizeof(pvsClosure) );
  makeClosure(aux343, fun341, env342);
  copy_pvsClosure(result, aux343);
  free(aux343);
}