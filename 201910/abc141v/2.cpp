#include "base.hpp"
#include "consts.hpp"

void solve() {
string S;cin>>S;

  int i = 0;
  for(char c : S) {
    if(c == (i ? 'R' : 'L')) {
      cout << dict::No ln;
      return;
    }
    i ^= 1;
  }

  cout << dict::Yes ln;
}
