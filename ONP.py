i = 0
res = []
def solve(s):
    def recur():
        global i
        if i >= len(s): return
        if s[i] == '(':
            i += 1
            recur()
            op = s[i]
            i += 1
            recur()
            res.append(op)
        elif s[i] in '+-*/^':
            op = s[i]
            i += 1
            recur()
            res.append(op)
        else:
            res.append(s[i])

        i += 1
    recur()
    return "".join(res)

for _ in range(int(input())):
    s = input()
    print(solve(s))
    i = 0
    res = []
