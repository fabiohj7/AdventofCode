import re

total = 0
with open('input.txt', 'r') as f:
    for line in f:
        matches = re.findall(r'mul\((\d{1,3}),(\d{1,3})\)', line)
        print(matches)
        products = [int(x) * int(y) for x, y in matches]
        total += sum(products)

print(total)
