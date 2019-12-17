#include "base.hpp"
//#include "consts.hpp"

void solve() {
  int t; cin >> t;
  times(t, o) {
    string a; cin >> a;
    int n = size(a);

    VC odd, even; odd.reserve(n); even.reserve(n);

    rtimes(n, i) {
      if(a[i] % 2 == 0) {
        even.PB(a[i]);
      } else {
        odd.PB(a[i]);
      }
    }

    times(n, i) {
      if(even.empty() || !odd.empty() && odd.back() < even.back()) {
        cout << odd.back();
        odd.pop_back();
      } else {
        cout << even.back();
        even.pop_back();
      }
    }
    cout ln;
  }
}
