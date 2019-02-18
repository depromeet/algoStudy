for _ in range(int(input())):
    n, m, s = map(int, input().split())
    a=(m+s-1)%n
    print(n if a==0 else a)

