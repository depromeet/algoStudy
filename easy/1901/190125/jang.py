from collections import Counter

a = Counter(input())
b = Counter(input())

ans = 0
for k, v in a.items():
    if k in b:
        ans += abs(v - b[k])
    else:
        ans += v

for k, v in b.items():
    if not k in a:
        ans += v

print(ans)

