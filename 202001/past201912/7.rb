(N,),*A=$<.map{|l|l.split.map &:to_i}

p [0,1,2].product(*[[0,1,2]]*~-N).map{|t|
  score = 0
  N.times{|j| j.times{|i| score += A[i][j-i-1] if t[i] == t[j] }}
  score
}.max
