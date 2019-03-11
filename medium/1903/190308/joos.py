for _ in range(int(input())):
    d = [0] * int(input())
    minus_sum = 0

    for i, v in enumerate(map(int, input().split())):
        d[i] = max(d[i - 1] + v, v)
        if v > 0:
            minus_sum += v

    if minus_sum == 0:
        print(max(d), max(d))
    else:
        print(max(d), minus_sum)
