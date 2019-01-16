import sys
n = int(input())
sorted_set = sorted(enumerate(map(int, input().split())), key=lambda t: t[1])

prev = sorted_set[0]

result = sys.maxsize
for i in range(1, n):
    current = sorted_set[i]
    diff = current[1] - prev[1]
    if prev[0] > current[0] and diff < result:
        result = diff
    prev = current

print(result)