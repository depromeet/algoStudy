#!/bin/python3
#
# Complete the 'cutTheTree' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER_ARRAY data
#  2. 2D_INTEGER_ARRAY edges
#
import sys

visited = []
total = 0
min_difference = sys.maxsize
sys.setrecursionlimit(int(1e6) + 1)


def dfs(tree, data, current):
    global visited
    global total
    global min_difference

    result = data[current - 1]
    visited[current - 1] = True
    interim_result = []

    for edge in tree[current]:
        if not visited[edge - 1]:
            interim_result.append(dfs(tree, data, edge))
    result += sum(interim_result)

    difference = abs(result - (total - result))
    if difference < min_difference:
        min_difference = difference

    return result


def cutTheTree(data, edges):
    global visited
    global total

    n = len(data)
    total = sum(data)
    tree = {}
    visited = [False] * n

    for edge in edges:
        edge_from, edge_to = edge
        if edge_from not in tree:
            tree[edge_from] = [edge_to]
        else:
            tree[edge_from] += [edge_to]
        if edge_to not in tree:
            tree[edge_to] = [edge_from]
        else:
            tree[edge_to] += [edge_from]

    return dfs(tree, data, 1)


if __name__ == '__main__':
    n = int(input().strip())
    data = list(map(int, input().rstrip().split()))
    edges = []
    for _ in range(n - 1):
        edges.append(list(map(int, input().rstrip().split())))
    cutTheTree(data, edges)
    print(min_difference)
