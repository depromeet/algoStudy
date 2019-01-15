n, p = map(int, input().split())

graph = [[] for _ in range(n)]
visited = [False] * n

for _ in range(p):
    s, e = map(int, input().split())
    graph[s].append(e)
    graph[e].append(s)

def dfs(current):
    global graph, visited

    if visited[current]:
        return 0

    visited[current] = True

    accum = 1
    for g in graph[current]:
        accum += dfs(g)

    return accum

l = []
for i in range(n):
    if not visited[i]:
        l.append(dfs(i))

T = n
ans = 0
for i in l:
    T -= i
    ans += T*i

print(ans)

