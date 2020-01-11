#include "base.hpp"
//#include "consts.hpp"

struct Ranges {
  set<PII> ranges;

  void add(int a, int b) { /* [a, b) */
    if(debug) {
      dd a; b;
      for(auto p : ranges) cerr << p;
      cerr ln;
    }
    {
      /*- [a,b)が完全に覆っている区間を除去 */
      auto it = leftmost_ge(iter(ranges), PII(a, LLONG_MIN));
      auto iu = it;
      while(iu != ranges.end() && iu->second <= b) ++iu;
      ranges.erase(it, iu);
    }
    {
      /*- aを含んでいる区間を除去、aを更新して統合 */
      auto x = rightmost_lt(iter(ranges), PII(a, LLONG_MIN));
      if(x != ranges.end()) {
        dd *x;
        int l1 = x->first, r1 = x->second;
        if(r1 >= a) {
          ranges.erase(x);
          a = l1;
          if(r1 >= b) b = r1;
        }
      }
    }
    {
      /*- bを含んでいる区間を除去、bを更新して統合 */
      auto y = rightmost_le(iter(ranges), PII(b, LLONG_MIN));
      if(y != ranges.end()) {
        dd *y;
        int l2 = y->first, r2 = y->second;
        if(r2 > b) {
          ranges.erase(y);
          b = r2;
          if(l2 <= a) a = l2;
        }
      }
    }
    ranges.insert(PII(a, b));
  }
};

void solve() {
  int N,X,D;cin>>N>>X>>D;

  if(D < 0) {
    D = -D;
    X -= (N - 1) * D;
  } else if(D == 0) {
    cout << (X == 0 ? 1 : N+1) ln;
    return;
  }

  map<int, Ranges> m;

  upto(0, N, k) {
    int xx = (2 * k - N) * X;
    m[modulo(xx, 2 * D)].add(
      divide(xx, D) + /* D * */ (2 * k * (k - 1) - N * (N - 1)) / 2,
      divide(xx, D) + /* D * */ (N * (N - 1) - 2 * (N - k) * (N - k - 1)) / 2 + (2 /* * D */)
    );
  }

  int ans = 0;
  for(auto &a : m) {
    for(auto &range : a.second.ranges) {
      dd a.first; range;
      int l = range.first, r = range.second;
      assert((r - l) % (2 /* * D */) == 0);
      ans += (r - l) / (2 /* * D */);
      dd a.first; l; r; (r - l) / (2 /* * D */);
    }
  }

  cout << ans ln;
}
