import sys
def memoized(func):
    cache = {}
    def newfunc(*args):
        if args not in cache:
            cache[args] = func(*args)
        return cache[args]
    return newfunc

@memoized
def func(n):
    if n < 12: return n
    return max(n, func(n//2) + func(n//3) + func(n//4))


try:
    while True:
        n = int(input())

        print(func(n))
except:
    pass

