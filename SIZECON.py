r=input
print(sum(i*(i>0)for i in map(int,(r() for _ in range(r())))))
