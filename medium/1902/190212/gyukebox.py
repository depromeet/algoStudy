def solve(a, b, c, lim):
    bin_a = format(a, 'b')
    bin_b = format(b, 'b')
    bin_c = format(c, 'b')
    digit_a = len(bin_a)
    digit_b = len(bin_b)
    digit_c = len(bin_c)

    std_digit = max([digit_a, digit_b, digit_c])
    mask = (2 ** std_digit) - 1
    indicator = format(((a | b) ^ c) & mask, '0{}b'.format(std_digit))

    if digit_a < std_digit:
        bin_a = '0' * (std_digit - digit_a) + bin_a
    if digit_b < std_digit:
        bin_b = '0' * (std_digit - digit_b) + bin_b

    bin_a = list(bin_a)
    bin_b = list(bin_b)

    change_count = 0
    for i in range(std_digit):
        if indicator[i] == '1':
            if bin_a[i] == '0' and bin_b[i] == '0':
                bin_b[i] = '1'
                change_count += 1
                continue
            if bin_a[i] == '1':
                bin_a[i] = '0'
                change_count += 1
            if bin_b[i] == '1':
                bin_b[i] = '0'
                change_count += 1

    if change_count > lim:
        return [-1]
    elif change_count < lim:
        lim = lim - change_count
        for i in range(std_digit):
            if bin_a[i] == '1':
                if bin_b[i] == '0' and lim > 1:
                    bin_a[i] = '0'
                    bin_b[i] = '1'
                    lim -= 2
                elif bin_b[i] == '1' and lim > 0:
                    bin_a[i] = '0'
                    lim -= 1
            if not lim:
                break

    bin_a = ''.join(bin_a)
    bin_b = ''.join(bin_b)
    new_a = format(int(bin_a, 2), 'X')
    new_b = format(int(bin_b, 2), 'X')
    return [new_a, new_b]


if __name__ == "__main__":
    Q = int(input())
    for _ in range(Q):
        K = int(input())
        A = int(input(), 16)
        B = int(input(), 16)
        C = int(input(), 16)
        res = solve(A, B, C, K)
        for r in res:
            print(r)
