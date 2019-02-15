def solve(n, prices):
    profit = 0
    base_price = prices[n - 1]
    bought = []

    for i in range(n - 2, -1, -1):
        if prices[i] < base_price:
            bought.append(prices[i])
        else:
            profit += (base_price * len(bought)) - sum(bought)
            base_price = prices[i]
            bought = []
    if bought:
        profit += (base_price * len(bought)) - sum(bought)

    return profit


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        prices = list(map(int, input().split()))
        print(solve(n, prices))
