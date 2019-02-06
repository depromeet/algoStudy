def sorting(n, const_l, br):
    l = const_l[:]
    d = {}

    for i, v in enumerate(sorted(l, reverse=br)):
        d[v] = i  # 찾아가야 할 위치를 저장

    j = 0
    answer = 0
    while j < n:
        sorted_pos = d[l[j]]
        if sorted_pos != j:
            l[j], l[sorted_pos] = l[sorted_pos], l[j]
            answer += 1
        else:
            j += 1
    return answer


def solution():
    n = int(input())
    l = list(map(int, input().split()))

    left = sorting(n, l, False)
    right = sorting(n, l, True)

    print(min(left, right))


solution()

