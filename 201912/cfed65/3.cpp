#include "base.hpp"
#include "uf.hpp"

void solve() {
  int N, M; cin >> N >> M;
  UnionFind<> uf(N);

  times(M, h) {
    int K; cin >> K;
    VI grp(K);
    times(K, i) {cin >> grp[i]; --grp[i];}
    if(K > 0) {
      uptil(1, K, i) {
        uf.merge(grp[0], grp[i]);
      }
    }
  }

  times(N, i) {
    cout << (i ? " " : "") << uf.zs[uf.root(i)];
  }
  cout ln;
}
