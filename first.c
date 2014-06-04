/*
C file generated from first.pvs
Make sure to link GMP and PVS.c in compilation:
    gcc -o first first.c PVS.c -lgmp
    ./first
*/

#include<stdio.h>
#include "PVS.h"
#include "first.h"

#define TRUE 1
#define FALSE 0

int main(void) {
  printf("Executing first ...\n");
  return 0;
}

void pvs_a569(mpz_t result) {
  mpz_t aux580;
  mpz_init(aux580);
  mpz_set_str(aux580, "2");
  mpz_t aux581;
  mpz_init(aux581);
  mpz_set_str(aux581, "1");
  mpz_t aux579;
  mpz_init(aux579);
  pvsSub(aux579, aux580, aux581);;
  mpz_clear(aux581);
  mpz_clear(aux580);
  mpz_t aux583;
  mpz_init(aux583);
  mpz_set_str(aux583, "1");
  mpz_t aux582;
  mpz_init(aux582);
  pvsNeg(aux582, aux583);
  mpz_clear(aux583);
  mpz_t aux578;
  mpz_init(aux578);
  pvsAdd(aux578, aux579, aux582);;
  mpz_clear(aux582);
  mpz_clear(aux579);
  mpz_t aux584;
  mpz_init(aux584);
  mpz_set_str(aux584, "1");
  pvsAdd(result, aux578, aux584);;
  mpz_clear(aux584);
  mpz_clear(aux578);
}

void pvs_d_a570(mpz_t result) {
  mpz_t aux580;
  mpz_init(aux580);
  mpz_set_str(aux580, "2");
  mpz_t aux581;
  mpz_init(aux581);
  mpz_set_str(aux581, "1");
  mpz_t aux579;
  mpz_init(aux579);
  pvsSub(aux579, aux580, aux581);;
  mpz_clear(aux581);
  mpz_clear(aux580);
  mpz_t aux583;
  mpz_init(aux583);
  mpz_set_str(aux583, "1");
  mpz_t aux582;
  mpz_init(aux582);
  pvsNeg(aux582, aux583);
  mpz_clear(aux583);
  mpz_t aux578;
  mpz_init(aux578);
  pvsAdd(aux578, aux579, aux582);;
  mpz_clear(aux582);
  mpz_clear(aux579);
  mpz_t aux584;
  mpz_init(aux584);
  mpz_set_str(aux584, "1");
  pvsAdd(result, aux578, aux584);;
  mpz_clear(aux584);
  mpz_clear(aux578);
}

int pvs_a585() {
  int result;
  result = TRUE;
  return result;
}

int pvs_d_a586() {
  int result;
  result = TRUE;
  return result;
}

void pvs_adda587(mpz_t result, mpz_t i) {
  mpz_t aux590;
  mpz_init(aux590);
  pvs_a569(aux590);
  pvsAdd(result, aux590, i);;
  mpz_clear(aux590);
}

void pvs_d_adda588(mpz_t result, mpz_t i) {
  mpz_t aux590;
  mpz_init(aux590);
  pvs_a569(aux590);
  pvsAdd(result, aux590, i);;
  mpz_clear(aux590);
}

void pvs_foo591(mpz_t result, mpz_t x) {
  mpz_t aux605;
  mpz_init(aux605);
  mpz_set_str(aux605, "1");
  mpz_t aux607;
  mpz_init(aux607);
  mpz_set_str(aux607, "0");
  mpz_t if606;
  mpz_init(if606);
  if(((mpz_cmp(x, aux607) == 0) && (TRUE && (TRUE  FALSE)))) {
    mpz_t aux608;
    mpz_init(aux608);
    mpz_set_str(aux608, "7");
    mpz_t aux611;
    mpz_init(aux611);
    mpz_set_str(aux611, "1");
    mpz_t aux610;
    mpz_init(aux610);
    pvsAdd(aux610, x, aux611);;
    mpz_clear(aux611);
    mpz_t aux612;
    mpz_init(aux612);
    mpz_set_str(aux612, "3");
    mpz_t if609;
    mpz_init(if609);
    if(( mpz_cmp(aux610, aux612) > 0 )) {
      mpz_set_str(if609, "0");
    } else {
      mpz_set_str(if609, "8");
    }
    pvsTimes(if606, aux608, if609);;
    mpz_clear(aux612);
    mpz_clear(aux610);
    mpz_clear(if609);
    mpz_clear(aux608);
  } else {
    mpz_t aux613;
    mpz_init(aux613);
    mpz_set_str(aux613, "8");
    mpz_t aux615;
    mpz_init(aux615);
    mpz_set_str(aux615, "1");
    mpz_t aux616;
    mpz_init(aux616);
    mpz_set_str(aux616, "1");
    mpz_t if614;
    mpz_init(if614);
    if(( mpz_cmp(aux615, aux616) < 0 )) {
      mpz_set_str(if614, "6");
    } else {
      mpz_set_str(if614, "3");
    }
    pvsSub(if606, aux613, if614);;
    mpz_clear(aux616);
    mpz_clear(aux615);
    mpz_clear(if614);
    mpz_clear(aux613);
  }
  pvsAdd(result, aux605, if606);;
  mpz_clear(aux607);
  mpz_clear(if606);
  mpz_clear(aux605);
}

