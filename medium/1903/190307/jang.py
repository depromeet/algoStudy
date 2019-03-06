answer = 0
mod = 10 ** 9 + 7

n = input()
l = len(n)

one = 1
for i in n[::-1]:
    answer += (int(i)*one % mod) * l
    l -= 1
    one = (one*10 + 1) % mod

print(answer)
