def solve(num):
    mod = 10 ** 9 + 7

    n = len(num)
    dp = [int(num[0])]
    ans = dp[0]
    for i in range(1, n):
        dp.append(((i + 1) * int(num[i])) % mod + (10 * dp[i - 1]) % mod)
        ans += (dp[i] % mod)
    return ans % mod


if __name__ == '__main__':
    print(solve(input()))
