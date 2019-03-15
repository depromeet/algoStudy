def solve(n, matrix):
    ans = 0
    for i in range(n):
        for j in range(n):
            ans += max([
                matrix[i][j],
                matrix[i][2 * n - j - 1],
                matrix[2 * n - i - 1][j],
                matrix[2 * n - i - 1][2 * n - j - 1],
            ])
    return ans


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        m = [list(map(int, input().split())) for _ in range(2 * n)]
        print(solve(n, m))
