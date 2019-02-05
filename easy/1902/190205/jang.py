n = int(input())
stones = list(map(int, input().split()))
i = 0
ans = 0
while i < n:
    if i+2 < n and stones[i+2] == 0:
        i += 2
    else:
        i += 1
    ans += 1

print(ans-1)