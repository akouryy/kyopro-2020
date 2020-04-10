#include "base.hpp"
//#include "consts.hpp"

void solve() {
  int N,M; cin>>N>>M;

  WI dp(3*N+1, VI(4*N+1));
  dp[0][N] = 1;

  times(3*N, i) times(4*N+1, j) {
    if(j < 4*N) (dp[i+1][j+1] += dp[i][j]) %= M;
    if(j > 0 && i <= 3*N-2) (dp[i+2][j-1] += dp[i][j] * (i+1) % M) %= M;
    if(i <= 3*N-3) (dp[i+3][j] += dp[i][j] * (i+1) % M * (i+2) % M) %= M;
  }

  int ans = 0;

  upto(N, 4*N, j) {
    (ans += dp[3*N][j]) %= M;
  }

  cout << ans ln;
}
