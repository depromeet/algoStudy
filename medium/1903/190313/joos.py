for _ in range(int(input())):
    n = int(input())
    accumulate = 0
    matrix = [list(map(int, input().split())) for _ in range(2*n)]

    for i in range(n):
        for j in range(n):
            accumulate += max(matrix[i][j],
                        matrix[2*n-i-1][j],
                        matrix[i][2*n-j-1],
                        matrix[n*2-i-1][n*2-j-1])

    print(accumulate)
