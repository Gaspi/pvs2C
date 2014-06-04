/*
PVS definitions
*/
#ifndef PVS_H
#define PVS_H

#include<stdio.h>
#include<stdlib.h>
#include <gmp.h>

// -------- BigInt --------

// typedef __mpz_struct BigInt;
typedef __mpz_struct* BigInt;

BigInt pvsInt(char* s);
BigInt pvsAdd(BigInt a, BigInt b);
BigInt pvsSub(BigInt a, BigInt b);
BigInt pvsNeg(BigInt a);
BigInt pvsTimes(BigInt a, BigInt b);



// ------------ Debug functions ------------
void printBigInt(BigInt a);

#endif


/*


//*/













