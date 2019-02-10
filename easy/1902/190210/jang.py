n = int(input())
x = list(map(int, input().split()))

cnt = 0
for i in range(1, len(x)):
    j = i - 1
    key = x[i]
    while x[j] > key and j >= 0:
        cnt += 1
        x[j+1] = x[j]
        j -= 1
    x[j+1] = key

print(cnt)