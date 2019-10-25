#include "base.hpp"
#include "math.hpp"
#include "prime.hpp"
//#include "consts.hpp"

void solve() {
// AB
/* <foxy.memo-area> */
int A;int B;cin>>A;cin>>B;
/* </foxy.memo-area> */

  HII p = prime_factor(gcd(A, B));

  cout << size(p) + 1 ln;
}
