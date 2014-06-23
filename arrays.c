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


void pvs_b2157(mpz_t result, int x) {
  mpz_set_si(result, (long) x);
}

void pvs_d_b2158(mpz_t result, int x) {
  mpz_set_si(result, (long) x);
}

mpz_t* pvs_getb2159(int a) {
  mpz_t* result;
  result = malloc( 10 * sizeof(mpz_t) );
  for(int i2164 = 0; i2164 < 10; i2164++) {
    mpz_init(result[i2164]);
  }
  for(int i2163 = 0; i2163 < 10;;; i2163++) {
    pvs_d_b2158(result[i2163], i2163);
  }
  return result;
}

mpz_t* pvs_d_getb2160(int a) {
  mpz_t* result;
  result = malloc( 10 * sizeof(mpz_t) );
  for(int i2164 = 0; i2164 < 10; i2164++) {
    mpz_init(result[i2164]);
  }
  for(int i2163 = 0; i2163 < 10;;; i2163++) {
    pvs_d_b2158(result[i2163], i2163);
  }
  return result;
}

mpz_t* pvs_id2165(mpz_t* t56181) {
  mpz_t* result;
  result = malloc( 10 * sizeof(mpz_t) );
  for(int i2170 = 0; i2170 < 10; i2170++) {
    mpz_init(result[i2170]);
  }
  for(int i2169 = 0; i2169 < 10; i2169++) {
    mpz_set(result[i2169], t56181[i2169]);
  }
  return result;
}

mpz_t* pvs_d_id2166(mpz_t* t56181) {
  mpz_t* result;
  result = malloc( 10 * sizeof(mpz_t) );
  for(int i2170 = 0; i2170 < 10; i2170++) {
    mpz_init(result[i2170]);
  }
  for(int i2169 = 0; i2169 < 10; i2169++) {
    mpz_set(result[i2169], t56181[i2169]);
  }
  return result;
}

mpz_t* pvs_id22171(mpz_t* t56181) {
  mpz_t* result;
  result = malloc( 10 * sizeof(mpz_t) );
  for(int i2176 = 0; i2176 < 10; i2176++) {
    mpz_init(result[i2176]);
  }
  for(int i2175 = 0; i2175 < 10; i2175++) {
    mpz_set(result[i2175], pvs_d_id2166(pvs_d_id2166(t56181))[i2175]);
  }
  return result;
}

mpz_t* pvs_d_id22172(mpz_t* t56181) {
  mpz_t* result;
  result = malloc( 10 * sizeof(mpz_t) );
  for(int i2176 = 0; i2176 < 10; i2176++) {
    mpz_init(result[i2176]);
  }
  for(int i2175 = 0; i2175 < 10; i2175++) {
    mpz_set(result[i2175], pvs_d_id2166(pvs_d_id2166(t56181))[i2175]);
  }
  return result;
}

mpz_t* pvs_incr2177(mpz_t* t56181) {
  mpz_t* result;
  result = malloc( 10 * sizeof(mpz_t) );
  for(int i2187 = 0; i2187 < 10; i2187++) {
    mpz_init(result[i2187]);
  }
  L2186 = ( (int) mpz_get_si(t56181[0]) );
  for(int i2185 = 0; i2185 < 10; i2185++) {
    mpz_set(result[i2185], t56181[i2185]);
  }
  mpz_set(result[L2186], t56181[9]);
  return result;
}

mpz_t* pvs_d_incr2178(mpz_t* t56181) {
  mpz_t* result;
  result = malloc( 10 * sizeof(mpz_t) );
  for(int i2187 = 0; i2187 < 10; i2187++) {
    mpz_init(result[i2187]);
  }
  L2186 = ( (int) mpz_get_si(t56181[0]) );
  for(int i2185 = 0; i2185 < 10; i2185++) {
    mpz_set(result[i2185], t56181[i2185]);
  }
  mpz_set(result[L2186], t56181[9]);
  return result;
}

mpz_t* pvs_decr2188(mpz_t* t56181) {
  mpz_t* result;
  result = malloc( 10 * sizeof(mpz_t) );
  for(int i2195 = 0; i2195 < 10; i2195++) {
    mpz_init(result[i2195]);
  }
  L2194 = 0;
  for(int i2193 = 0; i2193 < 10;;; i2193++) {
    pvs_d_b2158(result[i2193], i2193);
  }
  mpz_set_si(result[L2194], (long) 1);
  return result;
}

