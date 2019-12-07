r=input
print(sum(i for i in map(int,(r() for _ in "1"*r())) if i > 0))
