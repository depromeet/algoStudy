import sys
sys.setrecursionlimit(100001)

def get_cost(i, l, costs):
    if costs[i] != -1:
        return costs[i]

    if i < 0 or i >= len(l):
        return 1

    left = l[i-1] if i-1 >= 0 else 100001
    right = l[i+1] if i+1 < len(l) else 100001

    if left >= l[i] and l[i] <= right:
        return 1

    cost = 0
    if left < l[i] and i-1 >= 0:
        cost = max(get_cost(i-1, l, costs), cost)

    if right < l[i] and i+1 < len(l):
        cost = max(get_cost(i+1, l, costs), cost)

    costs[i] = cost + 1
    return cost + 1

def solution():
    n = int(input())
    l = [int(input()) for _ in range(n)]

    costs = [-1]*n
    ans = 0
    for i in range(n):
        ans += get_cost(i, l, costs)

    return ans

print(solution())
