#include "base.hpp"
//#include "consts.hpp"

void solve() {
// AB
/* <foxy.memo-area> */
int A;int B;cin>>A;cin>>B;
/* </foxy.memo-area> */

  while(true) {
    if(A==0 || B==0) break;
    if(A >= 2*B) A %= 2*B;
    else if(B >= 2*A) B %= 2*A;
    else break;
  }

  cout << A sp << B ln;
}
