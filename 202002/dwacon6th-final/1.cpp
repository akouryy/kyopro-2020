#include "base.hpp"
#include "consts.hpp"

void solve() {
  // H W
/* <foxy.memo-area> */
int H;int W;cin>>H;cin>>W;
/* </foxy.memo-area> */

  int H0 = H, W0 = W;
  if(H > W) swap(H, W);

  WI ans(H, VI(W, 5));

  if(H == 1) {
    if(W % 7 == 0 || W % 7 == 2) {
      times(W/7, j) {
        ans[0][j*7+0] = ans[0][j*7+1] = 2;
        // ans[0][j*7+2] = ans[0][j*7+3] = ans[0][j*7+4] = ans[0][j*7+5] = ans[0][j*7+6] = 5;
      }
      if(W % 7 == 2) {
        ans[0][W-2] = ans[0][W-1] = 2;
      }
    } else if(W % 7 == 5) {
      times(W/7, j) {
        // ans[0][j*7+0] = ans[0][j*7+1] = ans[0][j*7+2] = ans[0][j*7+3] = ans[0][j*7+4] = 5;
        ans[0][j*7+5] = ans[0][j*7+6] = 2;
      }
      // ans[0][W-5] = ans[0][W-4] = ans[0][W-3] = ans[0][W-2] = ans[0][W-1] = 5;
    } else {
      cout << dict::No ln;
      return;
    }
  } else if(H == 2) {
    if(W % 7 == 0 || W % 7 == 1) {
      times(W/7, j) {
        ans[0][j*7+0] = ans[1][j*7+0] = ans[0][j*7+3] = ans[1][j*7+4] = 2;
      }
      if(W % 7 == 1) {
        ans[0][W-1] = ans[1][W-1] = 2;
      }
    } else if(W % 7 == 6) {
      times(W/7, j) {
        ans[0][j*7+6] = ans[1][j*7+6] = ans[0][j*7+2] = ans[1][j*7+3] = 2;
      }
      ans[0][W/7*7+2] = ans[1][W/7*7+3] = 2;
    } else {
      cout << dict::No ln;
      return;
    }
  } else if(H == 3) {
    if(W == 3) {
      ans[0][0] = ans[0][1] = ans[2][0] = ans[2][1] = 2;
    } else {
      cout << dict::No ln;
      return;
    }
  } else {
    cout << dict::No ln;
    return;
  }

  cout << dict::Yes ln;
  times(H0, a) {
    times(W0, b) {
      cout << ans[H0 == H ? a : b][H0 == H ? b : a];
    }
    cout ln;
  }
}
