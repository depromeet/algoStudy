def dfs(r, c, mat):
    if r >= len(mat) or r < 0 or c >= len(mat[0]) or c < 0 or mat[r][c] == 0:
        return 0

    mat[r][c] = 0

    ret = 1
    ds = [[1, 0], [-1, 0], [0, 1], [0, -1], [-1, 1], [1, -1], [1, 1], [-1, -1]]
    for d in ds:
        ret += dfs(r+d[0], c+d[1], mat)

    return ret

def start():
    n, m = int(input()), int(input())
    mat = [list(map(int, input().split())) for _ in range(n)]

    ans = 0
    for r in range(n):
        for c in range(m):
            if mat[r][c] == 1:
                dim = dfs(r, c, mat)
                if dim > ans:
                    ans = dim
    return ans

print(start())
