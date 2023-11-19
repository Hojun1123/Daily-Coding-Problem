def check(x):
    for i in range(x):
        if row[x] == row[i] or abs(row[x] - row[i]) == abs(x - i):
            return False
    return True

def dfs(x):
    global N
    global answer
    if x == N:
        answer += 1
        return
    else:
        for i in range(N):
            row[x] = i
            if check(x):
                dfs(x + 1)


T = int(input())
for tc in range(1, T + 1):
    # 놓은 곳을 저장
    N = int(input())
    global row, answer
    row = [0] * N
    answer = 0

    dfs(0)

    print("#%d %d" %(tc, answer))