#include "base.hpp"
//#include "consts.hpp"

void solve() {
  int N; string S; cin >> N >> S;

  int depth = 0;
  {
    int now = 0;
    for(char c : S) {
      if(c == '(') {
        amax(depth, ++now);
      } else {
        --now;
      }
    }
    assert(now == 0);
  }
  dd depth;

  VI ans(N);
  int now = 0;
  times(N, i) {
    char c = S[i];
    if(c == '(') {
      ++now;
    }
    dd now;
    ans[i] = (now > depth / 2);
    if(c == ')') {
      --now;
    }
  }

  times(N, i) cout << ans[i];
  cout ln;
}
