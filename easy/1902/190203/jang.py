n = int(input())
l = list(map(int, input().split()))

while l:
    print(len(l))
    l = list(filter(lambda a: a != min(l), l))