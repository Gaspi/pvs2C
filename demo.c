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

int pvs_a1086() {
  int result;
  result = 8;
  return result;
}

int pvs_d_a1087() {
  int result;
  result = 8;
  return result;
}

unsigned long int pvs_exp21088(int n) {
  unsigned long int result;
  unsigned long int if1101;
  if((n == 0)) {
    if1101 = (unsigned long) 1;
  } else {
    mpz_t conv1096;
    mpz_init(conv1096);
    mpz_set_si(conv1096, (long) 2);
    mpz_t conv1097;
    mpz_init(conv1097);
    mpz_set_si(conv1097, (long) 1);
    mpz_t aux1098;
    mpz_init(aux1098);
    mpz_ui_sub(aux1098, (unsigned long) n, conv1097);
    mpz_clear(conv1097);
    unsigned long int aux1099;
    aux1099 = pvs_d_exp21089(( (int) mpz_get_si(aux1098) ));
    mpz_clear(aux1098);
    mpz_t aux1100;
    mpz_init(aux1100);
    mpz_mul_ui(aux1100, conv1096, aux1099);
    mpz_clear(conv1096);
    if1101 = mpz_get_ui(aux1100);
    mpz_clear(aux1100);
  }
  result = if1101;
  return result;
}

unsigned long int pvs_d_exp21089(int n) {
  unsigned long int result;
  unsigned long int if1101;
  if((n == 0)) {
    if1101 = (unsigned long) 1;
  } else {
    mpz_t conv1096;
    mpz_init(conv1096);
    mpz_set_si(conv1096, (long) 2);
    mpz_t conv1097;
    mpz_init(conv1097);
    mpz_set_si(conv1097, (long) 1);
    mpz_t aux1098;
    mpz_init(aux1098);
    mpz_ui_sub(aux1098, (unsigned long) n, conv1097);
    mpz_clear(conv1097);
    unsigned long int aux1099;
    aux1099 = pvs_d_exp21089(( (int) mpz_get_si(aux1098) ));
    mpz_clear(aux1098);
    mpz_t aux1100;
    mpz_init(aux1100);
    mpz_mul_ui(aux1100, conv1096, aux1099);
    mpz_clear(conv1096);
    if1101 = mpz_get_ui(aux1100);
    mpz_clear(aux1100);
  }
  result = if1101;
  return result;
}

int pvs_decr1102(int n) {
  int result;
  int if1109;
  if((n == 0)) {
    if1109 = 0;
  } else {
    mpz_t conv1107;
    mpz_init(conv1107);
    mpz_set_si(conv1107, (long) 1);
    mpz_t aux1108;
    mpz_init(aux1108);
    mpz_ui_sub(aux1108, (unsigned long) n, conv1107);
    mpz_clear(conv1107);
    if1109 = ( (int) mpz_get_si(aux1108) );
    mpz_clear(aux1108);
  }
  result = if1109;
  return result;
}

int pvs_d_decr1103(int n) {
  int result;
  int if1109;
  if((n == 0)) {
    if1109 = 0;
  } else {
    mpz_t conv1107;
    mpz_init(conv1107);
    mpz_set_si(conv1107, (long) 1);
    mpz_t aux1108;
    mpz_init(aux1108);
    mpz_ui_sub(aux1108, (unsigned long) n, conv1107);
    mpz_clear(conv1107);
    if1109 = ( (int) mpz_get_si(aux1108) );
    mpz_clear(aux1108);
  }
  result = if1109;
  return result;
}

unsigned long int pvs_double1110(unsigned long int n) {
  unsigned long int result;
  mpz_t conv1114;
  mpz_init(conv1114);
  mpz_set_si(conv1114, (long) 2);
  mpz_t aux1115;
  mpz_init(aux1115);
  mpz_mul_ui(aux1115, conv1114, n);
  mpz_clear(conv1114);
  result = mpz_get_ui(aux1115);
  mpz_clear(aux1115);
  return result;
}

unsigned long int pvs_d_double1111(unsigned long int n) {
  unsigned long int result;
  mpz_t conv1114;
  mpz_init(conv1114);
  mpz_set_si(conv1114, (long) 2);
  mpz_t aux1115;
  mpz_init(aux1115);
  mpz_mul_ui(aux1115, conv1114, n);
  mpz_clear(conv1114);
  result = mpz_get_ui(aux1115);
  mpz_clear(aux1115);
  return result;
}

unsigned long int pvs_fast_exp21116(int n) {
  unsigned long int result;
  unsigned long int if1119;
  if((n == 0)) {
    if1119 = (unsigned long) 1;
  } else {
    if1119 = pvs_d_double1111(pvs_d_fast_exp21117(pvs_d_decr1103(n)));
  }
  result = if1119;
  return result;
}

unsigned long int pvs_d_fast_exp21117(int n) {
  unsigned long int result;
  unsigned long int if1119;
  if((n == 0)) {
    if1119 = (unsigned long) 1;
  } else {
    if1119 = pvs_d_double1111(pvs_d_fast_exp21117(pvs_d_decr1103(n)));
  }
  result = if1119;
  return result;
}

