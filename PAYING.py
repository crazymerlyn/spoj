for _ in range(int(input())):
    n = int(input())

    val = 1
    cnt = 0
    while val <= n:
        cnt += 1
        val *= 2
    val //= 2
    val -= 1

    print(cnt - 1 + bin(n - val)[2:].count("1"))

