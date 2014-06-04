/*
C file generated from test.pvs
Make sure to link GMP and PVS.c in compilation:
    gcc -o test test.c PVS.c -lgmp
    ./test
*/

#include<stdio.h>
#include "PVS.h"
#include "test.h"

#define TRUE 1
#define FALSE 0

int main(void) {
  printf("Executing test ...\n");
  return 0;
}

void pvs_a953(mpz_t result) {
  mpz_t aux961;
  mpz_init(aux961);
  mpz_set_str(aux961, "2");
  mpz_t aux962;
  mpz_init(aux962);
  mpz_set_str(aux962, "1");
  mpz_t aux960;
  mpz_init(aux960);
  pvsSub(aux960, aux961, aux962);
  mpz_clear(aux962);
  mpz_clear(aux961);
  mpz_t aux964;
  mpz_init(aux964);
  mpz_set_str(aux964, "1");
  mpz_t aux963;
  mpz_init(aux963);
  mpq_neg(aux963, aux964)
  mpz_clear(aux964);
  pvsAdd(result, aux960, aux963);
  mpz_clear(aux963);
  mpz_clear(aux960);
}

void pvs_d_a954(mpz_t result) {
  mpz_t aux961;
  mpz_init(aux961);
  mpz_set_str(aux961, "2");
  mpz_t aux962;
  mpz_init(aux962);
  mpz_set_str(aux962, "1");
  mpz_t aux960;
  mpz_init(aux960);
  pvsSub(aux960, aux961, aux962);
  mpz_clear(aux962);
  mpz_clear(aux961);
  mpz_t aux964;
  mpz_init(aux964);
  mpz_set_str(aux964, "1");
  mpz_t aux963;
  mpz_init(aux963);
  mpq_neg(aux963, aux964)
  mpz_clear(aux964);
  pvsAdd(result, aux960, aux963);
  mpz_clear(aux963);
  mpz_clear(aux960);
}

int pvs_b965() {
  int result;
  result = TRUE;
  return result;
}

int pvs_d_b966() {
  int result;
  result = TRUE;
  return result;
}

int pvs_bar967(mpz_t n) {
  int result;
  mpz_t aux974;
  mpz_init(aux974);
  mpz_set_str(aux974, "3");
  mpz_t aux973;
  mpz_init(aux973);
  pvsAdd(aux973, n, aux974);
  mpz_clear(aux974);
  mpz_t aux975;
  mpz_init(aux975);
  mpz_set_str(aux975, "12");
  if((isEven(aux973) && ( mpz_cmp(n, aux975) < 0 ))) {
    mpz_t aux976;
    mpz_init(aux976);
    mpz_set_str(aux976, "6");
    result = (mpz_cmp(n, aux976) == 0);
    mpz_clear(aux976);
  } else {
    result = isEven(n);;
  }
  
  mpz_clear(aux975);
  mpz_clear(aux973);
  return result;
}

int pvs_d_bar968(mpz_t n) {
  int result;
  mpz_t aux974;
  mpz_init(aux974);
  mpz_set_str(aux974, "3");
  mpz_t aux973;
  mpz_init(aux973);
  pvsAdd(aux973, n, aux974);
  mpz_clear(aux974);
  mpz_t aux975;
  mpz_init(aux975);
  mpz_set_str(aux975, "12");
  if((isEven(aux973) && ( mpz_cmp(n, aux975) < 0 ))) {
    mpz_t aux976;
    mpz_init(aux976);
    mpz_set_str(aux976, "6");
    result = (mpz_cmp(n, aux976) == 0);
    mpz_clear(aux976);
  } else {
    result = isEven(n);;
  }
  
  mpz_clear(aux975);
  mpz_clear(aux973);
  return result;
}

void pvs_adda977(mpz_t result, mpz_t i) {
  mpz_t aux980;
  mpz_init(aux980);
  mpz_set_str(aux980, "3");
  mpz_t c = aux980;
  copy(result, c)
  mpz_clear(aux980);
}

void pvs_d_adda978(mpz_t result, mpz_t i) {
  mpz_t aux980;
  mpz_init(aux980);
  mpz_set_str(aux980, "3");
  mpz_t c = aux980;
  copy(result, c)
  mpz_clear(aux980);
}

void pvs_foo981(mpz_t result, mpz_t x) {
  mpz_t aux987;
  mpz_init(aux987);
  mpz_set_str(aux987, "1");
  mpz_t aux989;
  mpz_init(aux989);
  mpz_set_str(aux989, "0");
  mpz_t if988;
  mpz_init(if988);
  if((mpz_cmp(x, aux989) == 0)) {
    mpz_set_str(if988, "1");
  } else {
    mpz_t aux990;
    mpz_init(aux990);
    mpz_set_str(aux990, "3");
    pvsAdd(if988, aux990, x);;
    mpz_clear(aux990);
  }
  pvsAdd(result, aux987, if988);
  mpz_clear(aux989);
  mpz_clear(if988);
  mpz_clear(aux987);
}