void pvs_factorial1120(mpz_t result, mpz_t n) {
  mpz_t conv1127;
  mpz_init(conv1127);
  mpz_set_si(conv1127, (long) 0);
  int aux1128;
  aux1128 = (mpz_cmp(n, conv1127) > 0);
  mpz_clear(conv1127);
  if(aux1128) {
    mpz_t conv1129;
    mpz_init(conv1129);
    mpz_set_si(conv1129, (long) 1);
    mpz_t aux1130;
    mpz_init(aux1130);
    mpz_sub(aux1130, n, conv1129);
    mpz_clear(conv1129);
    mpz_t aux1131;
    mpz_init(aux1131);
    pvs_d_factorial1121(aux1131, aux1130);
    mpz_clear(aux1130);
    mpz_mul(result, n, aux1131);
    mpz_clear(aux1131);
  } else {
    mpz_set_si(result, (long) 1);
  }
}

void pvs_d_factorial1121(mpz_t result, mpz_t n) {
  mpz_t conv1127;
  mpz_init(conv1127);
  mpz_set_si(conv1127, (long) 0);
  int aux1128;
  aux1128 = (mpz_cmp(n, conv1127) > 0);
  mpz_clear(conv1127);
  if(aux1128) {
    mpz_t conv1129;
    mpz_init(conv1129);
    mpz_set_si(conv1129, (long) 1);
    mpz_t aux1130;
    mpz_init(aux1130);
    mpz_sub(aux1130, n, conv1129);
    mpz_clear(conv1129);
    mpz_t aux1131;
    mpz_init(aux1131);
    pvs_d_factorial1121(aux1131, aux1130);
    mpz_clear(aux1130);
    mpz_mul(result, n, aux1131);
    mpz_clear(aux1131);
  } else {
    mpz_set_si(result, (long) 1);
  }
}

void pvs_binomial1132(mpz_t result, mpz_t a, mpz_t b) {
  mpz_t conv1146;
  mpz_init(conv1146);
  mpz_set_si(conv1146, (long) 0);
  int aux1147;
  aux1147 = (mpz_cmp(b, conv1146) == 0);
  mpz_clear(conv1146);
  if(aux1147) {
    mpz_set_si(result, (long) 1);
  } else {
    mpz_t conv1148;
    mpz_init(conv1148);
    mpz_set_si(conv1148, (long) 0);
    int aux1149;
    aux1149 = (mpz_cmp(a, conv1148) == 0);
    mpz_clear(conv1148);
    if(aux1149) {
      mpz_set_si(result, (long) 0);
    } else {
      mpz_t conv1150;
      mpz_init(conv1150);
      mpz_set_si(conv1150, (long) 1);
      mpz_t aux1151;
      mpz_init(aux1151);
      mpz_sub(aux1151, a, conv1150);
      mpz_clear(conv1150);
      mpz_t conv1152;
      mpz_init(conv1152);
      mpz_set_si(conv1152, (long) 1);
      mpz_t aux1153;
      mpz_init(aux1153);
      mpz_sub(aux1153, b, conv1152);
      mpz_clear(conv1152);
      mpz_t aux1154;
      mpz_init(aux1154);
      pvs_d_binomial1133(aux1154, aux1151, aux1153);
      mpz_clear(aux1153);
      mpz_clear(aux1151);
      mpz_t conv1155;
      mpz_init(conv1155);
      mpz_set_si(conv1155, (long) 1);
      mpz_t aux1156;
      mpz_init(aux1156);
      mpz_sub(aux1156, a, conv1155);
      mpz_clear(conv1155);
      mpz_t aux1157;
      mpz_init(aux1157);
      pvs_d_binomial1133(aux1157, aux1156, b);
      mpz_clear(aux1156);
      mpz_add(result, aux1154, aux1157);
      mpz_clear(aux1157);
      mpz_clear(aux1154);
    }
  }
}

void pvs_d_binomial1133(mpz_t result, mpz_t a, mpz_t b) {
  mpz_t conv1146;
  mpz_init(conv1146);
  mpz_set_si(conv1146, (long) 0);
  int aux1147;
  aux1147 = (mpz_cmp(b, conv1146) == 0);
  mpz_clear(conv1146);
  if(aux1147) {
    mpz_set_si(result, (long) 1);
  } else {
    mpz_t conv1148;
    mpz_init(conv1148);
    mpz_set_si(conv1148, (long) 0);
    int aux1149;
    aux1149 = (mpz_cmp(a, conv1148) == 0);
    mpz_clear(conv1148);
    if(aux1149) {
      mpz_set_si(result, (long) 0);
    } else {
      mpz_t conv1150;
      mpz_init(conv1150);
      mpz_set_si(conv1150, (long) 1);
      mpz_t aux1151;
      mpz_init(aux1151);
      mpz_sub(aux1151, a, conv1150);
      mpz_clear(conv1150);
      mpz_t conv1152;
      mpz_init(conv1152);
      mpz_set_si(conv1152, (long) 1);
      mpz_t aux1153;
      mpz_init(aux1153);
      mpz_sub(aux1153, b, conv1152);
      mpz_clear(conv1152);
      mpz_t aux1154;
      mpz_init(aux1154);
      pvs_d_binomial1133(aux1154, aux1151, aux1153);
      mpz_clear(aux1153);
      mpz_clear(aux1151);
      mpz_t conv1155;
      mpz_init(conv1155);
      mpz_set_si(conv1155, (long) 1);
      mpz_t aux1156;
      mpz_init(aux1156);
      mpz_sub(aux1156, a, conv1155);
      mpz_clear(conv1155);
      mpz_t aux1157;
      mpz_init(aux1157);
      pvs_d_binomial1133(aux1157, aux1156, b);
      mpz_clear(aux1156);
      mpz_add(result, aux1154, aux1157);
      mpz_clear(aux1157);
      mpz_clear(aux1154);
    }
  }
}