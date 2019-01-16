from collections import Counter

input()
ans = 0
for c in Counter(map(int, input().split())).values():
    ans += c//2
print(ans)
