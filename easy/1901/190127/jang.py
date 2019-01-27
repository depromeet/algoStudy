n = int(input())
cnt = [0]*100

for i in map(int, input().split()):
    cnt[i] += 1

ans = 0
for i in range(1, n):
    if ans < cnt[i] + cnt[i-1]:
        ans = cnt[i] + cnt[i-1]

print(ans)
