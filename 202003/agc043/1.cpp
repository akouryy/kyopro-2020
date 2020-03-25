#include "base.hpp"
//#include "consts.hpp"

void solve() {
// HWH("S")
/* <foxy.memo-area> */
int H;int W;cin>>H;cin>>W;VS S(H);times(H,Ri_0){cin>>S[Ri_0];}
/* </foxy.memo-area> */

  WI cost(H, VI(W, 1LL<<62));
  cost[0][0] = S[0][0] == '#';
  times(H, i) times(W, j) {
    if(j < W-1) amin(cost[i][j+1], cost[i][j] + (S[i][j] == '.' && S[i][j+1] == '#'));
    if(i < H-1) amin(cost[i+1][j], cost[i][j] + (S[i][j] == '.' && S[i+1][j] == '#'));
  }

  cout << cost[H-1][W-1] ln;
}
