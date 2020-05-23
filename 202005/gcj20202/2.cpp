#define GCJ_CASE
#include "base.hpp"
#include "graph.hpp"
//#include "consts.hpp"

void solve(int case_id) {
  int C, D; cin >> C >> D;
  VI X(C);
  uptil(1, C, i) cin >> X[i];
  VI U(D), V(D);
  Graph<unit> g(C);
  times(D, j) {
    cin >> U[j] >> V[j]; --U[j]; --V[j];
    g.add_uedge(U[j], V[j], {});
  }

  VI sortedByRevSecond, sortedByRevOrder;
  uptil(1, C, i) {
    if(X[i] > 0) {
      sortedByRevSecond.PB(i);
    } else {
      sortedByRevOrder.PB(i);
    }
  }
  sort(iter(sortedByRevSecond), [&](int i, int j) { return X[i] > X[j]; });
  sort(iter(sortedByRevOrder), [&](int i, int j) { return -X[i] > -X[j]; });

  VI seconds(C);
  int oldSec = 0, oldOrder = 0, cnt = 0;
  while(!sortedByRevOrder.empty()) {
    int oi = sortedByRevOrder.back(); sortedByRevOrder.pop_back();
    int order = -X[oi];
    ++cnt;
    dd order; cnt; oldSec; oldOrder;
    if(order == oldOrder) {
      seconds[oi] = oldSec;
    } else if(order == cnt) {
      seconds[oi] = ++oldSec;
    } else {
      assert(order > cnt);
      times(order - cnt, hoge) {
        int si = sortedByRevSecond.back(); sortedByRevSecond.pop_back();
        int sec = X[si];
        oldSec = seconds[si] = sec;
        dd si; seconds[si];
        ++cnt;
      }
      seconds[oi] = ++oldSec;
    }
    oldOrder = order;
    dd oi; seconds[oi];
  }
  while(!sortedByRevSecond.empty()) {
    int si = sortedByRevSecond.back(); sortedByRevSecond.pop_back();
    int sec = X[si];
    oldSec = seconds[si] = sec;
    dd si; seconds[si];
  }

  times(D, j) {
    int a = abs(seconds[U[j]] - seconds[V[j]]);
    cout << (j ? " " : "") << (a > 0 ? a : 999);
  }
  cout ln;
}
