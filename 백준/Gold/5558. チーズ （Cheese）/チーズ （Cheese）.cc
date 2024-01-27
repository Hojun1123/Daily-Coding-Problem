#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <vector>
#include <list>
using namespace std;
int H, W, N;
int arr[1000][1000];
int check[1000][1000];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
struct yx {
    int y;
    int x;
};
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    //둥지S, 치즈 공장1~N, 장애물X, 빈 곳.
    char input;
    struct yx startPoint;
    cin >> H >> W >> N;
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            cin >> input;
            if (input == 'S')
            {
                arr[i][j] = 0;
                startPoint.y = i;
                startPoint.x = j;
            }
            else if (input == '.')
            {
                arr[i][j] = 0;
            }
            else if (input == 'X')
            {
                arr[i][j] = -1;
            }
            else
            {
                arr[i][j] = input - '0';
            }
        }
    }

    int answer = 0;
    int ny, nx, x, y;
    for (int i = 1; i <= N; ++i)
    {
        for (int _ = 0; _ < H; ++_)
        {
            for (int __ = 0; __ < W; ++__)
            {
                check[_][__] = 0;
            }
        }

        int cnt = 0;
        queue<struct yx> q;
        int qSize;
        bool findCheck = false;

        q.push(startPoint);
        check[startPoint.y][startPoint.x] = 1;
        while (!q.empty())
        {
            qSize = q.size();
            for (int j = 0; j < qSize; ++j)
            {
                ny = q.front().y;
                nx = q.front().x;
                q.pop();
                if (arr[ny][nx] == i)
                {
                    findCheck = true;
                    startPoint.y = ny;
                    startPoint.x = nx;
                    break;
                }
                for (int k = 0; k < 4; ++k)
                {
                    y = ny + dy[k];
                    x = nx + dx[k];
                    if (y >= 0 && y < H && x >= 0 && x < W && check[y][x] == 0 && arr[y][x] != -1)
                    {
                        q.push({ y, x });
                        check[y][x] = 1;
                    }
                }
            }
            if (findCheck)
                break;
            cnt++;
        }
        answer += cnt;
    }
    cout << answer; 
    return 0;
}