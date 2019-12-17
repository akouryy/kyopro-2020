#include "base.hpp"
#include "bit.hpp"
//#include "consts.hpp"

void solve() {
  int N; cin >> N;
  VI X(N), Y(N), Z(N), W(N);
  int cnt_h = 0;
  times(N, i) {
    cin >> X[i] >> Y[i] >> Z[i] >> W[i];
    if(X[i] > Z[i]) swap(X[i], Z[i]);
    if(Y[i] > W[i]) swap(Y[i], W[i]);
    cnt_h += Y[i] == W[i];
  }
  if(cnt_h > N/2) {
    swap(X, Y); swap(Z, W);
    cnt_h = N - cnt_h;
    dd cnt_h;
  }
  int nv = N - cnt_h;
  VPII vs; vs.reserve(nv);
  times(N, i) if(X[i] == Z[i]) {
    vs.PB(make_pair(X[i], i));
  }
  sort(iter(vs));

  int ans = 0;
  VPII hs;
  times(nv - 1, vi) {
    BIT<> bit(10001);
    int x, i; tie(x, i) = vs[vi];
    /*- 交わるH全列挙 */
    hs.clear();
    times(N, j) if(Y[j] == W[j] && Y[i] <= Y[j] && Y[j] <= W[i] && X[j] <= x && x <= Z[j]) {
      hs.PB(make_pair(-Z[j], j));
      bit.add(Y[j]+5000, 1);
    }
    sort(iter(hs));

    uptil(vi+1, nv, vj) {
      int x, j; tie(x, j) = vs[vj];
      int k = end(hs) - leftmost_ge(iter(hs), make_pair(-(x+1), 0ll));
      times(k, kk) {
        int g = hs.back().second; hs.pop_back();
        bit.add(Y[g]+5000, -1);
      }
      int tln = bit.sum(Y[j]+5000, W[j]+5000+1);
      dd vi; i; vj; j; Y[j]; W[j]; tln;
      ans += tln * (tln - 1) / 2;
    }
  }

  cout << ans ln;
}
