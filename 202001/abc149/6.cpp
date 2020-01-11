#include "base.hpp"
//#include "consts.hpp"

int N;
WI edges;
mint ans;

int dfs(int i, int p) {
  VI sizes;
  for(int j : edges[i]) if(j != p) {
    sizes.PB(dfs(j, i));
  }
  int sum_size = 0;
  for(int s : sizes) sum_size += s;
  sizes.PB(N - 1 - sum_size);

  //mint base = 1_m;
  //for(int s : sizes) base *= 1_m - 1_m / 2_m .pow(s);
  mint x = 1_m - 1_m / 2_m .pow(N-1);
  for(int s : sizes) x -= (1_m - 1_m / 2_m .pow(s)) / 2_m .pow(N-1-s);
  ans += x / 2_m;

  dd i; x; sizes; sum_size; ans;

  return sum_size + 1;
}

void solve() {
  cin >> N;
  edges = WI(N);
  times(N-1, i) {
    int A, B; cin >> A >> B; --A; --B;
    edges[A].PB(B);
    edges[B].PB(A);
  }

  ans = 0_m;
  dfs(0, 0);

  cout << ans ln;
}
