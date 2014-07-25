// ---------------------------------------------
//        C file generated from binom.pvs
// ---------------------------------------------
//   Make sure to link GC.c and GMP in compilation:
//      gcc -o binom binom.c GC.c -lgmp
//      ./binom
// ---------------------------------------------

#include<stdio.h>
#include<gmp.h>
#include "GC.h"
#include "binom.h"

#define TRUE 1
#define FALSE 0

int main(void) {
  printf("Executing binom ...\n");
  return 0;
}


void pvs_f705(mpz_t result, mpz_t a) {
  mpz_mul_ui(result, a, (unsigned long) *2*);
}

void pvs_f_d706(mpz_t result, mpz_t a) {
  mpz_mul_ui(result, a, (unsigned long) *2*);
}

void pvs_factorial707(mpz_t result, mpz_t n) {
  mpz_t conv709;
  mpz_set_si(conv709, (long) *0*);
  if ((mpz_cmp(n, conv709) == 0)) {
    mpz_set_si(result, (long) *1*);
  } else {
    mpz_t aux711;
    mpz_init(aux711);
    mpz_t aux710;
    mpz_init(aux710);
    mpz_sub_ui(aux710, n, (unsigned long) *1*);
    pvs_factorial_d708(aux711, aux710);
    mpz_clear(aux710);
    mpz_mul(result, n, aux711);
    mpz_clear(aux711);
  }
  mpz_clear(conv709);
}

void pvs_factorial_d708(mpz_t result, mpz_t n) {
  mpz_t conv712;
  mpz_set_si(conv712, (long) *0*);
  if ((mpz_cmp(n, conv712) == 0)) {
    mpz_set_si(result, (long) *1*);
  } else {
    mpz_t aux714;
    mpz_init(aux714);
    mpz_t aux713;
    mpz_init(aux713);
    mpz_sub_ui(aux713, n, (unsigned long) *1*);
    pvs_factorial_d708(aux714, aux713);
    mpz_clear(aux713);
    mpz_mul(result, n, aux714);
    mpz_clear(aux714);
  }
  mpz_clear(conv712);
}

void pvs_binom715(mpz_t result, mpz_t k, mpz_t n) {
  mpz_t conv717;
  mpz_set_si(conv717, (long) *0*);
  if ((mpz_cmp(k, conv717) == 0)) {
    mpz_set_si(result, (long) *1*);
  } else {
    mpz_t conv718;
    mpz_set_si(conv718, (long) *0*);
    if ((mpz_cmp(n, conv718) == 0)) {
      mpz_set_si(result, (long) *0*);
    } else {
      mpz_t aux721;
      mpz_init(aux721);
      mpz_t aux719;
      mpz_init(aux719);
      mpz_sub_ui(aux719, k, (unsigned long) *1*);
      mpz_t aux720;
      mpz_init(aux720);
      mpz_sub_ui(aux720, n, (unsigned long) *1*);
      pvs_binom_d716(aux721, aux719, aux720);
      mpz_clear(aux719);
      mpz_clear(aux720);
      mpz_t aux723;
      mpz_init(aux723);
      mpz_t aux722;
      mpz_init(aux722);
      mpz_sub_ui(aux722, n, (unsigned long) *1*);
      pvs_binom_d716(aux723, k, aux722);
      mpz_clear(aux722);
      mpz_add(result, aux721, aux723);
      mpz_clear(aux721);
      mpz_clear(aux723);
    }
    mpz_clear(conv718);
  }
  mpz_clear(conv717);
}

