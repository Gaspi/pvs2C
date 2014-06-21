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
struct pvsrec78 {
  mpz_t n;
  mpz_t* arr;
};


void pvs_f76(struct pvsrec78 result, struct pvsrec78 t55966) {
  mpz_t conv81;
  mpz_init(conv81);
  mpz_set_si(conv81, (long) 0);
  copy_struct pvsrec78(result, t55966);
  result.n = conv81;
  mpz_clear(conv81);
}

void pvs_d_f77(struct pvsrec78 result, struct pvsrec78 t55966) {
  mpz_t conv81;
  mpz_init(conv81);
  mpz_set_si(conv81, (long) 0);
  copy_struct pvsrec78(result, t55966);
  result.n = conv81;
  mpz_clear(conv81);
}

void pvs_f82(mpz_t* result, mpz_t* t55966) {
  mpz_t* aux89;
  aux89 = malloc( 10 * sizeof(mpz_t) );
  for(int i90 = 0; i90 < 10; i90++) {
    mpz_init(aux89[i90]);
  }
  for(int i88 = 0; i88 < 10; i88++) {
    mpz_set(aux89[i88], t55966[i88]);
  }
  mpz_t* a = aux89;
  for(int i91 = 0; i91 < 10; i91++) {
    mpz_set(result[i91], a[i91]);
  }
  free(aux89);
}

void pvs_d_f83(mpz_t* result, mpz_t* t55966) {
  mpz_t* aux89;
  aux89 = malloc( 10 * sizeof(mpz_t) );
  for(int i90 = 0; i90 < 10; i90++) {
    mpz_init(aux89[i90]);
  }
  for(int i88 = 0; i88 < 10; i88++) {
    mpz_set(aux89[i88], t55966[i88]);
  }
  mpz_t* a = aux89;
  for(int i91 = 0; i91 < 10; i91++) {
    mpz_set(result[i91], a[i91]);
  }
  free(aux89);
}