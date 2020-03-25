#include "base.hpp"
//#include "consts.hpp"

void pyon(int N, int i, char *s, char next) {
  if(i == N) {
    cout << s ln;
  } else {
    for(char c = 'a'; c <= next; ++c) {
      s[i] = c;
      pyon(N, i + 1, s, next + char(c == next));
    }
  }
}

void solve() {
  int N; cin >> N;
  char *s = new char[N+1];
  s[N] = '\0';

  pyon(N, 0, s, 'a');
}
