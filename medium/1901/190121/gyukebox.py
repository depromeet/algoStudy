#!/bin/python3

import math
import os
import random
import re
import sys


def absolutePermutation(n, k):
    initial = [(i + 1) for i in range(n)]

    if k == 0:
        return initial

    if n % k != 0:
        return [-1]

    num_groups = n // k
    if num_groups % 2 != 0:
        return [-1]

    num_iter = num_groups // 2
    for i in range(num_iter):
        start = i * k * 2
        end = (i + 1) * k * 2
        initial[start:end] = initial[start+k:end] + initial[start:start+k]

    return initial


if __name__ == '__main__':
    t = int(input())

    for t_itr in range(t):
        nk = input().split()
        n = int(nk[0])
        k = int(nk[1])
        result = absolutePermutation(n, k)
        print(' '.join(map(str, result)))
