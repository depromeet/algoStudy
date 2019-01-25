from heapq import heappop, heapify

for _ in range(int(input())):
    n = int(input())
    heap = list(map(int, input().split()))
    heapify(heap)
    s = sum(heap)

    cnt = 1
    ans = 0

    while heap:
        current = heappop(heap)
        if ans < cnt*s:
            ans = cnt*s

        cnt += 1
        s -= current

    print(ans)
