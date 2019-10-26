#include "base.hpp"
//#include "consts.hpp"

void solve() {
// NMN(A)
/* <foxy.memo-area> */
int N;int M;cin>>N;cin>>M;VI A(N);times(N,Ri_0){cin>>A[Ri_0];}
/* </foxy.memo-area> */

  priority_queue<int> pq;
  times(N, i) pq.push(A[i]);

  times(M, i) {
    int a = pq.top(); pq.pop();
    pq.push(a / 2);
  }

  int ans = 0;
  times(N, i) ans += pq.top(), pq.pop();

  cout << ans ln;
}
