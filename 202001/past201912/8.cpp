#include "base.hpp"
//#include "consts.hpp"

void solve() {
  int N,Q;cin>>N;
  VI C(N); times(N,i)cin>>C[i];
  cin>>Q;

  int even_sub=0, odd_sub=0, even_min=1ll<<60, odd_min=1ll<<60;
  times(N, i) {
    if(i % 2) amin(odd_min, C[i]);
    else amin(even_min, C[i]);
  }

  int ans = 0;

  times(Q, q) {
    int K, A; cin >> K >> A;
    if(K==1) {
      int X;cin>>X;swap(A, X); --X;
      if(X % 2) {
        if(C[X] - odd_sub >= A) {
          C[X] -= A;
          ans += A;
          amin(odd_min, C[X] - odd_sub);
        }
      } else {
        if(C[X] - even_sub >= A) {
          C[X] -= A;
          ans += A;
          amin(even_min, C[X] - even_sub);
        }
      }
    } else if(K==2){
      if(even_min >= A) {
        even_sub += A;
        even_min -= A;
        ans += (N + 1) / 2 * A;
      }
    } else {
      if(odd_min >= A && even_min >= A) {
        odd_sub += A;
        odd_min -= A;
        even_sub += A;
        even_min -= A;
        ans += N * A;
      }
    }
    dd C; even_sub; odd_sub; even_min; odd_min;
  }

  cout << ans ln;
}
