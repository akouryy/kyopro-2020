#include "base.hpp"
//#include "consts.hpp"

void solve() {
// NMN(AB)M(CD)
/* <foxy.memo-area> */
int N;int M;cin>>N;cin>>M;VI A(N);VI B(N);times(N,Ri_0){cin>>A[Ri_0];cin>>B[Ri_0
];}VI C(M);VI D(M);times(M,Ri_0){cin>>C[Ri_0];cin>>D[Ri_0];}
/* </foxy.memo-area> */

  vec<LD> norm(N), help(M);

  LD ok = 0.0, ng = 9e99;
  times(1000, o) {
    LD goal = (ok + ng) / 2;
    times(N, i) norm[i] = B[i] - goal * A[i];
    times(M, i) help[i] = D[i] - goal * C[i];
    sort(iter(norm)); reverse(iter(norm));
    sort(iter(help)); reverse(iter(help));

    LD s = norm[0] + norm[1] + norm[2] + norm[3] + max(norm[4], help[0]);
    if(s >= 0) {
      ok = goal;
    } else {
      ng = goal;
    }
  }

  cout << ok ln;
}
