#include "base.hpp"
//#include "consts.hpp"
#include "fact.hpp"
#include "nck.hpp"

void solve() {
  int N, T; cin >> N >> T;
  VI S(N); times(N, i) cin >> S[i];

  Inver<> inver(N+1);
  Fact<> fact(N+1, &inver);

  mint ans = 0_m, rem = 1_m;
  int g_old = T;
  times(N, i) {
    int g = g_old - S[i];
    if(g < 0) break;

    mint x = nCk(i, g_old, fact);
    upto(g + 1, min(g_old, i+1), j) {
      x += nCk(i + 1, j, fact);
    }
    rem -= 1_m / (2_m).pow(i + 1) * x;

    ans += rem;
    g_old = g;
  }

  cout << ans ln;
}
