with open('rules.txt', 'r') as f:
    rules = [line.strip('\n').split('|') for line in f]

with open('updates.txt', 'r') as f:
    updates = [line.strip('\n').split(',') for line in f]

temp = []
for line in updates:
    i = 0
    not_ordered = False
    while i < len(rules):
        if set(rules[i]).issubset(line):
            idx1 = line.index(rules[i][0])
            idx2 = line.index(rules[i][1])
            if idx1 > idx2:
                line[idx1], line[idx2] = line[idx2], line[idx1]
                i = 0
                not_ordered = True
        i += 1
    if not_ordered:
        temp.append(line)

result = 0
for i in temp:
    n = len(i)
    print(f'index {i[(n//2)]}')
    result += int(i[(n // 2)])
    print(i)
print(result)
