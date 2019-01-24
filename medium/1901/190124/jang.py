def sum_a_to_b(a, b):
    return (a+b)*(b-a+1)//2

for _ in range(int(input())):
    n, k, b = map(int, input().split())
    smallest = sum_a_to_b(1, b)
    biggest = sum_a_to_b(k-b+1, k)

    max_k = k
    if smallest > n or biggest < n:
        print(-1)
    else:
        for i in range(1, b)[::-1]:
            d = n - sum_a_to_b(1, i)

            if max_k <= d:
                f = max_k
                max_k -= 1
            else:
                f = d
            print(f, end=' ')
            n -= f

        print(n)
