#include "base.hpp"
//#include "consts.hpp"

void solve() {
  int N; cin >> N;
  string S; cin >> S;
  int bN = 1 << N;
  int mask = bN - 1;
  VI P(bN); times(bN, i) cin >> P[i];

  auto battle = [&](int a, int b) {
    if(a > b) swap(a, b);
    // dd a; b; S[b - a];
    return S[b - a - 1] == '1' ? b : a;
  };

  VI dp = P, dq(bN);
  times(N, lv) {
    swap(dp, dq);
    times(bN, i) {
      dp[i] = battle(dq[i], dq[i + (1 << lv) & mask]);
    }

    dd lv; dp; dq;
  }

  times(bN, i) {
    cout << dp[i] ln;
  }
}
