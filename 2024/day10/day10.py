with open('test.txt', 'r') as f:
    content = [line.strip('\n') for line in f]

for r, line in enumerate(content):
    for c, digit in enumerate(line):
        if digit == '0':
            
