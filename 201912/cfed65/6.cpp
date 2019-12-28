#include "base.hpp"
#include "bit.hpp"
#include "util_compress.hpp"

void solve() {
  int N; cin >> N;
  VI A(N); times(N, i) cin >> A[i];

  Compressed<int> cmp(A);
  BIT<> bit(N);

  VI x(N);
  times(N, i) {
    x[i] = bit.sum(cmp.zip[A[i]]);
    bit.add(cmp.zip[A[i]], i+1);
    dd bit.data;
  }

  VI y(N);
  reverse(iter(A));
  bit = BIT<>(N);
  times(N, i) {
    y[i] = bit.sum(cmp.zip[A[i]]) + i + 1;
    bit.add(cmp.zip[A[i]], i+1);
    dd bit.data;
  }
  reverse(iter(y));
  reverse(iter(A));

  dd x; y;

  mint ans = 0_m;

  times(N, i) {
    ans += mint(A[i]) * (mint(y[i]) * mint(i+1) + mint(x[i]) * mint(N-i));
    dd mint(y[i]) * mint(i+1); mint(x[i]) * mint(N-i); ans;
  }

  cout << ans ln;
}
