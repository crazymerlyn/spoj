for _ in range(int(input())):
    s = input()
    n = len(s)
    xs = [int(c == 's') for c in s]
    for i in range(1, n):
        xs[i] += xs[i-1]

    ys = [0] * n
    for i, c in enumerate(s):
        if i > 0: ys[i] += ys[i-1]
        if c == 'm': ys[i] += xs[i]

    zs = [0] * n
    for i, c in enumerate(s):
        if i > 0: zs[i] += zs[i-1]
        if c == 's': zs[i] += ys[i]

    print(zs[-1])

