/*
C file generated from demo.pvs
Make sure to link GMP and PVS.c in compilation:
    gcc -o demo demo.c -lgmp
    ./demo
*/

#include<stdio.h>
#include<gmp.h>
#include "demo.h"

#define TRUE 1
#define FALSE 0

int main(void) {
  printf("Executing demo ...\n");
  return 0;
}

int pvs_a607() {
  int result;
  result = 8;
  return result;
}

int pvs_d_a608() {
  int result;
  result = 8;
  return result;
}

int pvs_b609(int x) {
  int result;
  result = x;
  return result;
}

int pvs_d_b610(int x) {
  int result;
  result = x;
  return result;
}

void pvs_incr611(int* result, int* t56622) {
  int L624 = pvsSelect(t56622, 0);;
  int R622 = pvsSelect(t56622, 9);;
  int* N623 = pvsDestructiveUpdate(E621, L624, R622);
  int* E621;
  E621 = malloc( sizeof(int*) );
  copy_int*(E621, t56622);
  free(E621);
  copy_int*(result, N623);
}

void pvs_d_incr612(int* result, int* t56622) {
  int L624 = pvsSelect(t56622, 0);;
  int R622 = pvsSelect(t56622, 9);;
  int* N623 = pvsDestructiveUpdate(E621, L624, R622);
  int* E621;
  E621 = malloc( sizeof(int*) );
  copy_int*(E621, t56622);
  free(E621);
  copy_int*(result, N623);
}