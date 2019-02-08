import math

dp = [1] * 41
dp[3] = 2


def num_prime(n):
    prime = [True] * (n + 1)
    prime[0] = False
    prime[1] = False

    div = int(math.sqrt(n))
    for i in range(2, div + 1):
        if prime[i]:
            for j in range(i ** 2, n + 1, i):
                prime[j] = False

    return prime.count(True)


def redJohn(n):
    global dp
    for i in range(4, n):
        dp[i] = dp[i - 1] + dp[i - 4]

    k = dp[n - 1]
    return num_prime(k)


if __name__ == '__main__':
    t = int(input())
    for t_itr in range(t):
        n = int(input())
        result = redJohn(n)
        print(result)
