#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the superDigit function below.


def sum_of_digits(number):
    if number < 10:
        return number
    return sum_of_digits(sum(map(int, str(number))))


def superDigit(n, k):
    tmp = sum(map(int, n)) * k
    if tmp < 10:
        return tmp
    else:
        return superDigit(str(tmp), 1)


if __name__ == '__main__':
    nk = input().split()
    n = nk[0]
    k = int(nk[1])
    result = superDigit(n, k)
    print(result)
