#include "base.hpp"
#include "consts.hpp"
#include "uf.hpp"

void solve() {
// HWH("S")QQ(XYL)
/* <foxy.memo-area> */
int H;int W;int Q;cin>>H;cin>>W;VS S(H);times(H,Ri_0){cin>>S[Ri_0];}cin>>Q;VI I(
Q);VI J(Q);VI L(Q);times(Q,Ri_0){cin>>I[Ri_0];--I[Ri_0];cin>>J[Ri_0];--J[Ri_0];cin>>L[Ri_0];}
/* </foxy.memo-area> */

  VPII g; times(Q, k) g.PB(make_pair(L[k], k));
  sort(iter(g)); reverse(iter(g));

  WI space(H+1, VI(W+1, 1ll<<60));
  times(H+1, i) space[i][W] = 0;
  times(W+1, j) space[H][j] = 0;
  rtimes(H, i) rtimes(W, j)
  space[i][j] = S[i][j] == '#' ? 0 : 1 + min(min(space[i][j+1], space[i+1][j]), space[i+1][j+1]);
  dd space;

  HIVPII rev;
  times(H, i) times(W, j) rev[space[i][j]].PB(make_pair(i, j));

  VI ans(Q);
  UnionFind<> uf(H * W);
  int l_now = max(H, W) + 1;
  for(auto &tmp : g) {
    int k = tmp.second;
    downto(l_now-1, L[k], l) {
      for(auto &ij : rev[l]) {
        int i, j; tie(i, j) = ij;
        times(4, d) {
          int ii = i + di4[d], jj = j + dj4[d];
          if(0 <= ii && ii < H && 0 <= jj && jj < W && space[ii][jj] >= l) {
            uf.merge(i * W + j, ii * W + jj);
          }
        }
      }
    }
    if(debug) {
      cerr << k ln;
      times(H, i) {
        times(W, j) cerr << uf.root(i * W + j) sp;
        cerr ln;
      }
    }
    l_now = L[k];
    ans[k] = uf.zs[uf.root(I[k] * W + J[k])];
  }

  times(Q, k) cout << ans[k] ln;
}
