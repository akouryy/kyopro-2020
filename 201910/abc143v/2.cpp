#include "base.hpp"
//#include "consts.hpp"

void solve() {
// NN(D)
/* <foxy.memo-area> */
int N;cin>>N;VI D(N);times(N,Ri_0){cin>>D[Ri_0];}
/* </foxy.memo-area> */

  int ans = 0;
  times(N, i) times(i, j) ans += D[i] * D[j];

  cout << ans ln;
}
