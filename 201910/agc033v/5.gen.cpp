#line 1 "base.hpp"//5
#ifndef __clang__
#pragma GCC optimize ("O3")
#endif
void solve(
#ifdef GCJ_CASE
long long case_id
#endif
);
#if defined(EBUG) && !defined(ONLINE_JUDGE)
#define debug true
#define _GLIBCXX_DEBUG
// #define _LIBCPP_DEBUG 0
#define _LIBCPP_DEBUG2 0
#else
#define NDEBUG
#define debug false
#endif
#include<algorithm>
#include<functional>
#include<iomanip>
#include<iostream>
#include<limits>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<type_traits>
#include<vector>
#include<cassert>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>

using namespace std;
using LL=long long;
using ULL=unsigned long long;
#define int LL
#define CS const
#define CX constexpr
#define IL inline
#define OP operator
#define RT return
#define TL template
#define TN typename
#define lambda [&]
#define rep(f,t,i,c,u)for(int Rb_=(t),i=(f);i c Rb_;u(i))
#define upto(f,t,i)rep(f,t,i,<=,++)
#define uptil(f,t,i)rep(f,t,i,<,++)
#define downto(f,t,i)rep(f,t,i,>=,--)
#define downtil(f,t,i)rep(f,t,i,>,--)
#define times(n,i)uptil(0,n,i)
#define rtimes(n,i)downto((n)-1,0,i)
#define iter(v)begin(v),end(v)
#define citer(v)cbegin(v),cend(v)
#define riter(v)rbegin(v),rend(v)
#define criter(v)crbegin(v),crend(v)
#define IF(a,b,c)((a)?(b):(c))
#if debug
#define ln <<endl
#else
#define ln <<'\n'
#endif
#define tb <<'\t'
#define sp <<' '
#line 1 "base_util.hpp"//5b
#define BINOPa(t,u,op)t OP op(CS u&o)CS{RT t(*this)op##=o;}
#define CMPOP(t,op,f1,f2,x)bool OP op(CS t&x)CS{RT f1 op f2;}
#define CMPOPS(t,f1,f2,x)CMPOP(t,==,f1,f2,x)CMPOP(t,!=,f1,f2,x)\
CMPOP(t,<,f1,f2,x)CMPOP(t,<=,f1,f2,x)CMPOP(t,>,f1,f2,x)CMPOP(t,>=,f1,f2,x)
#line 1 "mod.hpp"//5b
#ifndef MOD
#define MOD 1000000007
#endif
#if !defined(FORCE_MOD)&&MOD!=1000000007&&MOD!=1000000009&&MOD!=998244353
#error mod
#endif
#line 1 "power.hpp"//5bm
TL<TN T>IL T power(T x,int n){T r(1);for(;n;n/=2){if(n%2)r*=x;x*=x;}RT r;}IL int pow_mod(int x,int n,int m){int r=1;
for(;n;n/=2){if(n%2)r=r*x%m;x=x*x%m;}RT r;}
#line 2001 "mod.hpp"//5b
IL CX int modulo(int a,int b){a%=b;RT a&&(a>0)!=(b>0)?a+b:a;}IL CX int divide(int a,int b){RT(a-modulo(a,b))/b;}
TL<int d=MOD>struct MInt{
/*!https://ei1333.github.io/luzhiled/snippets/other/mod-int.html*/
int v;CX MInt():v(0){}explicit CX MInt(int i):v(modulo(i,d)){}MInt&OP+=(CS MInt&m){v+=m.v;if(v>=d)v-=d;RT*this;}
MInt&OP-=(CS MInt&m){v-=m.v;if(v<0)v+=d;RT*this;}MInt&OP*=(CS MInt&m){v=v*m.v%d;RT*this;}MInt&OP/=(CS MInt&m){
RT*this*=m.inv();}BINOPa(MInt,MInt,+)BINOPa(MInt,MInt,-)BINOPa(MInt,MInt,*)BINOPa(MInt,MInt,/)MInt OP-()CS{
RT MInt()-=*this;}CMPOP(MInt,==,v,m.v,m)CMPOP(MInt,!=,v,m.v,m)MInt pow(int n)CS{RT power(*this,n);}MInt inv()CS{
int a=v,b=d,x=1,y=0;while(b){swap(y,x-=a/b*y);swap(b,a%=b);}RT(MInt)x;}
friend ostream&OP<<(ostream&o,CS MInt&m){RT o<<m.v;}friend istream&OP>>(istream&i,MInt&m){i>>m.v;m.v%=d;RT i;}};
using mint=MInt<>;CX mint OP"" _m(ULL n){RT mint(n);}CX MInt<998244353>OP"" _m998244353(ULL n){RT MInt<998244353>(n);}
CX MInt<1000000007>OP"" _m1e9_7(ULL n){RT MInt<1000000007>(n);}
CX MInt<1000000009>OP"" _m1e9_9(ULL n){RT MInt<1000000009>(n);}
#line 1 "typedefs.hpp"//5b
using unit = tuple<>;using int128=__int128;using LD=long double;TL<TN T>using vec=vector<T>;
TL<TN T>using vvec=vec<vec<T>>;TL<TN T>using vvvec=vec<vvec<T>>;TL<TN T>using vvvvec=vec<vvvec<T>>;
using VM=vec<mint>;using VI=vec<int>;
#line 1 "alias.hpp"//5b
#define EB emplace_back
#define PB push_back
#define foldl accumulate
#define scanl partial_sum
#line 1 "util.hpp"//5b
TL<TN T>IL bool amax(T&v,CS T&a){RT v<a&&(v=a,1);}TL<TN T>IL bool amin(T&v,CS T&a){RT v>a&&(v=a,1);}
TL<TN T>IL int sizeRAB(T t){RT t.size();}
#define size sizeRAB
#define clamp clampRAB
TL<TN T>IL CX CS T&clamp(CS T&a,CS T&l,CS T&r){RT a<l?l:r<a?r:a;}TL<TN V>IL void uniq2(V&v){
v.erase(unique(iter(v)),v.end());}TL<TN V>IL void uniq(V&v){sort(iter(v));uniq2(v);}
#define leftmost_ge lower_bound
#define leftmost_gt upper_bound
namespace rab{TL<TN I>IL bool is_in(I x,I l,I r){RT l<=x&&x<r;}TL<TN T>IL T fetch(CS T&d,CS vec<T>&v,int i){
RT 0<=i&&i<size(v)?v[i]:d;}}
#line 1 "debug.hpp"//5b
TL<TN T>IL istream&OP>>(istream&s,vec<T>&v){for(auto&&p:v)s>>p;RT s;}TL<TN T,TN S>
IL ostream&OP<<(ostream&s,CS pair<T,S>&p){RT s<<"("<<p.first<<","<<p.second<<")";}
#define Rdebug1(sep, ...)IL ostream& OP<<(ostream&s,CS __VA_ARGS__&v){\
int i=0;for(CS auto&e:v){i++&&s<<sep;s<<e;}RT s;}
TL<TN T>Rdebug1(' ',vec<T>)TL<TN T,TN S>Rdebug1(' ',map<T,S>)TL<TN T>Rdebug1('\n',vvec<T>)
TL<TN T,TN S>Rdebug1('\n',vec<map<T,S>>)
#line 6001 "base.hpp"//5
signed main(){if(debug)cerr<<"MOD: "<<MOD ln;else cin.tie(0),cerr.tie(0),ios::sync_with_stdio(0);
auto p=setprecision(20);cout<<fixed<<p;cerr<<fixed<<p;
#ifdef GCJ_CASE
int T;cin>>T;times(T,t){cout<<"Case #"<<t+1<<": ";solve(t);}
#else
solve();
#endif
RT 0;}
#line 1001 "5.cpp"//
//#include "consts.hpp"
// #include "prime.hpp"

