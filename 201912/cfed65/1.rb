gets.to_i.times do
  gets
  puts (gets =~ /8\d{10}/ ? :YES : :NO)
end
