from itertools import groupby

for _ in range(int(input())):
    words = input().strip().split()
    print(max(len(list(l)) for g, l in groupby(words, key=len)))
