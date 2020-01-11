gets
a=gets.to_i
$<.map{|l|
  b=l.to_i
  puts a<b ? "up #{b-a}":a>b ? "down #{a-b}":"stay"
  a=b
}
