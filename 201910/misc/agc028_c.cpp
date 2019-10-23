#include "base.hpp"
//#include "consts.hpp"

constexpr int INF = 1ll << 60;

void solve() {
// NN(AB)
/* <foxy.memo-area> */
int N;cin>>N;VI A(N);VI B(N);times(N,Ri_0){cin>>A[Ri_0];cin>>B[Ri_0];}
/* </foxy.memo-area> */

  VPII x(N * 2);
  times(N, i) {
    x[i * 2] = { A[i], i * 2 };
    x[i * 2 + 1] = { B[i], i * 2 + 1 };
  }
  sort(iter(x));

  auto f = [&](VI js) {
    VB vis(N);
    bool ac = false, bc = false, c = false;
    int ans = 0;

    for(int j : js) {
      auto p = x[j];
      auto& [k, i] = p;
      ans += k;
      ac = ac || i % 2 == 0;
      bc = bc || i % 2 == 1;
      c = c || vis[i / 2];
      vis[i / 2] = true;
    }

    if(c || !ac || !bc) {
      return ans;
    } else {
      return INF;
    }
  };

  int ans = INF;

  VI js(N); times(N, k) js[k] = k;
  ans = min(ans, f(js));
  js[N - 1] = N;
  ans = min(ans, f(js));
  js[N - 1] = N + 1;
  ans = min(ans, f(js));
  js[N - 2] = N - 1;
  js[N - 1] = N;
  ans = min(ans, f(js));

  if(ans == INF) {
    volatile int k = 0;
    while(1) ++k;
  }
  cout << ans ln;
}
