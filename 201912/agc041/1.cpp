#include "base.hpp"
//#include "consts.hpp"

void solve() {
int N,A,B; cin >>N>>A>>B;

  if((B - A) % 2 == 0) {
    cout << (B - A) / 2 ln;
  } else {
    cout << min(B - (1 - A), (N + 1 - A) - (1 - (N + 1 - B))) / 2 ln;
  }
}
