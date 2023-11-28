from collections import defaultdict
def solution(n):
    table = defaultdict(int)
    table[1] = 1
    table[2] = 2
    for i in range(3, n + 1):
        table[i] = table[i - 1] + table[i - 2]
    return table[n] % 1234567