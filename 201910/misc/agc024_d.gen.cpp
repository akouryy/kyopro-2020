#line 1 "base.hpp"//a
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
#line 1 "base_util.hpp"//ab
#define BINOPa(t,u,op)t OP op(CS u&o)CS{RT t(*this)op##=o;}
#define CMPOP(t,op,f1,f2,x)bool OP op(CS t&x)CS{RT f1 op f2;}
#define CMPOPS(t,f1,f2,x)CMPOP(t,==,f1,f2,x)CMPOP(t,!=,f1,f2,x)\
CMPOP(t,<,f1,f2,x)CMPOP(t,<=,f1,f2,x)CMPOP(t,>,f1,f2,x)CMPOP(t,>=,f1,f2,x)
#line 1 "mod.hpp"//ab
#ifndef MOD
#define MOD 1000000007
#endif
#if !defined(FORCE_MOD)&&MOD!=1000000007&&MOD!=1000000009&&MOD!=998244353
#error mod
#endif
#line 1 "power.hpp"//abm
TL<TN T>IL T power(T x,int n){T r(1);for(;n;n/=2){if(n%2)r*=x;x*=x;}RT r;}IL int pow_mod(int x,int n,int m){int r=1;
for(;n;n/=2){if(n%2)r=r*x%m;x=x*x%m;}RT r;}
#line 2001 "mod.hpp"//ab
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
#line 1 "typedefs.hpp"//ab
using unit = tuple<>;using int128=__int128;using LD=long double;TL<TN T>using vec=vector<T>;
TL<TN T>using vvec=vec<vec<T>>;TL<TN T>using vvvec=vec<vvec<T>>;TL<TN T>using vvvvec=vec<vvvec<T>>;
using VI=vec<int>;using VB=vec<bool>;
#line 1 "alias.hpp"//ab
#define EB emplace_back
#define PB push_back
#define foldl accumulate
#define scanl partial_sum
#line 1 "util.hpp"//ab
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
#line 1 "debug.hpp"//ab
TL<TN T>IL istream&OP>>(istream&s,vec<T>&v){for(auto&&p:v)s>>p;RT s;}TL<TN T,TN S>
IL ostream&OP<<(ostream&s,CS pair<T,S>&p){RT s<<"("<<p.first<<","<<p.second<<")";}
#define Rdebug1(sep, ...)IL ostream& OP<<(ostream&s,CS __VA_ARGS__&v){\
int i=0;for(CS auto&e:v){i++&&s<<sep;s<<e;}RT s;}
TL<TN T>Rdebug1(' ',vec<T>)TL<TN T,TN S>Rdebug1(' ',map<T,S>)TL<TN T>Rdebug1('\n',vvec<T>)
TL<TN T,TN S>Rdebug1('\n',vec<map<T,S>>)
#line 6001 "base.hpp"//a
signed main(){if(debug)cerr<<"MOD: "<<MOD ln;else cin.tie(0),cerr.tie(0),ios::sync_with_stdio(0);
auto p=setprecision(20);cout<<fixed<<p;cerr<<fixed<<p;
#ifdef GCJ_CASE
int T;cin>>T;times(T,t){cout<<"Case #"<<t+1<<": ";solve(t);}
#else
solve();
#endif
RT 0;}
#line 1 "graph.hpp"//a
TL<TN E>struct Edge{int from;int to;E weight;Edge(int from,int to,E weight):from(from),to(to),weight(weight){}
CMPOPS(Edge,make_tuple(weight,from,to),make_tuple(e.weight,e.from,e.to),e)};TL<TN E>class Graph{protected:int nv_,nde_;
public:vvec<Edge<E>>edges;Graph(int nv):nv_(nv),nde_(0),edges(nv){}IL int nv()CS{RT nv_;}IL int nde()CS{RT nde_;}
IL int nue()CS{RT nde_/2;}IL void add_dedge(int i,int j,CS E&val){if(debug&&(i<0||nv_<=i||j<0||nv_<=j)){
cerr<<"invalid index:("<<i<<","<<j<<")for Graph(nv="<<nv_<<")" ln;exit(1);}edges[i].emplace_back(i,j,val);++nde_;}
IL void add_uedge(int i,int j,CS E&val){add_dedge(i,j,val);add_dedge(j,i,val);}};
#line 2001 "agc024_d.cpp"//

void solve() {
/* <foxy.memo-area> */
int N;cin>>N;VI A(N);VI B(N);times(N-1,Ri_0){cin>>A[Ri_0];--A[Ri_0];cin>>B[Ri_0];--B[Ri_0];}
/* </foxy.memo-area> */

  Graph<int> tree(N);
  times(N-1, j) tree.add_uedge(A[j], B[j], 0);

  VI dist(N);
  int farthest = 0, farthest_dist = 0;
  function<void(int, int, int)> tree_center_dfs = [&](int i, int p, int d) {
    dist[i] = d;
    for(auto &e : tree.edges[i]) if(e.to != p) {
      tree_center_dfs(e.to, i, d + 1);
    }
    if(amax(farthest_dist, d)) farthest = i;
  };

  tree_center_dfs(0, 0, 0);
  farthest_dist = 0;
  tree_center_dfs(farthest, farthest, 0);
  int diam = farthest_dist;
  VI dist1 = dist;
  int v1 = farthest;
  farthest_dist = 0;
  tree_center_dfs(farthest, farthest, 0);
  VI &dist2 = dist;
  int v2 = farthest;

  {if(debug)cerr<<'#'<<__LINE__ ln<<"  diam:  "<<(diam)ln<<"  v1:    "<<(v1)ln<<"  v2:    "<<(v2)ln<<"  dist1: "<<(dist1)ln<<"  dist2: "<<(dist2)ln;}
  VI centers;
  times(N, i) {
    if((dist1[i] == diam / 2 && dist2[i] == (diam + 1) / 2) ||
       (dist2[i] == diam / 2 && dist1[i] == (diam + 1) / 2)) {
      centers.PB(i);
    }
  }

  cout << diam / 2 + 1 sp;


  auto calc = [&](VI lv) {
    VB vis(N);
    int ans = size(lv);

    VI lw;

    times(diam / 2, h) {
      // [invar] lw: empty
      int mx = 1;
      for(int i : lv) vis[i] = true;
      for(int i : lv) {
        int k = 0;
        for(auto &e : tree.edges[i]) if(!vis[e.to]) {
          ++k;
          lw.PB(e.to);
        }
        amax(mx, k);
      }
      ans *= mx;
      {if(debug)cerr<<'#'<<__LINE__ ln<<"  h:  "<<(h)ln<<"  lv: "<<(lv)ln<<"  mx: "<<(mx)ln;}
      swap(lv, lw);
      lw.clear();
    }

    return ans;
  };

  switch(size(centers)) {
    case 1: {
      int ans = calc(centers);
      for(auto &e : tree.edges[centers[0]]) {
        amin(ans, calc({ centers[0], e.to }));
      }
      cout << ans;
      break;
    }
    case 2:
      cout << calc(centers);
      break;
    default:
      if(debug) {
        {if(debug)cerr<<"centers: "<<(centers)ln;}
      } else {
        while(1) cout << 1;
      }
  }
}
