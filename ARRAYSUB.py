def add(stack, x):
    while stack and stack[-1] < x: stack.pop()
    stack.append(x)

def remove(stack, i):
    while stack[0][1] <= i:
        stack.pop(0)

n = int(input())
ns = [int(x) for x in input().split()]
ns = [(x, i) for i, x in enumerate(ns)]
k = int(input())

stack = []
res = []

for i in range(n):
    add(stack, ns[i])
    if i >= k:
        remove(stack, i-k)
    res.append(stack[0][0])

print(" ".join(map(str, res[k-1:])))
