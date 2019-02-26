n, k = map(int, input().split())
l = list(map(int, input().split()))

result = 0
purchase = 1
cnt = 0

for cost in sorted(l)[::-1]:
    result += purchase*cost
    cnt += 1
    if cnt == k:
        purchase += 1
        cnt = 0

print(result)