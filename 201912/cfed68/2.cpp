#include "base.hpp"
//#include "consts.hpp"

void solve() {
  int Q; cin >> Q;
  times(Q, q) {
    int N, M; cin >> N >> M;
    VS S(N); times(N, i) cin >> S[i];

    VI rm(N), cm(M);

    times(N, i) {
      int c = 0;
      times(M, j) c += S[i][j] == '.';
      rm[i] = c;
    }

    times(M, j) {
      int c = 0;
      times(N, i) c += S[i][j] == '.';
      cm[j] = c;
    }

    int ans = 1e9;

    times(N, i) times(M, j) {
      amin(ans, rm[i] + cm[j] - (S[i][j] == '.'));
    }

    cout << ans ln;
  }
}
