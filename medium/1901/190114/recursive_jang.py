def super_digit(su):
    if su//10 == 0:
        return su

    return super_digit(sum(map(int, str(su))))

n, k = input().split()
s = sum(map(int, n))
print(super_digit(s*int(k)))
