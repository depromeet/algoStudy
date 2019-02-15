for _ in range(int(input())):
    n = int(input())
    l = list(map(int, input().split()))

    benefit = 0
    pivot = l[n - 1]
    for i in range(0, n - 1)[::-1]:
        if l[i] >= pivot:
            pivot = l[i]
        else:
            benefit += (pivot - l[i])

    print(benefit)