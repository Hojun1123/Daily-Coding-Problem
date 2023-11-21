from collections import defaultdict
def solution(name, yearning, photo):
    answer = []
    table = defaultdict(int)
    for n, y in zip(name, yearning):
        table[n] = y
    return [sum([table[j] for j in p]) for p in photo]