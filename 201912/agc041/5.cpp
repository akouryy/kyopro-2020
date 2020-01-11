#include "base.hpp"
//#include "consts.hpp"

void solve() {
  int N, M, T; cin >> N >> M >> T;
  VI X(M), Y(M);times(M, i){cin>>X[i]>>Y[i]; --X[i];--Y[i];}
  if(T == 2) {
    if(N == 2) {
      cout << -1 ln;
      return;
    }
    VI cnt(N, 1);
    VI goal(N);
    VC ans(M);
    times(N, i) goal[i] = i;
    rtimes(M, j) {
      int a = goal[X[j]], b = goal[Y[j]];
      if(cnt[a] >= N - 1) {
        ans[j] = 'v';
        goal[X[j]] = b;
        --cnt[a];
        ++cnt[b];
      } else {
        ans[j] = '^';
        goal[Y[j]] = a;
        --cnt[b];
        ++cnt[a];
      }
    }
    times(M, j) cout << (char)ans[j];
    cout ln;
  } else {
    // [復] 解説を見てbitsetを使うことを知った
    vec<bitset<50000>> a(N);
    times(N, i) a[i].set(i, true);
    rtimes(M, j) {
      a[X[j]] = a[Y[j]] |= a[X[j]];
    }
    times(N, i) a[0] &= a[i];
    if(a[0].none()) {
      cout << -1 ln;
      return;
    }
    int goal;
    times(N, i) if(a[0][i]) goal = i;
    dd goal;
    VC ans(M);
    VB ok(N);
    ok[goal] = true;
    rtimes(M, j) {
      if(ok[X[j]]) {
        ans[j] = '^';
        ok[Y[j]] = true;
      } else {
        ans[j] = 'v';
        ok[X[j]] = ok[X[j]] || ok[Y[j]];
      }
    }
    times(M, j) cout << (char)ans[j];
    cout ln;
  }
}
