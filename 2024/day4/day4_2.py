total = 0


def print_selected_x(lines, x, y):
    for i in range(len(lines)):
        print()
        for j in range(len(lines[i])):
            if i == y and j == x:
                print(f"\033[91m{lines[i][j]}\033[00m", end=" ")
            else:
                print(lines[i][j], end=" ")
    print("\n-------------------")


with open('input.txt', 'r') as f:

    lines = [line.strip("\n") for line in f]

for y in range(len(lines)):

    # Check top letters and compare with opposite side
    for x in range(len(lines[y])):
        diagonal = False
        if lines[y][x] == "A":
            if 1 <= y <= len(lines) - 2 and 1 <= x <= len(lines[y]) - 2:
                if lines[y - 1][x - 1] == "M" and lines[y + 1][x + 1] == "S":
                    diagonal = True

                elif lines[y - 1][x - 1] == "S" and lines[y + 1][x + 1] == "M":
                    diagonal = True

                if diagonal:
                    if lines[y - 1][x + 1] == "S" and lines[y + 1][x -
                                                                   1] == "M":
                        total += 1
                        print(f"y: {y} x: {x}")

                    elif lines[y - 1][x + 1] == "M" and lines[y + 1][x -
                                                                     1] == "S":
                        total += 1
                        print(f"y: {y} x: {x}")

print(total)
