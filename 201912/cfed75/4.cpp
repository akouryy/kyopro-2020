#include "base.hpp"
//#include "consts.hpp"

void solve() {
  int t; cin >> t;
  times(t, o) {
    int n, s; cin >> n >> s;
    VPII lrs;
    times(n, i) {
      int l, r; cin >> l >> r;
      lrs.PB(make_pair(l, r));
    }
    sort(iter(lrs));

    int ok = 1, ng = s * 2;
    while(abs(ok - ng) > 1) {
      int m = (ok + ng) / 2;

      int a = 0, c = 0;
      rtimes(n, i) {
        int l, r; tie(l, r) = lrs[i];
        if(l > m) {
          ++a;
          c += l;
        } else if(r >= m && a <= n/2) {
          ++a;
          c += m;
        } else {
          c += l;
        }
      }

      if(a > n/2 && c <= s) {
        ok = m;
      } else {
        ng = m;
      }
    }

    cout << ok ln;
  }
}
