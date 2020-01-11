c = [0] * gets.to_i
$<.each do |l|
  c[l.to_i - 1] += 1
end
if x=c.index(0)
  puts "#{c.index(2)+1} #{x+1}"
else
  puts :Correct
end
