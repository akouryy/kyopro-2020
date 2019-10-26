#include "base.hpp"
#include "consts.hpp"

void solve() {
// NKQQ(A)
/* <foxy.memo-area> */
int N;int K;int Q;cin>>N;cin>>K;cin>>Q;VI A(Q);times(Q,Ri_0){cin>>A[Ri_0];}
/* </foxy.memo-area> */

  VI h(N, K - Q);
  times(Q, i) ++h[A[i]-1];

  times(N, i) cout << (h[i] > 0 ? dict::Yes : dict::No) ln;
}
