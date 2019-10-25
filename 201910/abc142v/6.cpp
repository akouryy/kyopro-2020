#include "base.hpp"
#include "graph.hpp"

void solve() {
// NMM(-A-B)
/* <foxy.memo-area> */
int N;int M;cin>>N;cin>>M;VI A(M);VI B(M);times(M,Ri_0){cin>>A[Ri_0];--A[Ri_0];
cin>>B[Ri_0];--B[Ri_0];}
/* </foxy.memo-area> */

  Graph<unit> g(N);
  times(M, i) g.add_dedge(A[i], B[i], {});

  VB vis(N);
  VB onPath(N);
  VI loop;
  bool looping = false;

  function<bool(int)> loop_dfs = [&](int i) {
    // dd i; onPath[i]; vis[i];
    if(onPath[i]) {
      loop.PB(i);
      return looping = true;
    } else if(vis[i]) {
      return false;
    }
    vis[i] = onPath[i] = true;
    for(auto e : g.edges[i]) {
      bool l = loop_dfs(e.to);
      // dd i; e.to; l; looping; loop;
      if(l) {
        if(looping) {
          if(loop[0] == i) {
            looping = false;
          } else {
            loop.PB(i);
          }
        }
        return true;
      }
    }
    onPath[i] = false;
    return false;
  };

  times(N, i) {
    vis = VB(N);
    onPath = VB(N);
    loop = VI();
    looping = false;
    if(loop_dfs(i)) goto found_loop;
  }

  { // loop not found
    cout << -1 ln;
    return;
  }

  found_loop:

  dd loop;


  {
    retry_shortcut:

    // lookup shortcut
    set<int> loop_set(iter(loop));
    int z = size(loop);
    times(z, i) {
      for(auto e : g.edges[loop[i]]) {
        if(e.to != loop[(i - 1 + z) % z] && loop_set.find(e.to) != loop_set.end()) {
          // use shortcut (i, e.to)
          dd i; e.to; loop;

          VI lq;
          int j = distance(begin(loop), find(iter(loop), e.to));
          if(i < j) {
            upto(i, j, k) lq.PB(loop[k]);
          } else {
            upto(0, j, k) lq.PB(loop[k]);
            uptil(i, z, k) lq.PB(loop[k]);
          }
          dd lq;
          swap(loop, lq);

          goto retry_shortcut;
        }
      }
    }
  }

  cout << size(loop) ln;
  times(size(loop), i) cout << loop[i] + 1 ln;
}
