mod = 10 ** 9 + 7
div2 = (mod + 1) // 2

def f(n, k):
    n -= 1
    return (k - 1) * (pow(k, n, mod) + pow(k - 2, n, mod)) * div2 % mod

for _ in range(int(input())):
    n, k = [int(x) for x in input().split()]
    print(f(n, k))

