for _ in range(int(input())):
    b, w = map(int, input().split())
    bc, wc, z = map(int, input().split())

    print(min(bc*b + wc*w, bc*(b+w) + z*w, wc*(b+w) + z*b))
