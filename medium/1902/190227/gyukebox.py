from collections import deque


def is_valid(n, x, y):
    return 0 <= x <= (n - 1) and 0 <= y <= (n - 1)


def bfs(n, c1, c2):
    visited = [[False] * n for _ in range(n)]
    visited[0][0] = True
    q = deque([(0, 0, 0)])
    dirs = [
        (c1, c2), (-c1, c2), (c1, -c2), (-c1, -c2),
        (c2, c1), (-c2, c1), (c2, -c1), (-c2, -c1)
    ]
    while q:
        curr_y, curr_x, curr_cnt = q.popleft()
        for d in dirs:
            dy, dx = d
            next_y = curr_y + dy
            next_x = curr_x + dx
            if is_valid(n, next_y, next_x) and not visited[next_y][next_x]:
                if next_x == n - 1 and next_y == n - 1:
                    return curr_cnt + 1
                q.append((next_y, next_x, curr_cnt + 1))
                visited[next_y][next_x] = True

    return -1


def solve(n):
    # constraints = [[(i, j) for j in range(1, n)] for i in range(1, n)]
    num_moves = [[0] * (n - 1) for _ in range(n - 1)]
    for i in range(n - 1):
        for j in range(i, n - 1):
            num_moves[i][j] = bfs(n, i + 1, j + 1)
            num_moves[j][i] = num_moves[i][j]
    return num_moves


if __name__ == '__main__':
    n = int(input())
    res = solve(n)
    for r in res:
        print(*r)
