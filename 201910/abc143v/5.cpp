#include "base.hpp"
//#include "consts.hpp"

constexpr int INF = 1ll << 60;

void solve() {
// NMLM(-A-BC)QQ(-S-T)
/* <foxy.memo-area> */
int N;int M;int L;int Q;cin>>N;cin>>M;cin>>L;VI A(M);VI B(M);VI C(M);times(
M,Ri_0){cin>>A[Ri_0];--A[Ri_0];cin>>B[Ri_0];--B[Ri_0];cin>>C[Ri_0];}cin>>Q;VI S(
Q);VI T(Q);times(Q,Ri_0){cin>>S[Ri_0];--S[Ri_0];cin>>T[Ri_0];--T[Ri_0];}
/* </foxy.memo-area> */

  WI dist(N, VI(N, INF));

  times(M, i) dist[A[i]][B[i]] = dist[B[i]][A[i]] = C[i];

  times(N, k) times(N, i) times(N, j) amin(dist[i][j], dist[i][k] + dist[k][j]);

  times(N, i) times(N, j) dist[i][j] = dist[i][j] <= L ? 1 : INF;

  times(N, k) times(N, i) times(N, j) amin(dist[i][j], dist[i][k] + dist[k][j]);

  times(Q, i) {
    cout << (dist[S[i]][T[i]] >= INF ? -1 : dist[S[i]][T[i]] - 1) ln;
  }
}
