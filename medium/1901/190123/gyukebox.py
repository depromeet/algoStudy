import os

dp = [0] * 251
dp[0] = 1


def getWays(n, m, coins):
    global dp

    for i in range(m):
        for j in range(coins[i], n + 1):
            print(i, j, coins[i])
            dp[j] += dp[j - coins[i]]

    return dp[n]


if __name__ == '__main__':
    nm = input().split()
    n = int(nm[0])
    m = int(nm[1])
    c = list(map(int, input().rstrip().split()))
    ways = getWays(n, m, c)
    print(ways)
