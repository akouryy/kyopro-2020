#define GCJ_CASE
#include "base.hpp"
#include "consts.hpp"

void solve(int caseid) {
  int N; cin >> N;
  VI S(N), E(N); times(N, i) cin >> S[i] >> E[i];

  VTIII x; times(N, i) x.EB(E[i], S[i], i);
  sort(iter(x));

  dd x;

  VB c(N);
  VI last(2);
  times(N, xi) {
    int i = get<2>(x[xi]);
    VB ok(2, true);
    times(xi, xj) {
      int j = get<2>(x[xj]);
      if(S[i] < E[j]) {
        ok[c[j]] = false;
      }
    }
    dd i; ok;

    if(ok[0] && ok[1]) {
      c[i] = last[0] <= last[1];
    }
    else if(ok[1]) c[i] = 1;
    else if(ok[0]) c[i] = 0;
    else {
      cout << dict::IMPOSSIBLE ln;
      return;
    }
    last[c[i]] = E[i];
    dd c; last;
  }

  times(N, i) cout << (c[i] ? 'C' : 'J');
  cout ln;
}
