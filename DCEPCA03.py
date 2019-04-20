def phi(n):
    res = n
    i = 2
    while i * i <= n:
        if n % i == 0:
            while n % i == 0: n //= i
            res -= res // i
        i += 1
    if n > 1:
        res -= res // n
    return res

limit = 10 ** 4
res = [0 for _ in range(limit + 1)]

for i in range(1, limit+1):
    res[i] = res[i-1] + phi(i)

for _ in range(int(input())):
    print(res[int(input())] ** 2)
