#line 1 "base.hpp"//6
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
#include<bitset>
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
#line 1 "base_util.hpp"//6b
#define BINOPa(t,u,op)t OP op(CS u&o)CS{RT t(*this)op##=o;}
#define CMPOP(t,op,f1,f2,x)bool OP op(CS t&x)CS{RT f1 op f2;}
#define CMPOPS(t,f1,f2,x)CMPOP(t,==,f1,f2,x)CMPOP(t,!=,f1,f2,x)\
CMPOP(t,<,f1,f2,x)CMPOP(t,<=,f1,f2,x)CMPOP(t,>,f1,f2,x)CMPOP(t,>=,f1,f2,x)
#line 1 "mod.hpp"//6b
#ifndef MOD
#define MOD 1000000007
#endif
#if !defined(FORCE_MOD)&&MOD!=1000000007&&MOD!=1000000009&&MOD!=998244353
#error mod
#endif
#line 1 "power.hpp"//6bm
TL<TN T>IL T power(T x,int n){T r(1);for(;n;n/=2){if(n%2)r*=x;x*=x;}RT r;}IL int pow_mod(int x,int n,int m){int r=1;
for(;n;n/=2){if(n%2)r=r*x%m;x=x*x%m;}RT r;}
#line 2001 "mod.hpp"//6b
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
#line 1 "typedefs.hpp"//6b
using unit = tuple<>;using LD=long double;TL<TN T>using vec=vector<T>;
TL<TN T>using vvec=vec<vec<T>>;TL<TN T>using vvvec=vec<vvec<T>>;TL<TN T>using vvvvec=vec<vvvec<T>>;

#line 1 "alias.hpp"//6b
#define EB emplace_back
#define PB push_back
#define foldl accumulate
#define scanl partial_sum
#line 1 "util.hpp"//6b
TL<TN T>IL bool amax(T&v,CS T&a){RT v<a&&(v=a,1);}TL<TN T>IL bool amin(T&v,CS T&a){RT v>a&&(v=a,1);}
TL<TN T>IL int sizeRAB(T t){RT t.size();}
#define size sizeRAB
#define clamp clampRAB
TL<TN T>IL CX CS T&clamp(CS T&a,CS T&l,CS T&r){RT a<l?l:r<a?r:a;}TL<TN V>IL void uniq2(V&v){
v.erase(unique(iter(v)),v.end());}TL<TN V>IL void uniq(V&v){sort(iter(v));uniq2(v);}
#define leftmost_ge lower_bound
#define leftmost_gt upper_bound
TL<TN C,TN D>IL C rightmost_le(CS C&from,CS C&to,CS D&d){auto l=leftmost_gt(from,to,d);RT l==from?to:--l;}
TL<TN C,TN D>IL C rightmost_lt(CS C&from,CS C&to,CS D&d){auto l=leftmost_ge(from,to,d);RT l==from?to:--l;}
namespace rab{TL<TN I>IL bool is_in(I x,I l,I r){RT l<=x&&x<r;}TL<TN T>IL T fetch(CS T&d,CS vec<T>&v,int i){
RT 0<=i&&i<size(v)?v[i]:d;}}
#line 1 "debug.hpp"//6b
TL<TN T>IL istream&OP>>(istream&s,vec<T>&v){for(auto&&p:v)s>>p;RT s;}TL<TN T,TN S>
IL ostream&OP<<(ostream&s,CS pair<T,S>&p){RT s<<"("<<p.first<<","<<p.second<<")";}
#define Rdebug1(sep, ...)IL ostream& OP<<(ostream&s,CS __VA_ARGS__&v){\
int i=0;for(CS auto&e:v){i++&&s<<sep;s<<e;}RT s;}
TL<TN T>Rdebug1(' ',vec<T>)TL<TN T,TN S>Rdebug1(' ',map<T,S>)TL<TN T>Rdebug1('\n',vvec<T>)
TL<TN T,TN S>Rdebug1('\n',vec<map<T,S>>)
#line 6001 "base.hpp"//6
signed main(){if(debug)cerr<<"MOD: "<<MOD ln;else cin.tie(0),cerr.tie(0),ios::sync_with_stdio(0);
auto p=setprecision(20);cout<<fixed<<p;cerr<<fixed<<p;
#ifdef GCJ_CASE
int T;cin>>T;times(T,t){cout<<"Case #"<<t+1<<": ";solve(t);}
#else
solve();
#endif
RT 0;}
#line 1001 "6.cpp"//
//#include "consts.hpp"