void pvs_d_foo982(mpz_t result, mpz_t x) {
  mpz_t aux987;
  mpz_init(aux987);
  mpz_set_str(aux987, "1");
  mpz_t aux989;
  mpz_init(aux989);
  mpz_set_str(aux989, "0");
  mpz_t if988;
  mpz_init(if988);
  if((mpz_cmp(x, aux989) == 0)) {
    mpz_set_str(if988, "1");
  } else {
    mpz_t aux990;
    mpz_init(aux990);
    mpz_set_str(aux990, "3");
    pvsAdd(if988, aux990, x);;
    mpz_clear(aux990);
  }
  pvsAdd(result, aux987, if988);
  mpz_clear(aux989);
  mpz_clear(if988);
  mpz_clear(aux987);
}

void pvs_add2991(mpz_t result, mpz_t a) {
  mpz_t aux1001;
  mpz_init(aux1001);
  mpz_set_str(aux1001, "1");
  mpz_t if1000;
  mpz_init(if1000);
  if((mpz_cmp(a, aux1001) == 0)) {
    mpz_set_str(if1000, "1");
  } else {
    mpz_set_str(if1000, "0");;
  }
  mpz_t aux999;
  mpz_init(aux999);
  pvsAdd(aux999, a, if1000);
  mpz_clear(aux1001);
  mpz_clear(if1000);
  mpz_t aux1002;
  mpz_init(aux1002);
  mpz_set_str(aux1002, "2");
  mpz_t d = aux1002;
  mpz_t c = aux999;
  mpz_t aux1003;
  mpz_init(aux1003);
  pvsAdd(aux1003, c, d);
  mpz_clear(aux1002);
  mpz_clear(aux999);
  mpz_t aux1004;
  mpz_init(aux1004);
  mpz_set_str(aux1004, "1");
  pvsAdd(result, aux1003, aux1004);
  mpz_clear(aux1004);
  mpz_clear(aux1003);
}

void pvs_d_add2992(mpz_t result, mpz_t a) {
  mpz_t aux1001;
  mpz_init(aux1001);
  mpz_set_str(aux1001, "1");
  mpz_t if1000;
  mpz_init(if1000);
  if((mpz_cmp(a, aux1001) == 0)) {
    mpz_set_str(if1000, "1");
  } else {
    mpz_set_str(if1000, "0");;
  }
  mpz_t aux999;
  mpz_init(aux999);
  pvsAdd(aux999, a, if1000);
  mpz_clear(aux1001);
  mpz_clear(if1000);
  mpz_t aux1002;
  mpz_init(aux1002);
  mpz_set_str(aux1002, "2");
  mpz_t d = aux1002;
  mpz_t c = aux999;
  mpz_t aux1003;
  mpz_init(aux1003);
  pvsAdd(aux1003, c, d);
  mpz_clear(aux1002);
  mpz_clear(aux999);
  mpz_t aux1004;
  mpz_init(aux1004);
  mpz_set_str(aux1004, "1");
  pvsAdd(result, aux1003, aux1004);
  mpz_clear(aux1004);
  mpz_clear(aux1003);
}

void pvs_f1005(mpz_t result, mpz_t x) {
  mpz_t aux1009;
  mpz_init(aux1009);
  mpz_set_str(aux1009, "12");
  mpz_t x: int = aux1009;
  mpz_t aux1010;
  mpz_init(aux1010);
  mpz_set_str(aux1010, "2");
  pvsAdd(result, x#0, aux1010);
  mpz_clear(aux1010);
  mpz_clear(aux1009);
}

void pvs_d_f1006(mpz_t result, mpz_t x) {
  mpz_t aux1009;
  mpz_init(aux1009);
  mpz_set_str(aux1009, "12");
  mpz_t x: int = aux1009;
  mpz_t aux1010;
  mpz_init(aux1010);
  mpz_set_str(aux1010, "2");
  pvsAdd(result, x#0, aux1010);
  mpz_clear(aux1010);
  mpz_clear(aux1009);
}

void pvs_factorial1011(mpz_t result, mpz_t n) {
  mpz_t aux1017;
  mpz_init(aux1017);
  mpz_set_str(aux1017, "0");
  if((mpz_cmp(n, aux1017) == 0)) {
    mpz_set_str(result, "1");
  } else {
    mpz_t aux1020;
    mpz_init(aux1020);
    mpz_set_str(aux1020, "1");
    mpz_t aux1019;
    mpz_init(aux1019);
    pvsSub(aux1019, n, aux1020);
    mpz_clear(aux1020);
    mpz_t aux1018;
    mpz_init(aux1018);
    pvs_d_factorial1012(aux1018, aux1019)
    mpz_clear(aux1019);
    pvsTimes(result, n, aux1018);;
    mpz_clear(aux1018);
  }
  
  mpz_clear(aux1017);
}

void pvs_d_factorial1012(mpz_t result, mpz_t n) {
  mpz_t aux1017;
  mpz_init(aux1017);
  mpz_set_str(aux1017, "0");
  if((mpz_cmp(n, aux1017) == 0)) {
    mpz_set_str(result, "1");
  } else {
    mpz_t aux1020;
    mpz_init(aux1020);
    mpz_set_str(aux1020, "1");
    mpz_t aux1019;
    mpz_init(aux1019);
    pvsSub(aux1019, n, aux1020);
    mpz_clear(aux1020);
    mpz_t aux1018;
    mpz_init(aux1018);
    pvs_d_factorial1012(aux1018, aux1019)
    mpz_clear(aux1019);
    pvsTimes(result, n, aux1018);;
    mpz_clear(aux1018);
  }
  
  mpz_clear(aux1017);
}