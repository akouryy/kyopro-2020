#include "base.hpp"
#include "graph.hpp"

void solve() {
/* <foxy.memo-area> */
int N;cin>>N;VI A(N);VI B(N);times(N-1,Ri_0){cin>>A[Ri_0];--A[Ri_0];cin>>B[Ri_0];--B[Ri_0];}
/* </foxy.memo-area> */

  Graph<int> tree(N);
  times(N-1, j) tree.add_uedge(A[j], B[j], 0);

  VI dist(N);
  int farthest = 0, farthest_dist = 0;
  function<void(int, int, int)> tree_center_dfs = [&](int i, int p, int d) {
    dist[i] = d;
    for(auto &e : tree.edges[i]) if(e.to != p) {
      tree_center_dfs(e.to, i, d + 1);
    }
    if(amax(farthest_dist, d)) farthest = i;
  };

  tree_center_dfs(0, 0, 0);
  farthest_dist = 0;
  tree_center_dfs(farthest, farthest, 0);
  int diam = farthest_dist;
  VI dist1 = dist;
  int v1 = farthest;
  farthest_dist = 0;
  tree_center_dfs(farthest, farthest, 0);
  VI &dist2 = dist;
  int v2 = farthest;

  dd diam; v1; v2; dist1; dist2;

  VI centers;
  times(N, i) {
    if((dist1[i] == diam / 2 && dist2[i] == (diam + 1) / 2) ||
       (dist2[i] == diam / 2 && dist1[i] == (diam + 1) / 2)) {
      centers.PB(i);
    }
  }

  cout << diam / 2 + 1 sp;


  auto calc = [&](VI lv) {
    VB vis(N);
    int ans = size(lv);

    VI lw;

    times(diam / 2, h) {
      // [invar] lw: empty
      int mx = 1;
      for(int i : lv) vis[i] = true;
      for(int i : lv) {
        int k = 0;
        for(auto &e : tree.edges[i]) if(!vis[e.to]) {
          ++k;
          lw.PB(e.to);
        }
        amax(mx, k);
      }
      ans *= mx;
      dd h; lv; mx;
      swap(lv, lw);
      lw.clear();
    }

    return ans;
  };

  switch(size(centers)) {
    case 1: {
      int ans = calc(centers);
      for(auto &e : tree.edges[centers[0]]) {
        amin(ans, calc({ centers[0], e.to }));
      }
      cout << ans;
      break;
    }
    case 2:
      cout << calc(centers);
      break;
    default:
      if(debug) {
        dd centers;
      } else {
        while(1) cout << 1;
      }
  }
}
