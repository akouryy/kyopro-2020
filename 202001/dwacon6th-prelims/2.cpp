#include "base.hpp"
//#include "consts.hpp"

void solve() {
// NN(X)
/* <foxy.memo-area> */
int N;cin>>N;VI X(N);times(N,Ri_0){cin>>X[Ri_0];}
/* </foxy.memo-area> */

  mint base = 1_m; times(N-1, i) base *= mint(i+1);

  mint ans = 0_m, sum = 0_m;
  times(N-1, i) {
    sum += 1_m / mint(i+1);
    ans += base * sum * mint(X[i+1] - X[i]);
  }

  cout << ans ln;
}
