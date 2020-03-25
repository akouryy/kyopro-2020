#include "base.hpp"
//#include "consts.hpp"

void solve() {
// NN(XL)
/* <foxy.memo-area> */
int N;cin>>N;VI X(N);VI L(N);times(N,Ri_0){cin>>X[Ri_0];cin>>L[Ri_0];}
/* </foxy.memo-area> */

  VPII qp(N); times(N,i) qp[i] =make_pair(X[i]+L[i],X[i]-L[i]);
  sort(iter(qp));

  int ans = 0, q_old = -(1ll<<40);
  times(N,i) {
    if(q_old > qp[i].second) continue;
    ++ans;
    q_old = qp[i].first;
  }

  cout << ans ln;
}
