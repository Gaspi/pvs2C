
gcc -c -O -fomit-frame-pointer gmp.c
cp gmp.o "Clean System Files"/gmp.o
clm -ABC _SystemBigInt
clm -PABC BigInt
clm -PABC Rational
clm -PABC Complex
sleep 1
clm -PO BigInt
clm -PO Rational
clm -PO Complex
