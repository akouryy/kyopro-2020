#include "base.hpp"
#include "nck.hpp"
//#include "consts.hpp"

int ABS(int i) {
  return i >= 0 ? i : -i;
}

void step(VI &a) {
  times(size(a)-1, i) {
    a[i] = ABS(a[i] - a[i+1]);
  }
  a.pop_back();
}

int calc(const VI &a) {
  int n = size(a);
  int acc = 0;
  times(n, i) {
    acc ^= a[i] * ((n-1&i) == i) % 2;
  }
  return acc;
}

void solve() {
  // NN(A)
  /* <foxy.memo-area> */
  int N;cin>>N;string AS;cin>>AS;VI A(N);times(N,Ri_0){A[Ri_0]=AS[Ri_0]-'0';}
  /* </foxy.memo-area> */

  if(N < 4) {
    times(N-1, i) {
      step(A);
      dd A;
    }
    cout << A[0] ln;
  } else {
    step(A);
    dd A;
    if(find(iter(A), 1) != end(A)) {
      cout << calc(A) ln;
    } else {
      times(size(A), i) A[i] /= 2;
      cout << calc(A) * 2 ln;
    }
  }
}
