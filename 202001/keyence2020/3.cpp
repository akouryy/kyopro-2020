#include "base.hpp"
//#include "consts.hpp"

void solve() {
// NKS
/* <foxy.memo-area> */
int N;int K;int S;cin>>N;cin>>K;cin>>S;
/* </foxy.memo-area> */

  times(K, i) {
    cout << (i ? " " : "") << S;
  }
  times(N-K, i) {
    cout sp << (S == 1000000000 ? 1 : S+1);
  }

  cout ln;
}
