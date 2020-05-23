#define GCJ_CASE
#include "base.hpp"
//#include "consts.hpp"

void solve(int case_id) {
  int L, R;
  cin >> L >> R;

  bool swapped = L < R;
  if(swapped) swap(L, R);
  dd swapped; L; R;

  int i1;
  {
    int ok = min(L + 10, (LL)INT_MAX), ng = 0;
    while(abs(ok - ng) > 1) {
      int mid = (ok + ng) / 2;
      // dd mid; L - mid * (mid + 1) / 2; R + (swapped ? 1 : 0);
      if(L - mid * (mid + 1) / 2 >= R + (swapped ? 1 : 0)) {
        ng = mid;
      } else {
        ok = mid;
      }
    }
    i1 = ok;
    L -= i1 * (i1 + 1) / 2;
    dd i1; L;
    assert(swapped ? (L <= R) : (L < R));
    if(L < 0) {
      cout << i1 - 1 sp << (swapped ? R : (L + i1)) sp << (swapped ? (L + i1) : R) ln;
      return;
    }
  }
  int dL;
  {
    int ok = min(L + 10, (LL)INT_MAX), ng = 0;
    while(abs(ok - ng) > 1) {
      int mid = (ok + ng) / 2;
      // dd mid; L - i1 * mid - mid * (mid + 1);
      if(L - i1 * mid - mid * (mid + 1) >= 0) {
        ng = mid;
      } else {
        ok = mid;
      }
    }
    dL = ok - 1;
    int x = L - i1 * dL - dL * (dL + 1);
    dd dL; x;
    assert(x >= 0);
    assert(x - i1 - (dL + 1) * 2 < 0);
  }
  int dR;
  {
    int ok = min(R + 10, (LL)INT_MAX), ng = 0;
    while(abs(ok - ng) > 1) {
      int mid = (ok + ng) / 2;
      dd mid; R - i1 * mid - mid * mid;
      if(R - i1 * mid - mid * mid >= 0) {
        ng = mid;
      } else {
        ok = mid;
      }
    }
    dR = ok - 1;
    int x = R - i1 * dR - dR * dR;
    dd dR; x;
    assert(x >= 0);
    assert(x - i1 - (dR * 2 + 1) < 0);
  }

  int d = min(dL * 2 + 1, dR * 2);

  int ll = L - i1 * (d / 2) - (d / 2) * (d / 2 + 1),
      rr = R - i1 * ((d + 1) / 2) - ((d + 1) / 2) * ((d + 1) / 2);
  dd d; (d / 2); ((d + 1) / 2); ll; rr;
  cout << i1 + d sp << (swapped ? rr : ll) sp << (swapped ? ll : rr) ln;
}