void solve() {
// NM"S"
/* <foxy.memo-area> */
int N;int M;string S;cin>>N;cin>>M;cin>>S;
/* </foxy.memo-area> */

  if(S[0] == 'B') {
    times(M, i) S[i] = 'R' + 'B' - S[i];
  }

  {
    times(M, i) if(S[i] != 'R') goto not_same;

    int i = 0, j = 1;
    times(100, o)
      while(++i) i == 100 || (j *= i);

    mint ans = 0_m;
    {
      // [0]->R
      VM dp(N);
      dp[0] = 1_m;
      dp[1] = 2_m;
      uptil(2, N, i) {
        dp[i] = dp[i - 1] + dp[i - 2];
      }
      ans += dp[N - 1];
      {if(debug)cerr<<"dp: "<<(dp)ln;}
    }
    {
      // [0]->B
      VM dp(N - 1);
      dp[0] = 1_m;
      if(N >= 3) dp[1] = 1_m;
      uptil(2, N - 1, i) {
        dp[i] = dp[i - 1] + dp[i - 2];
      }
      ans += dp[N - 2];
      {if(debug)cerr<<"dp: "<<(dp)ln;}
    }

    cout << ans ln;
    return;
  }
  not_same:;

  int p = 1ll << 60;
  {
    int ren = 1;
    times(M, i) {
      if(S[i] == 'R') {
        ++ren;
      } else {
        if(p == 1ll << 60 || ren % 2 == 1) {
          amin(p, ren);
        }
        ren = 0;
      }
    }
  }
  {if(debug)cerr<<"p: "<<(p)ln;}
#define M hoge

  if(N % 2 == 1) {
    cout << 0 ln;
    return;
  }

  int m = N / 2;
  int q = (p + 1) / 2;

#define N hoge
#define p hoge

  /*
  auto pfh = prime_factor(m);
  int zpf = size(pfh);
  VI pf; pf.reserve(zpf);
  for(auto &p : pfh) pf.PB(p.first);
  {if(debug)cerr<<"pf: "<<(pf)ln;}
  */

  /*
  VI pf;
  for(int i = 1; i*i <= m; ++i) {
    if(m % i == 0) {
      pf.PB(i);
      if(i*i != m) pf.PB(m / i);
    }
  }
  sort(iter(pf));
  */
  VI pf = {m};
  {if(debug)cerr<<"pf: "<<(pf)ln;}
  int zpf = size(pf);

  VM dp(m);
  VM g(zpf);

  mint ans = 0_m;

  times(zpf, h) {
    mint s = dp[0] = 1_m;
    uptil(1, pf[h], i) {
      s += dp[i] = s;
      if(i >= q) {
        s -= dp[i - q];
      }
      if(i <= q) {
        dp[i] += dp[0] * mint(i - 1);
        s += dp[0] * mint(i - 1);
      }
    }

    g[h] = s;
    times(h, hh) {
      if(pf[h] % pf[hh] == 0) g[h] -= g[hh];
    }
    ans += g[h] ;//* mint(pf[h]);

    {if(debug)cerr<<'#'<<__LINE__ ln<<"  h:     "<<(h)ln<<"  pf[h]: "<<(pf[h])ln<<"  s:     "<<(s)ln<<"  g[h]:  "<<(g[h])ln<<"  dp:    "<<(dp)ln;}
  }

  cout << ans * 2_m ln;
}
