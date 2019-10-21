#include "base.hpp"
//#include "consts.hpp"

void solve() {
// NN(A)
/* <foxy.memo-area> */
int N;cin>>N;VI A(N);times(N,Ri_0){cin>>A[Ri_0];}
/* </foxy.memo-area> */

  sort(iter(A));

  VI q;
  {
    int c = 1;
    times(N - 1, i) {
      if(A[i] == A[i+1]) {
        ++c;
      } else {
        q.PB(c);
        c = 1;
      }
    }
    q.PB(c);
  }
  sort(iter(q));
  // dd q;

  VI p(size(q)+1);
  times(size(q), i) p[i+1] = p[i] + q[i];

  upto(1, N, k) {
    int ok = 0, ng = N + 1;
    while(abs(ok - ng) > 1) {
      int m = (ok + ng) / 2;
      auto h = leftmost_gt(iter(q), m);
      int x = p[distance(begin(q), h)] + m * distance(h, end(q));
      // dd k; m; distance(begin(q), h); x;
      if(x >= k * m) {
        ok = m;
      } else {
        ng = m;
      }
    }
    cout << ok ln;
  }
}
