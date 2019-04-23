for _ in range(int(input())):
    n = int(input())
    mod = 10 ** 9 + 7

    res = 1
    for i in range(2, 10):
        res += pow((9 // i) + 1, n - 1, mod)

    print(res % mod)

