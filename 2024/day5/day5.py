with open('rules.txt', 'r') as f:
    rules = [line.strip('\n').split('|') for line in f]

with open('updates.txt', 'r') as f:
    updates = [line.strip('\n').split(',') for line in f]

temp = []
for line in updates:
    to_remove = False
    for item in rules:
        if set(item).issubset(line):
            if line.index(item[0]) > line.index(item[1]):
                to_remove = True
                break

    if not to_remove:
        temp.append(line)

result = 0
for i in temp:
    n = len(i)
    print(f'index {i[(n//2)]}')
    result += int(i[(n // 2)])
    print(i)
print(result)
