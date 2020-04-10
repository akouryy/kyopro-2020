#define MOD 998244353

#include "base.hpp"
//#include "consts.hpp"

void solve() {
  // NXX(MM(AB))
  /* <foxy.memo-area> */
  int N;int X=3;WI A;WI B;cin>>N;VI M(X);A.resize(X);B.resize(X);times(X,Ri_0
  ){cin>>M[Ri_0];A[Ri_0].resize(M[Ri_0]);B[Ri_0].resize(M[Ri_0]);times(M[Ri_0]
  ,Ri_1){cin>>A[Ri_0][Ri_1];--A[Ri_0][Ri_1];cin>>B[Ri_0][Ri_1];--B[Ri_0][Ri_1];}}
  /* </foxy.memo-area> */

  VWI edges(3, WI(N));
  times(3, i) times(M[i], j) {
    edges[i][A[i][j]].PB(B[i][j]);
    edges[i][B[i][j]].PB(A[i][j]);
  }

  WM gc(3);
  VI gs;
  times(3, i) {
    VI gr(N);
    rtimes(N, j) {
      gs.clear();
      for(int k : edges[i][j]) if(k > j) {
        gs.PB(gr[k]);
      }
      uniq(gs);
      if(size(gs) == 0 || gs[0] > 0) {
        gr[j] = 0;
      } else {
        times(size(gs) - 1, k) {
          if(gs[k] + 1 != gs[k+1]) {
            gr[j] = gs[k] + 1;
            goto pyonp;
          }
        }
        gr[j] = gs.back() + 1;
        pyonp:;
      }

      if(gr[j] >= size(gc[i])) gc[i].resize(gr[j] + 1);
      gc[i][gr[j]] += 10_m .pow(18 * (j + 1));
    }
    dd gr; gc[i];
  }

  mint ans = 0_m;
  times(size(gc[0]), i) times(size(gc[1]), j) {
    if((i ^ j) < size(gc[2])) {
      dd i; j; i^j; gc[0][i] * gc[1][j] * gc[2][i ^ j];
      ans += gc[0][i] * gc[1][j] * gc[2][i ^ j];
    }
  }

  cout << ans ln;
}
