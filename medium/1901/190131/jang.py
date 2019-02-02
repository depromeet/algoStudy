def dfs(accum, current, chain, answer, visited):
    if visited[current]:
        return

    visited[current] = True
    answer[current] = accum
    for c in chain[current]:
        dfs(accum + 6, c, chain, answer, visited)

def start():
    for _ in range(int(input())):
        n, m = map(int, input().split())
        chain = [[] for _ in range(n)]
        visited = [False]*n
        answer = [0]*n

        for _ in range(m):
            f, t = map(int, input().split())
            chain[f-1].append(t-1)
            chain[t-1].append(f-1)

        s = int(input())
        dfs(0, s-1, chain, answer, visited)
        for i, v in enumerate(answer):
            if i != s-1:
                print(-1 if v == 0 else v, end=' ')
        print()

start()