mpz_t* pvs_d_decr2189(mpz_t* t56181) {
  mpz_t* result;
  result = malloc( 10 * sizeof(mpz_t) );
  for(int i2195 = 0; i2195 < 10; i2195++) {
    mpz_init(result[i2195]);
  }
  L2194 = 0;
  for(int i2193 = 0; i2193 < 10;;; i2193++) {
    pvs_d_b2158(result[i2193], i2193);
  }
  mpz_set_si(result[L2194], (long) 1);
  return result;
}

mpz_t* pvs_sum2196(mpz_t* T, mpz_t* U) {
  mpz_t* result;
  result = malloc( 10 * sizeof(mpz_t) );
  for(int i2201 = 0; i2201 < 10; i2201++) {
    mpz_init(result[i2201]);
  }
  for(int i2200 = 0; i2200 < 10;;; i2200++) {
    mpz_add(result[i2200], T[i2200], U[i2200]);
  }
  return result;
}

mpz_t* pvs_d_sum2197(mpz_t* T, mpz_t* U) {
  mpz_t* result;
  result = malloc( 10 * sizeof(mpz_t) );
  for(int i2201 = 0; i2201 < 10; i2201++) {
    mpz_init(result[i2201]);
  }
  for(int i2200 = 0; i2200 < 10;;; i2200++) {
    mpz_add(result[i2200], T[i2200], U[i2200]);
  }
  return result;
}

mpz_t* pvs_foo2202(mpz_t* t56181) {
  mpz_t* result;
  result = malloc( 10 * sizeof(mpz_t) );
  for(int i2215 = 0; i2215 < 10; i2215++) {
    mpz_init(result[i2215]);
  }
  L2213 = 0;
  L2214 = ( (int) mpz_get_si(t56181[0]) );
  for(int i2212 = 0; i2212 < 10; i2212++) {
    mpz_set(result[i2212], t56181[i2212]);
  }
  mpz_add_ui(result[L2213], t56181[9], (unsigned long) 1);
  mpz_add_ui(result[L2214], t56181[0], (unsigned long) 1);
  return result;
}

mpz_t* pvs_d_foo2203(mpz_t* t56181) {
  mpz_t* result;
  result = malloc( 10 * sizeof(mpz_t) );
  for(int i2215 = 0; i2215 < 10; i2215++) {
    mpz_init(result[i2215]);
  }
  L2213 = 0;
  L2214 = ( (int) mpz_get_si(t56181[0]) );
  for(int i2212 = 0; i2212 < 10; i2212++) {
    mpz_set(result[i2212], t56181[i2212]);
  }
  mpz_add_ui(result[L2213], t56181[9], (unsigned long) 1);
  mpz_add_ui(result[L2214], t56181[0], (unsigned long) 1);
  return result;
}

int** pvs_bar2216(int** t56181) {
  int** result;
  result = malloc( 10 * sizeof(int*) );
  for(int i2247 = 0; i2247 < 10; i2247++) {
    result[i2247] = malloc( 8 * sizeof(int) );
  }
  L2240 = 0;
  L2242 = 0;
  int** aux2243;
  aux2243 = malloc( 10 * sizeof(int*) );
  for(int i2244 = 0; i2244 < 10; i2244++) {
    aux2243[i2244] = malloc( 8 * sizeof(int) );
  }
  for(int i2238 = 0; i2238 < 10; i2238++) {
    for(int i2239 = 0; i2239 < 8; i2239++) {
      aux2243[i2238][i2239] = t56181[i2238][i2239];
    }
  }
  int* E2241 = aux2243[L2240];
  E2241[L2242] = 0;
  int** a = aux2243;
  for(int i2245 = 0; i2245 < 10; i2245++) {
    for(int i2246 = 0; i2246 < 8; i2246++) {
      result[i2245][i2246] = a[i2245][i2246];
    }
  }
  free(aux2243);
  return result;
}

