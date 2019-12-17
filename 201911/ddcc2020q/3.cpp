#include "base.hpp"
//#include "consts.hpp"

void solve() {
// HWKH("S")
/* <foxy.memo-area> */
int H;int W;int K;cin>>H;cin>>W;cin>>K;VS S(H);times(H,Ri_0){cin>>S[Ri_0];}
/* </foxy.memo-area> */

  WI ans(H, VI(W));

  int c = 0;

  times(H, i) times(W, j) if(S[i][j] == '#') {
    ++c;
    ans[i][j] = c;
    downto(i-1, 0, a) {
      if(ans[a][j] || S[a][j] == '#') break;
      ans[a][j] = c;
    }
    uptil(i+1, H, a) {
      if(ans[a][j] || S[a][j] == '#') break;
      ans[a][j] = c;
    }
  }

  times(H, i) times(W, j) if(ans[i][j]) {
    downto(j-1, 0, b) {
      if(ans[i][b]) break;
      ans[i][b] = ans[i][j];
    }
    uptil(j+1, W, b) {
      if(ans[i][b]) break;
      ans[i][b] = ans[i][j];
    }
  }

  cout << ans ln;
}
