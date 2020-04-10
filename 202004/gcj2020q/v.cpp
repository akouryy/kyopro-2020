#define GCJ_CASE 1
#include "base.hpp"
//#include "consts.hpp"
struct a{};

void solve(int case_id) {
  int N; cin >> N;
  WI M(N, VI(N)); times(N, i) times(N, j) cin >> M[i][j];

  int d = 0;
  times(N, i) d += M[i][i];

  int r = 0;
  times(N, i) {
    VB used(N);
    times(N, j) {
      if(used[M[i][j]]) {
        ++r;
        break;
      }
      used[M[i][j]] = true;
    }
  }

  int c = 0;
  times(N, j) {
    VB used(N);
    times(N, i) {
      if(used[M[i][j]]) {
        ++c;
        break;
      }
      used[M[i][j]] = true;
    }
  }

  cout << d sp << r sp << c ln;
}
