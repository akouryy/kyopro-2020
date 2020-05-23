#define GCJ_CASE
#line 1 "base.hpp"//3
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
#include<sstream>
#include<type_traits>
#include<unordered_set>
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
#line 1 "base_util.hpp"//3b
#define BINOPa(t,u,op)t OP op(CS u&o)CS{RT t(*this)op##=o;}
#define CMPOP(t,op,f1,f2,x)bool OP op(CS t&x)CS{RT f1 op f2;}
#define CMPOPS(t,f1,f2,x)CMPOP(t,==,f1,f2,x)CMPOP(t,!=,f1,f2,x)\
CMPOP(t,<,f1,f2,x)CMPOP(t,<=,f1,f2,x)CMPOP(t,>,f1,f2,x)CMPOP(t,>=,f1,f2,x)
#line 1 "mod.hpp"//3b
#ifndef MOD
#define MOD 1000000007
#endif
#if !defined(FORCE_MOD)&&MOD!=1000000007&&MOD!=1000000009&&MOD!=998244353
#error mod
#endif
#line 1 "power.hpp"//3bm
TL<TN T>IL T power(T x,int n){T r(1);for(;n;n/=2){if(n%2)r*=x;x*=x;}RT r;}IL int pow_mod(int x,int n,int m){int r=1;
for(;n;n/=2){if(n%2)r=r*x%m;x=x*x%m;}RT r;}
#line 2001 "mod.hpp"//3b
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
#line 1 "typedefs.hpp"//3b
using unit = tuple<>;using LD=long double;TL<TN T>using vec=vector<T>;
TL<TN T>using vvec=vec<vec<T>>;TL<TN T>using vvvec=vec<vvec<T>>;TL<TN T>using vvvvec=vec<vvvec<T>>;
using VI=vec<int>;using HPIIVPII=map<pair<int, int>, vec<pair<int, int>>>;using VPII=vec<pair<int, int>>;
#line 1 "alias.hpp"//3b
#define EB emplace_back
#define PB push_back
#define foldl accumulate
#define scanl partial_sum
#line 1 "util.hpp"//3b
TL<TN T>IL bool amax(T&v,CS T&a){RT v<a&&(v=a,1);}TL<TN T>IL bool amin(T&v,CS T&a){RT v>a&&(v=a,1);}
TL<TN T>IL int sizeRAB(T t){RT t.size();}
#define size sizeRAB
#define clamp clampRAB
TL<TN T>IL CX CS T&clamp(CS T&a,CS T&l,CS T&r){RT a<l?l:r<a?r:a;}TL<TN V>IL void uniq2(V&v){
v.erase(unique(iter(v)),v.end());}TL<TN V>IL void uniq(V&v){sort(iter(v));uniq2(v);}
#define leftmost_ge lower_bound
#define leftmost_gt upper_bound
TL<TN C,TN D>IL decltype(end(C()))rightmost_le(CS C&set,CS D&d){auto l=set.leftmost_gt(d);
RT l==begin(set)?end(set):--l;}TL<TN C,TN D>IL decltype(end(C()))rightmost_lt(CS C&set,CS D&d){
auto l=set.leftmost_ge(d);RT l==begin(set)?end(set):--l;}TL<TN C,TN D>IL C rightmost_le(CS C&from,CS C&to,CS D&d){
auto l=leftmost_gt(from,to,d);RT l==from?to:--l;}TL<TN C,TN D>IL C rightmost_lt(CS C&from,CS C&to,CS D&d){
auto l=leftmost_ge(from,to,d);RT l==from?to:--l;}namespace rab{TL<TN I>IL bool is_in(I x,I l,I r){RT l<=x&&x<r;}
TL<TN T>IL T fetch(CS T&d,CS vec<T>&v,int i){RT 0<=i&&i<size(v)?v[i]:d;}}
#line 1 "debug.hpp"//3b
TL<TN T,TN S>IL ostream&OP<<(ostream&s,CS pair<T,S>&p);TL<TN T,TN U,TN V>IL ostream&OP<<(ostream&s,CS tuple<T,U,V>&p);
TL<TN T>IL ostream&OP<<(ostream&s,CS vec<T>&p);TL<TN T,TN S>IL ostream&OP<<(ostream&s,CS map<T,S>&p);TL<TN T>
IL ostream&OP<<(ostream&s,CS vvec<T>&p);TL<TN T,TN S>IL ostream&OP<<(ostream&s,CS vec<map<T,S>>&p);TL<TN T>
IL istream&OP>>(istream&s,vec<T>&v){for(auto&&p:v)s>>p;RT s;}TL<TN T,TN S>IL ostream&OP<<(ostream&s,CS pair<T,S>&p){
RT s<<"("<<p.first<<","<<p.second<<")";}TL<TN T,TN U,TN V>IL ostream&OP<<(ostream&s,CS tuple<T,U,V>&p){
RT s<<"("<<get<0>(p)<<","<<get<1>(p)<<","<<get<2>(p)<<")";}
#define Rdebug1(sep, ...)IL ostream& OP<<(ostream&s,CS __VA_ARGS__&v){\
int i=0;for(CS auto&e:v){i++&&s<<sep;s<<e;}RT s;}
TL<TN T>Rdebug1(' ',vec<T>)TL<TN T,TN S>Rdebug1(' ',map<T,S>)TL<TN T>Rdebug1('\n',vvec<T>)
TL<TN T,TN S>Rdebug1('\n',vec<map<T,S>>)
#line 6001 "base.hpp"//3
signed main(){if(debug)cerr<<"MOD: "<<MOD ln;else cin.tie(0),cerr.tie(0),ios::sync_with_stdio(0);
auto p=setprecision(20);cout<<fixed<<p;cerr<<fixed<<p;
#ifdef GCJ_CASE
int T;cin>>T;times(T,t){cout<<"Case #"<<t+1<<": ";solve(t);}
#else
solve();
#endif
RT 0;}
#line 1 "math.hpp"//3
IL int int_abs(int k){RT k>=0?k:-k;}IL int int_sign(int k){RT k>0?1:k==0?0:-1;}
int gcd(int a,int b){int t;while(b)t=b,b=a%b,a=t;RT int_abs(a);}
#line 1 "uf.hpp"//3
TL<class T=int,class Adder=plus<T>,class Inverser=negate<T>>struct UnionFind{
/*!
http://noshi91.hatenablog.com/entry/2018/05/30/191943
https://en.wikipedia.org/wiki/Disjoint-set_data_structure
https://qiita.com/drken/items/cce6fc5c579051e64fab
*/
int n,*par,*zs/*sizes*/;
T*pot;bool dl;Adder add;Inverser inv;explicit UnionFind(int n,T t0=0,bool dl=false):
n(n),par(new int[n]),zs(new int[n]),pot(new T[n]),dl(dl){clear(t0);}void clear(T t0=0){times(n,i)par[i]=i;
fill(zs,zs+n,1);fill(pot,pot+n,t0);}~UnionFind(){if(dl){delete[]par;delete[]zs;delete[]pot;}}int size(){RT n;}
int root(int i){int p=par[i];if(p==i)RT i;int r=root(p);pot[i]+=pot[p];RT par[i]=r;}
bool is_same(int i,int j){RT root(i)==root(j);}bool is_all_same(){int r=root(0);uptil(1,n,i)if(root(i)^r)RT 0;RT 1;}
bool merge(int i,int j,T pdiff=0){i=root(i);j=root(j);if(i==j)RT 0;if(zs[i]>zs[j]){swap(i,j);pdiff=inv(pdiff);}
par[i]=j;zs[j]+=zs[i];pot[i]=pdiff;RT 1;}T diff(int i,int j){root(i);root(j);RT add(pot[i],inv(pot[j]));}};
using unionfind=UnionFind<>;
#line 3001 "3.cpp"//
//#include "consts.hpp"

