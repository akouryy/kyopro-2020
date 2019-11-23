#include "base.hpp"
//#include "consts.hpp"

void solve() {
// NK
/* <foxy.memo-area> */
int N;int K;cin>>N;cin>>K;
/* </foxy.memo-area> */

  if(2 * K > N + 1) {
    cout << -1 ln;
    return;
  }

  if(N % 2 == 0) {
    int a = K + N/2 - 1, b = K + N, c = K + 2 * N;

    times(N/2, i) {
      cout << a sp << b sp << c ln;
      --a; b+=2; ++c;
    }

    a = K + N - 1; b = K + N + 1; c = K + N * 5 / 2;

    times(N/2, i) {
      cout << a sp << b sp << c ln;
      --a; b+=2; ++c;
    }
  } else {
    int a = K + (N-1)/2, b = K + N, c = K + 2 * N;

    times((N+1)/2, i) {
      cout << a sp << b sp << c ln;
      --a; b+=2; ++c;
    }

    a = K + N - 1; b = K + N + 1; c = K + (N * 5 + 1) / 2;

    times((N-1)/2, i) {
      cout << a sp << b sp << c ln;
      --a; b+=2; ++c;
    }
  }
}
