while True:
    line = input().strip()
    if line == "0": break
    n = len(line)
    s = [0] * (n + 1)
    s[0] = 1
    line = "9" + line

    for i in range(1, n+1):
        if line[i] != "0": s[i] += s[i-1]
        if line[i-1] in "12" and int(line[i-1:i+1]) <= 26:
            s[i] += s[i-2]
    print(s[-1])

