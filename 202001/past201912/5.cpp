#include "base.hpp"
//#include "consts.hpp"

void solve() {
  int N,Q;cin>>N>>Q;

  WB ans(N, VB(N)), bns;

  times(Q, q) {
    int K, A; cin >> K >> A; --A;
    if(K==1) {
      int B; cin >> B; --B;
      ans[A][B] = true;
    } else if(K==2) {
      times(N, j) ans[A][j] = ans[A][j] || ans[j][A];
    } else{
      bns = ans;
      times(N, j) times(N, k) if(A!=k) ans[A][k] = ans[A][k] || bns[A][j] && bns[j][k];
    }
  }

  times(N, j) {
    times(N, k) cout << (ans[j][k] ? 'Y' : 'N');
    cout ln;
  }
}
