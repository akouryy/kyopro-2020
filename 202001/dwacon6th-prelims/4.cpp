#include "base.hpp"
//#include "consts.hpp"

void solve() {
// NN(-A)
/* <foxy.memo-area> */
int N;cin>>N;VI A(N);times(N,Ri_0){cin>>A[Ri_0];--A[Ri_0];}
/* </foxy.memo-area> */
  if(N == 2) {
    cout << -1 ln;
    return;
  }

  VI b(N, N-1); times(N, i) --b[A[i]];

  VB used(N);
  priority_queue<int, VI, greater<int>> pq;
  priority_queue<PII, VPII, greater<PII>> bq;
  times(N, i) pq.push(i);
  times(N, i) bq.push(PII(b[i], i));
  int before = -1;
  times(N-3, o) {
    while(used[pq.top()]) pq.pop();
    int i = -1;
    while(bq.top().first == o) {
      int k = bq.top().second; bq.pop();
      if(used[k]) {
        //
      } else if(b[k] != o) {
        bq.push(PII(b[k], k));
      } else {
        i = k;
      }
    }
    if(i == -1) {
      i = pq.top(); pq.pop();
      if(before >= 0 && A[before] == i) {
        int j = pq.top(); pq.pop();
        pq.push(i);
        dd i; j;
        i = j;
      }
    }
    used[i] = true;
    ++b[A[i]];
    cout << i+1 sp;
    before = i;
  }

  VI pqr;
  times(N, i) {
    if(!used[i]) pqr.PB(i);
  }
  assert(size(pqr) == 3);
  dd pqr;

  for(int x : pqr) for(int y : pqr) for(int z : pqr) if(x != y && y != z && z != x) {
    if((before == -1 || A[before] != x) && A[x] != y && A[y] != z) {
      dd x; y; z;
      cout << x+1 sp << y+1 sp << z+1 ln;
      return;
    }
  }
  assert(false);
}
