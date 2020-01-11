#include "base.hpp"
//#include "consts.hpp"
#include "kruskal.hpp"

void solve() {
// NMN(XYC)M(VWD)
/* <foxy.memo-area> */
int N;int M;cin>>N;cin>>M;VI X(N+M);VI Y(N+M);VI C(N+M);times(N+M,Ri_0){cin>>X[Ri_0];
cin>>Y[Ri_0];cin>>C[Ri_0];}
/* </foxy.memo-area> */

  LD ans = 9e99;
  times(1<<M, b) {
    VI mp(N); times(N, i) mp[i] = i;
    times(M, i) if(b&(1<<i)) mp.PB(N+i);

    Graph<LD> g(size(mp));
    times(size(mp), i) times(i, j) {
      LD w = sqrt(LD(
        (X[mp[i]] - X[mp[j]]) * (X[mp[i]] - X[mp[j]]) + (Y[mp[i]] - Y[mp[j]]) * (Y[mp[i]] - Y[mp[j]])));
      if(C[mp[i]] != C[mp[j]]) w *= 10;
      g.add_uedge(i, j, w);

      dd i;j;w;
    }
    auto kr = rab::kruskal(g);
    LD ans2 = 0;
    times(size(mp), i) for(auto& e : kr.edges[i]) {
      ans2 += e.weight;
      dd b; mp; e.from; e.to; e.weight; ans2;
    }
    amin(ans, ans2/2); //undirected
  }

  cout << ans ln;
}
