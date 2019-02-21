for _ in range(int(input())):
    n = int(input())
    arr = [0] + list(map(int, input().split())) + [0]*15
    brr = [0] * len(arr)

    if n & 1: # xxx ... 111일 경우
        t = arr[n]
        arr[n-1] -= 1
        if arr[n-1] < 0:
            arr[n-1] = 0
        arr[n] = 1
        arr[n+1] = 1
        arr[n+2] = t - 1
    else: # xxx ... 000 일 경우
        t = arr[n-1]
        arr[n-2] -= 1
        if arr[n-2] < 0:
            arr[n-2] = 0
        arr[n-1] = 1
        arr[n] += 1
        arr[n+1] = t-1

    if arr[0]:
        for i in range(1, len(arr)):
            arr[i] = arr[i-1]

    cur = 1
    for i in range(0, n+10):
        if arr[i] == 0:
            continue

        if cur & 1 and i & 1:
            brr[cur] = arr[i]
            cur += 1
        elif not (cur & 1) and not (i & 1):
            brr[cur] = arr[i]
            cur += 1
        else:
            brr[cur-1] += arr[i]

    print(cur-1)
    ans_l = []
    for i in range(1, cur):
        ans_l.append(brr[i])

    print(*ans_l)