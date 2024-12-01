x = []
y = []
result = 0
with open("input.txt", "r") as f:
    for lines in f:
        a, b = lines.split()
        x.append(int(a))
        y.append(int(b))

for item in x:
    result += item * y.count(item)

print(result)
