for _ in range(int(input())):
    n = int(input())

    max_3 = n % 3

    while max_3 % 5 != 0:
        max_3 += 3
        if n - max_3 < 0:
            print(-1)
            break
    else:
        print("5" * (n - max_3), end='')
        print("3" * (max_3))
