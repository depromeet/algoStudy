import sys

def LI(): return [int(x) for x in sys.stdin.readline().split()]


def solve(n, m, lst):
    dp = [0 for _ in range(n+1)]
    dp[0] = 1
    for num in lst:
        for i in range(n+1):
            if i+num > n:
                continue
            dp[i+num] += dp[i]
    return dp[n]

def main():
    n, m = LI()
    lst = LI()
    print(solve(n, m, lst))

main()
