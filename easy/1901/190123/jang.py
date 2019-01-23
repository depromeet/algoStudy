import sys

input()
l = sorted(map(int, input().split()))
m = sys.maxsize

for i in range(len(l)-1):
    d = abs(l[i] - l[i+1])
    if d < m:
        m = d

for i in range(len(l)-1):
    if abs(l[i] - l[i+1]) == m:
        print(l[i], l[i+1], end = ' ')


