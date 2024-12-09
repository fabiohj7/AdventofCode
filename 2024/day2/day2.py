total = 0
decreasing = False
with open('input.txt', 'r') as f:
    for line in f:
        x = [int(x) for x in line.split()]
        if x[0] - x[1] > 0:
            decreasing = True
        else:
            decreasing = False
        safe = True
        for i in range(len(x) - 1):
            if decreasing and abs(x[i] -
                                  x[i + 1]) <= 3 and x[i] - x[i + 1] > 0:
                pass
            elif not decreasing and abs(x[i] -
                                        x[i + 1]) <= 3 and x[i] - x[i + 1] < 0:
                pass
            else:
                safe = False
                break
        if safe:
            total += 1

print(total)
