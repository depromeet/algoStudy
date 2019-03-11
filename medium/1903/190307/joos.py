
ans = 0
mod = 10**9+7

multiply = 1
for i in range(0,len(n))[::-1]:
    ans +=  int(n[i]) * multiply *(i+1)
    ans %= mod
    multiply = (10*multiply+1)%mod    # # 각자리수 하나를 뺀다.
print(ans)
