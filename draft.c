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
  printf("Executing draft ...\n");
  return 0;
}

struct struct_pair1138 {
  mpz_t y;
  int x;
};
typedef (struct struct_pair1138)* pair1138;


pair1138 pvs_a1136() {
  pair1138 result;
  result = GC_malloc(1, sizeof( struct_pair1138 ) );
  mpz_init(result->y);
  result->x = 2;
  mpz_set_si(result->y, (long) 12);
  return *result*;
}

pair1138 pvs_a_d1137() {
  pair1138 result;
  result = GC_malloc(1, sizeof( struct_pair1138 ) );
  mpz_init(result->y);
  result->x = 2;
  mpz_set_si(result->y, (long) 12);
  return *result*;
}

int pvs_first1139(pair1138 a) {
  return *a*->x;
}

int pvs_first_d1140(!pair1138 a) {
  return *a*->x;
}

pair1138 pvs_zero1141(pair1138 a) {
  pair1138 result;
  int res1143;
  res1143 = 0;
  result = GC_malloc(1, sizeof( struct_pair1138 ) );
  mpz_init(result->y);
  mpz_set(result->y, *a*->y);
  result->x = *a*->x;
  result->x = res1143;
  return *result*;
}

pair1138 pvs_zero_d1142(!pair1138 a) {
  int res1144;
  res1144 = 0;
  a->x = res1144;
  return *a*;
}

unsigned long int pvs_a1145() {
  unsigned long int result;
  result = (unsigned long) 2;
  return result;
}

unsigned long int pvs_a_d1146() {
  unsigned long int result;
  result = (unsigned long) 2;
  return result;
}

int pvs_b1147() {
  int result;
  result = (3 + 1);
  return result;
}

int pvs_b_d1148() {
  int result;
  result = (3 + 1);
  return result;
}

void pvs_c1149() {
  mpz_set_si(result, (long) (3 * (1 + 2)));
}

void pvs_c_d1150() {
  mpz_set_si(result, (long) (3 * (1 + 2)));
}

int pvs_incr1151(int x) {
  int result;
  result = (x + 1);
  return result;
}

int pvs_incr_d1152(int x) {
  int result;
  result = (x + 1);
  return result;
}

int pvs_zero1153(mpz_t x) {
  int result;
  result = 0;
  return result;
}

int pvs_zero_d1154(mpz_t x) {
  int result;
  result = 0;
  return result;
}

int pvs_f1155(int a, int b) {
  mpz_t conv1157;
  mpz_set_si(conv1157, (long) b);
  int result;
  result = (int) (pvs_zero1153(conv1157) * pvs_incr1151(a));
  mpz_clear(conv1157);
  return result;
}

int pvs_f_d1156(int a, int b) {
  mpz_t conv1158;
  mpz_set_si(conv1158, (long) b);
  int result;
  result = (int) (pvs_zero1153(conv1158) * pvs_incr1151(a));
  mpz_clear(conv1158);
  return result;
}

int pvs_f1159(int x) {
  int if1163;
  if (((x <= 1) && 1)) {
    int if1161;
    if (((x == 0) || (x < 0))) {
      if1161 = 0;
    } else {
      if1161 = x;
    }
    if1163 = if1161;
  } else {
    int if1162;
    if ((x > 10)) {
      if1162 = 10;
    } else {
      if1162 = (x - 5);
    }
    if1163 = if1162;
  }
  int result;
  result = if1163;
  return result;
}

int pvs_f_d1160(int x) {
  int if1166;
  if (((x <= 1) && 1)) {
    int if1164;
    if (((x == 0) || (x < 0))) {
      if1164 = 0;
    } else {
      if1164 = x;
    }
    if1166 = if1164;
  } else {
    int if1165;
    if ((x > 10)) {
      if1165 = 10;
    } else {
      if1165 = (x - 5);
    }
    if1166 = if1165;
  }
  int result;
  result = if1166;
  return result;
}

int pvs_t1167(int x) {
  int result;
  result = x;
  return result;
}

int pvs_t_d1168(int x) {
  int result;
  result = x;
  return result;
}

int* pvs_id21169(int* t56344) {
  return *t56344*;
}

int* pvs_id2_d1170(!int* t56344) {
  return *t56344*;
}

int* pvs_f1171(int x) {
  int* result;
  result = GC_malloc(1000, sizeof(int) );
  int i1173;
  for(i1173 = 0; i1173 < 1000; i1173++) {
    result[i1173] = pvs_t1167(i1173);
  }
  return *result*;
}

int* pvs_f_d1172(int x) {
  int* result;
  result = GC_malloc(1000, sizeof(int) );
  int i1174;
  for(i1174 = 0; i1174 < 1000; i1174++) {
    result[i1174] = pvs_t1167(i1174);
  }
  return *result*;
}

int* pvs_update1175(int* x) {
  int* result;
  int L1177;
  L1177 = 0;
  int res1178;
  res1178 = 0;
  result = GC_malloc(1000, sizeof(int) );
  int i1211;
  for(i1211 = 0; i1211 < 1000; i1211++) {
    result[i1211] = *x*[i1211];
  }
  result[L1177] = res1178;
  return *result*;
}

