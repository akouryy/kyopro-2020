#include "base.hpp"
#include "consts.hpp"

#define split(dice) \
  int t = dice & 7, b = (dice >> 3) & 7, n = (dice >> 6) & 7, s = (dice >> 9) & 7, w = (dice >> 12) & 7, e = (dice >> 15) & 7; \
  assert(t + b == 7 && n + s == 7 && w + e == 7)

inline int make(int t, int b, int n, int s, int w, int e) {
  return t | (b << 3) | (n << 6) | (s << 9) | (w << 12) | (e << 15);
}

int flip(int dice) {
  return (7 | 7 << 3 | 7 << 6 | 7 << 9 | 7 << 12 | 7 << 15) - dice;
}

int goSouth(int dice) {
  split(dice);
  return make(n, s, b, t, w, e);
}

int goNorth(int dice) {
  split(dice);
  return make(s, n, t, b, w, e);
}

int goWest(int dice) {
  split(dice);
  return make(e, w, n, s, t, b);
}

int goEast(int dice) {
  split(dice);
  return make(w, e, n, s, b, t);
}

void solve() {
  int H, W; cin >> H >> W;
  VS S(H); times(H, i) cin >> S[i];

  queue<TIII> q; q.push(TIII(0, 0, make(1, 6, 5, 2, 4, 3)));
  map<TIII, bool> ok;

  while(!q.empty()) {
    int i, j, dice; tie(i, j, dice) = q.front(); q.pop();
    if(ok[(TIII(i, j, dice))]) continue;
    ok[(TIII(i, j, dice))] = true;
    if(i == H-1 && j == W-1) {
      cout << "YES" ln;
      return;
    }
    times(4, d) {
      int ii = i + di4[d], jj = j + dj4[d];
      int nd = d == 0 ? goNorth(dice) : d == 1 ? goEast(dice) : d == 2 ? goSouth(dice) : goWest(dice);

      if(0 <= ii && ii < H && 0 <= jj && jj < W &&
         ((nd >> 3) & 7) + '0' == S[ii][jj] && !ok[(TIII(ii, jj, nd))]) {
        q.push(TIII(ii, jj, nd));
      }
    }
  }

  cout << "NO" ln;
}
