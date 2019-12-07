ans = [0] * 1001
for i in range(1, 1001):
    ans[i] = ans[i-1] + 1./i

for _ in range(int(input())):
    n = int(input())
    print("%.2f" % (ans[n] * n))
