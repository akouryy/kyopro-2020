N,M=gets.split.map &:to_i

dp = [9e99] * 2**N
dp[0] = 0
$<.each{|l| s,c=l.split; k=s.tr('YN', '10').to_i(2); dp[k] = [dp[k], c.to_i].min }
(2**N-1).downto(0){|b| N.times{|i|
  dp[b] = [dp[b], dp[b | (1<<i)]].min
}}
(2**N).times do |b|
  b.times do |c|
    dp[b|c] = [dp[b|c], dp[b] + dp[c]].min
  end
end
p dp[-1] == 9e99 ? -1 : dp[-1]
