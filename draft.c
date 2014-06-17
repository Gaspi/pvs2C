
#include<stdio.h>
#include<gmp.h>


int eval0( int (*a)(int) ) {
  return (*a)(12);
}

int arg(int x) {
  return x;
}

int main(void) {
  void* test[1];
  mpz_t aux;
  mpz_init( aux );
  mpz_set_d( aux , 3);
  test[0] = aux;

  mpz_t test2;
  mpz_init(test2);
  mpz_set(test2, test[0]);

  printf("Res = %d\nTest = %d\n", eval0(&arg),(int) mpz_get_d(test2) );
  return 0;
}



