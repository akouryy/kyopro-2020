#define GCJ_CASE
#include "base.hpp"
//#include "consts.hpp"

void solve(int cid) {
  int n; cin >> n;

  int imax = 1;
  while((1 << imax-1) <= n) ++imax;
  --imax;

  cout ln;

  VPII ans;

  bool to_r = true;
  downto(imax, 1, i) {
    dd i; n; 1 << i-1;
    if(n >= (1 << i-1) + i-1) {
      if(to_r) {
        upto(1, i, j) ans.EB(i, j);
      } else {
        downto(i, 1, j) ans.EB(i, j);
      }
      to_r = !to_r;
      n -= 1 << i-1;
    } else {
      if(to_r) {
        ans.EB(i, 1);
      } else {
        ans.EB(i, i);
      }
      --n;
    }
  }

  dd n; ans;
  rtimes(size(ans), i) cout << ans[i].first sp << ans[i].second ln;
  upto(imax+1, imax+n, i) cout << i sp << 1 ln;
  assert(n >= 0);
}
