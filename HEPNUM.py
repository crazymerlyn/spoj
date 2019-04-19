def norm(s):
    return s.lstrip("0") or "0"

while True:
    a, b = input().split()
    if a == '*': break
    a = norm(a)
    b = norm(b)

    a = (len(a), a)
    b = (len(b), b)

    if a > b: print(">")
    elif a < b: print("<")
    else: print("=")
