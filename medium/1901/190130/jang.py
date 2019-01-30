n, k = map(int, input().split())
a = list(map(int, input()))
l = []

accum = 0
for i in range(n):
    l.append(accum ^ a[i])
    accum ^= l[-1]
    if i >= k-1:
        accum ^= l[i-k+1]
    print(l[i], end='')

