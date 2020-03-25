N, *T, X = $<.map{|l| l.split }
a = T.find_index{|s,t| s == X}
p T[a..-1].map{|s,t| t.to_i}.reduce :+
