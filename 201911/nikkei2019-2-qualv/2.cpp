#define MOD 998244353

#include "base.hpp"
//#include "consts.hpp"

void solve() {
// NN(D)
/* <foxy.memo-area> */
int N;cin>>N;VI D(N);times(N,Ri_0){cin>>D[Ri_0];}
/* </foxy.memo-area> */

  VI c(N);

  times(N, i) {
    if((i == 0) != (D[i] == 0)) {
      cout << 0 ln;
      return;
    }

    ++c[D[i]];
  }

  mint ans = 1_m;

  times(N-1, i) {
    if(c[i+1]) ans *= mint(c[i]).pow(c[i+1]);
  }

  cout << ans ln;
}
