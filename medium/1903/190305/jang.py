import sys

for _ in range(int(input())):
    n = int(input())
    origin_l = list(map(int, input().split()))
    m = min(origin_l)

    result = sys.maxsize
    for k in range(4):
        l = list(map(lambda t: t - (m - k), origin_l))

        ans = 0
        ds = [5, 2, 1]

        for d in ds:
            mx = 0
            for i in range(n):
                ans += (l[i] // d)
                l[i] %= d

        if result > ans:
            result = ans
    print(result)