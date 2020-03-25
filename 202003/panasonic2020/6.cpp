#include "base.hpp"
//#include "consts.hpp"

int tri[31];

inline bool sameRow(int l, int a, int c) {
  return a / tri[l] == c / tri[l];
}

inline bool freeColumnRange(int l, int a, int b, int d) {
  return a / tri[l] % 3 != 1 || d / tri[l] - b / tri[l] <= 1;
}

int dist00(int l, int i, int j) {
  if(l == 0) {
    assert(i == 0 && j == 0);
    return 0;
  } else {
    return dist00(l-1, i % tri[l-1], j % tri[l-1]) + tri[l-1] * (i / tri[l-1] + j / tri[l-1]);
  }
}

inline int distLU(int l, int i, int j) {
  return dist00(l, i % tri[l], j % tri[l]);
}

inline int distLD(int l, int i, int j) {
  return dist00(l, tri[l] - 1 - i % tri[l], j % tri[l]);
}

inline int distRU(int l, int i, int j) {
  return dist00(l, i % tri[l], tri[l] - 1 - j % tri[l]);
}

inline int distRD(int l, int i, int j) {
  return dist00(l, tri[l] - 1 - i % tri[l], tri[l] - 1 - j % tri[l]);
}

void solve() {
  tri[0] = 1;
  times(30, x) tri[x + 1] = tri[x] * 3;

  int Q; cin >> Q;
  times(Q, q) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    --a; --b; --c; --d;
    if(abs(a - c) > abs(b - d)) {
      swap(a, b); swap(c, d);
    }
    if(b > d) {
      swap(a, c); swap(b, d);
    }

    int l = 30;
    while(l > 0 && sameRow(l, a, c) && freeColumnRange(l, a, b, d)) {
      --l;
    }
    // dd l; a; b; c; d;
    if(sameRow(l, a, c) && freeColumnRange(l, a, b, d)) {
      assert(l == 0);
      cout << d - b ln;
    } else if(sameRow(l, a, c)) {
      assert(!freeColumnRange(l, a, b, d));
      cout << min(
        distRU(l, a, b) + distLU(l, c, d) + tri[l] * (d / tri[l] - b / tri[l] - 1),
        distRD(l, a, b) + distLD(l, c, d) + tri[l] * (d / tri[l] - b / tri[l] - 1)
      ) + 3 ln;
    } else if(a < c) {
      dd l; a; b; c; d; distRD(l, a, b); distLU(l, c, d); tri[l] * (d / tri[l] - b / tri[l] + c / tri[l] - a / tri[l] - 2);
      cout << distRD(l, a, b) + distLU(l, c, d) + tri[l] * (d / tri[l] - b / tri[l] + c / tri[l] - a / tri[l] - 2) + 2 ln;
    } else {
      cout << distRU(l, a, b) + distLD(l, c, d) + tri[l] * (d / tri[l] - b / tri[l] + a / tri[l] - c / tri[l] - 2) + 2 ln;
    }
  }
}
