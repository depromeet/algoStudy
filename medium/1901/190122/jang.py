ans = 0

def even_tree(current, graph, visited):
    global ans

    if visited[current]:
        return 0

    visited[current] = True
    cnt = 1
    for g in graph[current]:
        cnt += even_tree(g, graph, visited)

    if cnt % 2 == 0:
        ans += 1
        cnt = 0

    return cnt

def solution():
    n, k = map(int, input().split())

    visited = [False]*n
    graph = [[] for _ in range(n)]

    for _ in range(k):
        fm, to = map(int, input().split())
        graph[fm-1].append(to-1)
        graph[to-1].append(fm-1)

    even_tree(0, graph, visited)
    print(ans-1)

solution()