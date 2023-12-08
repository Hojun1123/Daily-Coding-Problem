from collections import defaultdict
import math
def solution(n):
    answer = ''
    p = 1
    pSum = 0
    pSumDict = defaultdict(int)
    while True:
        pSum += 3 ** p
        pSumDict[p] = pSum
        if pSum >= n:
            break
        p += 1
    p -= 1
    for i in range(p, 0, -1):
        currN = n - pSumDict[i]
        prevP = pSumDict[i] - pSumDict[i - 1]
        if currN <= prevP:
            answer += '1'
            n -= prevP * 1
        elif currN <= 2 * prevP:
            answer += '2'
            n -= prevP * 2
        elif currN <= 3 * prevP:
            answer += '4'
            n -= prevP * 3
            
    if n % 3 == 1:
        answer += '1'
    elif n % 3 == 2:
        answer += '2'
    else:
        answer += '4'
    return answer