
#include<stdio.h>

typedef int (*intvoid)(void*);

struct int_lambda {
  void* args;
  int (*body)(void*);
};





int main() {
  printf("Hello world!\n");
}
