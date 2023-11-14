from collections import deque
def solution(queue1, queue2):
    queue1 = deque(queue1)
    queue2 = deque(queue2)
    answer = 0
    sum1 = sum(queue1)
    checkInf = len(queue1)
    sum2 = sum(queue2)
    if sum1 == sum2:
        return 0
    
    while True:
        answer += 1
        if sum1 > sum2:
            temp = queue1.popleft()
            queue2.append(temp)
            sum1 -= temp
            sum2 += temp
        else:
            temp = queue2.popleft()
            queue1.append(temp)
            sum2 -= temp
            sum1 += temp
        if sum1 == sum2:
            return answer
        if checkInf * 4 <= answer:
            return -1