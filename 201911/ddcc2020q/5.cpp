#include "base.hpp"
//#include "consts.hpp"

void solve() {
  int N; cin >> N;

  int d = (int)sqrt(N);

  for(int i = 0; i < N; i += d) {
    cout << "?";
    uptil(0, N-i, j) cout sp << j+1;
    uptil(N, N+i, j) cout sp << j+1;
    cout ln;
    flush(cout);
  }

  int i0 = -1;
  bool r_old = false;
  for(int i = 0; i < N; i += d) {
    string s;
    cin >> s;
    bool r = s == "Red";
    if(i >= 1 && r != r_old) {
      i0 = i - d;
    }
    r_old = r;
  }
  if(i0 == -1) i0 = (N-1) / d * d;

  dd N; d; i0;

  uptil(i0, min(i0 + d, N), i) {
    cout << "?";
    uptil(0, N-i, j) cout sp << j+1;
    uptil(N, N+i, j) cout sp << j+1;
    cout ln;
    flush(cout);
  }

  int i1 = -1;
  r_old = false;
  uptil(i0, min(i0 + d, N), i) {
    string s;
    cin >> s;
    bool r = s == "Red";
    if(i > i0 && r != r_old) {
      i1 = i - 1;
    }
    r_old = r;
  }
  dd i1;
  if(i1 == -1) i1 = min(i0 + d, N)-1;
  dd i1;

  VI is_red(N*2, -1);

  uptil(N - i1 - 1, N, q) {
    cout << "?";
    uptil(0, N - i1 - 1, j) cout sp << j+1;
    uptil(N, N + i1, j) cout sp << j+1;
    cout sp << q+1;
    cout ln;
    flush(cout);
  }
  uptil(N + i1, 2 * N, q) {
    cout << "?";
    uptil(0, N - i1 - 1, j) cout sp << j+1;
    uptil(N, N + i1, j) cout sp << j+1;
    cout sp << q+1;
    cout ln;
    flush(cout);
  }
  uptil(N - i1 - 1, N, q) {
    string s;
    cin >> s;
    is_red[q] = s == "Red";
  }
  uptil(N + i1, 2 * N, q) {
    string s;
    cin >> s;
    is_red[q] = s == "Red";
  }

  VI red_list, blue_list;
  int rls = 0, bls = 0;

  uptil(N - i1 - 1, N, q) {
    if(is_red[q] && rls++ < (N-1)/2) red_list.PB(q);
    if(!is_red[q] && bls++ < (N-1)/2) blue_list.PB(q);
  }
  uptil(N + i1, 2 * N, q) {
    if(is_red[q] && rls++ < (N-1)/2) red_list.PB(q);
    if(!is_red[q] && bls++ < (N-1)/2) blue_list.PB(q);
  }

  assert((N-1)/2 == size(red_list));
  assert((N-1)/2 == size(blue_list));

  uptil(0, N - i1 - 1, q) {
    cout << "?";
    for(int j : red_list) cout sp << j+1;
    for(int j : blue_list) cout sp << j+1;
    cout sp << q+1;
    cout ln;
    flush(cout);
  }
  uptil(N, N + i1, q) {
    cout << "?";
    for(int j : red_list) cout sp << j+1;
    for(int j : blue_list) cout sp << j+1;
    cout sp << q+1;
    cout ln;
    flush(cout);
  }
  uptil(0, N - i1 - 1, q) {
    string s;
    cin >> s;
    is_red[q] = s == "Red";
  }
  uptil(N, N + i1, q) {
    string s;
    cin >> s;
    is_red[q] = s == "Red";
  }

  cout << "! ";

  times(N*2, i) if(is_red[i] == -1) exit(-1);

  times(N*2, i) cout << (is_red[i] ? "R" : "B");
  cout ln;
}
