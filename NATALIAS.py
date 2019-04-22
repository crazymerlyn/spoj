for _ in range(int(input())):
    s = input().replace(' ', '')
    i = 0
    res = []

    def f():
        global i, s
        if i == len(s): return
        if s[i] == 'T':
            res.append(True)
            i += 1
            return
        if s[i] == 'F':
            res.append(False)
            i += 1
            return
        if s[i] == 'N':
            i += 4
            f()
            res[-1] = not res[-1]
            i += 1
            return
        if s[i] == 'A':
            i += 4
            f()
            i += 1
            f()
            i += 1
            res[-2] = res[-2] and res[-1]
            res.pop()
            return
        if s[i] == 'O':
            i += 3
            f()
            i += 1
            f()
            i += 1
            res[-2] = res[-2] or res[-1]
            res.pop()
            return


    f()
    print('T' if res[0] else 'F')
