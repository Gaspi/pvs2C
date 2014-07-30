// ---------------------------------------------
//        C file generated from draft.pvs
// ---------------------------------------------
//   Make sure to link GC.c and GMP in compilation:
//      gcc -o draft draft.c GC.c -lgmp
//      ./draft
// ---------------------------------------------

#include<stdio.h>
#include<gmp.h>
#include "GC.h"
#include "draft.h"

#define TRUE 1
#define FALSE 0

int main(void) {
  GC_start();
  printf("Executing draft ...\n");
  // Insert code here
  GC_quit();
  return 0;
}


pair1380 pvs_a1378() {
  pair1380 result;
  result = GC_malloc(1, sizeof( struct struct_pair1380 ) );
  mpz_init( result->y );
  result->x = 2;
  mpz_set_si(result->y, (long) 12);
  return result;
}

pair1380 pvs_a_d1379() {
  pair1380 result;
  result = GC_malloc(1, sizeof( struct struct_pair1380 ) );
  mpz_init( result->y );
  result->x = 2;
  mpz_set_si(result->y, (long) 12);
  return result;
}

int pvs_first1381(pair1380 a) {
  int result;
  result = a->x;
  if( GC_count( a ) == 1 ) {
    mpz_clear(a->y);
  }
  GC_free(a);
  return result;
}

int pvs_first_d1382(pair1380 a) {
  int result;
  result = a->x;
  if( GC_count( a ) == 1 ) {
    mpz_clear(a->y);
  }
  GC_free(a);
  return result;
}

pair1380 pvs_zero1383(pair1380 a) {
  pair1380 result;
  if ( GC_count( a ) == 1 )
    result = a;
  else {
    result = GC_malloc(1, sizeof( struct struct_pair1380 ));
    mpz_init( result->y );
    mpz_set(result->y, a->y);
    result->x = a->x;
  }
  result->x = 0;
  int res1385;
  return result;
}

pair1380 pvs_zero_d1384(pair1380 a) {
  a->x = 0;
  int res1386;
  pair1380 result;
  return a;
}

uli pvs_a1387() {
  return (uli) 2;
}

uli pvs_a_d1388() {
  return (uli) 2;
}

int pvs_b1389() {
  return (3 + 1);
}

int pvs_b_d1390() {
  return (3 + 1);
}

void pvs_c1391(mpz_t result) {
  mpz_set_si(result, (long) (3 * (1 + 2)));
}

void pvs_c_d1392(mpz_t result) {
  mpz_set_si(result, (long) (3 * (1 + 2)));
}

int pvs_incr1393(int x) {
  return (x + 1);
}

int pvs_incr_d1394(int x) {
  return (x + 1);
}

int pvs_zero1395(mpz_t x) {
  mpz_clear(x);
  int result;
  return 0;
}

int pvs_zero_d1396(mpz_t x) {
  mpz_clear(x);
  int result;
  return 0;
}

int pvs_f1397(int a, int b) {
  mpz_t conv1399;
  mpz_init( conv1399 );
  mpz_set_si(conv1399, (long) b);
  int result;
  result = (int) (pvs_zero_d1396( conv1399 ) * pvs_incr_d1394( a ));
  mpz_clear(conv1399);
  return result;
}

int pvs_f_d1398(int a, int b) {
  mpz_t conv1400;
  mpz_init( conv1400 );
  mpz_set_si(conv1400, (long) b);
  int result;
  result = (int) (pvs_zero_d1396( conv1400 ) * pvs_incr_d1394( a ));
  mpz_clear(conv1400);
  return result;
}

int pvs_f1401(int x) {
  if (((x <= 1) && 1)) {
    if (((x == 0) || (x < 0))) {
      return 0;
    } else {
      return x;
    }
  } else {
    if ((x > 10)) {
      return 10;
    } else {
      return (x - 5);
    }
  }
}

int pvs_f_d1402(int x) {
  if (((x <= 1) && 1)) {
    if (((x == 0) || (x < 0))) {
      return 0;
    } else {
      return x;
    }
  } else {
    if ((x > 10)) {
      return 10;
    } else {
      return (x - 5);
    }
  }
}

int pvs_t1409(int x) {
  return x;
}

int pvs_t_d1410(int x) {
  return x;
}

int* pvs_id21411(int* t59375) {
  return t59375;
}

int* pvs_id2_d1412(int* t59375) {
  return t59375;
}

int* pvs_f1415(int x) {
  int* result;
  result = GC_malloc(1000, sizeof(int) );
  int i1417;
  for(i1417 = 0; i1417 < 1000; i1417++) {
    result[i1417] = pvs_t_d1410( i1417 );
  }
  return result;
}

