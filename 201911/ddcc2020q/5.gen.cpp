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
using VI=vec<int>;
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

  {if(debug)cerr<<'#'<<__LINE__ ln<<"  N:  "<<(N)ln<<"  d:  "<<(d)ln<<"  i0: "<<(i0)ln;}
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
  {if(debug)cerr<<"i1: "<<(i1)ln;}
  if(i1 == -1) i1 = min(i0 + d, N)-1;
  {if(debug)cerr<<"i1: "<<(i1)ln;}
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
