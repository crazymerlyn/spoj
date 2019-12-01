from math import factorial
res = [0] * 1001

def catalan(n):
    return factorial(2*n) // factorial(n) ** 2 // (n + 1)

for i in range(3, 1001):
    res[i] = catalan(i - 2) % 100007

for _ in range(int(input())):
    n = int(input())
    print(res[n])