int* pvs_update_d1176(!int* x) {
  int L1179;
  L1179 = 0;
  int res1180;
  res1180 = 0;
  x[L1179] = res1180;
  return *x*;
}

int* pvs_t21181(int x) {
  mpq_t* set1184;
  set1184 = GC_malloc(1000, sizeof(mpq_t) );
  int i1183;
  for(i1183 = 0; i1183 < 1000; i1183++) {
    mpq_init(set1184[i1183]);
    mpq_set_d(set1184[i1183], (double) (x + i1183) );
    mpq_canonicalize(set1184[i1183]);
  }
  int* result;
  result = (int*) GC( set1184 );
  if( GC_count( *set1184* ) == 1 ) {
    int i1212;
    for(i1212 = 0; i1212 < 1000; i1212++) {
      mpq_clear(*set1184*[i1212]);
    }
  }
  GC_free(*set1184*);
  return *result*;
}

int* pvs_t2_d1182(int x) {
  mpq_t* set1186;
  set1186 = GC_malloc(1000, sizeof(mpq_t) );
  int i1185;
  for(i1185 = 0; i1185 < 1000; i1185++) {
    mpq_init(set1186[i1185]);
    mpq_set_d(set1186[i1185], (double) (x + i1185) );
    mpq_canonicalize(set1186[i1185]);
  }
  int* result;
  result = (int*) GC( set1186 );
  if( GC_count( *set1186* ) == 1 ) {
    int i1213;
    for(i1213 = 0; i1213 < 1000; i1213++) {
      mpq_clear(*set1186*[i1213]);
    }
  }
  GC_free(*set1186*);
  return *result*;
}

int* pvs_id1187(int** t56344) {
  int* result;
  result = (int*) GC( t56344[0] );
  if( GC_count( *t56344* ) == 1 ) {
    int i1214;
    for(i1214 = 0; i1214 < 1000; i1214++) {
      GC_free(*t56344*[i1214]);
    }
  }
  GC_free(*t56344*);
  return *result*;
}

int* pvs_id_d1188(!int** t56344) {
  int* result;
  result = (int*) GC( t56344[0] );
  if( GC_count( *t56344* ) == 1 ) {
    int i1216;
    for(i1216 = 0; i1216 < 1000; i1216++) {
      GC_free(*t56344*[i1216]);
    }
  }
  GC_free(*t56344*);
  return *result*;
}

int* pvs_te1189() {
  int* aux1192;
  aux1192 = GC_malloc(1000, sizeof(int) );
  int i1191;
  for(i1191 = 0; i1191 < 1000; i1191++) {
    aux1192[i1191] = pvs_t1167(i1191);
  }
  int* result;
  result = (int*) GC( pvs_update1175(pvs_update1175(aux1192)) );
  GC_free(*aux1192*);
  return *result*;
}

int* pvs_te_d1190() {
  int* aux1194;
  aux1194 = GC_malloc(1000, sizeof(int) );
  int i1193;
  for(i1193 = 0; i1193 < 1000; i1193++) {
    aux1194[i1193] = pvs_t1167(i1193);
  }
  int* result;
  result = (int*) GC( pvs_update1175(pvs_update1175(aux1194)) );
  GC_free(*aux1194*);
  return *result*;
}

int** pvs_update1195(int** x) {
  int** result;
  int L1199;
  L1199 = 1;
  int res1200;
  res1200 = 0;
  int L1197;
  L1197 = 0;
  int L1201;
  L1201 = 1;
  int* res1202;
  res1202 = GC_malloc(1000, sizeof(int) );
  int i1203;
  for(i1203 = 0; i1203 < 1000; i1203++) {
    res1202[i1203] = i1203;
  }
  result = GC_malloc(1000, sizeof(int*) );
  int i1220;
  for(i1220 = 0; i1220 < 1000; i1220++) {
    result[i1220] = GC_malloc(1000, sizeof(int) );
    int i1221;
    for(i1221 = 0; i1221 < 1000; i1221++) {
      result[i1220][i1221] = *x*[i1220][i1221];
    }
  }
  int* E1198;
  E1198 = GC_malloc(1000, sizeof(int) );
  int i1222;
  for(i1222 = 0; i1222 < 1000; i1222++) {
    E1198[i1222] = result[L1197][i1222];
  }
  E1198[L1199] = res1200;
  result[L1197] = (int*) GC( *E1198* );
  result[L1201] = (int*) GC( res1202 );
  GC_free(*res1202*);
  return *result*;
}

int** pvs_update_d1196(!int** x) {
  int L1206;
  L1206 = 1;
  int res1207;
  res1207 = 0;
  int L1204;
  L1204 = 0;
  int L1208;
  L1208 = 1;
  int* res1209;
  res1209 = GC_malloc(1000, sizeof(int) );
  int i1210;
  for(i1210 = 0; i1210 < 1000; i1210++) {
    res1209[i1210] = i1210;
  }
  int* E1205;
  E1205 = GC_malloc(1000, sizeof(int) );
  int i1224;
  for(i1224 = 0; i1224 < 1000; i1224++) {
    E1205[i1224] = x[L1204][i1224];
  }
  E1205[L1206] = res1207;
  x[L1204] = (int*) GC( *E1205* );
  x[L1208] = (int*) GC( res1209 );
  GC_free(*res1209*);
  return *x*;
}