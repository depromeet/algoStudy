input()

scores = list(map(int, input().split()))
highest = scores[0]
lowest = scores[0]

h_count = 0
l_count = 0
for score in scores:
    if highest < score:
        highest = score
        h_count += 1
    if lowest > score:
        lowest = score
        l_count += 1

print(h_count, l_count)