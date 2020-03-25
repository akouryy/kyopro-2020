#include "base.hpp"
#include "graph.hpp"
//#include "consts.hpp"

int N;
Graph<int> g(0);

VI X, farthest;

int dfs1(int i, int p) {
  int x = 0;
  for(auto e : g.edges[i]) if(e.to != p) {
    amax(x, dfs1(e.to, i) + e.weight);
  }
  return X[i] = x;
}

void dfs2(int i, int p, int Y) {
  if(i != p && size(g.edges[i]) == 1) {
    farthest[i] = Y;
  } else {
    int a = Y, b = 0;
    for(auto e : g.edges[i]) if(e.to != p) {
      int x = X[e.to] + e.weight;
      if(x > a) {
        b = a;
        a = x;
      } else if(x > b) {
        b = x;
      }
    }
    // dd i; p; a; b;
    amax(farthest[i], a);
    for(auto e : g.edges[i]) if(e.to != p) {
      dfs2(e.to, i, e.weight + (a == X[e.to] + e.weight ? b : a));
    }
  }
}

int cnt(int i, int p, int k, HII& fls) {
  int ret = 0;
  for(auto e : g.edges[i]) if(e.to != p) {
    ret += cnt(e.to, i, k, fls);
  }
  if(size(g.edges[i]) == 1 && fls.find(i) != fls.end() && fls[i] == k) ++ret;
  return ret;
}

void solve() {
  cin >> N;
  g = Graph<int>(N);
  X.resize(N);
  farthest.resize(N);

  times(N-1, i) {
    int A, B; cin >> A >> B;
    g.add_uedge(A-1, B-1, 1);
  }

  string ans(N, '0');
  ans[1-1] = '1';
  if(N > 1) ans[2-1] = '1';

  if(N >= 3) {
    dfs1(0, 0);
    dfs2(0, 0, 0);

    dd X; farthest;
    int diam = *max_element(iter(farthest));

    VPII fl;
    times(N, i) if(size(g.edges[i]) == 1) {
      fl.PB(PII(farthest[i], i));
    }
    sort(iter(fl));
    reverse(iter(fl));
    dd fl;

    if(size(fl) >= 3) {
      int k = fl[2].first;
      if(k % 2 == 1 || fl[0].first != k) {
        ++k;
      } else {
        int c = distance(begin(farthest), min_element(iter(farthest)));
        assert(farthest[c] * 2 == diam);
        HII fls;
        for(auto &p : fl) fls[p.second] = p.first;
        for(auto e : g.edges[c]) {
          if(cnt(e.to, c, k, fls) > 1) {
            dd c; e.to; cnt(e.to, c, k, fls);
            ++k;
            break;
          }
        }
      }
      upto(k, N, i) ans[i-1] = '1';
    } else {
      ans = string(N, '1');
    }
  }

  cout << ans ln;
}