void pvs_binom_d716(mpz_t result, mpz_t k, mpz_t n) {
  mpz_t conv724;
  mpz_set_si(conv724, (long) *0*);
  if ((mpz_cmp(k, conv724) == 0)) {
    mpz_set_si(result, (long) *1*);
  } else {
    mpz_t conv725;
    mpz_set_si(conv725, (long) *0*);
    if ((mpz_cmp(n, conv725) == 0)) {
      mpz_set_si(result, (long) *0*);
    } else {
      mpz_t aux728;
      mpz_init(aux728);
      mpz_t aux726;
      mpz_init(aux726);
      mpz_sub_ui(aux726, k, (unsigned long) *1*);
      mpz_t aux727;
      mpz_init(aux727);
      mpz_sub_ui(aux727, n, (unsigned long) *1*);
      pvs_binom_d716(aux728, aux726, aux727);
      mpz_clear(aux726);
      mpz_clear(aux727);
      mpz_t aux730;
      mpz_init(aux730);
      mpz_t aux729;
      mpz_init(aux729);
      mpz_sub_ui(aux729, n, (unsigned long) *1*);
      pvs_binom_d716(aux730, k, aux729);
      mpz_clear(aux729);
      mpz_add(result, aux728, aux730);
      mpz_clear(aux728);
      mpz_clear(aux730);
    }
    mpz_clear(conv725);
  }
  mpz_clear(conv724);
}

