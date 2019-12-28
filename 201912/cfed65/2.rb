require 'prime'

G = 4, 8, 15, 16, 23, 42
G2 = G.combination(2).map{|x,y| [x*y, [x, y]] }.to_h

puts "! 1 2"
puts "! 3 4"
puts "! 1 3"
puts "! 5 5"
$stdout.flush

a = [nil] * 7 # 1-based

q, r, s, t = 4.times.map{ gets.to_i }

a12 = G2[q]
a34 = G2[r]
a13 = G2[s]

a[1] = (a12 & a13)[0]
a[2] = (a12 - [a[1]])[0]
a[3] = (a13 - [a[1]])[0]
a[4] = (a34 - [a[3]])[0]
a[5] = (t ** 0.5).round
a[6] = (G - a)[0]

puts "!#{a * ' '}"
