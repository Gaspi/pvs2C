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


mpq_t fun1365(void *args) {
  mpz_t y = (mpz_t)args[1];
  int x = (int)args[0];
  mpz_t conv1360;
  mpz_init(conv1360);
  mpz_set_si(conv1360, (long) 0);
  int aux1361;
  aux1361 = (mpz_cmp(y, conv1360) == 0);
  mpz_clear(conv1360);
  mpz_t if1362;
  mpz_init(if1362);
  if(aux1361) {
    mpz_set_si(if1362, (long) 1);
  } else {
    mpz_set_si(if1362, (long) 0);
  }
  mpz_t aux1363;
  mpz_init(aux1363);
  mpz_add_ui(aux1363, if1362, (unsigned long) x);
  mpz_clear(if1362);
  mpq_t conv1364;
  mpq_init(conv1364);
  mpq_set_z(conv1364, aux1363);
  mpq_canonicalize(conv1364);
  mpz_clear(aux1363);
  mpq_clear(conv1364);
  return conv1364;
}

mpq_t fun1371(void *args) {
  mpz_t y = (mpz_t)args[1];
  int x = (int)args[0];
  mpz_t conv1366;
  mpz_init(conv1366);
  mpz_set_si(conv1366, (long) 0);
  int aux1367;
  aux1367 = (mpz_cmp(y, conv1366) == 0);
  mpz_clear(conv1366);
  mpz_t if1368;
  mpz_init(if1368);
  if(aux1367) {
    mpz_set_si(if1368, (long) 1);
  } else {
    mpz_set_si(if1368, (long) 0);
  }
  mpz_t aux1369;
  mpz_init(aux1369);
  mpz_add_ui(aux1369, if1368, (unsigned long) x);
  mpz_clear(if1368);
  mpq_t conv1370;
  mpq_init(conv1370);
  mpq_set_z(conv1370, aux1369);
  mpq_canonicalize(conv1370);
  mpz_clear(aux1369);
  mpq_clear(conv1370);
  return conv1370;
}

