def solve(t1, t2, n):
    dp = [0] * 21
    dp[0] = t1
    dp[1] = t2
    for i in range(2, n):
        dp[i] = dp[i - 1] ** 2 + dp[i - 2]

    return dp[n - 1]


if __name__ == '__main__':
    print(solve(*list(map(int, input().split()))))
