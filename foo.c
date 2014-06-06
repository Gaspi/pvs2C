/*
C file generated from foo.pvs
Make sure to link GMP and PVS.c in compilation:
    gcc -o foo foo.c PVS.c -lgmp
    ./foo
*/

#include<stdio.h>
#include "PVS.h"
#include "foo.h"

#define TRUE 1
#define FALSE 0

int main(void) {
  printf("Executing foo ...\n");
  return 0;
}

void pvs_a53(mpz_t result) {
  mpz_t_from_int(result, (2 + 3));
}

void pvs_d_a54(mpz_t result) {
  mpz_t_from_int(result, (2 + 3));
}

void pvs_f55(mpz_t result, mpz_t x, mpz_t y) {
  mpz_t aux59;
  mpz_init(aux59);
  pvs_a53(aux59);
  int conv60;
  conv60 = int_from_mpz_t(aux59);
  mpz_t_from_int(result, ((x + y) + conv60));
  mpz_clear(aux59);
}

void pvs_d_f56(mpz_t result, mpz_t x, mpz_t y) {
  mpz_t aux59;
  mpz_init(aux59);
  pvs_a53(aux59);
  int conv60;
  conv60 = int_from_mpz_t(aux59);
  mpz_t_from_int(result, ((x + y) + conv60));
  mpz_clear(aux59);
}