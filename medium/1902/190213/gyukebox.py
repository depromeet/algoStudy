from fractions import Fraction


def make_graph(n, edges):
    graph = {i + 1: [] for i in range(n)}
    for edge in edges:
        dep, dest = edge
        graph[dep].append(dest)
        graph[dest].append(dep)
    return graph


def bfs(n, graph):
    q = []
    rel = []
    visited = [False] * n
    visited[0] = True
    for child in graph[1]:
        rel.append((1, child))
        q.append(child)
    while q:
        nxt = q[0]
        visited[nxt - 1] = True
        del q[0]
        for child in graph[nxt]:
            if not visited[child - 1]:
                rel.append((nxt, child))
                q.append(child)
    return rel


def solve(n, graph, g, k, guesses):
    win_count = 0
    relationships = sorted(bfs(n, graph), key=lambda x: x[1])
    guesses = sorted(guesses, key=lambda x: x[1])

    correct = list(set(relationships) & set(guesses))
    if len(correct) >= k:
        win_count += 1

    for i in range(n - 1):
        rel = relationships.copy()
        idx = i
        while True:
            parent, child = rel[idx]
            rel[idx] = (child, parent)
            if parent == 1:
                break
            idx = parent - 2

        correct = list(set(rel) & set(guesses))
        if len(correct) >= k:
            win_count += 1

    return str(Fraction(win_count, n))


if __name__ == '__main__':
    q = int(input())
    for _ in range(q):
        n = int(input())
        edges = [tuple(map(int, input().split())) for _ in range(n - 1)]
        graph = make_graph(n, edges)
        g, k = map(int, input().split())
        guesses = [tuple(map(int, input().split())) for _ in range(g)]
        res = solve(n, graph, g, k, guesses)
        if res == '0' or res == '1':
            print('{}/1'.format(res))
        else:
            print(res)

