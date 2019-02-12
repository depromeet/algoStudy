from collections import defaultdict
import sys

sys.setrecursionlimit(20000)


def dfs(visit, graph, current, cost):
    if visit[current][cost]:
        return

    visit[current][cost] = True

    for g in graph[current]:
        dfs(visit, graph, g[0], cost | g[1])


def min_penalty():
    V, E = map(int, input().split())
    graph = defaultdict(list)

    for _ in range(E):
        s, e, c = map(int, input().split())
        graph[s].append((e, c))
        graph[e].append((s, c))

    A, B = map(int, input().split())

    visit = [[False] * 1024 for _ in range(1001)]
    dfs(visit, graph, A, 0)

    for i, v in enumerate(visit[B]):
        if v:
            print(i)
            break
    else:
        print(-1)


min_penalty()


