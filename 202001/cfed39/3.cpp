#include "base.hpp"
//#include "consts.hpp"

void solve() {
  string S; cin >> S;

  char next = 'a';
  for(char &c : S) {
    if(c <= next) c = next++;
    if(next > 'z') {
      cout << S ln;
      return;
    }
  }

  cout << -1 ln;
}
