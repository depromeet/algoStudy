def get_length(n):
    t = 1 << 32
    length = 32

    for _ in range(32):
        if n // t != 0:
            break
        length -= 1
        t = t >> 1

    return length + 1


def and_product():
    for _ in range(int(input())):
        a, b = map(int, input().split())

        t = 1
        l = get_length(b)

        for _ in range(l):
            if a & t == 0:  # i번째 비트가 0이면
                f = ((2 << (l - 1)) - 1) - (t - 1)
                if b >= (a & f) | t:
                    a = a & f
            t = t << 1
        print(a)


and_product()
