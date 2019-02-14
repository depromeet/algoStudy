def winner(x):
    return 'BOB' if x % 2 == 0 else 'ANDY'


def solve(n, arr):
    turn = 0
    idx = 0
    for i in range(1, n):
        if arr[i] > arr[idx]:
            turn += 1
            idx = i
    return winner(turn)


if __name__ == '__main__':
    g = int(input())
    for _ in range(g):
        n = int(input())
        arr = list(map(int, input().split()))
        print(solve(n, arr))
