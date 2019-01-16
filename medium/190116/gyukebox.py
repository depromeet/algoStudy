#!/bin/python3
import os
from collections import Counter

# Complete the steadyGene function below.


def steadyGene(gene):
    length = len(gene)
    ideal = length // 4
    counter = dict(Counter(gene))
    to_replace = {}
    for letter, appearance in counter.items():
        if appearance > ideal:
            to_replace[letter] = appearance - ideal

    if not to_replace:
        return 0

    # find initial left and right bound
    left_bound = 0
    covered = {}
    for i in range(length):
        if gene[i] in to_replace:
            if gene[i] in covered:
                covered[gene[i]] += 1
            else:
                covered[gene[i]] = 1
        if covered.keys() == to_replace.keys():
            if any(covered[key] < to_replace[key] for key in to_replace):
                continue
            else:
                right_bound = i
                break

    # search through rest
    ans = right_bound - left_bound + 1
    while right_bound < length:
        left_bound_ptr = gene[left_bound]
        if left_bound_ptr in to_replace:
            covered[left_bound_ptr] -= 1
            if covered[left_bound_ptr] < to_replace[left_bound_ptr]:
                right_bound += 1
                while right_bound < length and gene[right_bound] != left_bound_ptr:
                    if gene[right_bound] in to_replace:
                        covered[gene[right_bound]] += 1
                    right_bound += 1
                covered[left_bound_ptr] += 1

        left_bound += 1
        substr_len = right_bound - left_bound + 1
        if substr_len < ans:
            ans = substr_len

    return ans


if __name__ == '__main__':
    n = int(input())
    gene = input()
    result = steadyGene(gene)
    print(result)
