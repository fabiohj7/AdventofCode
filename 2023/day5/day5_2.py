with open("./testinput5.txt") as fin:
    lines = fin.read().strip().split("\n")

seeds = list(map(int, lines[0].split(" ")[1:]))

fseeds = []
j = 0
for s in seeds:
    if j % 2 == 0:
        fseeds.append(s)
        j += 1
    elif j % 2 == 1:
        fseeds.append(seeds[j - 1] + s - 1)
        j += 1

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


def remap(l, h, m):
    ans = []
    for dst, src, ran in m:
        fran = src + ran - 1
        shift = dst - src
        if not (fran < l or src > h):
            l = max(l, src)
            h = min(h, fran)
            ans.append((l, h, shift))


def findLoc(seed):
    num = seed

    for m in maps:
        for first, second, third in m:
            if second <= num < second + third:
                num = first + (num - second)
                break

    return num


print(fseeds)
remap(fseeds[0], fseeds[1], maps[0])

locs = []
for seed in seeds:
    loc = findLoc(seed)
    locs.append(loc)

print(min(locs))
