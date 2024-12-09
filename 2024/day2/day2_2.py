total = 0


def check(x):
    decreasing = False
    if x[0] - x[1] > 0:
        decreasing = True
    else:
        decreasing = False

    return decreasing


def is_safe(x):
    decreasing = check(x)
    for i in range(len(x) - 1):
        if decreasing and abs(x[i] - x[i + 1]) <= 3 and x[i] - x[i + 1] > 0:
            pass
        elif not decreasing and abs(x[i] -
                                    x[i + 1]) <= 3 and x[i] - x[i + 1] < 0:
            pass
        else:
            return False

    return True


with open('input.txt', 'r') as f:
    for line in f:
        x = [int(x) for x in line.split()]
        for i in range(len(x)):
            temp = x.copy()
            temp.pop(i)
            safe = is_safe(temp)
            if safe:
                total += 1
                break

print(total)
