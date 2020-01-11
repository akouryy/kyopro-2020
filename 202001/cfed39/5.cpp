#include "base.hpp"
//#include "consts.hpp"

void solve() {
  int T; cin>>T;
  times(T, t) {
    string S; cin>>S;
    int N = size(S);
    bool is_10pow = S[0] == '1';
    uptil(1, N-1, i) is_10pow = is_10pow && S[i] == '0';
    is_10pow = is_10pow && (S[N-1] == '0' || S[N-1] == '1');
    if(is_10pow) {
      cout << string(N-2, '9') ln;
      continue;
    }

    bool ok=false;
    downto(N-1, max(N-10, 0ll), lim) {
      VI cnt(10);
      times(lim, i) {
        cnt[S[i] - '0'] ^= 1;
      }
      VI rest; times(10, d) if(cnt[d]) rest.PB(d);
      dd S; lim; rest;
      if(size(rest) <= N-lim) {
        uptil(size(rest), N-lim, o) rest.PB(9);

        if(lim == N) {
          cout << S ln;
          ok=true;
          break;
        } else {
          sort(iter(rest));
          auto it = rightmost_lt(iter(rest), S[lim] - '0');
          if(it != end(rest)) {
            S[lim] = '0' + *it;
            rest.erase(it);
            sort(iter(rest));
            uptil(lim + 1, N, i) {
              S[i] = rest[N - 1 - i] + '0';
            }
            cout << S ln;
            ok=true;
            break;
          }
        }
      }

      //2
      dd lim;
      if(lim > 0) {
        string T = S;
        {
          int g;
          for(g = lim-1; T[g] == '0' && (T[g] = '9'); --g);
          --T[g];
        }
        VI cnt(10);
        times(lim, i) {
          cnt[T[i] - '0'] ^= 1;
        }
        VI rest; times(10, d) if(cnt[d]) rest.PB(d);
        dd T; lim; rest;
        if(size(rest) != N-lim) continue;

        if(lim == N) {
          cout << T ln;
          ok=true;
          break;
        } else {
          sort(iter(rest));
          dd T; rest; lim; N;
          uptil(lim, N, i) {
            // dd i; N-1-i; T[i]; rest[N-1-i];
            T[i] = rest[N - 1 - i] + '0';
          }
          cout << T ln;
          ok=true;
          break;
        }
      }
    }
    assert(ok);
  }
}
