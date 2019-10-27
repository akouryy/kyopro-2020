#include "base.hpp"
#include "consts.hpp"
#include "graph.hpp"

void solve() {
/* <foxy.memo-area> */
int N;cin>>N;VI A(N);VI B(N);times(N-1,Ri_0){cin>>A[Ri_0];--A[Ri_0];cin>>B[Ri_0];
--B[Ri_0];}
/* </foxy.memo-area> */
  Graph<unit> tree(N);
  times(N-1, j) tree.add_uedge(A[j], B[j], {});

// 直径
  VI dist(N);
  int farthest = 0, farthest_dist = 0;
  function<void(int, int, int)> diam_dfs = [&](int i, int p, int d) {
    dist[i] = d;
    for(auto &e : tree.edges[i]) if(e.to != p) {
      diam_dfs(e.to, i, d + 1);
    }
    if(amax(farthest_dist, d)) farthest = i;
  };

  diam_dfs(0, 0, 0);
  farthest_dist = 0;
  diam_dfs(farthest, farthest, 0);
  int diam = farthest_dist;
// /直径

  cout << (diam % 3 == 1 ? dict::Second : dict::First) ln;
}
