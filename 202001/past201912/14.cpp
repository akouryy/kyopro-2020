#include "base.hpp"
//#include "consts.hpp"

void solve() {
// NWCN(LRP)
/* <foxy.memo-area> */
int N;int W;int C;cin>>N;cin>>W;cin>>C;VI L(N);VI R(N);VI P(N);times(N,Ri_0){
cin>>L[Ri_0];cin>>R[Ri_0];cin>>P[Ri_0];}
/* </foxy.memo-area> */

  priority_queue<PII, VPII, greater<PII>> pq;

  int now = 0;

  times(N, i) {
    if(L[i] - C + 1 <= 0) now += P[i];
    else pq.push({ L[i] - C + 1, +P[i] });

    pq.push({ R[i], -P[i] });
  }

  int ans = now;

  while(!pq.empty()) {
    int x = pq.top().first;
    if(x > W - C) break;

    while(!pq.empty() && pq.top().first == x) { now += pq.top().second; pq.pop(); };

    amin(ans, now);
    dd now;
  }

  cout << ans ln;
}
