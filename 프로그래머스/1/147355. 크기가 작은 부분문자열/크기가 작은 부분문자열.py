def solution(t, p):
    answer = 0
    plen = len(p)
    for i in range(plen-1, len(t)):
        if p >= t[i-(plen-1):i+1]:
            answer += 1
    return answer