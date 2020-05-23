#define GCJ_CASE
#include "base.hpp"
//#include "consts.hpp"

using PP = pair<signed, signed>;

void solve(int cid) {
  signed R, C; cin >> R >> C;
  vvec<signed> S(R, vec<signed>(C)); times(R, i) times(C, j) cin >> S[i][j];

  set<PP> cand, fix;
  // cand.reserve(R*C);
  vec<set<signed>> live_row(R), live_col(C);

  int ans = 0, now = 0;

  times(R, i) times(C, j) {
    now += S[i][j];
    cand.insert(PP(i, j));
    live_row[i].insert(j);
    live_col[j].insert(i);
  }

  while(true) {
    ans += now;
    fix.clear();

    for(auto &ca : cand) {
      int i = ca.first, j = ca.second;
      if(S[i][j] == 0) continue;
      int s = 0, c = 0;
      {
        auto x = live_row[i].leftmost_gt(j);
        if(x != end(live_row[i])) {
          ++c;
          s += S[i][*x];
        }
      }
      {
        auto x = live_col[j].leftmost_gt(i);
        if(x != end(live_col[j])) {
          ++c;
          s += S[*x][j];
        }
      }
      {
        auto x = rightmost_lt(live_row[i], j);
        if(x != end(live_row[i])) {
          ++c;
          s += S[i][*x];
        }
      }
      {
        auto x = rightmost_lt(live_col[j], i);
        if(x != end(live_col[j])) {
          ++c;
          s += S[*x][j];
        }
      }

      if(S[i][j] * c < s) {
        fix.insert(PP(i, j));
      }
    }
    dd ans; now; S;

    cand.clear();
    if(size(fix) == 0) break;

    for(auto& fx : fix) {
      int i = fx.first, j = fx.second;
      now -= S[i][j];
      live_row[i].erase(j);
      live_col[j].erase(i);
      S[i][j] = 0;

      {
        auto x = live_row[i].leftmost_gt(j);
        if(x != end(live_row[i])) {
          cand.insert(PP(i, *x));
        }
      }
      {
        auto x = live_col[j].leftmost_gt(i);
        if(x != end(live_col[j])) {
          cand.insert(PP(*x, j));
        }
      }
      {
        auto x = rightmost_lt(live_row[i], j);
        if(x != end(live_row[i])) {
          cand.insert(PP(i, *x));
        }
      }
      {
        auto x = rightmost_lt(live_col[j], i);
        if(x != end(live_col[j])) {
          cand.insert(PP(*x, j));
        }
      }
    }
  }

  cout << ans ln;
}
