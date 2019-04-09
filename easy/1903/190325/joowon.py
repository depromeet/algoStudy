_ = input()
array = [int(i) for i in input().split()]

counts = [0 for i in range(101)]
for i in array:
    counts[i] += 1

big = max(counts)
print(len(array) - big)
