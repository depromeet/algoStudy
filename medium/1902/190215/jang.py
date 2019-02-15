for _ in range(int(input())):
    n = int(input())
    l = list(map(int, input().split()))

    benefit = 0
    pivot = l[-1]
    for i in l[::-1]:
        if i >= pivot:
            pivot = i
        else:
            benefit += (pivot - i)

    print(benefit)