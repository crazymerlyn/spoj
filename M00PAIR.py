def f(n):
    if n % 2 == 0:
        if n == 2: return 1
        n = n // 2 - 1
        return 1 + 2 * (4 ** n - 1) // 3

    if n == 1: return 0
    n = (n - 1) // 2

    return (4 ** n - 1) // 3

try:
    while True:
        n = int(input())
        print(f(n))
except:
    pass

