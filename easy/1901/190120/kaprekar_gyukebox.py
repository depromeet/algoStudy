#!/bin/python3
import math
import os
# Complete the kaprekarNumbers function below.


def kaprekarNumbers(p, q):
    valid = []
    for i in range(p, q + 1):
        original = i
        squared = list(str(original ** 2))
        length = len(squared) - len(str(original))
        q = int(''.join(squared[length:]))
        if length > 0:
            p = int(''.join(squared[:length]))
        else:
            p = 0
        if p + q == original:
            valid.append(original)

    if not valid:
        print('INVALID RANGE')
    else:
        for number in valid:
            print(number, end=' ')


if __name__ == '__main__':
    p = int(input())
    q = int(input())
    kaprekarNumbers(p, q)
