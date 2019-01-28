def find(parent, x):
    if parent[x] == x: # if x is root
        return x

    parent[x] = find(parent, parent[x])
    return parent[x]

def union(parent, x, y):
    x = find(parent, x)
    y = find(parent, y)

    if x != y:
        parent[y] = x

def kruskal_sum():
    n, m = map(int, input().split())

    edges = []
    parent = [0] + list(range(1, n+1))

    for _ in range(m):
        edges.append(tuple(map(int, input().split())))

    ans = 0
    for start, end, cost in sorted(edges, key=lambda t: t[2]):
        if find(parent, start) != find(parent, end):
            ans += cost
            union(parent, start, end)

    return ans

print(kruskal_sum())