void pvs_d_foo592(mpz_t result, mpz_t x) {
  mpz_t aux605;
  mpz_init(aux605);
  mpz_set_str(aux605, "1");
  mpz_t aux607;
  mpz_init(aux607);
  mpz_set_str(aux607, "0");
  mpz_t if606;
  mpz_init(if606);
  if(((mpz_cmp(x, aux607) == 0) && (TRUE && (TRUE  FALSE)))) {
    mpz_t aux608;
    mpz_init(aux608);
    mpz_set_str(aux608, "7");
    mpz_t aux611;
    mpz_init(aux611);
    mpz_set_str(aux611, "1");
    mpz_t aux610;
    mpz_init(aux610);
    pvsAdd(aux610, x, aux611);;
    mpz_clear(aux611);
    mpz_t aux612;
    mpz_init(aux612);
    mpz_set_str(aux612, "3");
    mpz_t if609;
    mpz_init(if609);
    if(( mpz_cmp(aux610, aux612) > 0 )) {
      mpz_set_str(if609, "0");
    } else {
      mpz_set_str(if609, "8");
    }
    pvsTimes(if606, aux608, if609);;
    mpz_clear(aux612);
    mpz_clear(aux610);
    mpz_clear(if609);
    mpz_clear(aux608);
  } else {
    mpz_t aux613;
    mpz_init(aux613);
    mpz_set_str(aux613, "8");
    mpz_t aux615;
    mpz_init(aux615);
    mpz_set_str(aux615, "1");
    mpz_t aux616;
    mpz_init(aux616);
    mpz_set_str(aux616, "1");
    mpz_t if614;
    mpz_init(if614);
    if(( mpz_cmp(aux615, aux616) < 0 )) {
      mpz_set_str(if614, "6");
    } else {
      mpz_set_str(if614, "3");
    }
    pvsSub(if606, aux613, if614);;
    mpz_clear(aux616);
    mpz_clear(aux615);
    mpz_clear(if614);
    mpz_clear(aux613);
  }
  pvsAdd(result, aux605, if606);;
  mpz_clear(aux607);
  mpz_clear(if606);
  mpz_clear(aux605);
}

void pvs_add2617(mpz_t result, mpz_t a) {
  mpz_t aux627;
  mpz_init(aux627);
  mpz_set_str(aux627, "1");
  mpz_t if626;
  mpz_init(if626);
  if((mpz_cmp(a, aux627) == 0)) {
    mpz_set_str(if626, "1");
  } else {
    mpz_set_str(if626, "0");
  }
  mpz_t aux625;
  mpz_init(aux625);
  pvsAdd(aux625, a, if626);;
  mpz_clear(aux627);
  mpz_clear(if626);
  mpz_t aux628;
  mpz_init(aux628);
  mpz_set_str(aux628, "2");
  mpz_t d = aux628;
  mpz_t c = aux625;
  mpz_t aux629;
  mpz_init(aux629);
  pvsAdd(aux629, c, d);;
  mpz_clear(aux628);
  mpz_clear(aux625);
  mpz_t aux630;
  mpz_init(aux630);
  mpz_set_str(aux630, "1");
  pvsAdd(result, aux629, aux630);;
  mpz_clear(aux630);
  mpz_clear(aux629);
}

void pvs_d_add2618(mpz_t result, mpz_t a) {
  mpz_t aux627;
  mpz_init(aux627);
  mpz_set_str(aux627, "1");
  mpz_t if626;
  mpz_init(if626);
  if((mpz_cmp(a, aux627) == 0)) {
    mpz_set_str(if626, "1");
  } else {
    mpz_set_str(if626, "0");
  }
  mpz_t aux625;
  mpz_init(aux625);
  pvsAdd(aux625, a, if626);;
  mpz_clear(aux627);
  mpz_clear(if626);
  mpz_t aux628;
  mpz_init(aux628);
  mpz_set_str(aux628, "2");
  mpz_t d = aux628;
  mpz_t c = aux625;
  mpz_t aux629;
  mpz_init(aux629);
  pvsAdd(aux629, c, d);;
  mpz_clear(aux628);
  mpz_clear(aux625);
  mpz_t aux630;
  mpz_init(aux630);
  mpz_set_str(aux630, "1");
  pvsAdd(result, aux629, aux630);;
  mpz_clear(aux630);
  mpz_clear(aux629);
}

