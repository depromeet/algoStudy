v, q = map(int, input().split())
l = list(map(int, input().split()))
for _ in range(q):
    s, e = map(int, input().split())
    print(min(l[s:e+1]))