mpq_t fun1468(void *args) {
  mpz_t x = (mpz_t)args[3];
  pvsClosure t = (pvsClosure)args[2];
  int x1 = (int)args[1];
  mpz_t y = (mpz_t)args[0];
  mpz_t if1466;
  mpz_init(if1466);
  if((mpz_cmp(x#0, y) == 0)) {
    mpz_set_si(if1466, (long) 12);
  } else {
    pvsClosure aux1465;
    aux1465 = malloc( sizeof(pvsClosure) );
    t56371(aux1465, x1);
    mpz_set_si(if1466, (long) aux1465(x#0));
    free(aux1465);
  }
  mpq_t conv1467;
  mpq_init(conv1467);
  mpq_set_z(conv1467, if1466);
  mpq_canonicalize(conv1467);
  mpz_clear(if1466);
  mpq_clear(conv1467);
  return conv1467;
}

pvsClosure fun1470(void *args) {
  int x1 = (int)args[3];
  pvsClosure t = (pvsClosure)args[2];
  mpz_t y = (mpz_t)args[1];
  int x = (int)args[0];
  pvsClosure if1469;
  if1469 = malloc( sizeof(pvsClosure) );
  if((x1 == x)) {
    void args[4];
    args[1] = x1;
    args[0] = y;
    args[3] = x;
    makeClosure(if1469, fun1468, args);
  } else {
    t56371(if1469, x1);
  }
  free(if1469);
  return if1469;
}

mpq_t fun1475(void *args) {
  mpz_t x = (mpz_t)args[3];
  pvsClosure t = (pvsClosure)args[2];
  int x1 = (int)args[1];
  mpz_t y = (mpz_t)args[0];
  mpz_t if1473;
  mpz_init(if1473);
  if((mpz_cmp(x#0, y) == 0)) {
    mpz_set_si(if1473, (long) 12);
  } else {
    pvsClosure aux1472;
    aux1472 = malloc( sizeof(pvsClosure) );
    t56371(aux1472, x1);
    mpz_set_si(if1473, (long) aux1472(x#0));
    free(aux1472);
  }
  mpq_t conv1474;
  mpq_init(conv1474);
  mpq_set_z(conv1474, if1473);
  mpq_canonicalize(conv1474);
  mpz_clear(if1473);
  mpq_clear(conv1474);
  return conv1474;
}

pvsClosure fun1477(void *args) {
  int x1 = (int)args[3];
  pvsClosure t = (pvsClosure)args[2];
  mpz_t y = (mpz_t)args[1];
  int x = (int)args[0];
  pvsClosure if1476;
  if1476 = malloc( sizeof(pvsClosure) );
  if((x1 == x)) {
    void args[4];
    args[1] = x1;
    args[0] = y;
    args[3] = x;
    makeClosure(if1476, fun1475, args);
  } else {
    t56371(if1476, x1);
  }
  free(if1476);
  return if1476;
}

void pvs_a1358(pvsClosure result, int x) {
  void args[2];
  args[0] = x;
  makeClosure(result, fun1371, args);
}

void pvs_d_a1359(pvsClosure result, int x) {
  void args[2];
  args[0] = x;
  makeClosure(result, fun1371, args);
}

int pvs_b1372(int x) {
  int result;
  result = x;
  return result;
}

int pvs_d_b1373(int x) {
  int result;
  result = x;
  return result;
}

void pvs_incr1374(int* result, int* t56371) {
  int L1381;
  L1381 = t56371[0];
  for(int i1380 = 0; i1380 < 10; i1380++) {
    result[i1380] = t56371[i1380];
  }
  result[L1381] = t56371[9];
}

void pvs_d_incr1375(int* result, int* t56371) {
  int L1381;
  L1381 = t56371[0];
  for(int i1380 = 0; i1380 < 10; i1380++) {
    result[i1380] = t56371[i1380];
  }
  result[L1381] = t56371[9];
}

void pvs_decr1382(int* result, int* t56371) {
  int L1387;
  L1387 = 0;
  for(int i1386 = 0; i1386 < 10; i1386++) {
    result[i1386] = pvs_d_b1373(i1386);
  }
  result[L1387] = 1;
}

void pvs_d_decr1383(int* result, int* t56371) {
  int L1387;
  L1387 = 0;
  for(int i1386 = 0; i1386 < 10; i1386++) {
    result[i1386] = pvs_d_b1373(i1386);
  }
  result[L1387] = 1;
}

void pvs_sum1388(int* result, int* T, int* U) {
  mpq_t* set1397;
  set1397 = malloc( 10 * sizeof(mpq_t) );
  for(int i1398 = 0; i1398 < 10; i1398++) {
    mpq_init(set1397[i1398]);
  }
  for(int i1395 = 0; i1395 < 10; i1395++) {
    mpz_t conv1396;
    mpz_init(conv1396);
    mpz_set_si(conv1396, (long) T[i1395]);
    mpz_add_ui(set1397[i1395], conv1396, (unsigned long) U[i1395]);
    mpz_clear(conv1396);
  }
  for(int i1399 = 0; i1399 < 10; i1399++) {
    result[i1399] = ( (int) mpq_get_d(set1397[i1399]) );
  }
  free(set1397);
}

void pvs_d_sum1389(int* result, int* T, int* U) {
  mpq_t* set1397;
  set1397 = malloc( 10 * sizeof(mpq_t) );
  for(int i1398 = 0; i1398 < 10; i1398++) {
    mpq_init(set1397[i1398]);
  }
  for(int i1395 = 0; i1395 < 10; i1395++) {
    mpz_t conv1396;
    mpz_init(conv1396);
    mpz_set_si(conv1396, (long) T[i1395]);
    mpz_add_ui(set1397[i1395], conv1396, (unsigned long) U[i1395]);
    mpz_clear(conv1396);
  }
  for(int i1399 = 0; i1399 < 10; i1399++) {
    result[i1399] = ( (int) mpq_get_d(set1397[i1399]) );
  }
  free(set1397);
}

void pvs_foo1400(int* result, int* t56371) {
  int L1417;
  L1417 = 0;
  mpz_t conv1418;
  mpz_init(conv1418);
  mpz_set_si(conv1418, (long) 1);
  mpz_t aux1419;
  mpz_init(aux1419);
  mpz_add_ui(aux1419, conv1418, (unsigned long) t56371[9]);
  mpz_clear(conv1418);
  int L1420;
  L1420 = t56371[0];
  mpz_t conv1421;
  mpz_init(conv1421);
  mpz_set_si(conv1421, (long) 1);
  mpz_t aux1422;
  mpz_init(aux1422);
  mpz_add_ui(aux1422, conv1421, (unsigned long) t56371[0]);
  mpz_clear(conv1421);
  for(int i1416 = 0; i1416 < 10; i1416++) {
    result[i1416] = t56371[i1416];
  }
  result[L1417] = ( (int) mpz_get_si(aux1419) );
  result[L1420] = ( (int) mpz_get_si(aux1422) );
  mpz_clear(aux1419);
  mpz_clear(aux1422);
}

void pvs_d_foo1401(int* result, int* t56371) {
  int L1417;
  L1417 = 0;
  mpz_t conv1418;
  mpz_init(conv1418);
  mpz_set_si(conv1418, (long) 1);
  mpz_t aux1419;
  mpz_init(aux1419);
  mpz_add_ui(aux1419, conv1418, (unsigned long) t56371[9]);
  mpz_clear(conv1418);
  int L1420;
  L1420 = t56371[0];
  mpz_t conv1421;
  mpz_init(conv1421);
  mpz_set_si(conv1421, (long) 1);
  mpz_t aux1422;
  mpz_init(aux1422);
  mpz_add_ui(aux1422, conv1421, (unsigned long) t56371[0]);
  mpz_clear(conv1421);
  for(int i1416 = 0; i1416 < 10; i1416++) {
    result[i1416] = t56371[i1416];
  }
  result[L1417] = ( (int) mpz_get_si(aux1419) );
  result[L1420] = ( (int) mpz_get_si(aux1422) );
  mpz_clear(aux1419);
  mpz_clear(aux1422);
}

void pvs_bar1423(int** result, int** t56371) {
  int L1445;
  L1445 = 0;
  int L1447;
  L1447 = 0;
  int** aux1448;
  aux1448 = malloc( 10 * sizeof(int*) );
  for(int i1449 = 0; i1449 < 10; i1449++) {
    aux1448[i1449] = malloc( 12 * sizeof(int) );
  }
  for(int i1443 = 0; i1443 < 10; i1443++) {
    for(int i1444 = 0; i1444 < 12; i1444++) {
      aux1448[i1443][i1444] = t56371[i1443][i1444];
    }
  }
  int* E1446 = aux1448[L1445];
  E1446[L1447] = 0;
  int** a = aux1448;
  for(int i1450 = 0; i1450 < 10; i1450++) {
    for(int i1451 = 0; i1451 < 12; i1451++) {
      result[i1450][i1451] = a[i1450][i1451];
    }
  }
  free(aux1448);
}

void pvs_d_bar1424(int** result, int** t56371) {
  int L1445;
  L1445 = 0;
  int L1447;
  L1447 = 0;
  int** aux1448;
  aux1448 = malloc( 10 * sizeof(int*) );
  for(int i1449 = 0; i1449 < 10; i1449++) {
    aux1448[i1449] = malloc( 12 * sizeof(int) );
  }
  for(int i1443 = 0; i1443 < 10; i1443++) {
    for(int i1444 = 0; i1444 < 12; i1444++) {
      aux1448[i1443][i1444] = t56371[i1443][i1444];
    }
  }
  int* E1446 = aux1448[L1445];
  E1446[L1447] = 0;
  int** a = aux1448;
  for(int i1450 = 0; i1450 < 10; i1450++) {
    for(int i1451 = 0; i1451 < 12; i1451++) {
      result[i1450][i1451] = a[i1450][i1451];
    }
  }
  free(aux1448);
}

void pvs_test1452(mpz_t* result, mpz_t* t56371) {
  int L1461;
  L1461 = 0;
  mpz_t conv1462;
  mpz_init(conv1462);
  mpz_set_si(conv1462, (long) 12);
  for(int i1460 = 0; i1460 < 10; i1460++) {
    mpz_set(result[i1460], t56371[i1460]);
  }
  mpz_set(result[L1461], conv1462);
  mpz_clear(conv1462);
}

void pvs_d_test1453(mpz_t* result, mpz_t* t56371) {
  int L1461;
  L1461 = 0;
  mpz_t conv1462;
  mpz_init(conv1462);
  mpz_set_si(conv1462, (long) 12);
  for(int i1460 = 0; i1460 < 10; i1460++) {
    mpz_set(result[i1460], t56371[i1460]);
  }
  mpz_set(result[L1461], conv1462);
  mpz_clear(conv1462);
}

void pvs_set1463(pvsClosure result, pvsClosure t56371, int x, mpz_t y) {
  void args[4];
  args[1] = y;
  args[0] = x;
  pvsClosure aux1478;
  aux1478 = malloc( sizeof(pvsClosure) );
  makeClosure(aux1478, fun1477, args);
  copy_pvsClosure(result, aux1478);
  free(aux1478);
}

void pvs_d_set1464(pvsClosure result, pvsClosure t56371, int x, mpz_t y) {
  void args[4];
  args[1] = y;
  args[0] = x;
  pvsClosure aux1478;
  aux1478 = malloc( sizeof(pvsClosure) );
  makeClosure(aux1478, fun1477, args);
  copy_pvsClosure(result, aux1478);
  free(aux1478);
}