#include "base.hpp"
//#include "consts.hpp"

void solve() {
// NMKN("D")
/* <foxy.memo-area> */
int N;int M;int K;cin>>N;cin>>M;cin>>K;VS D(N);times(N,Ri_0){cin>>D[Ri_0];}
/* </foxy.memo-area> */

  // VI dp(K+1), dq(K+1);
  int *dp = new int[K+1], *dq = new int[K+1];
  times(K+1, i) dp[i] = dq[i] = 0;
  int *zpl = new int[M+1], *zpr = new int[M+1], *zp = new int[M+1];
  times(N, d) {
    swap(dp, dq);

    VI os;
    times(M, i) if(D[d][i] == '1') os.PB(i);
    int cnt = size(os), dfl = os[cnt-1] - os[0] + 1;
    if(cnt == 0) {
      swap(dp, dq);
      continue;
    }

    // VI zpl(cnt+1), zpr(cnt+1);
    times(cnt, i) {
      zpl[i] = os[i] - os[0];
      zpr[cnt-1-i] = os[cnt-1] - os[i];
    }
    zpl[cnt] = zpr[cnt] = dfl;

    // VI zp(cnt+1, dfl);
    fill(zp, zp+cnt+1, 0);
    times(cnt+1, i) times(cnt+1-i, j) {
      zp[i+j] = max(zp[i+j], zpl[i] + zpr[j]);
    }
    times(cnt+1, i) zp[i] = max(0ll, dfl - zp[i]);

    // fill(dp, dp+K+1, 1ll << 60);
    upto(0, K, r) {
      int d = 1ll << 60;
      upto(0, min(cnt, r), v) {
        d = min(d, dq[r-v] + zp[v]);
      }
      dp[r] = d;
    }
    // dd zpl; zpr; zp; dp;
  }

  // dd dp;
  cout << *min_element(dp, dp+K+1) ln;
}
