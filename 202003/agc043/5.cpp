#include "base.hpp"
#include "consts.hpp"

void solve() {
// N"A"
/* <foxy.memo-area> */
int N;string A;cin>>N;cin>>A;
/* </foxy.memo-area> */

  times(1<<N, b) {
    times(1<<N, i) {
      int s = 1;
      times(N, j) if((i >> j) & 1) s &= (b >> j) & 1;
      if(A[i] - '0' != s) goto ng;
    }
    {
      dd b;
      cout << dict::Possible ln;
      VPII ans;
      ans.PB(PII(0, 0));
      times(N, j) {
        if((b >> j) & 1) {
          ans.PB(PII(j+1, 0));
        } else {
          ans.PB(PII(j, 1));
          ans.PB(PII(j+1, 1));
          ans.PB(PII(j+1, 0));
        }
      }
      rtimes(N, j) {
        ans.PB(PII(j, 0));
      }
      cout << size(ans)-1 ln;
      times(size(ans), i) {
        cout << ans[i].first sp << ans[i].second ln;
      }
      return;
    }
    ng:;
  }

  cout << dict::Impossible ln;
}
