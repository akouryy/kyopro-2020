N = gets.to_i
A = gets.chomp.chars.map &:to_i

single = (0...N).filter{|i| A[1<<i] == 0 }
double = [*0...N].combination(2).filter{|i,j| A[(1<<i) + (1<<j)] == 0 }

#p single, double

if A.each_with_index.any?{|a,d|
    a != (single.any?{|i| d[i]==1 } || double.any?{|i,j| d[i]==1&&d[j]==1 } ? 0 : 1)
  } then
  puts "Impossible"
  exit
end

puts "Possible"

ans = [[0,0]]
single.each do |i|
  1.upto(i){|k| ans << [k,0] }
  ans << [i,1]
  ans << [i+1,1]
  (i+1).downto(0){|k| ans << [k,0] }
end
double.each do |i,j|
  1.upto(i){|k| ans << [k,0] }
  i.upto(j+1){|k| ans << [k,1] }
  ans << [j+1,0]
  ans << [j,0]
  j.downto(i){|k| ans << [k,1] }
  i.upto(j){|k| ans << [k,0] }
  ans << [j,1]
  ans << [j+1,1]
  (j+1).downto(0){|k| ans << [k,0] }
end

puts ans.size
puts ans.map{|x,y| "#{x} #{y}" }
