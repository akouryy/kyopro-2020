#include "base.hpp"
//#include "consts.hpp"

void solve() {
  int N; cin >> N;
  if(N == 1) {
    cout << 1 ln << 0 ln;
  } else if(N == 2) {
    cout << 2 ln << 0 ln << 11 ln;
  } else {
    cout << N-1 ln;
    times(N-1, i) {
      cout << 0 << string(i, '1') << 0 ln;;
    }
  }
}
