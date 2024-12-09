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
    # Check for horizontal words
    total += lines[y].count("XMAS")

    total += lines[y][::-1].count("XMAS")

    # Check for vertical words and diagonal
    for x in range(len(lines[y])):
        if lines[y][x] == "X":
            if y >= 3:
                # Check upwards
                if lines[y - 1][x] == "M" and lines[y - 2][x] == "A" and lines[
                        y - 3][x] == "S":
                    total += 1

                # Check Diagonal left
                if x >= 3:
                    if lines[y - 1][x - 1] == "M" and lines[y - 2][
                            x - 2] == "A" and lines[y - 3][x - 3] == "S":
                        total += 1
                # Check Diagonal right
                if x < len(lines[y]) - 3:
                    if lines[y - 1][x + 1] == "M" and lines[y - 2][
                            x + 2] == "A" and lines[y - 3][x + 3] == "S":
                        total += 1

            # Check downwards
            if y < len(lines) - 3:
                if lines[y + 1][x] == "M" and lines[y + 2][x] == "A" and lines[
                        y + 3][x] == "S":
                    total += 1

                # Check diagonal Left
                if x >= 3:
                    if lines[y + 1][x - 1] == "M" and lines[y + 2][
                            x - 2] == "A" and lines[y + 3][x - 3] == "S":
                        total += 1

                # Check diagonal right
                if x < len(lines[y]) - 3:
                    if lines[y + 1][x + 1] == "M" and lines[y + 2][
                            x + 2] == "A" and lines[y + 3][x + 3] == "S":
                        total += 1

print(total)
