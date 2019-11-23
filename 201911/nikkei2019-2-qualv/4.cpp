#include "base.hpp"

constexpr int INF = 1ll << 60;
#include "dijkstra.hpp"
//#include "consts.hpp"

void solve() {
// NMM(-L-RC)
/* <foxy.memo-area> */
int N;int M;cin>>N;cin>>M;VI L(M);VI R(M);VI C(M);times(M,Ri_0){cin>>L[Ri_0];--L
[Ri_0];cin>>R[Ri_0];--R[Ri_0];cin>>C[Ri_0];}
/* </foxy.memo-area> */

  Graph<int> g(N);
  times(N-1, i) g.add_dedge(i+1, i, 0);

  times(M, j) g.add_dedge(L[j], R[j], C[j]);

  auto dj = dijkstra(g, 0);

  cout << (dj[N-1] == INF ? -1 : dj[N-1]) ln;
}
