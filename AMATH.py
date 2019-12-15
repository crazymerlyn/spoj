import sys
from math import gcd

def facs(n):
    a, b = 0, 0
    while n % 2 == 0:
        n //= 2
        a += 1
    while n % 5 == 0:
        n //= 5
        b += 1
    return a, b

def ans(n, m):
    """Find T such that n ** T = 1 (mod m)"""
    if gcd(n, m) != 1: return -1
    phi = m
    if m % 2 == 0: phi -= phi // 2
    if m % 5 == 0: phi -= phi // 5

    a, b = facs(phi)
    res = [[n]*(b+1) for _ in range(a+1)]
    for j in range(1, b+1): res[0][j] = res[0][j-1] ** 5 % m
    for i in range(1, a+1):
        for j in range(b+1):
            res[i][j] = res[i-1][j] ** 2 % m
    for i, j in sorted([(i, j) for i in range(a+1) for j in range(b+1)], key=lambda x: 2 ** x[0] * 5 ** x[1]):
        if res[i][j] == 1:
            return 2 ** i * 5 ** j

for line in sys.stdin.readlines():
    n, k = [int(x) for x in line.strip().split()]
    k = 10 ** k
    g = gcd(n, k)
    k //= g
    n %= k

    if k == 1:
        print(1)
        exit()

    print(ans(n, k))

