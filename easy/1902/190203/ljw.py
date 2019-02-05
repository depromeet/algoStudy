# n ** 2
input()
sticks = list(map(int, input().split()))

while len(sticks) != 0:
    cnt = 0
    min_value =  min(sticks)
    for i in range(len(sticks)):
        if sticks[i] >= min_value:
            sticks[i] -= min_value
            cnt += 1
    print(cnt)
    sticks = list(filter(lambda x: x > 0, sticks))


# nlogn
from collections import defaultdict # 콜렉션에서 불러옵니다.

d = defaultdict(lambda: 0) # Default 값을 0으로 설정합니다.
input()
sticks = list(map(int, input().split()))
sticks_len = len(sticks)
for s in sticks:
    d[s] += 1
d_sort = sorted(d)

for i in d_sort:
    print(sticks_len)
    sticks_len -= d[i]
