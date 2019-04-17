import sys

for line in sys.stdin.readlines():
    n = int(line.strip())
    res = 1
    while n != 1:
        if n % 2 == 0:
            res += 1
            n //= 2
        else:
            res += 2
            n = (n * 3 + 1) // 2
    print(res)
