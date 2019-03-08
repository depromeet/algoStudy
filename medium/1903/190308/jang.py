for _ in range(int(input())):
    n = int(input())
    D = [0] * n
    max_subary = 0

    for i, a in enumerate(map(int, input().split())):
        D[i] = max(D[i - 1] + a, a)
        if a > 0:
            max_subary += a

    if max_subary == 0:
        print(max(D), max(D))
    else:
        print(max(D), max_subary)