int** pvs_d_bar2217(int** t56181) {
  int** result;
  result = malloc( 10 * sizeof(int*) );
  for(int i2247 = 0; i2247 < 10; i2247++) {
    result[i2247] = malloc( 8 * sizeof(int) );
  }
  L2240 = 0;
  L2242 = 0;
  int** aux2243;
  aux2243 = malloc( 10 * sizeof(int*) );
  for(int i2244 = 0; i2244 < 10; i2244++) {
    aux2243[i2244] = malloc( 8 * sizeof(int) );
  }
  for(int i2238 = 0; i2238 < 10; i2238++) {
    for(int i2239 = 0; i2239 < 8; i2239++) {
      aux2243[i2238][i2239] = t56181[i2238][i2239];
    }
  }
  int* E2241 = aux2243[L2240];
  E2241[L2242] = 0;
  int** a = aux2243;
  for(int i2245 = 0; i2245 < 10; i2245++) {
    for(int i2246 = 0; i2246 < 8; i2246++) {
      result[i2245][i2246] = a[i2245][i2246];
    }
  }
  free(aux2243);
  return result;
}

mpz_t* pvs_test2248(mpz_t* t56181) {
  mpz_t* result;
  result = malloc( 10 * sizeof(mpz_t) );
  for(int i2261 = 0; i2261 < 10; i2261++) {
    mpz_init(result[i2261]);
  }
  L2259 = 0;
  for(int i2258 = 0; i2258 < 10; i2258++) {
    mpz_set(result[i2258], t56181[i2258]);
  }
  mpz_t conv2260;
  mpz_init(conv2260);
  mpz_set_si(conv2260, (long) 8);
  mpz_add_ui(result[L2259], conv2260, (unsigned long) 1);
  mpz_clear(conv2260);
  return result;
}

mpz_t* pvs_d_test2249(mpz_t* t56181) {
  mpz_t* result;
  result = malloc( 10 * sizeof(mpz_t) );
  for(int i2261 = 0; i2261 < 10; i2261++) {
    mpz_init(result[i2261]);
  }
  L2259 = 0;
  for(int i2258 = 0; i2258 < 10; i2258++) {
    mpz_set(result[i2258], t56181[i2258]);
  }
  mpz_t conv2260;
  mpz_init(conv2260);
  mpz_set_si(conv2260, (long) 8);
  mpz_add_ui(result[L2259], conv2260, (unsigned long) 1);
  mpz_clear(conv2260);
  return result;
}

mpz_t** pvs_set02262(mpz_t** t56181, int x, int y) {
  mpz_t** result;
  result = malloc( 10 * sizeof(mpz_t*) );
  for(int i2283 = 0; i2283 < 10; i2283++) {
    result[i2283] = malloc( 10 * sizeof(mpz_t) );
    for(int i2284 = 0; i2284 < 10; i2284++) {
      mpz_init(result[i2283][i2284]);
    }
  }
  L2280 = x;
  for(int i2278 = 0; i2278 < 10; i2278++) {
    for(int i2279 = 0; i2279 < 10; i2279++) {
      mpz_set(result[i2278][i2279], t56181[i2278][i2279]);
    }
  }
  L2282 = 0;
  for(int i2281 = 0; i2281 < 10; i2281++) {
    mpz_set(result[L2280][i2281], t56181[0][i2281]);
  }
  mpz_set_si(result[L2280][L2282], (long) 0);
  return result;
}

mpz_t** pvs_d_set02263(mpz_t** t56181, int x, int y) {
  mpz_t** result;
  result = malloc( 10 * sizeof(mpz_t*) );
  for(int i2283 = 0; i2283 < 10; i2283++) {
    result[i2283] = malloc( 10 * sizeof(mpz_t) );
    for(int i2284 = 0; i2284 < 10; i2284++) {
      mpz_init(result[i2283][i2284]);
    }
  }
  L2280 = x;
  for(int i2278 = 0; i2278 < 10; i2278++) {
    for(int i2279 = 0; i2279 < 10; i2279++) {
      mpz_set(result[i2278][i2279], t56181[i2278][i2279]);
    }
  }
  L2282 = 0;
  for(int i2281 = 0; i2281 < 10; i2281++) {
    mpz_set(result[L2280][i2281], t56181[0][i2281]);
  }
  mpz_set_si(result[L2280][L2282], (long) 0);
  return result;
}