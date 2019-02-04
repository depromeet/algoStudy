from heapq import heappop, heappush
from collections import defaultdict

def prim():
    n, m = map(int, input().split())

    graph = defaultdict(list)

    for _ in range(m):
        s, e, w = map(int, input().split())
        graph[s].append((e, w))
        graph[e].append((s, w))

    start = int(input())

    visit = [False]*n

    minheap = []
    heappush(minheap, (0, start)) # push weight, node_num

    answer = 0
    while minheap:
        weight, node_num = heappop(minheap)
        if not visit[node_num-1]:
            visit[node_num-1] = True
            answer += weight
            for num, w in graph[node_num]:
                heappush(minheap, (w, num))

    print(answer)

prim()