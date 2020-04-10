#include "base.hpp"
//#include "consts.hpp"

bool fetch(int i) {
  cout << i+1 << endl;
  int ret; cin >> ret; return ret;
}

void solve() {
  int T, B; cin >> T >> B;

  times(T, caseid) {
    int same_first = -1, diff_first = -1;
    VB ans(B);

    int cnt = 0;
    times(B/2, i) {
      int x = fetch(i), y = fetch(B-1-i); cnt += 2;
      if(x == y && same_first == -1) same_first = i;
      if(x != y && diff_first == -1) diff_first = i;

      ans[i] = x;
      ans[B-1-i] = y;

      if(cnt % 10 == 0) {
        int s = max(0ll, same_first), d = max(0ll, diff_first);
        bool ss = ans[s] == fetch(s), dd = ans[d] == fetch(d);
        if(ss && dd) {
          // nop
        } else if(ss && !dd) {
          // rev
          reverse(iter(ans));
        } else if(!ss && dd) {
          // ~rev
          reverse(iter(ans));
          times(B, i) ans[i] = !ans[i];
        } else {
          // ~
          times(B, i) ans[i] = !ans[i];
        }
        cnt += 2;
      }
    }
    dd ans;
    times(B, i) cout << int(ans[i]);
    cout << endl;

    string yes; cin >> yes;
  }
}
