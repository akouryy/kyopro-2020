#include "base.hpp"
//#include "consts.hpp"

void solve() {
// N"S"
/* <foxy.memo-area> */
int N;string S;cin>>N;cin>>S;
/* </foxy.memo-area> */

  int ans = 1;
  times(N-1, i) ans += S[i] != S[i+1];

  cout << ans ln;
}
