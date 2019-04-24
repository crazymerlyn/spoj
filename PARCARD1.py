limit = 10000

dp = [0] * (limit + 1)
dp[0] = 1

for i in range(1, limit + 1):
    for r in range(1, i + 1):
        a, b = r * (3*r-1)//2 , r * (3*r+1) // 2
        if a > i: break
        dp[i] += (2 * (r % 2) - 1) * dp[i - a]
        if b > i: break
        dp[i] += (2 * (r % 2) - 1) * dp[i - b]

print(*dp)


