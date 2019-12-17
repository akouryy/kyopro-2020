#include "base.hpp"
//#include "consts.hpp"

void solve() {
// XY
/* <foxy.memo-area> */
int X;int Y;cin>>X;cin>>Y;
/* </foxy.memo-area> */

  cout << (X == 3 ? 100000 : X == 2 ? 200000 : X == 1 ? 300000 : 0) +
    (Y == 3 ? 100000 : Y == 2 ? 200000 : Y == 1 ? 300000 : 0) +
    (Y == 1 && X == 1 ? 400000 : 0) ln;
}
