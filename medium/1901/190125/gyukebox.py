#!/bin/python3
import os


def mandragora(H, n):
    if n == 1:
        return H[0]

    ans = 0
    monsters = sorted(H)
    tmp_sum = 0
    exp_sum = sum(H)
    for i in range(n - 1):
        tmp_sum += monsters[i]
        exp = (i + 2) * (exp_sum - tmp_sum)
        if exp > ans:
            ans = exp
    return ans


if __name__ == '__main__':
    t = int(input())
    for t_itr in range(t):
        n = int(input())
        H = list(map(int, input().rstrip().split()))
        result = mandragora(H, n)
        print(result)
