#include "base.hpp"
//#include "consts.hpp"

int dp[5001][5001];

void solve() {
// N"S"
/* <foxy.memo-area> */
int N;string S;cin>>N;cin>>S;
/* </foxy.memo-area> */

  times(N, i) dp[i][N] = dp[N][i] = 0;

  int ans = 0;

  rtimes(N, i) rtimes(i, j) {
    dp[i][j] = min(
      i - j,
      (S[i] == S[j]) * (1 + dp[i + 1][j + 1])
    );

    amax(ans, dp[i][j]);
  }

  cout << ans ln;
}
