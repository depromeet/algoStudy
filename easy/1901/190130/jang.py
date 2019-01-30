n, k = map(int, input().split())
l = sorted(map(int, input().split()))

ans = l[0]
prev = l[0]
for i in range(1, len(l)):
    dist = (l[i] - prev) // 2
    if dist > ans:
        ans = dist
    prev = l[i]

last = (n-1) - l[-1]
if ans < last:
    ans = last

print(ans)