#!/bin/python3
from collections import Counter

# Complete the sockMerchant function below.


def sockMerchant_without_counter(n, ar):
    valid = 0
    socks = dict.fromkeys(ar, 0)
    for value in ar:
        socks[value] += 1
    for value in socks.values():
        valid += value // 2
    return valid


def sockMerchant(n, ar):
    valid = 0
    cnt = Counter(ar)
    for value in cnt.values():
        valid += value // 2
    return valid


if __name__ == '__main__':
    n = int(input())
    ar = list(map(int, input().rstrip().split()))
    result = sockMerchant_without_counter(n, ar)
    print(result)
