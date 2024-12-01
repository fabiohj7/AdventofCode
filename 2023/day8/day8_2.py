# Referenced from William Y. Feng
import math
import re

with open("./input8.txt") as fin:
    lines = fin.read().strip().split("\n")


steps = lines[0]
nums = lines[2:]
nodes = {}

for line in lines:
    match = re.search(r"(.*) = \((.*), (.*)\)", line)
    if match:
        src, left, right = match.groups()
        nodes[src] = (left, right)


def findz(cur):
    count = 0
    while cur[2] != "Z":
        step = steps[count % len(steps)]
        print(step)
        if step == "L":
            cur = nodes[cur][0]
        else:
            cur = nodes[cur][1]

        count += 1
    return count


cur = [n for n in nodes if n[2] == "A"]
lens = [findz(node) for node in cur]
print(lens)

ans = math.lcm(*lens)
print(ans)
