def solve(ppl, costs):
    num_flowers = len(costs)
    if ppl >= num_flowers:
        return sum(costs)

    costs = sorted(costs, reverse=True)
    total = 0
    ppl_idx = 0
    weight = 1

    while True:
        total += weight * costs[0]
        del costs[0]
        if not costs:
            break
        ppl_idx += 1
        if ppl_idx == ppl:
            weight += 1
            ppl_idx = 0

    return total


if __name__ == '__main__':
    n, k = map(int, input().split())
    c = list(map(int, input().split()))
    print(solve(k, c))
