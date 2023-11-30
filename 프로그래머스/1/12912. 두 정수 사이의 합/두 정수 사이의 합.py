def solution(a, b):
    t = -1 if a > b else 1
    return sum([i for i in range(a,b + t, -1 if a > b else 1)])