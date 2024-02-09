#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
#include <string>
using namespace std;
int N, M;
int arr[300][300];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int check[300][300];
int tmp[300][300];
struct yx {
    int y;
    int x;
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> arr[i][j];
        }
    }

    int answer = 0;
    while (true)
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                check[i][j] = 0;
                tmp[i][j] = 0;
            }
        }

        int ccnt = 0;
        int ice = false;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                if (arr[i][j] > 0 && check[i][j] == 0)
                {
                    ice = true;
                    ccnt++;
                    queue<yx> q;
                    q.push({ i, j });
                    check[i][j] = 1;
                    while (!q.empty())
                    {
                        yx now = q.front();
                        q.pop();
                        for (int k = 0; k < 4; ++k)
                        {
                            int y = now.y + dy[k];
                            int x = now.x + dx[k];
                            if (x >= 0 && y >= 0 && y < N && x < M && check[y][x] == 0 && arr[y][x] > 0)
                            {
                                q.push({ y, x });
                                check[y][x] = 1;
                            }
                        }
                    }
                }
            }
        }
        
        if (ccnt >= 2)
        {
            break;
        }
        if (!ice)
        {
            answer = 0;
            break;
        }


        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                if (arr[i][j] == 0) continue;
                for (int k = 0; k < 4; ++k)
                {
                    int y = dy[k] + i;
                    int x = dx[k] + j;
                    if (x >= 0 && y >= 0 && x < M && y < N && arr[y][x] == 0)
                    {
                        tmp[i][j] += 1;
                    }
                }
            }
        }

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                arr[i][j] = max(arr[i][j] - tmp[i][j], 0);
            }
        }
        answer++;
    }
    cout << answer;
    return 0;
}