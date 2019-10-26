#include "base.hpp"
//#include "consts.hpp"

void solve() {
// "S"
/* <foxy.memo-area> */
string S;cin>>S;
/* </foxy.memo-area> */

  VS v = {"Sunny", "Cloudy", "Rainy"};

  cout << (S == v[0] ? v[1] : S == v[1] ? v[2] : v[0]) ln;
}
