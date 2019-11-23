#include "base.hpp"
#include "consts.hpp"

void solve() {
// NN(A)N(B)
/* <foxy.memo-area> */
int N;cin>>N;VI A(N);times(N,Ri_0){cin>>A[Ri_0];}VI B(N);times(N,Ri_0){cin>>B[
Ri_0];}
/* </foxy.memo-area> */

  VI sa = A, sb = B;
  sort(iter(sa));
  sort(iter(sb));

  times(N, i) if(sa[i] > sb[i]) {
    cout << dict::No ln;
    return;
  }

  times(N-1, i) if(sa[i+1] <= sb[i]) {
    cout << dict::Yes ln;
    return;
  }

  VPII t(N);
  times(N, i) t[i] = make_pair(B[i], A[i]);
  sort(iter(t));

  HII tainv; times(N, i) tainv[t[i].second] = i;

  int i = 0, cnt = 0;

  do {
    ++cnt;
    i = tainv[sa[i]];
    dd i;
  } while(i != 0);

  cout << (cnt == N ? dict::No : dict::Yes) ln;
}
