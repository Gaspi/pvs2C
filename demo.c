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

int pvs_a75() {
  int result;
  result = 8;
  return result;
}

int pvs_d_a76() {
  int result;
  result = 8;
  return result;
}

int pvs_b77(int x) {
  int result;
  result = x;
  return result;
}

int pvs_d_b78(int x) {
  int result;
  result = x;
  return result;
}

void pvs_incr79(int* result, int* t55888) {
  int L92 = pvsSelect(t55888, 0);;
  int R90;
  R90 = pvsSelect(t55888, 9);;
  int* N91 = pvsDestructiveUpdate(E89, L92, R90);
  int* E89;
  E89 = malloc( sizeof(int*) );
  copy_int*(E89, t55888);
  free(E89);
  copy_int*(result, N91);
}

void pvs_d_incr80(int* result, int* t55888) {
  int L92 = pvsSelect(t55888, 0);;
  int R90;
  R90 = pvsSelect(t55888, 9);;
  int* N91 = pvsDestructiveUpdate(E89, L92, R90);
  int* E89;
  E89 = malloc( sizeof(int*) );
  copy_int*(E89, t55888);
  free(E89);
  copy_int*(result, N91);
}