for i in range(int(input())):
    s = input()
    n = max(len(set(s)), 2)
    d = {}
    cur = 0

    for c in s:
        if c not in d:
            d[c] = cur
            cur += 1

    ans = 0
    for c in s:
        ans = ans * n + (d[c] if d[c] > 1 else (1-d[c]))

    print(f"Case #{i+1}: {ans}")

