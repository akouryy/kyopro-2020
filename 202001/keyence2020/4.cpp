#include "base.hpp"
//#include "consts.hpp"

void solve() {
// NN(A)N(B)
/* <foxy.memo-area> */
int N;cin>>N;VI A(N);times(N,Ri_0){cin>>A[Ri_0];}VI B(N);times(N,Ri_0){cin>>B[
Ri_0];}
/* </foxy.memo-area> */

  VI c, d;
  VPIB cd;
  int ans = 1ll<<60;
  times(1<<N, h) {
    c.clear(); d.clear(); cd.clear();
    times(N, i) {
      if(h & (1<<i)) {
        c.PB(i%2 ? B[i] : A[i]);
        cd.PB(make_pair(i%2 ? B[i] : A[i], false));
      } else {
        d.PB(i%2 ? A[i] : B[i]);
        cd.PB(make_pair(i%2 ? A[i] : B[i], true));
      }
    }
    if(size(c) != (N+1)/2) continue;
    dd 1;cd;

    int cnt = 0;
    times(N, ii) times(N-1-ii, j) {
      if(cd[j].first > cd[j+1].first) {
        swap(cd[j], cd[j+1]);
        ++cnt;
      }
    }
    dd 2;cd;
    times(N, i) if(cd[i].second != i%2) {
      int j = i;
      while(cd[j].second != i%2) ++j;
      downto(j-1, i, k) {
        swap(cd[k], cd[k+1]);
        ++cnt;
      }
    }
    times(N-1, i) if(cd[i].first > cd[i+1].first) goto ng;

    ans = min(ans, cnt);
    dd 3;cd; cnt;

    ng:;
  }

  cout << (ans == 1ll<<60 ? -1 : ans) ln;
}
