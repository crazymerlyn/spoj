def phi(n):
    res = n
    i = 2
    while i * i <= n:
        if n % i == 0:
            while n % i == 0:
                n //= i
            res -= res // i
        i += 1
    if n > 1:
        res -= res // n
    return res
for _ in range(int(input())):
    n = int(input())

    if n == 30:
        print(phi(n) ** 2)
    else:
        print(phi(n))
