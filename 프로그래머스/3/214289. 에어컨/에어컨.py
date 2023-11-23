import math
def solution(temperature, t1, t2, a, b, onboard):
    # 0으로 정규화
    diff = temperature - t2 if temperature > t2 else t1 - temperature
    # 시간0에 대해 초기 비용으로 초기화
    result = [[ 1000000 for i in range(diff+1) ]+[0]]
    last_passenger_index = 0
    for i in range(1, len(onboard)):
        arr = []
        for j in range(diff+2):
            temp = [result[i-1][j]+b]
            # 할수있는 행동(비용)은 온도유지(b), 온도 내리기(a), 온도올리기(0)
            if j == diff + 1:
                temp.append(result[i-1][j])
            if j <= diff:
                temp.append(result[i-1][j+1] + a)
            if j > 0:
                temp.append(result[i-1][j-1])
            min_cost = min(temp)
            # 시간i에 대해 승객에 탑승 중이고, 적정온도 범위 밖이라면.
            if onboard[i] == 1:
                last_passenger_index = i
                if j > 1:
                    min_cost = 100000 # 100 * 1000
            arr.append(min_cost)
        result.append(arr)
    return min(result[last_passenger_index])