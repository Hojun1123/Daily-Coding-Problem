from collections import defaultdict
T = int(input())
for test_case in range(1, T + 1):
    N, M = map(int, input().split())
    play = []
    #table init
    table = [[0 for i in range(N)] for j in range(N)]
    table[N//2][N//2] = 2
    table[N//2 - 1][N//2 - 1] = 2
    table[N//2 - 1][N//2] = 1
    table[N//2][N//2 - 1] = 1

    #game start
    for i in range(M):
        x, y, color = map(int, input().split())
        x -= 1
        y -= 1
        play.append([y, x, color])

    moveVector = [[0, 1], [0, -1], [1, 0], [-1, 0], [1, 1], [-1, -1], [-1, 1], [1, -1]]
    for p in play:
        # y축, x축, color
        y, x, color = p
        nColor = 2 if color == 1 else 1 # 반대 색상
        renderPoints = defaultdict(list)
        table[y][x] = color

        for j in range(8):
            m = moveVector[j]
            dy = y + m[0]
            dx = x + m[1]
            check = False
            temp = []
            while 0 <= dy < N and 0 <= dx < N:
                if table[dy][dx] == color:
                    if check:
                        renderPoints[j] += temp
                    break
                elif table[dy][dx] == 0:
                    break
                else:
                    check = True
                    temp.append([dy, dx])
                dy += m[0]
                dx += m[1]
        #rendering
        for j in range(8):
            l = renderPoints[j]
            for _ in l:
                table[_[0]][_[1]] = color

    #count
    blackCount = 0
    whiteCount = 0
    for i in table:
        for j in i:
            if j == 1:
                blackCount += 1
            elif j == 2:
                whiteCount += 1

    print("#%d %d %d"%(test_case, blackCount, whiteCount))