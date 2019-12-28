#include "base.hpp"
//#include "consts.hpp"

void solve() {
  int N, X; cin >> N >> X;
  VI A(N); times(N, i) {cin >> A[i]; --A[i];}

  VI rmins(X, 1ll << 60);
  int lm = X, rm = 0;
  {
    int rmin = 1ll << 60;
    rtimes(N, i) {
      amin(rmin, A[i]);
      amin(rmins[A[i]], rmin);
      if(rmin < A[i]) {
        amin(lm, A[i]+1);
        amax(rm, rmin);
      }
    }
  }
  rtimes(X-1, i) amin(rmins[i], rmins[i+1]);
  dd A; rmins;

  {
    int g = 0;
    times(N, i) {
      amax(g, A[i]);
      if(g > A[i]) amax(rm, A[i]);
    }
  }

  int ans = 0, r = rm;
  times(lm, l) {
    while(r < l || r + 1 < X && rmins[r + 1] < l) ++r;
    ans += X - r;
    dd l; r; ans;
  }

  cout << ans ln;
}
