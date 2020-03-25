#include "base.hpp"
//#include "consts.hpp"

void solve() {
// NMN(D)M(-U-V)
/* <foxy.memo-area> */
int N;int M;cin>>N;cin>>M;VI D(N);times(N,Ri_0){cin>>D[Ri_0];}VI U(M);VI V(M);
times(M,Ri_0){cin>>U[Ri_0];--U[Ri_0];cin>>V[Ri_0];--V[Ri_0];}
/* </foxy.memo-area> */

  WI edges(N);
  times(M, j) {
    edges[U[j]].PB(V[j]);
    edges[V[j]].PB(U[j]);
  }

  VB used(N);
  VB black(N);
  HPIII costs;

  VPII DI(N); times(N, i) DI[i] = make_pair(D[i], i);
  sort(iter(DI));

  times(N, h) {
    int d, i; tie(d, i) = DI[h];
    if(used[i]) continue;
    used[i] = true;
    int deg = 0;
    for(int j : edges[i]) deg += used[j];

    if(deg == 0) {
      int fr = -1;
      for(int j : edges[i]) if(D[i] == D[j]) fr = j;
      if(fr == -1) {
        cout << -1 ln;
        return;
      }
      black[i] = true;
      used[fr] = true;
      black[fr] = false;
      costs[make_pair(i, fr)] = costs[make_pair(fr, i)] = d;

      for(int j : edges[fr]) if(used[j]) {
        costs[make_pair(j, fr)] = costs[make_pair(fr, j)] = d;
      }
    } else if(deg == 1) {
      int nb = -1;
      for(int j : edges[i]) if(used[j]) nb = j;
      assert(nb >= 0);
      if(D[nb] == D[i]) {
        black[i] = !black[nb];
        costs[make_pair(i, nb)] = costs[make_pair(nb, i)] = D[i];
      } else {
        black[i] = black[nb];
        costs[make_pair(i, nb)] = costs[make_pair(nb, i)] = D[i] - D[nb];
      }
    } else {
      int nb = -1;
      for(int j : edges[i]) if(used[j] && D[i] != D[j]) nb = j;
      if(nb == -1) {
        int fr = -1;
        for(int j : edges[i]) if(used[j]) fr = j;
        assert(fr >= 0);
        black[i] = !black[fr];
        for(int j : edges[i]) if(used[j]) {
          costs[make_pair(i, j)] = costs[make_pair(j, i)] = D[i];
        }
      } else {
        black[i] = black[nb];
        for(int j : edges[i]) if(used[j]) {
          costs[make_pair(i, j)] = costs[make_pair(j, i)] = (j == nb ? D[i] - D[nb] : D[i]);
        }
      }
    }
  }

  dd black; costs;

  for(bool b : black) cout << (b ? 'B' : 'W');
  cout ln;
  times(M, j) cout << costs[make_pair(U[j], V[j])] ln;

  // cout << ans ln;
}
