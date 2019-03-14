t1, t2, k = map(int, input().split())
i = 2

while i < k:
    t = t2
    t2 = t1 + t2**2
    t1 = t
    i += 1

print(t2)
