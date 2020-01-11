#define INF (1ll<<60)

#include "base.hpp"
#include "consts.hpp"
#include "dijkstra.hpp"

void solve() {
// HWH(W(A))
/* <foxy.memo-area> */
int H;int W;cin>>H;cin>>W;WI A(H,VI(W));times(H,Ri_0){times(W,Ri_1){cin>>A[Ri_0]
[Ri_1];}}
/* </foxy.memo-area> */

  Graph<int> g(H*W);
  times(H, i) times(W, j) times(4, d) {
    int ii = i + di4[d], jj = j + dj4[d];
    if(0 <= ii && ii < H && 0 <= jj && jj < W) {
      g.add_dedge(i*W+j, ii*W+jj, A[ii][jj]);
    }
  }

  VI lb = dijkstra(g, (H-1)*W+0), rb = dijkstra(g, (H-1)*W+(W-1)), rt = dijkstra(g, 0*W+(W-1));

  int ans = 1ll << 60;
  times(H, mi) times(W, mj) {
    int m = mi*W+mj;
    amin(ans, lb[m] + rb[m] + rt[m] - 2 * A[mi][mj]);
  }

  cout << ans ln;
}
