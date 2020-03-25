#include "base.hpp"
#include "graph.hpp"
//#include "consts.hpp"

int N;
Graph<int> g(0);
HPIII w;
VI D;

int init(int i, int p) {
  int x = D[i];
  for(auto e : g.edges[i]) if(e.to != p) {
    int c = init(e.to, i);
    w[PII(i, e.to)] = c;
    w[PII(e.to, i)] = -c;
    x += c;
  }
  return x;
}

void solve() {
  cin >> N;
  g = Graph<int>(N);

  times(N-1, i) {
    int A, B; cin >> A >> B;
    g.add_uedge(A-1, B-1, 1);
  }

  D.resize(N);
  VI Aa(N);
  times(N, i) cin >> Aa[i];
  times(N, i) {
    int B; cin >> B;
    D[i] = B - Aa[i];
  }
  dd D;

  init(0, 0);

  int ans = 0;

  for(auto &p : w) {
    dd p;
  }

  while(true) {
    int add = 0;
    VI ks(N);
    times(N, i) {
      for(auto e : g.edges[i]) {
        amax(ks[i], w[PII(i, e.to)]);
      }
      add += ks[i];
    }
    dd ks;
    times(N, i) {
      for(auto e : g.edges[i]) {
        w[PII(i, e.to)] -= ks[i];
        w[PII(e.to, i)] += ks[i];
      }
    }

    if(add == 0) break;
    ans += add;
  }

  cout << ans ln;
}
