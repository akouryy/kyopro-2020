#include "base.hpp"
//#include "consts.hpp"

int G[] = {4, 8, 15, 16, 23, 42};

void solve() {
  HIPII G2;
  times(6, i) times(i, j) G2[G[i] * G[j]] = make_pair(G[i], G[j]);

  cout << "? 1 2" << endl;
  cout << "? 3 4" << endl;
  cout << "? 1 3" << endl;
  cout << "? 5 5" << endl;
  cout.flush();

  int a01, a23, a02, a44; cin >> a01 >> a23 >> a02 >> a44;

  int a[6];
  if(G2[a01].first == G2[a02].first || G2[a01].first == G2[a02].second) {
    a[0] = G2[a01].first;
  } else if(G2[a01].second == G2[a02].first || G2[a01].second == G2[a02].second) {
    a[0] = G2[a01].second;
  } else {
    exit(-1);
  }
  a[1] = G2[a01].first == a[0] ? G2[a01].second : G2[a01].first;
  a[2] = G2[a02].first == a[0] ? G2[a02].second : G2[a02].first;
  a[3] = G2[a23].first == a[2] ? G2[a23].second : G2[a23].first;
  a[4] = int(sqrt(a44) + 0.5);
  times(6, g) {
    bool ok = true;
    times(5, i) if(G[g] == a[i]) ok = false;
    if(ok) a[5] = G[g];
  }

  cout << "!";
  times(6, i) cout << " " << a[i];
  cout ln;
}
