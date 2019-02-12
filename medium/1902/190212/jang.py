import sys

def bit_flip(b):
    return sys.maxsize - b


for _ in range(int(input())):
    K = int(input())
    a, b, c = input(), input(), input()

    ans_A = ''
    ans_B = ''

    cnt = 0

    for i in range(len(a))[::-1]:
        A = int(a[i], 16)
        B = int(b[i], 16)
        C = int(c[i], 16)

        T = (bit_flip(A ^ 0)) & (bit_flip(B ^ 0)) & C

        cvted_A = A & C
        cvted_B = T | (B & C)

        diff_A = cvted_A ^ A
        diff_B = cvted_B ^ B

        f = 1
        for _ in range(8):
            if diff_A & f != 0:
                cnt += 1
            if diff_B & f != 0:
                cnt += 1

            f <<= 1

        ans_A = hex(cvted_A)[2:].upper() + ans_A
        ans_B = hex(cvted_B)[2:].upper() + ans_B

    if cnt > K:
        print(-1)
    else:
        print(ans_A)
        print(ans_B)
