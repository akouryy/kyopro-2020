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
using unit = tuple<>;using LD=long double;TL<TN T>using vec=vector<T>;
TL<TN T>using vvec=vec<vec<T>>;TL<TN T>using vvvec=vec<vvec<T>>;TL<TN T>using vvvvec=vec<vvvec<T>>;
using VI=vec<int>;using VPII=vec<pair<int, int>>;
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
#line 1 "bit.hpp"//5
TL<TN T=int,TN Adder=plus<T>,TN Subber=TN enable_if<is_same<Adder,plus<T>>::value,minus<T>>::type>
struct BIT{
  int n;
  vec<T>data;
  Adder adder;
  Subber subber;
  explicit BIT(int n,T init=T()):n(n),data(n,init){}
  IL void add(int i,T t){for(++i;i<n;i+=i&-i)data[i-1]=adder(data[i-1],t);}
  IL T sum(int i){T rt{};for(;i;i-=i&-i)rt=adder(rt,data[i-1]);RT rt;}
  IL T sum(int l,int r){RT subber(sum(r),sum(l));}
};
#line 2001 "5.cpp"//
//#include "consts.hpp"

void solve() {
  int N; cin >> N;
  VI X(N), Y(N), Z(N), W(N);
  int cnt_h = 0;
  times(N, i) {
    cin >> X[i] >> Y[i] >> Z[i] >> W[i];
    if(X[i] > Z[i]) swap(X[i], Z[i]);
    if(Y[i] > W[i]) swap(Y[i], W[i]);
    cnt_h += Y[i] == W[i];
  }
  if(cnt_h > N/2) {
    swap(X, Y); swap(Z, W);
    cnt_h = N - cnt_h;
    {if(debug)cerr<<"cnt_h: "<<(cnt_h)ln;}
  }
  int nv = N - cnt_h;
  VPII vs; vs.reserve(nv);
  times(N, i) if(X[i] == Z[i]) {
    vs.PB(make_pair(X[i], i));
  }
  sort(iter(vs));

  int ans = 0;
  VPII hs;
  times(nv - 1, vi) {
    BIT<> bit(10001);
    int x, i; tie(x, i) = vs[vi];
    hs.clear();
    times(N, j) if(Y[j] == W[j] && Y[i] <= Y[j] && Y[j] <= W[i] && X[j] <= x && x <= Z[j]) {
      hs.PB(make_pair(-Z[j], j));
      bit.add(Y[j]+5000, 1);
    }
    sort(iter(hs));

    uptil(vi+1, nv, vj) {
      int x, j; tie(x, j) = vs[vj];
      int k = distance(leftmost_ge(iter(hs), make_pair(-(x+1), 0ll)), end(hs));
      times(k, kk) {
        int g = hs.back().second; hs.pop_back();
        bit.add(Y[g]+5000, -1);
      }
      int tln = bit.sum(Y[j]+5000, W[j]+5000+1);
      {if(debug)cerr<<'#'<<__LINE__ ln<<"  vi:   "<<(vi)ln<<"  i:    "<<(i)ln<<"  vj:   "<<(vj)ln<<"  j:    "<<(j)ln<<"  Y[j]: "<<(Y[j])ln<<"  W[j]: "<<(W[j])ln<<"  tln:  "<<(tln)ln;}
      ans += tln * (tln - 1) / 2;
    }
  }

  cout << ans ln;
}
