#include "base.hpp"
#include "consts.hpp"

void solve() {
// HWH("A")
/* <foxy.memo-area> */
int H;int W;cin>>H;cin>>W;VS A(H);times(H,Ri_0){cin>>A[Ri_0];}
/* </foxy.memo-area> */

  WB ok(H, VB(W));

  VPII v, w;
  times(H, i) times(W, j) {
    if(ok[i][j] = A[i][j] == '#') v.PB({i, j});
  }

  int ans = -1;
  while(!v.empty()) {
    ++ans;

    for(auto &p : v) {
      int i = p.first, j = p.second;
      times(4, d) {
        int ii = i + di4[d], jj = j + dj4[d];
        if(0 <= ii && ii < H && 0 <= jj && jj < W && !ok[ii][jj]) {
          ok[ii][jj] = true;
          w.PB({ii, jj});
        }
      }
    }

    swap(v, w);
    w.clear();
  }

  cout << ans ln;
}
