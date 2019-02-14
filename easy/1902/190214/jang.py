n = int(input())
l = list(map(int, input().split()))
s = sorted(set(l))

ans = 1
m = s[0]

for i in range(1, len(s)):
    if m + 4 < s[i]:
        ans += 1
        m = s[i]

print(ans)
