for _ in range(int(input())):
    k = int(input())
    n = int(input())
    l = sorted(enumerate(map(int, input().split())), key=lambda t: t[1])

    left = 0
    right = n-1

    ans = [-1, -1]
    while left < right:
        if l[left][1] + l[right][1] > k:
            right -= 1
        elif l[left][1] + l[right][1] == k:
            ans[0], ans[1] = l[left][0]+1, l[right][0]+1
            break
        else:
            left += 1

    print(*sorted(ans))