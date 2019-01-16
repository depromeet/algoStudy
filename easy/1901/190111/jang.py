for _ in range(int(input())):
    _, k = map(int, input().split())

    s = 0
    for a in map(int, input().split()):
        if a <= 0: s += 1

    print("YES" if k > s else "NO")