void solve(int case_id) {
  int N; cin >> N;
  VI X(N), Y(N);
  times(N, i) cin >> X[i] >> Y[i];

  HPIIVPII fromSlopes;
  times(N, j) times(j, i) {
    int dx = X[i] - X[j], dy = Y[i] - Y[j];

    int sx, sy;
    if(dx == 0) {
      sx = 0; sy = 1;
    } else if(dy == 0) {
      sx = 1; sy = 0;
    } else {
      int g = gcd(dx, dy);
      sx = dx / g; sy = dy / g;
      if(sx < 0) {
        sx = -sx; sy = -sy;
      }
    }
    {if(debug)cerr<<'#'<<__LINE__ ln<<"  i:  "<<(i)ln<<"  j:  "<<(j)ln<<"  sx: "<<(sx)ln<<"  sy: "<<(sy)ln;}
    fromSlopes[(make_pair(sx, sy))].EB(i, j);
  }
  {if(debug)cerr<<"fromSlopes: "<<(fromSlopes)ln;}
  int ans = 0;
  unionfind uf(N);

  if(N == 1) {
    cout << 1 ln;
    return;
  }

  for(const auto& p : fromSlopes) {
    int sx = p.first.first, sy = p.first.second;
    const VPII& ijs = p.second;

    if(size(ijs) == 1) {
      // [1*, 2]
      amax(ans, min(N, 4LL));
      continue;
    }

    uf.clear();
    for(const auto& ij : ijs) {
      uf.merge(ij.first, ij.second);
    }

    int oneCnt = 0, nonOneSum = 0, oddCnt = 0;
    times(N, i) {
      if(uf.root(i) == i) {
        int s = uf.zs[i];
        if(s == 1) {
          ++oneCnt;
        } else {
          nonOneSum += s;
          if(s % 2 == 1) ++oddCnt;
        }
      }
    }
    int a = nonOneSum + min(oneCnt, oddCnt % 2 == 0 ? 2LL : 1LL);
    {if(debug)cerr<<'#'<<__LINE__ ln<<"  sx:        "<<(sx)ln<<"  sy:        "<<(sy)ln<<"  oneCnt:    "<<(oneCnt)ln<<"  nonOneSum: "<<(nonOneSum)ln<<"  oddCnt:    "<<(oddCnt)ln<<"  a:         "<<(a)ln;}
    amax(ans, a);
  }

  cout << ans ln;
}
