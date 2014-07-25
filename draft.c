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


!pair854 pvs_a852() {
  !pair854 #result#;
  #result# = GC_malloc(1, sizeof( struct struct_pair854 ) );
  mpz_init(#result#->y);
  #result#->x = *2*;
  mpz_set_si(#result#->y, (long) *12*);
  return *#result#*;
}

!pair854 pvs_a_d853() {
  !pair854 #result#;
  #result# = GC_malloc(1, sizeof( struct struct_pair854 ) );
  mpz_init(#result#->y);
  #result#->x = *2*;
  mpz_set_si(#result#->y, (long) *12*);
  return *#result#*;
}

int pvs_first855(pair854 a) {
  int result;
  result = *a*->x;
  return result;
}

int pvs_first_d856(pair854 a) {
  int result;
  result = *a*->x;
  return result;
}

!pair854 pvs_zero857(pair854 a) {
  !pair854 #result#;
  if ( GC_count( *a* ) == 1 )
    #result# = GC( *a* );
  else {
    #result# = GC_malloc(1, sizeof( struct struct_pair854 ));
    mpz_set(#result#->y, *a*->y);
    #result#->x = *a*->x;
  }
  #result#->x = 0;
  return *#result#*;
}

!pair854 pvs_zero_d858(!pair854 #a#) {
  #a#->x = 0;
  return *#a#*;
}

unsigned long int pvs_a861() {
  unsigned long int result;
  result = (unsigned long) *2*;
  return result;
}

unsigned long int pvs_a_d862() {
  unsigned long int result;
  result = (unsigned long) *2*;
  return result;
}

int pvs_b863() {
  int result;
  result = (*3* + *1*);
  return result;
}

int pvs_b_d864() {
  int result;
  result = (*3* + *1*);
  return result;
}

void pvs_c865(mpz_t result) {
  mpz_set_si(result, (long) (*3* * (*1* + *2*)));
}

void pvs_c_d866(mpz_t result) {
  mpz_set_si(result, (long) (*3* * (*1* + *2*)));
}

int pvs_incr867(int x) {
  int result;
  result = (x + *1*);
  return result;
}

int pvs_incr_d868(int x) {
  int result;
  result = (x + *1*);
  return result;
}

int pvs_zero869(mpz_t x) {
  return 0;
}

int pvs_zero_d870(mpz_t x) {
  return 0;
}

int pvs_f871(int a, int b) {
  mpz_t conv873;
  mpz_set_si(conv873, (long) b);
  int result;
  result = (int) (pvs_zero_d870(conv873) * pvs_incr_d868(a));
  mpz_clear(conv873);
  return result;
}

int pvs_f_d872(int a, int b) {
  mpz_t conv874;
  mpz_set_si(conv874, (long) b);
  int result;
  result = (int) (pvs_zero_d870(conv874) * pvs_incr_d868(a));
  mpz_clear(conv874);
  return result;
}

int pvs_f875(int x) {
  int if879;
  if (((x <= *1*) && *1*)) {
    int if877;
    if (((x == *0*) || (x < *0*))) {
      if877 = *0*;
    } else {
      if877 = x;
    }
    if879 = if877;
  } else {
    int if878;
    if ((x > *10*)) {
      if878 = *10*;
    } else {
      if878 = (x - *5*);
    }
    if879 = if878;
  }
  int result;
  result = if879;
  return result;
}

int pvs_f_d876(int x) {
  int if882;
  if (((x <= *1*) && *1*)) {
    int if880;
    if (((x == *0*) || (x < *0*))) {
      if880 = *0*;
    } else {
      if880 = x;
    }
    if882 = if880;
  } else {
    int if881;
    if ((x > *10*)) {
      if881 = *10*;
    } else {
      if881 = (x - *5*);
    }
    if882 = if881;
  }
  int result;
  result = if882;
  return result;
}

int pvs_t883(int x) {
  int result;
  result = x;
  return result;
}

int pvs_t_d884(int x) {
  int result;
  result = x;
  return result;
}

int* pvs_id2885(int* #t57024#) {
  return *#t57024#*;
}

!int* pvs_id2_d886(!int* #t57024#) {
  return *#t57024#*;
}

!int* pvs_f887(int x) {
  !int* #result#;
  #result# = GC_malloc(1000, sizeof(int) );
  int i889;
  for(i889 = 0; i889 < 1000; i889++) {
    #result#[i889] = pvs_t_d884(i889);
  }
  return *#result#*;
}

!int* pvs_f_d888(int x) {
  !int* #result#;
  #result# = GC_malloc(1000, sizeof(int) );
  int i890;
  for(i890 = 0; i890 < 1000; i890++) {
    #result#[i890] = pvs_t_d884(i890);
  }
  return *#result#*;
}

!int* pvs_update891(int* x) {
  !int* #result#;
  if ( GC_count( *x* ) == 1 )
    #result# = GC( *x* );
  else {
    #result# = GC_malloc(1000, sizeof(int) );
    int i927;
    for(i927 = 0; i927 < 1000; i927++) {
      #result#[i927] = *x*[i927];
    }
  }
  #result#[0] = 0;
  return *#result#*;
}

!int* pvs_update_d892(!int* #x#) {
  #x#[0] = 0;
  return *#x#*;
}

!int* pvs_t2897(int x) {
  !mpq_t* #set900#;
  #set900# = GC_malloc(1000, sizeof(mpq_t) );
  int i899;
  for(i899 = 0; i899 < 1000; i899++) {
    mpq_init(#set900#[i899]);
    mpq_set_d(#set900#[i899], (double) (x + i899) );
    mpq_canonicalize(#set900#[i899]);
  }
  !int* #result#;
  #result# = (int*) GC( *#set900#* );
  if( GC_count( #set900# ) == 1 ) {
    int i928;
    for(i928 = 0; i928 < 1000; i928++) {
      mpq_clear(#set900#[i928]);
    }
  }
  GC_free(#set900#);
  return *#result#*;
}

!int* pvs_t2_d898(int x) {
  !mpq_t* #set902#;
  #set902# = GC_malloc(1000, sizeof(mpq_t) );
  int i901;
  for(i901 = 0; i901 < 1000; i901++) {
    mpq_init(#set902#[i901]);
    mpq_set_d(#set902#[i901], (double) (x + i901) );
    mpq_canonicalize(#set902#[i901]);
  }
  !int* #result#;
  #result# = (int*) GC( *#set902#* );
  if( GC_count( #set902# ) == 1 ) {
    int i929;
    for(i929 = 0; i929 < 1000; i929++) {
      mpq_clear(#set902#[i929]);
    }
  }
  GC_free(#set902#);
  return *#result#*;
}

int* pvs_id903(int** #t57024#) {
  int* #result#;
  #result# = (int*) GC( *#t57024#*[*0*] );
  if( GC_count( #t57024# ) == 1 ) {
    int i930;
    for(i930 = 0; i930 < 1000; i930++) {
      GC_free(#t57024#[i930]);
    }
  }
  GC_free(#t57024#);
  return *#result#*;
}

int* pvs_id_d904(int** #t57024#) {
  int* #result#;
  #result# = (int*) GC( *#t57024#*[*0*] );
  if( GC_count( #t57024# ) == 1 ) {
    int i932;
    for(i932 = 0; i932 < 1000; i932++) {
      GC_free(#t57024#[i932]);
    }
  }
  GC_free(#t57024#);
  return *#result#*;
}

!int* pvs_te905() {
  !int* #aux908#;
  #aux908# = GC_malloc(1000, sizeof(int) );
  int i907;
  for(i907 = 0; i907 < 1000; i907++) {
    #aux908#[i907] = pvs_t_d884(i907);
  }
  !int* #result#;
  #result# = (int*) GC( pvs_update_d892(pvs_update_d892(*#aux908#*)) );
  GC_free(#aux908#);
  return *#result#*;
}

!int* pvs_te_d906() {
  !int* #aux910#;
  #aux910# = GC_malloc(1000, sizeof(int) );
  int i909;
  for(i909 = 0; i909 < 1000; i909++) {
    #aux910#[i909] = pvs_t_d884(i909);
  }
  !int* #result#;
  #result# = (int*) GC( pvs_update_d892(pvs_update_d892(*#aux910#*)) );
  GC_free(#aux910#);
  return *#result#*;
}

!int** pvs_update911(int** x) {
  !int** #result#;
  !int* #res918#;
  #res918# = GC_malloc(1000, sizeof(int) );
  int i919;
  for(i919 = 0; i919 < 1000; i919++) {
    #res918#[i919] = i919;
  }
  if ( GC_count( *x* ) == 1 )
    #result# = GC( *x* );
  else {
    #result# = GC_malloc(1000, sizeof(int*) );
    int i936;
    for(i936 = 0; i936 < 1000; i936++) {
      if ( GC_count( *x*[i936] ) == 1 )
        #result#[i936] = GC( *x*[i936] );
      else {
        #result#[i936] = GC_malloc(1000, sizeof(int) );
        int i937;
        for(i937 = 0; i937 < 1000; i937++) {
          #result#[i936][i937] = *x*[i936][i937];
        }
      }
    }
  }
  !int* #E914#;
  #E914# = GC_malloc(1000, sizeof(int) );
  int i938;
  for(i938 = 0; i938 < 1000; i938++) {
    #E914#[i938] = #result#[0][i938];
  }
  #E914#[1] = 0;
  #result#[0] = (int*) GC( *#E914#* );
  #result#[1] = (int*) GC( *#res918#* );
  GC_free(#res918#);
  return *#result#*;
}

!int** pvs_update_d912(!int** #x#) {
  !int* #res925#;
  #res925# = GC_malloc(1000, sizeof(int) );
  int i926;
  for(i926 = 0; i926 < 1000; i926++) {
    #res925#[i926] = i926;
  }
  !int* #E921#;
  #E921# = GC_malloc(1000, sizeof(int) );
  int i940;
  for(i940 = 0; i940 < 1000; i940++) {
    #E921#[i940] = #x#[0][i940];
  }
  #E921#[1] = 0;
  #x#[0] = (int*) GC( *#E921#* );
  #x#[1] = (int*) GC( *#res925#* );
  GC_free(#res925#);
  return *#x#*;
}