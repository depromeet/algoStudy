from copy import deepcopy

n = int(input())
m = [list(map(int, input())) for _ in range(n)]
ans = deepcopy(m)

if n < 3:
    for r in m:
        print(''.join(map(str, r)))
else:
    for i in range(1, n-1):
        for j in range(1, n-1):
            c = m[i][j]
            if m[i-1][j] < c and m[i+1][j] < c and m[i][j-1] < c and m[i][j+1] < c:
                ans[i][j] = 'X'

    for r in ans:
        print(''.join(map(str, r)))
