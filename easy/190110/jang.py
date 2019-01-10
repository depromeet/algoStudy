from collections import Counter

input()
c1 = Counter(map(int, input().split()))
input()
c2 = Counter(map(int, input().split()))

for k, v in c1.items():
    if k in c2:
        c2[k] -= v

ans = []
for c, v in c2.items():
    if v != 0:
        ans.append(c)

print(' '.join(map(str, sorted(ans))))


