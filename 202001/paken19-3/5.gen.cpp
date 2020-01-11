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
using VS=vec<string>;using VI=vec<int>;using VPII=vec<pair<int, int>>;using WI=vvec<int>;using HIVPII=map<int, vec<pair<int, int>>>;
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
TL<TN C,TN D>IL C rightmost_le(CS C&from,CS C&to,CS D&d){auto l=leftmost_gt(from,to,d);RT l==from?to:--l;}
TL<TN C,TN D>IL C rightmost_lt(CS C&from,CS C&to,CS D&d){auto l=leftmost_ge(from,to,d);RT l==from?to:--l;}
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
#line 1 "consts.hpp"//5
int di4[]={-1,0,1,0},dj4[]={0,1,0,-1},di8[]={-1,-1,0,1,1,1,0,-1},dj8[]={0,1,1,1,0,-1,-1,-1,-1},
di_knight[]={-2,-1,1,2,2,1,-1,-2},dj_knight[]={1,2,2,1,-1,-2,-2,-1};namespace dict{
[[maybe_unused]]CX char
YES[]="YES",Yes[]="Yes",yes[]="yes",NO[]="NO",No[]="No",no[]="no",WIN[]="WIN",Win[]="Win",win[]="win",
LOSE[]="LOSE",Lose[]="Lose",lose[]="lose",OK[]="OK",ok[]="ok",NG[]="NG",ng[]="ng",NA[]="NA",na[]="na",
AC[]="AC",ac[]="ac",WA[]="WA",wa[]="wa",FIRST[]="FIRST",First[]="First",first[]="first",
SECOND[]="SECOND",Second[]="Second",second[]="second",
POSSIBLE[]="POSSIBLE",Possible[]="Possible",possible[]="possible",
IMPOSSIBLE[]="IMPOSSIBLE",Impossible[]="Impossible",impossible[]="impossible",
PRIME[]="PRIME",Prime[]="Prime",prime[]="prime",
NOT_PRIME[]="NOT PRIME",Not_Prime[]="Not Prime",not_prime[]="not prime",
UNBOUNDED[]="UNBOUNDED",Unbounded[]="Unbounded",unbounded[]="unbounded",
ALICE[]="ALICE",Alice[]="Alice",alice[]="alice",BOB[]="BOB",Bob[]="Bob",bob[]="bob",
BROWN[]="BROWN",Brown[]="Brown",brown[]="brown",SAME[]="SAME",Same[]="Same",same[]="same",
DIFFERENT[]="DIFFERENT",Different[]="Different",different[]="different",
TAKAHASHI[]="TAKAHASHI",Takahashi[]="Takahashi",takahashi[]="takahashi",AOKI[]="AOKI",Aoki[]="Aoki",aoki[]="aoki";}
#line 1 "uf.hpp"//5
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
#line 3001 "5.cpp"//

void solve() {
// HWH("S")QQ(XYL)
/* <foxy.memo-area> */
int H;int W;int Q;cin>>H;cin>>W;VS S(H);times(H,Ri_0){cin>>S[Ri_0];}cin>>Q;VI I(
Q);VI J(Q);VI L(Q);times(Q,Ri_0){cin>>I[Ri_0];--I[Ri_0];cin>>J[Ri_0];--J[Ri_0];cin>>L[Ri_0];}
/* </foxy.memo-area> */

  VPII g; times(Q, k) g.PB(make_pair(L[k], k));
  sort(iter(g)); reverse(iter(g));

  WI space(H+1, VI(W+1, 1ll<<60));
  times(H+1, i) space[i][W] = 0;
  times(W+1, j) space[H][j] = 0;
  rtimes(H, i) rtimes(W, j)
  space[i][j] = S[i][j] == '#' ? 0 : 1 + min(min(space[i][j+1], space[i+1][j]), space[i+1][j+1]);
  {if(debug)cerr<<"space: "<<(space)ln;}
  HIVPII rev;
  times(H, i) times(W, j) rev[space[i][j]].PB(make_pair(i, j));

  VI ans(Q);
  UnionFind<> uf(H * W);
  int l_now = max(H, W) + 1;
  for(auto &tmp : g) {
    int k = tmp.second;
    downto(l_now-1, L[k], l) {
      for(auto &ij : rev[l]) {
        int i, j; tie(i, j) = ij;
        times(4, d) {
          int ii = i + di4[d], jj = j + dj4[d];
          if(0 <= ii && ii < H && 0 <= jj && jj < W && space[ii][jj] >= l) {
            uf.merge(i * W + j, ii * W + jj);
          }
        }
      }
    }
    if(debug) {
      cerr << k ln;
      times(H, i) {
        times(W, j) cerr << uf.root(i * W + j) sp;
        cerr ln;
      }
    }
    l_now = L[k];
    ans[k] = uf.zs[uf.root(I[k] * W + J[k])];
  }

  times(Q, k) cout << ans[k] ln;
}
