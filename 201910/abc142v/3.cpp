#include "base.hpp"
//#include "consts.hpp"

void solve() {
// NN(A)
/* <foxy.memo-area> */
int N;cin>>N;VI A(N);times(N,Ri_0){cin>>A[Ri_0];}
/* </foxy.memo-area> */

  VPII a(N); times(N, i) a[i] = {A[i], i};
  sort(iter(a));

  times(N, i) cout << a[i].second + 1 ln;
}
