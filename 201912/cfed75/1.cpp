#include "base.hpp"
//#include "consts.hpp"

void solve() {
  int t; cin >> t;
  times(t, o) {
    string s; cin >> s;
    bool ok[26];
    times(26, i) ok[i] = 0;

    char c = s[0];
    int n = 1;

    uptil(1, size(s), i) {
      if(c == s[i]) {
        ++n;
      } else {
        if(n % 2 == 1) ok[c - 'a'] = 1;
        n = 1;
        c = s[i];
      }
    }
    if(n % 2 == 1) ok[c - 'a'] = 1;

    times(26, i) if(ok[i]) cout << char('a' + i);
    cout ln;
  }

}
