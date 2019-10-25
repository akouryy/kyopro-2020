#include "base.hpp"
//#include "consts.hpp"

void solve() {
// NKN(H)
/* <foxy.memo-area> */
int N;int K;cin>>N;cin>>K;VI H(N);times(N,Ri_0){cin>>H[Ri_0];}
/* </foxy.memo-area> */

  int ans = 0;
  times(N, i) ans += H[i] >= K;

  cout << ans ln;
}
