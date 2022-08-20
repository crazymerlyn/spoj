n, x = [int(x) for x in input().split()]

if x > sum(3**i for i in range(n)):
    print(-1)
    exit()

first = []
second = []

i = 1
while x:
    if x % 3 == 1:
        first.append(i)
    elif x % 3 == 2:
        second.append(i)
        x += 1
    i += 1
    x //= 3

print(*second)
print(*first)
