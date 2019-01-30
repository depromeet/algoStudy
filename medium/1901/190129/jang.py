import copy
import sys

sys.setrecursionlimit(25000)

reachable = False
optimized_path = []

def dfs(n, matrix, current_path, r, c, end_r, end_c):
    if r == end_r and c == end_c:
        global reachable, optimized_path
        reachable = True

        if optimized_path == [] or len(current_path) < len(optimized_path):
            optimized_path = copy.deepcopy(current_path)
        return

    if r < 0 or r >= n or c < 0 or c >= n or matrix[r][c] == 1:
        return

    matrix[r][c] = 1

    dirs = [[-2, -1], [-2, 1], [0, 2], [2, 1], [2, -1], [0, -2]]
    path_name = ['UL', 'UR', 'R', 'LR', 'LL', 'L']

    for i, d in enumerate(dirs):
        current_path.append(path_name[i])
        dfs(n, matrix, current_path, r+d[0], c+d[1], end_r, end_c)
        current_path.pop()

    matrix[r][c] = 0

def red_knight():
    n = int(input())
    start_r, start_c, end_r, end_c = map(int, input().split())
    matrix = [[0]*n for _ in range(n)]
    path = []
    dfs(n, matrix, path, start_r, start_c, end_r, end_c)

    if reachable:
        print(len(optimized_path))
        print(*optimized_path)
    else:
        print("Impossible")

red_knight()

