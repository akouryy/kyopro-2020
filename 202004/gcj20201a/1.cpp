#define GCJ_CASE
#include "base.hpp"
//#include "consts.hpp"

bool starts_with(string s, string t) {
  return size(s) >= size(t) && equal(iter(t), begin(s));
}

bool ends_with(string s, string t) {
  return size(s) >= size(t) && equal(riter(t), rbegin(s));
}

void solve(int cid) {
  int N; cin >> N;

  bool ok = true;

  string pre, post;
  stringstream mid;
  times(N, i) {
    string S; cin >> S;
    int l = S.find_first_of('*'), r = S.find_last_of('*');

    string sl = S.substr(0, l), sr = S.substr(r + 1, size(S) - r - 1);

    for(char c : S.substr(l + 1, r - l)) if(c != '*') mid << c;

    dd sl; sr; S.substr(l + 1, r - l);

    if(starts_with(pre, sl)) {
      // pass
    } else if(starts_with(sl, pre)) {
      pre = sl;
    } else {
      ok = false;
    }
    if(ends_with(post, sr)) {
      // pass
    } else if(ends_with(sr, post)) {
      post = sr;
    } else {
      ok = false;
    }
    dd pre; mid.str(); post; ok;
  }

  if(ok) {
    cout << pre << mid.str() << post ln;
  } else {
    cout << '*' ln;
  }
}
