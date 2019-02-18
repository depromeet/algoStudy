def solve(rows, cols):
    rows = sorted(rows)
    cols = sorted(cols)
    return 'Possible' if rows == cols else 'Impossible'


if __name__ == '__main__':
    q = int(input())
    for _ in range(q):
        n = int(input())
        rows = [0] * n
        cols = [0] * n
        for i in range(n):
            for j, k in enumerate(list(map(int, input().split()))):
                cols[i] += k
                rows[j] += k
        print(solve(rows, cols))
