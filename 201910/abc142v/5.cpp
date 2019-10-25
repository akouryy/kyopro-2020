#include "base.hpp"
//#include "consts.hpp"

constexpr int INF = 1ll<<60;

void solve() {
// NMM(ABB(C))
/* <foxy.memo-area> */
int N;int M;WI C;cin>>N;cin>>M;VI A(M);VI B(M);C.resize(M);times(M,Ri_0){cin>>A[
Ri_0];cin>>B[Ri_0];C[Ri_0].resize(B[Ri_0]);times(B[Ri_0],Ri_1){cin>>C[Ri_0][Ri_1
];}}
/* </foxy.memo-area> */

  VI dp(1<<N, INF), dq(1<<N, INF);
  dp[0] = 0;

  times(M, i) {
    int c = 0;
    times(B[i], j) c |= 1 << (C[i][j] - 1);

    times(1<<N, b) {
      amin(dp[b | c], dp[b] + A[i]);
    }
  }

  int ans = dp[(1<<N) - 1];
  cout << (ans == INF ? -1 : ans) ln;
}