int* pvs_f_d1416(int x) {
  int* result;
  result = GC_malloc(1000, sizeof(int) );
  int i1418;
  for(i1418 = 0; i1418 < 1000; i1418++) {
    result[i1418] = pvs_t_d1410( i1418 );
  }
  return result;
}

int* pvs_update1419(int* x) {
  int* result;
  if ( GC_count( x ) == 1 )
    result = x;
  else {
    result = GC_malloc(1000, sizeof(int) );
    int i1573;
    for(i1573 = 0; i1573 < 1000; i1573++) {
      result[i1573] = x[i1573];
    }
  }
  result[0] = 0;
  int L1421;
  int res1422;
  return result;
}

int* pvs_update_d1420(int* x) {
  x[0] = 0;
  int res1424;
  int L1423;
  int* result;
  return x;
}

int* pvs_t21437(int x) {
  int* result;
  result = GC_malloc(1000, sizeof(int) );
  int i1439;
  for(i1439 = 0; i1439 < 1000; i1439++) {
    result[i1439] = (x + i1439);
  }
  return result;
}

int* pvs_t2_d1438(int x) {
  int* result;
  result = GC_malloc(1000, sizeof(int) );
  int i1440;
  for(i1440 = 0; i1440 < 1000; i1440++) {
    result[i1440] = (x + i1440);
  }
  return result;
}

int* pvs_id1441(int** t59375) {
  int* result;
  result = (int*) t59375[0];
  if( GC_count( t59375 ) == 1 ) {
    int i1574;
    for(i1574 = 0; i1574 < 1000; i1574++) {
      GC_free(t59375[i1574]);
    }
  }
  GC_free(t59375);
  int** a;
  return result;
}

int* pvs_id_d1442(int** t59375) {
  int* result;
  result = (int*) t59375[0];
  if( GC_count( t59375 ) == 1 ) {
    int i1576;
    for(i1576 = 0; i1576 < 1000; i1576++) {
      GC_free(t59375[i1576]);
    }
  }
  GC_free(t59375);
  int** a;
  return result;
}

int* pvs_te1473() {
  int* aux1476;
  aux1476 = GC_malloc(1000, sizeof(int) );
  int i1475;
  for(i1475 = 0; i1475 < 1000; i1475++) {
    aux1476[i1475] = pvs_t_d1410( i1475 );
  }
  return pvs_update_d1420( pvs_update_d1420( aux1476 ) );
}

int* pvs_te_d1474() {
  int* aux1478;
  aux1478 = GC_malloc(1000, sizeof(int) );
  int i1477;
  for(i1477 = 0; i1477 < 1000; i1477++) {
    aux1478[i1477] = pvs_t_d1410( i1477 );
  }
  return pvs_update_d1420( pvs_update_d1420( aux1478 ) );
}

int** pvs_update1481(int** x) {
  int* res1488;
  res1488 = GC_malloc(1000, sizeof(int) );
  int i1489;
  for(i1489 = 0; i1489 < 1000; i1489++) {
    res1488[i1489] = i1489;
  }
  int** result;
  if ( GC_count( x ) == 1 )
    result = x;
  else {
    result = GC_malloc(1000, sizeof(int*) );
    int i1578;
    for(i1578 = 0; i1578 < 1000; i1578++) {
      result[i1578] = (int*) x[i1578];
    }
  }
  int* E1484;
  E1484 = GC_malloc(1000, sizeof(int) );
  int i1579;
  for(i1579 = 0; i1579 < 1000; i1579++) {
    E1484[i1579] = result[0][i1579];
  }
  E1484[1] = 0;
  result[0] = (int*) E1484;
  result[1] = (int*) res1488;
  int L1483;
  int L1485;
  int res1486;
  int L1487;
  return result;
}

int** pvs_update_d1482(int** x) {
  int* res1495;
  res1495 = GC_malloc(1000, sizeof(int) );
  int i1496;
  for(i1496 = 0; i1496 < 1000; i1496++) {
    res1495[i1496] = i1496;
  }
  int* E1491;
  E1491 = GC_malloc(1000, sizeof(int) );
  int i1580;
  for(i1580 = 0; i1580 < 1000; i1580++) {
    E1491[i1580] = x[0][i1580];
  }
  E1491[1] = 0;
  x[0] = (int*) E1491;
  x[1] = (int*) res1495;
  int** result;
  int L1490;
  int L1492;
  int res1493;
  int L1494;
  return x;
}