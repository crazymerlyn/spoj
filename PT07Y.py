n, m = [int(x) for x in input().split()]

if m != n - 1:
    print("NO")
    exit()

graph = [[] for _ in range(n+1)]

for _ in range(m):
    u, v = [int(x) for x in input().split()]
    graph[u].append(v)
    graph[v].append(u)

seen = [0] * (n+1)
q = [1]
while q:
    node = q.pop()
    for adj in graph[node]:
        if seen[adj]: continue
        seen[adj] = 1
        q.append(adj)
if 0 in seen[1:]:
    print("NO")
else:
    print("YES")
