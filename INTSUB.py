for t in range(1, int(input()) + 1):
    n = int(input()) * 2
    res = 0
    mod = 10 ** 9 + 7
    for i in range(1, n + 1):
        left = n - i
        muls = n // i - 1

        res += pow(2, left, mod) - pow(2, left - muls, mod)
        res %= mod

    print("Case %d: %d" % (t, (res + mod) % mod))

