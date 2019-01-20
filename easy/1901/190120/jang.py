for _ in range(int(input())):
    n = int(input())
    a = int(input())
    b = int(input())

    t = min(a, b)
    t2 = max(a, b)

    s = set()
    for i in range(n):
        s.add(t*(n-1-i) + t2*i)
    print(' '.join(map(str, sorted(s))))
