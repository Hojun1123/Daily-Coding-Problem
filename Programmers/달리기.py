from collections import defaultdict
def solution(players, callings):
    table = defaultdict(int)
    for i in range(len(players)):
        table[players[i]] = i + 1
    for a in callings:
        table[a] -= 1
        rank = table[a]
        b = players[rank-1]
        table[b] += 1
        players[rank-1], players[rank] = a, b
    return players