int tri[31];

inline bool sameRow(int l, int a, int c) {
  return a / tri[l] == c / tri[l];
}

inline bool freeColumnRange(int l, int a, int b, int d) {
  return a / tri[l] % 3 != 1 || d / tri[l] - b / tri[l] <= 1;
}

int dist00(int l, int i, int j) {
  if(l == 0) {
    assert(i == 0 && j == 0);
    return 0;
  } else {
    return dist00(l-1, i % tri[l-1], j % tri[l-1]) + tri[l-1] * (i / tri[l-1] + j / tri[l-1]);
  }
}

inline int distLU(int l, int i, int j) {
  return dist00(l, i % tri[l], j % tri[l]);
}

inline int distLD(int l, int i, int j) {
  return dist00(l, tri[l] - 1 - i % tri[l], j % tri[l]);
}

inline int distRU(int l, int i, int j) {
  return dist00(l, i % tri[l], tri[l] - 1 - j % tri[l]);
}

inline int distRD(int l, int i, int j) {
  return dist00(l, tri[l] - 1 - i % tri[l], tri[l] - 1 - j % tri[l]);
}

void solve() {
  tri[0] = 1;
  times(30, x) tri[x + 1] = tri[x] * 3;

  int Q; cin >> Q;
  times(Q, q) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    --a; --b; --c; --d;
    if(abs(a - c) > abs(b - d)) {
      swap(a, b); swap(c, d);
    }
    if(b > d) {
      swap(a, c); swap(b, d);
    }

    int l = 30;
    while(l > 0 && sameRow(l, a, c) && freeColumnRange(l, a, b, d)) {
      --l;
    }
    // dd l; a; b; c; d;
    if(sameRow(l, a, c) && freeColumnRange(l, a, b, d)) {
      assert(l == 0);
      cout << d - b ln;
    } else if(sameRow(l, a, c)) {
      assert(!freeColumnRange(l, a, b, d));
      cout << min(
        distRU(l, a, b) + distLU(l, c, d) + tri[l] * (d / tri[l] - b / tri[l] - 1),
        distRD(l, a, b) + distLD(l, c, d) + tri[l] * (d / tri[l] - b / tri[l] - 1)
      ) + 3 ln;
    } else if(a < c) {
      {if(debug)cerr<<'#'<<__LINE__ ln<<"  l:                                                                "<<(l)ln<<"  a:                                                                "<<(a)ln<<"  b:                                                                "<<(b)ln<<"  c:                                                                "<<(c)ln<<"  d:                                                                "<<(d)ln<<"  distRD(l, a, b):                                                  "<<(distRD(l, a, b))ln<<"  distLU(l, c, d):                                                  "<<(distLU(l, c, d))ln<<"  tri[l] * (d / tri[l] - b / tri[l] + c / tri[l] - a / tri[l] - 2): "<<(tri[l] * (d / tri[l] - b / tri[l] + c / tri[l] - a / tri[l] - 2))ln;}
      cout << distRD(l, a, b) + distLU(l, c, d) + tri[l] * (d / tri[l] - b / tri[l] + c / tri[l] - a / tri[l] - 2) + 2 ln;
    } else {
      cout << distRU(l, a, b) + distLD(l, c, d) + tri[l] * (d / tri[l] - b / tri[l] + a / tri[l] - c / tri[l] - 2) + 2 ln;
    }
  }
}
