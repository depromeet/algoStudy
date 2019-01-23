n, m = map(int, input().split())
a = list(map(int, input().split()))
D = [0]*251

D[0] = 1

for i in range(m):
    for j in range(a[i], n+1):
        D[j] += D[j-a[i]]

print(D[n])