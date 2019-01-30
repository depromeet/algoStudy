def fair_ration():
    input()
    a = list(map(int, input().split()))

    ans = 0
    for i in range(len(a)-1):
        if a[i] % 2 == 1:
            a[i] += 1
            a[i+1] += 1
            ans += 2

    if a[-1] % 2 == 1:
        return "NO"

    return ans


print(fair_ration())

