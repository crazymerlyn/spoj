from fractions import gcd

res = 0

for _ in range(3):
    res = gcd(res, int(input()))
print(res)
