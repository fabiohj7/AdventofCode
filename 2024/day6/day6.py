visited = []
total = 0


def move_forward(total, visited, current, direction: int, lab):
    try:
        # Going up
        if direction == 1:
            if lab[current[0] - 1][current[1]] != "#":
                current = (current[0] - 1, current[1])
        # Going right
        elif direction == 2:
            if lab[current[0]][current[1] + 1] != "#":
                current = (current[0], current[1] + 1)
        # Going Down
        elif direction == 3:
            if lab[current[0] + 1][current[1]] != "#":
                current = (current[0] + 1, current[1])
        # Going left
        elif direction == 4:
            if lab[current[0]][current[1] - 1] != "#":
                current = (current[0], current[1] - 1)
    except:
        print(total + 1)
        exit(0)

    if current not in visited:
        visited.append(current)
        total += 1

    return current, total


with open('input.txt', 'r') as f:
    lab = [line.strip('\n') for line in f]

directions = [1, 2, 3, 4]
dire = 1
current = ()

for y, r in enumerate(lab):
    for x, c in enumerate(r):
        if c == '^':
            visited.append((y, x))
            current = (y, x)

while current[0] < len(lab) and current[1] < len(lab[0]):
    temp = current
    current, total = move_forward(total, visited, current, dire, lab)

    if temp == current:
        if dire + 1 in directions:
            dire += 1
        else:
            dire = 1
print(total)
