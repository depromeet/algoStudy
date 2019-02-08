def prime(n):
    primes = [True] * (n + 1)

    # 0과 1은 소수가 아님.
    primes[0], primes[1] = [False] * 2
    for i in range(2, int(n ** 0.5) + 1):
        if primes[i]:
            for j in range(i * i, n + 1, i):
                primes[j] = False

    return primes.count(True)

def get_case(n):
    D = [0] * (n + 5)

    D[1] = D[2] = D[3] = 1
    D[4] = 2
    for i in range(5, n + 1):
        D[i] = D[i - 4] + D[i - 1]

    return prime(D[n])


def john_is_back():
    for _ in range(int(input())):
        n = int(input())
        print(get_case(n))

john_is_back()