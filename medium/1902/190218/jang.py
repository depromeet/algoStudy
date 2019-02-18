for _ in range(int(input())):
    n = int(input())
    rs = [0] * n
    cs = [0] * n

    for j in range(n):
        for i, k in enumerate(map(int, input().split())):
            cs[i] += k
            rs[j] += k

    if sorted(cs) == sorted(rs):
        print("Possible")
    else:
        print("Impossible")