!mpz_t* pvs_f731(int k) {
  !mpq_t* #set735#;
  #set735# = GC_malloc(1000, sizeof(mpq_t) );
  int i733;
  for(i733 = 0; i733 < 1000; i733++) {
    mpq_init(#set735#[i733]);
    mpz_t set734;
    mpz_init(set734);
    if ((k == *0*)) {
      mpz_set_si(set734, (long) *1*);
    } else {
      mpz_set_si(set734, (long) *0*);
    }
    mpq_set_z(#set735#[i733], set734);
    mpq_canonicalize(#set735#[i733]);
    mpz_clear(set734);
  }
  !mpz_t* #result#;
  #result# = (mpz_t*) GC( *#set735#* );
  if( GC_count( #set735# ) == 1 ) {
    int i786;
    for(i786 = 0; i786 < 1000; i786++) {
      mpq_clear(#set735#[i786]);
    }
  }
  GC_free(#set735#);
  return *#result#*;
}

!mpz_t* pvs_f_d732(int k) {
  !mpq_t* #set738#;
  #set738# = GC_malloc(1000, sizeof(mpq_t) );
  int i736;
  for(i736 = 0; i736 < 1000; i736++) {
    mpq_init(#set738#[i736]);
    mpz_t set737;
    mpz_init(set737);
    if ((k == *0*)) {
      mpz_set_si(set737, (long) *1*);
    } else {
      mpz_set_si(set737, (long) *0*);
    }
    mpq_set_z(#set738#[i736], set737);
    mpq_canonicalize(#set738#[i736]);
    mpz_clear(set737);
  }
  !mpz_t* #result#;
  #result# = (mpz_t*) GC( *#set738#* );
  if( GC_count( #set738# ) == 1 ) {
    int i787;
    for(i787 = 0; i787 < 1000; i787++) {
      mpq_clear(#set738#[i787]);
    }
  }
  GC_free(#set738#);
  return *#result#*;
}

int pvs_lex_order739(Pair741 a, Pair741 b) {
  mpz_t conv742;
  mpz_from_nil( conv742, a->f1 );
  mpz_t conv743;
  mpz_from_nil( conv743, b->f1 );
  mpz_t conv744;
  mpz_from_nil( conv744, a->f1 );
  mpz_t conv745;
  mpz_from_nil( conv745, b->f1 );
  mpz_t conv746;
  mpz_from_nil( conv746, *a*->f2 );
  mpz_t conv747;
  mpz_from_nil( conv747, *b*->f2 );
  int result;
  result = ((mpz_cmp(conv742, conv743) < 0) || ((mpz_cmp(conv744, conv745) == 0) && (mpz_cmp(conv746, conv747) < 0)));
  mpz_clear(conv742);
  mpz_clear(conv743);
  mpz_clear(conv744);
  mpz_clear(conv745);
  mpz_clear(conv746);
  mpz_clear(conv747);
  return result;
}

int pvs_lex_order_d740(Pair741 a, Pair741 b) {
  mpz_t conv748;
  mpz_from_nil( conv748, a->f1 );
  mpz_t conv749;
  mpz_from_nil( conv749, b->f1 );
  mpz_t conv750;
  mpz_from_nil( conv750, a->f1 );
  mpz_t conv751;
  mpz_from_nil( conv751, b->f1 );
  mpz_t conv752;
  mpz_from_nil( conv752, *a*->f2 );
  mpz_t conv753;
  mpz_from_nil( conv753, *b*->f2 );
  int result;
  result = ((mpz_cmp(conv748, conv749) < 0) || ((mpz_cmp(conv750, conv751) == 0) && (mpz_cmp(conv752, conv753) < 0)));
  mpz_clear(conv748);
  mpz_clear(conv749);
  mpz_clear(conv750);
  mpz_clear(conv751);
  mpz_clear(conv752);
  mpz_clear(conv753);
  return result;
}

mpz_t** pvs_fill_line754(mpz_t K, mpz_t k, mpz_t n) {
  mpz_t** #result#;
  mpz_t conv756;
  mpz_set_si(conv756, (long) *0*);
  if ((mpz_cmp(n, conv756) == 0)) {
    #result# = GC_malloc(1000, sizeof(mpz_t*) );
    int i757;
    for(i757 = 0; i757 < 1000; i757++) {
      #result#[i757] = (mpz_t*) GC( pvs_f_d732(i757) );
    }
  } else {
    mpz_t conv758;
    mpz_set_si(conv758, (long) *0*);
    if ((mpz_cmp(k, conv758) == 0)) {
      mpz_t aux759;
      mpz_init(aux759);
      mpz_sub_ui(aux759, n, (unsigned long) *1*);
      #result# = (mpz_t**) GC( pvs_fill_line_d755(K, K, aux759) );
      mpz_clear(aux759);
    } else {
      mpz_t aux760;
      mpz_init(aux760);
      mpz_sub_ui(aux760, k, (unsigned long) *1*);
      mpz_t** F;
      F = (mpz_t**) GC( pvs_fill_line_d755(K, aux760, n) );
      mpz_clear(aux760);
      int conv765;
      conv765 = ( (int) mpz_get_si(n) );
      int L764;
      L764 = conv765;
      mpz_t res766;
      mpz_init(res766);
      mpz_t aux768;
      mpz_init(aux768);
      mpz_sub_ui(aux768, k, (unsigned long) *1*);
      mpz_t aux767;
      mpz_init(aux767);
      mpz_sub_ui(aux767, n, (unsigned long) *1*);
      mpz_t aux769;
      mpz_init(aux769);
      mpz_sub_ui(aux769, n, (unsigned long) *1*);
      mpz_add(res766, F[aux768][aux767], F[k][aux769]);
      int conv762;
      conv762 = ( (int) mpz_get_si(k) );
      int L761;
      L761 = conv762;
      #result# = GC_malloc(1000, sizeof(mpz_t*) );
      int i788;
      for(i788 = 0; i788 < 1000; i788++) {
        #result#[i788] = GC_malloc(1000, sizeof(mpz_t) );
        int i789;
        for(i789 = 0; i789 < 1000; i789++) {
          mpz_set(#result#[i788][i789], F[i788][i789]);
        }
      }
      mpz_t* #E763#;
      #E763# = GC_malloc(1000, sizeof(mpz_t) );
      int i790;
      for(i790 = 0; i790 < 1000; i790++) {
        mpz_set(#E763#[i790], #result#[L761][i790]);
      }
      mpz_set(#E763#[L764], res766);
      #result#[L761] = (mpz_t*) GC( #E763# );
      mpz_clear(aux768);
      mpz_clear(aux767);
      mpz_clear(aux769);
      mpz_clear(res766);
      if( GC_count( F ) == 1 ) {
        int i791;
        for(i791 = 0; i791 < 1000; i791++) {
          if( GC_count( F[i791] ) == 1 ) {
            int i792;
            for(i792 = 0; i792 < 1000; i792++) {
              mpz_clear(F[i791][i792]);
            }
          }
          GC_free(F[i791]);
        }
      }
      GC_free(F);
    }
    mpz_clear(conv758);
  }
  return *#result#*;
}

mpz_t** pvs_fill_line_d755(mpz_t K, mpz_t k, mpz_t n) {
  mpz_t** #result#;
  mpz_t conv770;
  mpz_set_si(conv770, (long) *0*);
  if ((mpz_cmp(n, conv770) == 0)) {
    #result# = GC_malloc(1000, sizeof(mpz_t*) );
    int i771;
    for(i771 = 0; i771 < 1000; i771++) {
      #result#[i771] = (mpz_t*) GC( pvs_f_d732(i771) );
    }
  } else {
    mpz_t conv772;
    mpz_set_si(conv772, (long) *0*);
    if ((mpz_cmp(k, conv772) == 0)) {
      mpz_t aux773;
      mpz_init(aux773);
      mpz_sub_ui(aux773, n, (unsigned long) *1*);
      #result# = (mpz_t**) GC( pvs_fill_line_d755(K, K, aux773) );
      mpz_clear(aux773);
    } else {
      mpz_t aux774;
      mpz_init(aux774);
      mpz_sub_ui(aux774, k, (unsigned long) *1*);
      mpz_t** F;
      F = (mpz_t**) GC( pvs_fill_line_d755(K, aux774, n) );
      mpz_clear(aux774);
      int conv779;
      conv779 = ( (int) mpz_get_si(n) );
      int L778;
      L778 = conv779;
      mpz_t res780;
      mpz_init(res780);
      mpz_t aux782;
      mpz_init(aux782);
      mpz_sub_ui(aux782, k, (unsigned long) *1*);
      mpz_t aux781;
      mpz_init(aux781);
      mpz_sub_ui(aux781, n, (unsigned long) *1*);
      mpz_t aux783;
      mpz_init(aux783);
      mpz_sub_ui(aux783, n, (unsigned long) *1*);
      mpz_add(res780, F[aux782][aux781], F[k][aux783]);
      int conv776;
      conv776 = ( (int) mpz_get_si(k) );
      int L775;
      L775 = conv776;
      #result# = GC_malloc(1000, sizeof(mpz_t*) );
      int i793;
      for(i793 = 0; i793 < 1000; i793++) {
        #result#[i793] = GC_malloc(1000, sizeof(mpz_t) );
        int i794;
        for(i794 = 0; i794 < 1000; i794++) {
          mpz_set(#result#[i793][i794], F[i793][i794]);
        }
      }
      mpz_t* #E777#;
      #E777# = GC_malloc(1000, sizeof(mpz_t) );
      int i795;
      for(i795 = 0; i795 < 1000; i795++) {
        mpz_set(#E777#[i795], #result#[L775][i795]);
      }
      mpz_set(#E777#[L778], res780);
      #result#[L775] = (mpz_t*) GC( #E777# );
      mpz_clear(aux782);
      mpz_clear(aux781);
      mpz_clear(aux783);
      mpz_clear(res780);
      if( GC_count( F ) == 1 ) {
        int i796;
        for(i796 = 0; i796 < 1000; i796++) {
          if( GC_count( F[i796] ) == 1 ) {
            int i797;
            for(i797 = 0; i797 < 1000; i797++) {
              mpz_clear(F[i796][i797]);
            }
          }
          GC_free(F[i796]);
        }
      }
      GC_free(F);
    }
    mpz_clear(conv772);
  }
  return *#result#*;
}

void pvs_binom_D784(mpz_t result, mpz_t x, mpz_t y) {
  mpz_set(result, pvs_fill_line_d755(x, x, y)[x][y]);
}

void pvs_binom_D_d785(mpz_t result, mpz_t x, mpz_t y) {
  mpz_set(result, pvs_fill_line_d755(x, x, y)[x][y]);
}