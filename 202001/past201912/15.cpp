#include "base.hpp"
//#include "consts.hpp"

void solve() {
// NN(6(A))
/* <foxy.memo-area> */
int N;cin>>N;WI A(N,VI(6));times(N,Ri_0){times(6,Ri_1){cin>>A[Ri_0][Ri_1];}}
/* </foxy.memo-area> */

  map<int, LD> alpha;

  VPIPII a; times(N, i) times(6, j) a.PB({A[i][j], {i, j}});
  sort(iter(a)); reverse(iter(a));

  alpha[0] = 1;

  uptil(1, N*6, h) {
    int i0, j0; tie(i0, j0) = a[h-1].second;

    LD s = 1;
    times(6, j) s += alpha[A[i0][j]] / 6;

    alpha[a[h].first] = max(alpha[a[h-1].first], s);

    dd a[h].first; alpha[a[h-1].first]; i0; s; alpha[a[h].first];
  }

  cout << alpha[a[N*6-1].first] ln;
}
