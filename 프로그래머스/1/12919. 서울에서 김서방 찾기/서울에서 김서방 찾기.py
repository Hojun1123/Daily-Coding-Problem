def solution(seoul):
    return "김서방은 " + str([i for i in range(len(seoul)) if seoul[i] == 'Kim'][0]) + "에 있다"