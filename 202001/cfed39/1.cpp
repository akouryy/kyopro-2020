#include "base.hpp"
//#include "consts.hpp"

void solve() {
// NN(A)
/* <foxy.memo-area> */
int N;cin>>N;VI A(N);times(N,Ri_0){cin>>A[Ri_0];}
/* </foxy.memo-area> */

  int ans = 0;
  times(N, i) ans += abs(A[i]);

  cout << ans ln;
}
