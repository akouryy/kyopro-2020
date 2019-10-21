#include "base.hpp"
//#include "consts.hpp"

void solve() {
// NN(L)
/* <foxy.memo-area> */
int N;cin>>N;VI L(N);times(N,Ri_0){cin>>L[Ri_0];}
/* </foxy.memo-area> */

  int ans = 0;

  sort(iter(L));

  times(N, i) times(N, j) if(i != j) {
    int a = L[i], b = L[j];
    int x = abs(a - b), y = a + b;

    // cerr <<

    ans += distance(leftmost_gt(iter(L), x), leftmost_ge(iter(L), y));

    ans -= x < a && a < y;
    ans -= x < b && b < y;
  }

  cout << ans / 6 ln;
}
