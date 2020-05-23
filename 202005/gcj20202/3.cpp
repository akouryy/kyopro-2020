#define GCJ_CASE
#include "base.hpp"
#include "math.hpp"
#include "uf.hpp"
//#include "consts.hpp"

void solve(int case_id) {
  int N; cin >> N;
  VI X(N), Y(N);
  times(N, i) cin >> X[i] >> Y[i];

  HPIIVPII fromSlopes;
  times(N, j) times(j, i) {
    int dx = X[i] - X[j], dy = Y[i] - Y[j];

    int sx, sy;
    if(dx == 0) {
      sx = 0; sy = 1;
    } else if(dy == 0) {
      sx = 1; sy = 0;
    } else {
      int g = gcd(dx, dy);
      sx = dx / g; sy = dy / g;
      if(sx < 0) {
        sx = -sx; sy = -sy;
      }
    }
    dd i; j; sx; sy;
    fromSlopes[(make_pair(sx, sy))].EB(i, j);
  }
  dd fromSlopes;

  int ans = 0;
  unionfind uf(N);

  if(N == 1) {
    cout << 1 ln;
    return;
  }

  for(const auto& p : fromSlopes) {
    int sx = p.first.first, sy = p.first.second;
    const VPII& ijs = p.second;

    if(size(ijs) == 1) {
      // [1*, 2]
      amax(ans, min(N, 4LL));
      continue;
    }

    uf.clear();
    for(const auto& ij : ijs) {
      uf.merge(ij.first, ij.second);
    }

    int oneCnt = 0, nonOneSum = 0, oddCnt = 0;
    times(N, i) {
      if(uf.root(i) == i) {
        int s = uf.zs[i];
        if(s == 1) {
          ++oneCnt;
        } else {
          nonOneSum += s;
          if(s % 2 == 1) ++oddCnt;
        }
      }
    }
    int a = nonOneSum + min(oneCnt, oddCnt % 2 == 0 ? 2LL : 1LL);
    dd sx; sy; oneCnt; nonOneSum; oddCnt; a;
    amax(ans, a);
  }

  cout << ans ln;
}
