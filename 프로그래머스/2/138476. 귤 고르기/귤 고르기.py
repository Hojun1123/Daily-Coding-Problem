from collections import defaultdict
from itertools import combinations
def solution(k, tangerine):
    table = defaultdict(int)
    for i in tangerine:
        table[i] += 1
    table = sorted(table.items(), key = lambda x : x[1], reverse = True)
    subsum = 0
    answer = 0
    for _k, _v in table:
        answer += 1
        subsum += _v
        if subsum >= k:
            return answer
            