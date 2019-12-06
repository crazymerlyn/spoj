from collections import defaultdict
n, k = [int(x) for x in input().split()]
xs = [int(x) for x in input().split()]

res = 0
d = defaultdict(int)
for x in xs:
    res += d[x-k] + d[x+k]
    d[x] += 1
print(res)
