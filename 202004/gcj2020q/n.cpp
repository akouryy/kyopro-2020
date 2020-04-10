#define GCJ_CASE
#include "base.hpp"
//#include "consts.hpp"

void solve(int ccc) {
  string S; cin >> S;

  stringstream ss;

  int lv = 0;
  for(char c : S) {
    int k = c - '0';
    if(lv < k) {
      ss << string(k - lv, '(');
    } else {
      ss << string(lv - k, ')');
    }
    ss << c;
    lv = k;
  }

  ss << string(lv, ')');

  cout << ss.str() ln;
}