void pvs_factorial631(mpz_t result, mpz_t n) {
  mpz_t aux637;
  mpz_init(aux637);
  mpz_set_str(aux637, "0");
  if((mpz_cmp(n, aux637) == 0)) {
    mpz_set_str(result, "1");
  } else {
    mpz_t aux640;
    mpz_init(aux640);
    mpz_set_str(aux640, "1");
    mpz_t aux639;
    mpz_init(aux639);
    pvsSub(aux639, n, aux640);;
    mpz_clear(aux640);
    mpz_t aux638;
    mpz_init(aux638);
    pvs_d_factorial632(aux638, aux639);
    mpz_clear(aux639);
    pvsTimes(result, n, aux638);;
    mpz_clear(aux638);
  }
  
  mpz_clear(aux637);
}

void pvs_d_factorial632(mpz_t result, mpz_t n) {
  mpz_t aux637;
  mpz_init(aux637);
  mpz_set_str(aux637, "0");
  if((mpz_cmp(n, aux637) == 0)) {
    mpz_set_str(result, "1");
  } else {
    mpz_t aux640;
    mpz_init(aux640);
    mpz_set_str(aux640, "1");
    mpz_t aux639;
    mpz_init(aux639);
    pvsSub(aux639, n, aux640);;
    mpz_clear(aux640);
    mpz_t aux638;
    mpz_init(aux638);
    pvs_d_factorial632(aux638, aux639);
    mpz_clear(aux639);
    pvsTimes(result, n, aux638);;
    mpz_clear(aux638);
  }
  
  mpz_clear(aux637);
}

void pvs_binomial641(mpz_t result, mpz_t a, mpz_t b) {
  mpz_t aux653;
  mpz_init(aux653);
  mpz_set_str(aux653, "0");
  if((mpz_cmp(b, aux653) == 0)) {
    mpz_set_str(result, "1");
  } else {
    mpz_t aux654;
    mpz_init(aux654);
    mpz_set_str(aux654, "0");
    if((mpz_cmp(a, aux654) == 0)) {
      mpz_set_str(result, "0");
    } else {
      mpz_t aux657;
      mpz_init(aux657);
      mpz_set_str(aux657, "1");
      mpz_t aux656;
      mpz_init(aux656);
      pvsSub(aux656, a, aux657);;
      mpz_clear(aux657);
      mpz_t aux659;
      mpz_init(aux659);
      mpz_set_str(aux659, "1");
      mpz_t aux658;
      mpz_init(aux658);
      pvsSub(aux658, b, aux659);;
      mpz_clear(aux659);
      mpz_t aux655;
      mpz_init(aux655);
      pvs_d_binomial642(aux655, aux656, aux658);
      mpz_clear(aux658);
      mpz_clear(aux656);
      mpz_t aux662;
      mpz_init(aux662);
      mpz_set_str(aux662, "1");
      mpz_t aux661;
      mpz_init(aux661);
      pvsSub(aux661, a, aux662);;
      mpz_clear(aux662);
      mpz_t aux660;
      mpz_init(aux660);
      pvs_d_binomial642(aux660, aux661, b);
      mpz_clear(aux661);
      pvsAdd(result, aux655, aux660);;
      mpz_clear(aux660);
      mpz_clear(aux655);
    }
    
    mpz_clear(aux654);
  }
  
  mpz_clear(aux653);
}

void pvs_d_binomial642(mpz_t result, mpz_t a, mpz_t b) {
  mpz_t aux653;
  mpz_init(aux653);
  mpz_set_str(aux653, "0");
  if((mpz_cmp(b, aux653) == 0)) {
    mpz_set_str(result, "1");
  } else {
    mpz_t aux654;
    mpz_init(aux654);
    mpz_set_str(aux654, "0");
    if((mpz_cmp(a, aux654) == 0)) {
      mpz_set_str(result, "0");
    } else {
      mpz_t aux657;
      mpz_init(aux657);
      mpz_set_str(aux657, "1");
      mpz_t aux656;
      mpz_init(aux656);
      pvsSub(aux656, a, aux657);;
      mpz_clear(aux657);
      mpz_t aux659;
      mpz_init(aux659);
      mpz_set_str(aux659, "1");
      mpz_t aux658;
      mpz_init(aux658);
      pvsSub(aux658, b, aux659);;
      mpz_clear(aux659);
      mpz_t aux655;
      mpz_init(aux655);
      pvs_d_binomial642(aux655, aux656, aux658);
      mpz_clear(aux658);
      mpz_clear(aux656);
      mpz_t aux662;
      mpz_init(aux662);
      mpz_set_str(aux662, "1");
      mpz_t aux661;
      mpz_init(aux661);
      pvsSub(aux661, a, aux662);;
      mpz_clear(aux662);
      mpz_t aux660;
      mpz_init(aux660);
      pvs_d_binomial642(aux660, aux661, b);
      mpz_clear(aux661);
      pvsAdd(result, aux655, aux660);;
      mpz_clear(aux660);
      mpz_clear(aux655);
    }
    
    mpz_clear(aux654);
  }
  
  mpz_clear(aux653);
}