# solution1
n, k = map(int, input().split())
if k > n // 2: #어차피 할 것 고르는 것적은 것이 나으니까?
    k = n - k

a = sorted(map(int, input().split()))
dp = [[float('inf') for i in range(n + 1)] for j in range(n + 1)]

dp[0][0] = 0

for i in range(0, n):
    for j in range(0, i + 1):

        if j > k or i - j > n - k:
            continue
        temp_li = dp[i][j] + a[i] * (i - j - (n - k - (i - j)))
        temp_lu = dp[i][j] + a[i] * (j - (k - j))

        if dp[i + 1][j + 1] > temp_li:
            dp[i + 1][j + 1] = temp_li

        if dp[i + 1][j] > temp_lu:
            dp[i + 1][j] = temp_lu

print(dp[n][k])


# solution2

n, k = map(int, input().split())
arr = list(map(int, input().split()))
if k > n // 2: #어차피 할 것 고르는 것적은 것이 나으니까?
    k = n - k

arr.sort()
start = (len(arr) - 2*k + 1) // 2
set_i = set(range(start, start+2*k-1, 2))
result = 0
for i in set_i:
    for j in range(0, len(arr)):
        if j in set_i: continue
        result += abs(arr[i] - arr[j])
print(result)
