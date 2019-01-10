import sys

ans = sys.maxsize

sys.setrecursionlimit(int(1e6)+1)

def dfs(current_idx, T, chain, v, visited):
    global ans
    if current_idx == -1 or visited[current_idx]:
        return 0

    visited[current_idx] = True

    lower_end = v[current_idx]
    for idx in chain[current_idx]:
        lower_end += dfs(idx, T, chain, v, visited)

    diff = abs(T - 2*lower_end)
    if diff < ans:
        ans = diff

    return lower_end


def start():
    n = int(input())
    v = list(map(int, input().split()))
    T = sum(v)
    visited = [False]*len(v)

    chain = [[] for _ in range(len(v))]

    for _ in range(n-1):
        i, j = map(int, input().split())
        chain[i-1].append(j-1)
        chain[j-1].append(i-1)

    dfs(0, T, chain, v, visited)
    print(ans)

start()



