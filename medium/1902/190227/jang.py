from collections import deque


def check_boundary(r, c, n):
    return 0 <= r < n and 0 <= c < n


def bfs(a, b, n):
    q = deque([(0, 0, 0)])
    dirs = [[a, b], [-a, b], [-a, -b], [a, -b],
            [b, a], [-b, a], [-b, -a], [b, -a]]
    visited = [[False]*n for _ in range(n)]

    visited[0][0] = True
    while q:
        current_r, current_c, depth = q.popleft()

        depth += 1

        for dr, dc in dirs:
            new_r = current_r + dr
            new_c = current_c + dc
            if check_boundary(new_r, new_c, n) and not visited[new_r][new_c]:
                if new_r == n-1 and new_c == n-1:
                    return depth

                q.append((new_r, new_c, depth))
                visited[new_r][new_c] = True

    return -1

def knightL():
    n = int(input())

    answer = [[0]*(n-1) for _ in range(n-1)]

    for i in range(1, n):
        for j in range(i, n):
            answer[i-1][j-1] = bfs(i, j, n)
            answer[j-1][i-1] = answer[i-1][j-1]

    for ans in answer:
        print(*ans)


knightL()