with open("./input5.txt") as fin:
    lines = fin.read().strip().split("\n")

seeds = list(map(int, lines[0].split(" ")[1:]))

maps = []

i = 2
while i < len(lines):
    maps.append([])

    i += 1
    while i < len(lines) and not lines[i] == "":
        dstStart, srcStart, rangeLen = map(int, lines[i].split())
        maps[-1].append((dstStart, srcStart, rangeLen))
        i += 1

    i += 1


def findLoc(seed):
    num = seed

    for m in maps:
        for first, second, third in m:
            if second <= num < second + third:
                num = first + (num - second)
                break

    return num


locs = []
for seed in seeds:
    loc = findLoc(seed)
    locs.append(loc)

print(min(locs))
