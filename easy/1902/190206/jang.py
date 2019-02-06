for _ in range(int(input())):
    s1 = set(input())
    s2 = set(input())

    print("YES" if s1 & s2 else "NO")