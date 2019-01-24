n, k = map(int, input().split())
arr = list(map(int, input().split()))

page = 1
ans = 0
for probs in arr:
    cnt = 1
    for i in range(1, probs+1):
        if page == i:
            ans += 1

        if cnt == k:
            page += 1
            cnt = 1
        else:
            cnt += 1
    if probs % k != 0:
        page += 1

print(ans)