#include "base.hpp"
//#include "consts.hpp"

#undef size
/* begin https://ei1333.github.io/luzhiled/snippets/tree/doubling-lowest-common-ancestor.html
   (Unlicense)
 */
template< typename G >
struct DoublingLowestCommonAncestor {
  const int LOG;
  vector< int > dep;
  const G &g;
  vector< vector< int > > table;

  DoublingLowestCommonAncestor(const G &g) : g(g), dep(g.size()), LOG(32 - __builtin_clz(g.size())) {
    table.assign(LOG, vector< int >(g.size(), -1));
  }

  void dfs(int idx, int par, int d) {
    table[0][idx] = par;
    dep[idx] = d;
    for(auto &to : g[idx]) {
      if(to != par) dfs(to, idx, d + 1);
    }
  }

  void build() {
    dfs(0, -1, 0);
    for(int k = 0; k + 1 < LOG; k++) {
      for(int i = 0; i < table[k].size(); i++) {
        if(table[k][i] == -1) table[k + 1][i] = -1;
        else table[k + 1][i] = table[k][table[k][i]];
      }
    }
  }

  int query(int u, int v) {
    if(dep[u] > dep[v]) swap(u, v);
    for(int i = LOG - 1; i >= 0; i--) {
      if(((dep[v] - dep[u]) >> i) & 1) v = table[i][v];
    }
    if(u == v) return u;
    for(int i = LOG - 1; i >= 0; i--) {
      if(table[i][u] != table[i][v]) {
        u = table[i][u];
        v = table[i][v];
      }
    }
    return table[0][u];
  }
};

/* end https://ei1333.github.io/luzhiled/snippets/tree/doubling-lowest-common-ancestor.html */

void solve() {
int N;cin>>N;
VI P(N+1);times(N,Ri_0){cin>>P[Ri_0+1];}
int Q;cin>>Q;
VI A(Q);VI B(Q);times(Q,Ri_0){cin>>A[Ri_0];cin>>B[Ri_0];}

  WI children(N+1);
  upto(1, N, i) {
    children[P[i] == -1 ? 0 : P[i]].PB(i); // 0:会長
  }

  DoublingLowestCommonAncestor<WI> lca(children);
  lca.build();

  times(Q, i) {
    cout << (lca.query(A[i], B[i]) == B[i] ? "Yes" : "No") ln;
  }
}
