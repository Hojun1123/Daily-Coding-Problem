def solution(arr):
    answer = 0
    cnt = len(arr)
    step = min(arr)
    while cnt:
        cnt = len(arr)
        answer += step
        for i in arr:
            if answer % i == 0:
                cnt -= 1
    return answer