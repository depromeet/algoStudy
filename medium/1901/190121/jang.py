def start():
    for _ in range(int(input())):
        n, k = map(int, input().split())

        if k == 0:
            print(*list(range(1, n+1)))
        elif n % 2 == 0:
            ans = []
            d = 1
            j = 0
            for i in range(1, n+1):
                if j >= k:
                    d *= -1
                    j = 0

                v = i + d*k
                if v < 1 or v > n:
                    print('-1')
                    break
                ans.append(i + d*k)
                j += 1
            else:
                print(*ans)
        elif k == 1:
            print(n, *list(range(1, n)))
        else:
            print('-1')

start()
