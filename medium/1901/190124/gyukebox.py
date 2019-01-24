import os
import sys


def bonetrousle(n, k, b):
    initial_list = [i + 1 for i in range(b)]
    min_sum = sum(initial_list)
    max_sum = sum([k - i for i in range(b)])

    if not min_sum <= n <= max_sum:
        return [-1]

    diff = n - min_sum

    if not diff:
        return initial_list
    else:
        for i in range(b):
            box = k - 1 - i
            current = b - 1 - i
            limit = box - current
            if diff <= limit:
                initial_list[current] += diff
                return initial_list
            else:
                initial_list[current] += limit
                diff -= limit


if __name__ == '__main__':
    t = int(input())

    for t_itr in range(t):
        nkb = input().split()
        n = int(nkb[0])
        k = int(nkb[1])
        b = int(nkb[2])

        result = bonetrousle(n, k, b)
        print(' '.join(map(str, result)))
