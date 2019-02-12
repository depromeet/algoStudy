p, d, m, s = map(int, input().split())

ans = 0
while s - p >= 0:
    s -= p
    if p - d <= m:
        p = m
    else:
        p -= d

    ans += 1

print(ans)