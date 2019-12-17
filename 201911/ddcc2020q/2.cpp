#include "base.hpp"
//#include "consts.hpp"

void solve() {
// NN(A)
/* <foxy.memo-area> */
int N;cin>>N;VI A(N);times(N,Ri_0){cin>>A[Ri_0];}
/* </foxy.memo-area> */

  int s = 0;
  times(N, i) s += A[i];

  int ans = s, k = 0;
  times(N, i) {
    k += A[i];
    amin(ans, abs(k * 2 - s));
  }

  cout << ans ln;
}
