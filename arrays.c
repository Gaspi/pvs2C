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


void pvs_b177(mpz_t result, int x) {
  mpz_set_si(result, (long) x);
}

void pvs_d_b178(mpz_t result, int x) {
  mpz_set_si(result, (long) x);
}

void pvs_a179(mpz_t result) {
  mpz_t conv182;
  mpz_init(conv182);
  mpz_set_si(conv182, (long) 1);
  mpz_add_ui(result, conv182, (unsigned long) 1);
  mpz_clear(conv182);
}

void pvs_d_a180(mpz_t result) {
  mpz_t conv182;
  mpz_init(conv182);
  mpz_set_si(conv182, (long) 1);
  mpz_add_ui(result, conv182, (unsigned long) 1);
  mpz_clear(conv182);
}

void pvs_incr183(mpz_t* result, mpz_t* t56009) {
  int L190;
  L190 = ( (int) mpz_get_si(t56009[0]) );
  for(int i189 = 0; i189 < 10; i189++) {
    mpz_set(result[i189], t56009[i189]);
  }
  mpz_set(result[L190], t56009[9]);
}

void pvs_d_incr184(mpz_t* result, mpz_t* t56009) {
  int L190;
  L190 = ( (int) mpz_get_si(t56009[0]) );
  for(int i189 = 0; i189 < 10; i189++) {
    mpz_set(result[i189], t56009[i189]);
  }
  mpz_set(result[L190], t56009[9]);
}

void pvs_decr191(mpz_t* result, mpz_t* t56009) {
  int L196;
  L196 = 0;
  for(int i195 = 0; i195 < 10; i195++) {
    pvs_d_b178(result[i195], i195);
  }
  mpz_set_si(result[L196], (long) 1);
}

void pvs_d_decr192(mpz_t* result, mpz_t* t56009) {
  int L196;
  L196 = 0;
  for(int i195 = 0; i195 < 10; i195++) {
    pvs_d_b178(result[i195], i195);
  }
  mpz_set_si(result[L196], (long) 1);
}

void pvs_sum197(mpz_t* result, mpz_t* T, mpz_t* U) {
  for(int i200 = 0; i200 < 10; i200++) {
    mpz_add(result[i200], T[i200], U[i200]);
  }
}

void pvs_d_sum198(mpz_t* result, mpz_t* T, mpz_t* U) {
  for(int i200 = 0; i200 < 10; i200++) {
    mpz_add(result[i200], T[i200], U[i200]);
  }
}

void pvs_foo201(mpz_t* result, mpz_t* t56009) {
  int L210;
  L210 = 0;
  int L211;
  L211 = ( (int) mpz_get_si(t56009[0]) );
  for(int i209 = 0; i209 < 10; i209++) {
    mpz_set(result[i209], t56009[i209]);
  }
  mpz_add_ui(result[L210], t56009[9], (unsigned long) 1);
  mpz_add_ui(result[L211], t56009[0], (unsigned long) 1);
}

void pvs_d_foo202(mpz_t* result, mpz_t* t56009) {
  int L210;
  L210 = 0;
  int L211;
  L211 = ( (int) mpz_get_si(t56009[0]) );
  for(int i209 = 0; i209 < 10; i209++) {
    mpz_set(result[i209], t56009[i209]);
  }
  mpz_add_ui(result[L210], t56009[9], (unsigned long) 1);
  mpz_add_ui(result[L211], t56009[0], (unsigned long) 1);
}

void pvs_bar212(int** result, int** t56009) {
  int L234;
  L234 = 0;
  int L236;
  L236 = 0;
  int** aux237;
  aux237 = malloc( 10 * sizeof(int*) );
  for(int i238 = 0; i238 < 10; i238++) {
    aux237[i238] = malloc( 8 * sizeof(int) );
  }
  for(int i232 = 0; i232 < 10; i232++) {
    for(int i233 = 0; i233 < 8; i233++) {
      aux237[i232][i233] = t56009[i232][i233];
    }
  }
  int* E235 = aux237[L234];
  E235[L236] = 0;
  int** a = aux237;
  for(int i239 = 0; i239 < 10; i239++) {
    for(int i240 = 0; i240 < 8; i240++) {
      result[i239][i240] = a[i239][i240];
    }
  }
  free(aux237);
}

void pvs_d_bar213(int** result, int** t56009) {
  int L234;
  L234 = 0;
  int L236;
  L236 = 0;
  int** aux237;
  aux237 = malloc( 10 * sizeof(int*) );
  for(int i238 = 0; i238 < 10; i238++) {
    aux237[i238] = malloc( 8 * sizeof(int) );
  }
  for(int i232 = 0; i232 < 10; i232++) {
    for(int i233 = 0; i233 < 8; i233++) {
      aux237[i232][i233] = t56009[i232][i233];
    }
  }
  int* E235 = aux237[L234];
  E235[L236] = 0;
  int** a = aux237;
  for(int i239 = 0; i239 < 10; i239++) {
    for(int i240 = 0; i240 < 8; i240++) {
      result[i239][i240] = a[i239][i240];
    }
  }
  free(aux237);
}

void pvs_test241(mpz_t* result, mpz_t* t56009) {
  int L250;
  L250 = 0;
  for(int i249 = 0; i249 < 10; i249++) {
    mpz_set(result[i249], t56009[i249]);
  }
  mpz_t conv251;
  mpz_init(conv251);
  mpz_set_si(conv251, (long) 8);
  mpz_add_ui(result[L250], conv251, (unsigned long) 1);
  mpz_clear(conv251);
}

void pvs_d_test242(mpz_t* result, mpz_t* t56009) {
  int L250;
  L250 = 0;
  for(int i249 = 0; i249 < 10; i249++) {
    mpz_set(result[i249], t56009[i249]);
  }
  mpz_t conv251;
  mpz_init(conv251);
  mpz_set_si(conv251, (long) 8);
  mpz_add_ui(result[L250], conv251, (unsigned long) 1);
  mpz_clear(conv251);
}

void pvs_set0252(mpz_t** result, mpz_t** t56009, int x, int y) {
  int L266;
  L266 = x;
  for(int i264 = 0; i264 < 10; i264++) {
    for(int i265 = 0; i265 < 10; i265++) {
      mpz_set(result[i264][i265], t56009[i264][i265]);
    }
  }
  int L268;
  L268 = 0;
  for(int i267 = 0; i267 < 10; i267++) {
    mpz_set(result[L266][i267], t56009[0][i267]);
  }
  mpz_set_si(result[L266][L268], (long) 0);
}

void pvs_d_set0253(mpz_t** result, mpz_t** t56009, int x, int y) {
  int L266;
  L266 = x;
  for(int i264 = 0; i264 < 10; i264++) {
    for(int i265 = 0; i265 < 10; i265++) {
      mpz_set(result[i264][i265], t56009[i264][i265]);
    }
  }
  int L268;
  L268 = 0;
  for(int i267 = 0; i267 < 10; i267++) {
    mpz_set(result[L266][i267], t56009[0][i267]);
  }
  mpz_set_si(result[L266][L268], (long) 0);
}