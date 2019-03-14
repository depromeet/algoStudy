for _ in range(int(input())):
    n = int(input())
    grid = [sorted(input()) for _ in range(n)]

    f = True

    for i in range(1, n):
        for j in range(len(grid[i])):
            if grid[i - 1][j] > grid[i][j]:
                print("NO")
                f = False
                break
        if not f:
            break

    if f:
        print("YES")