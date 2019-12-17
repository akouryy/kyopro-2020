#include "base.hpp"
//#include "consts.hpp"

void solve() {
  int Q; cin >> Q;

  times(Q, o) {
    int n; cin >> n;
    int cnt0 = 0, cnt1 = 0, hasOdd = 0;

    times(n, i) {
      string s; cin >> s;
      if(size(s) % 2 == 1) hasOdd = 1;
      for(char c : s) {
        cnt0 += c == '0';
        cnt1 += c == '1';
      }
    }

    if(cnt0 % 2 == 0 || cnt1 % 2 == 0 || hasOdd) {
      cout << n ln;
    } else {
      cout << n - 1 ln;
    }
  }
}
