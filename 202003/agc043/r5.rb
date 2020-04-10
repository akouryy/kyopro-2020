*Z,Q=[h=0,1],->i,j{i<2?[[j,1],[j,0]]:(s=Q[i/2,j+1];i%2<1?s:[a=[j,1],*s,a,a=[j,0],*s.reverse,a])}
G=->((q,r)){
x,y=Z[-1]
(q<x ?x.downto(t=q+1):(x..t=q)).map{|s|Z<<[s,0]}
r>0&&Z<<[t,1]
Z<<[u=2*q+1-t,r]
r<1&&Z<<[u,1]
}
N=gets.to_i
A=gets.chars{|c|
c==?0&&(0...1<<N).all?{|j|h&j!=j||h==j||$_[j]>?0}&&Q[h,0].map(&G)
h+=1
}
Z[-1][0]>0&&G[[0,0]]
puts [*0...1<<N].combination(2).any?{|i,j|i&j==i&&A[i]<A[j]}?:Impossible:[:Possible,Z.size-1,Z.map{|z|z*?\s}]
