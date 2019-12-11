from decimal import *
limit = 20

getcontext().prec = 200000

def f(n):
    s = Decimal(1.4142135623730950488)
    for _ in range(n):
        s = s/2 + 1/s
    return s
print(f(limit))
#print(Decimal(2).sqrt())
