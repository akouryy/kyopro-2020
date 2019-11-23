#define MOD 998244353
#include "base.hpp"
#include "graph.hpp"
//#include "consts.hpp"

struct pyon {
  int alpha; int beta;
  pyon(): alpha(0), beta(0) {}
  pyon(int a, int b): alpha(a), beta(b) {}

  pyon operator+(const pyon& p) {
    return pyon(alpha + p.alpha, beta + p.beta);
  }

  friend ostream& operator<<(ostream& o, const pyon& p) {
    return o << p.alpha << "::" << p.beta;
  }
};

void solve() {
// -NN("A")
/* <foxy.memo-area> */
int N;cin>>N;--N;VS A(N);times(N,Ri_0){cin>>A[Ri_0];}
/* </foxy.memo-area> */

  Graph<bool> g(N + 2);
  HPIII edges;

  times(N, i) times(N, j) {
    int p = abs(i - j), q = N + 1 - abs(N - 1 - (i + j));

    if(A[i][j] == 'o') {
      int& z = edges[{min(p, q), max(p, q)}];
      if(z == 0) {
        z = 1;
        dd p; q; true;
        g.add_uedge(p, q, true);
        // dd p; q;
      } else if(z == 2) {
        cout << 0 ln;
        return;
      }
    } else if(A[i][j] == 'x') {
      int& z = edges[{min(p, q), max(p, q)}];
      if(z == 0) {
        z = 2;
        dd p; q; false;
        g.add_uedge(p, q, false);
        // dd p; q;
      } else if(z == 1) {
        cout << 0 ln;
        return;
      }
    }
  }

  VB vis(N + 2), val(N + 2);
  function<pyon(int, bool, pyon)> dfs = [&](int i, bool b, pyon p) {
    if(vis[i]) return b == val[i] ? p : pyon();
    vis[i] = true;
    val[i] = b;
    dd i; val[i];
    if(b) swap(p.alpha, p.beta);

    for(auto &e : g.edges[i]) {
      p = dfs(e.to, b ^ e.weight, p);
    }
    return p;
  };

  vec<pyon> pyons(N + 2);
  times(N + 2, i) if(!vis[i]) pyons[i] = dfs(i, false, pyon(1, 0));
  vis = VB(N + 2);
  times(N + 2, i) if(!vis[i]) pyons[i] = pyons[i] + dfs(i, true, pyon(1, 0));

  dd pyons;

  mint ans = 1_m;

  times(2, m) {
    mint sa = 1_m, sb = 0_m;
    vis = VB(N + 2);
    times(N + 2, i) if(i % 2 == m) if(!vis[i]) {
      dfs(i, false, pyon(0, 0)); // visit only

      tie(sa, sb) = make_pair(
        sa * mint(pyons[i].alpha) + sb * mint(pyons[i].beta),
        sa * mint(pyons[i].beta) + sb * mint(pyons[i].alpha)
      );
    }

    ans *= sa;
  }

  cout << ans ln;
}
