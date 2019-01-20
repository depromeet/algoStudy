#!/bin/python3
import os


def candies(n, arr):
    candies = [1 for _ in range(n)]

    for i in range(n - 1):
        if arr[i] < arr[i + 1] and candies[i] >= candies[i + 1]:
            candies[i + 1] = candies[i] + 1

    for i in range(n - 1, 0, -1):
        if arr[i] < arr[i - 1] and candies[i] >= candies[i - 1]:
            candies[i - 1] = candies[i] + 1

    return sum(candies)


if __name__ == '__main__':
    n = int(input())
    arr = []
    for _ in range(n):
        arr_item = int(input())
        arr.append(arr_item)
    result = candies(n, arr)
    print(result)
