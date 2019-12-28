#include "base.hpp"
//#include "consts.hpp"

void solve() {
  // NMVPN(A)
/* <foxy.memo-area> */
int N;int M;int V;int P;cin>>N;cin>>M;cin>>V;cin>>P;VI A(N);times(N,Ri_0){cin>>A
[Ri_0];}
/* </foxy.memo-area> */

  sort(iter(A));
  reverse(iter(A));
  // A.PB(-(1ll << 60));
  dd A;

  int ok = P-1, ng = N;
  while(abs(ok - ng) > 1) {
    int mid = (ok + ng) / 2;

    int midScore = A[mid] + M;
    int cap = P * M;
    uptil(P-1, N, i) if(i != mid) {
      if(A[i] > midScore) {
        cap = -(1ll << 60);
      } else {
        cap += min(M, midScore - A[i]);
      }
      //dd i; A[i]; cap;
    }
    dd mid; midScore; cap;
    if(cap >= V * M) {
      ok = mid;
    } else {
      ng = mid;
    }
  }

  cout << ok+1 ln;
}
