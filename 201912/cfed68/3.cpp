#include "base.hpp"
//#include "consts.hpp"

void solve() {
  int Q; cin >> Q;
  times(Q, q) {
    string s, t, p; cin >> s >> t >> p;

    HCI pp;
    for(char c : p) ++pp[c];

    int si = 0, sz = size(s);
    for(char c : t) {
      if(si < sz && c == s[si]) {
        ++si;
      } else if(pp[c] > 0) {
        --pp[c];
      } else {
        cout << "NO" ln;
        goto no;
      }
    }
    cout << ((si == sz) ? "YES" : "NO") ln;
    no:;
  }
}
