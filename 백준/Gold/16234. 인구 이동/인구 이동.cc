#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
int N, L, R;
int arr[100][100];
int check[100][100];
int graph[100][100][100][100];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
struct yx {
    int y, x;
};
queue<yx> q;
int populationSum, countryCnt;
int tmpY[10000];
int tmpX[10000];
bool Open()
{
    bool openFlag = false;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            for (int k = 0; k < 4; ++k)
            {
                int y = dy[k] + i;
                int x = dx[k] + j;
                if (x >= 0 && y >= 0 && x < N && y < N)
                {
                    int diff = abs(arr[i][j] - arr[y][x]);
                    if (diff >= L && diff <= R)
                    {
                        graph[y][x][i][j] = 1;
                        openFlag = true;
                    }
                    else
                    {
                        graph[y][x][i][j] = 0;
                    }
                }
            }
        }
    }
    return openFlag;
}

void bfs()
{
    for (int i = 0; i < q.size(); ++i)
    {
        yx now = q.front();
        q.pop();
        tmpY[countryCnt] = now.y;
        tmpX[countryCnt] = now.x;
        countryCnt++;
        populationSum += arr[now.y][now.x];
        for (int k = 0; k < 4; ++k)
        {
            int y = dy[k] + now.y;
            int x = dx[k] + now.x;
            if (x >= 0 && y >= 0 && x < N && y < N && check[y][x] == 0 && graph[now.y][now.x][y][x]) {
                check[y][x] = 1;
                q.push({ y, x });
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> L >> R;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> arr[i][j];
        }
    }

    int answer = 0;
    while (true)
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                check[i][j] = 0;
            }
        }
        if (!Open())
            break;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (check[i][j] == 0)
                {
                    
                    q.push({ i, j });
                    check[i][j] = 1;
                    populationSum = 0;
                    countryCnt = 0;
                    while (!q.empty())
                    {
                        bfs();
                    }
                    for (int k = 0; k < countryCnt; ++k)
                    {
                        arr[tmpY[k]][tmpX[k]] = populationSum / countryCnt;
                    }
                }
            }
        }
        answer++;
    }
    cout << answer;
    return 0;
}