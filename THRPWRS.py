while True:
    n = int(input())
    if n == 0: break

    res = ", ".join(str(3 ** i) for i, b in enumerate(bin(n-1)[2:][::-1]) if b == '1')
    if res: res += " "

    print("{ " + res + "}")
