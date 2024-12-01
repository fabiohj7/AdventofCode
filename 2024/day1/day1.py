x = []
y = []
result = 0
with open("input.txt", "r") as f:
    for lines in f:
        a, b = lines.split()
        x.append(int(a))
        y.append(int(b))

for i in range(len(x)):
    result += abs(min(x) - min(y))
    x.remove(min(x))
    y.remove(min(y))
print(result)
