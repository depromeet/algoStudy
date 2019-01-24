import sys

def LI(): return [int(x) for x in sys.stdin.readline().split()]

def solve(n, e, edges):
    _map = [[] for _ in range(n+1)]
    for f, t in edges:
        _map[t].append(f)
    
    def helper(root, cb):
        cnt = 1
        for child in _map[root]:
            cur_cnt = helper(child, cb)
            cnt += cur_cnt
            if cur_cnt % 2 == 0:
                cb()
        return cnt
    
    ref = {"value": 0}
    def callback():
        ref["value"] += 1
    helper(1, callback)

    return ref["value"]

def main():
    n, e = LI()
    edges = [tuple(LI()) for _ in range(e)]
    print(solve(n, e, edges))

main()
