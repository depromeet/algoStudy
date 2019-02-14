def gaming_array():
    for _ in range(int(input())):
        n = int(input())
        arr = list(map(int, input().split()))

        max = 0
        cnt = 0

        for a in arr:
            if max < a:
                cnt += 1
                max = a

        print("ANDY" if cnt % 2 == 0 else "BOB")


gaming_array()