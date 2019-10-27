#include "base.hpp"
//#include "consts.hpp"
// #include "prime.hpp"

void solve() {
// NM"S"
/* <foxy.memo-area> */
int N;int M;string S;cin>>N;cin>>M;cin>>S;
/* </foxy.memo-area> */

  if(S[0] == 'B') {
    times(M, i) S[i] = 'R' + 'B' - S[i];
  }

  {
    times(M, i) if(S[i] != 'R') goto not_same;

    mint ans = 0_m;
    {
      // [0]->R
      VM dp(N);
      dp[0] = 1_m;
      dp[1] = 2_m;
      uptil(2, N, i) {
        dp[i] = dp[i - 1] + dp[i - 2];
      }
      ans += dp[N - 1];
      dd dp;
    }
    {
      // [0]->B
      VM dp(N - 1);
      dp[0] = 1_m;
      if(N >= 3) dp[1] = 1_m;
      uptil(2, N - 1, i) {
        dp[i] = dp[i - 1] + dp[i - 2];
      }
      ans += dp[N - 2];
      dd dp;
    }

    cout << ans ln;
    return;
  }
  not_same:;

  int p = 1ll << 60;
  {
    int ren = 1;
    times(M, i) {
      if(S[i] == 'R') {
        ++ren;
      } else {
        if(p == 1ll << 60 || ren % 2 == 1) {
          amin(p, ren);
        }
        ren = 0;
      }
    }
  }
  dd p;

#define M hoge

  if(N % 2 == 1) {
    cout << 0 ln;
    return;
  }

  int m = N / 2;
  int q = (p + 1) / 2;

#define N hoge
#define p hoge

  /*
  auto pfh = prime_factor(m);
  int zpf = size(pfh);
  VI pf; pf.reserve(zpf);
  for(auto &p : pfh) pf.PB(p.first);
  dd pf;
  */

  /*
  VI pf;
  for(int i = 1; i*i <= m; ++i) {
    if(m % i == 0) {
      pf.PB(i);
      if(i*i != m) pf.PB(m / i);
    }
  }
  sort(iter(pf));
  */
  VI pf = {m};
  dd pf;
  int zpf = size(pf);

  VM dp(m);
  VM g(zpf);

  mint ans = 0_m;

  times(zpf, h) {
    mint s = dp[0] = 1_m;
    uptil(1, pf[h], i) {
      s += dp[i] = s;
      if(i >= q) {
        s -= dp[i - q];
      }
      if(i <= q) {
        dp[i] += dp[0] * mint(i - 1);
        s += dp[0] * mint(i - 1);
      }
    }

    g[h] = s;
    times(h, hh) {
      if(pf[h] % pf[hh] == 0) g[h] -= g[hh];
    }
    ans += g[h] ;//* mint(pf[h]);

    dd h; pf[h]; s; g[h]; dp;
  }

  cout << ans * 2_m ln;
}
