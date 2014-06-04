// ---------- PVS definitions  -------------

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include "PVS.h"


// -------- BigInt --------

BigInt pvsInt(char* s) {
  BigInt res;
  mpz_init_set_str( res, s, 10 );
  return res;
}

BigInt pvsAdd(BigInt a, BigInt b) {
  BigInt res;
  mpz_init( res );
  mpz_add( res, a, b );
  return res;
}

BigInt pvsSub(BigInt a, BigInt b) {
  BigInt res;
  mpz_init( res );
  mpz_sub( res, a, b );
  return res;
}

BigInt pvsNeg(BigInt a) {
  BigInt res;
  mpz_init( res );
  mpz_neg( res, a );
  return res;
}

BigInt pvsTimes(BigInt a, BigInt b) {
  BigInt res;
  mpz_init( res ); // Useless ?
  mpz_mul( res, a, b );
  return res;
}


// Debug function
void printBigInt(BigInt a) {
  printf( mpz_get_str(NULL,10, a) );
}



/*

// -------- Closures --------

typedef BigInt int_void(void*);

struct BigIntClosure {
  void* args;
  int_void body;
};

BigIntClosure mk_int_lambda( int_void f , void* args ) {
  struct BigIntClosure res;
  res.args = args;
  res.body = f;
  return res;
}

void passArg(BigIntClosure l, int i , void* arg) {
  l.args[i] = arg;
}

BigInt eval(BigIntClosure l) {
  return l.body( l.args );
}




//*/

/*
// This main should only be used for debug
int main(void) {
  printBigInt( pvsAdd( pvsInt("2"), pvsInt("3")) );
  
  
  printf("Prelude should not be executed...");
  return 0;
}




/*
TODO :

Destructive update for pvsAdd, pvsSubb, ...
if the number of reference on paramtere object is zero


Closures

GC

//*/






