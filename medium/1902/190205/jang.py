def new_chaos():
    for _ in range(int(input())):
        n = int(input())
        l = list(map(int, input().split()))
        ans = 0
        for i in range(0, n)[::-1]:
            if l[i] - (i+1) > 2:
                print("Too chaotic")
                break

            for j in range(max(0, l[i]-2), i):
                if l[j] > l[i]:
                    ans += 1
        else:
            print(ans)

new_chaos()