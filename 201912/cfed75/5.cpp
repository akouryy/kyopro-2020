#include "base.hpp"
//#include "consts.hpp"

void solve() {
  int t; cin >> t;
  times(t, o) {
    int n; cin >> n;
    VPII mp(n);
    VI msum(n); // ruiseki

    times(n, i) {
      int m, p; cin >> m >> p;
      mp[i] = make_pair(m, p);
      ++msum[m];
    }

    sort(iter(mp));
    times(n-1, i) msum[i+1] += msum[i];
    assert(msum[n-1] == n);

    dd mp; msum;

    int ans = 0, c = 0;
    priority_queue<int, VI, greater<int>> pq;
    downto(n-1, 1, i) {
      while(!mp.empty() && mp.back().first >= i) {
        pq.push(mp.back().second);
        mp.pop_back();
      }

      int req = i - msum[i-1];
      while(c < req) {
        ans += pq.top(); pq.pop();
        ++c;
      }

      dd i; c; req; mp; pq.top();
    }

    cout << ans ln;
  }
}
