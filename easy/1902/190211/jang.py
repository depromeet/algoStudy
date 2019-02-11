n = int(input())
a = [0]*(n+1)
for i, v in enumerate(map(int, input().split())):
    a[v] = i+1

for i in range(1, n+1):
    print(a[a[i]])