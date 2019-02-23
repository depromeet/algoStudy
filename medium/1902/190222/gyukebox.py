def solve_timeout(n):
    bin_n = format(n, 'b')
    exp = len(bin_n) - 1
    mask = 2 ** exp - 1

    turn = 0
    while n != 1:
        if n & mask:
            n -= mask
            exp = len(bin_n) - 1
            mask = 2 ** exp - 1
        else:
            turn += exp
            break

    return 'Louise' if turn % 2 else 'Richard'


def solve(n):
    if n == 1:
        return 'Richard'

    bin_n = format(n, 'b')
    exp = len(bin_n) - 1
    mask = 2 ** exp - 1

    moves = 0
    if not n & mask:
        moves = exp
    else:
        cnt = 0
        idx = 0
        for i in range(1, exp + 1):
            if bin_n[i] == '1':
                cnt += 1
                idx = i
        moves += (exp - idx + cnt)

    return 'Louise' if moves % 2 else 'Richard'


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        print(solve(int(input())))
