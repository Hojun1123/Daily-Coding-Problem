from collections import defaultdict
def solution(x, y, n):
    answer = 0
    table = defaultdict(int)
    for i in range(x, y + 1):
        table[i] = 1000000
        
    table[x] = 0
    cnt = 1
    for i in range(x, y + 1):
        if table[i] == 1000000:
            continue
        table[i + n] = min(table[i + n], table[i] + 1)
        table[i * 2] = min(table[i * 2], table[i] + 1)
        table[i * 3] = min(table[i * 3], table[i] + 1)
    return -1 if table[y] == 1000000 else table[y]
