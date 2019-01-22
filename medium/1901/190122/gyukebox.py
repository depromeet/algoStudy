#!/bin/python3
import os
visited = []
num_nodes = []


def dfs(current, tree):
    global visited
    global num_nodes

    if visited[current]:
        return 1

    visited[current] = True
    num_nodes[current] += 1

    children = tree[current]
    if not children:
        return 1
    else:
        sum_of_children = sum([dfs(i, tree) for i in children])
        num_nodes[current] += sum_of_children
        return num_nodes[current]


def evenForest(t_nodes, t_edges, t_from, t_to):
    global visited
    global num_nodes
    visited = [False] * t_nodes
    num_nodes = [0] * t_nodes

    tree = [[] for _ in range(t_nodes)]
    for i in range(t_edges):
        tree[t_to[i] - 1].append(t_from[i] - 1)

    dfs(0, tree)
    ans = 0
    for i in range(1, t_nodes):
        if num_nodes[i] % 2 == 0:
            ans += 1
    return ans


if __name__ == '__main__':
    t_nodes, t_edges = map(int, input().rstrip().split())
    t_from = [0] * t_edges
    t_to = [0] * t_edges
    for i in range(t_edges):
        t_from[i], t_to[i] = map(int, input().rstrip().split())

    res = evenForest(t_nodes, t_edges, t_from, t_to)
    print(res)
