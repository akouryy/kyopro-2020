#include "base.hpp"
//#include "consts.hpp"

void solve() {
  int Q; cin >> Q;
  times(Q, q) {
    int N, K; cin >> N >> K;
    bool bob;
    if(K % 3 == 0) {
      int x = N % (K + 1);
      bob = x % 3 == 0 && x != K;
    } else {
      bob = N % 3 == 0;
    }
    cout << (bob ? "Bob" : "Alice") ln;
  }
}
