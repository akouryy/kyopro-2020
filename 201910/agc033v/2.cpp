#include "base.hpp"
#include "consts.hpp"

void solve() {
// HWN-I-J"S""T"
/* <foxy.memo-area> */
int H;int W;int N;int I;int J;string S;string T;cin>>H;cin>>W;cin>>N;cin>>I;--I;
cin>>J;--J;cin>>S;cin>>T;
/* </foxy.memo-area> */

  times(2, o) {
    int l = 0, r = W; // [l, r)
    rtimes(N, i) {
      if(T[i] == 'L') {
        if(r < W) ++r;
      } else if(T[i] == 'R') {
        if(l > 0) --l;
      }
      dd T[i]; l; r;
      if(S[i] == 'L') {
        if(l < W) ++l;
      } else if(S[i] == 'R') {
        if(r > 0) --r;
      }

      dd S[i]; l; r;

      if(l >= r) {
        cout << dict::NO ln;
        return;
      }
    }

    if(J < l || r <= J) {
      cout << dict::NO ln;
      return;
    }


    swap(H, W);
    swap(I, J);
    times(N, i) {
      S[i] = S[i] == 'U' ? 'L' : S[i] == 'D' ? 'R' : S[i] == 'L' ? 'U' : 'D';
    }
    times(N, i) {
      T[i] = T[i] == 'U' ? 'L' : T[i] == 'D' ? 'R' : T[i] == 'L' ? 'U' : 'D';
    }
  }

  cout << dict::YES ln;
}
