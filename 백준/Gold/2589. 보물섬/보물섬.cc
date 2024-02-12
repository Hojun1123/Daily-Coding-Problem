#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
int N, M;
string arr[50];
int check[50][50];
struct yx {
    int y, x;
};
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    int answer = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (arr[i][j] == 'L')
            {
                for (int k = 0; k < N; ++k)
                {
                    for (int l = 0; l < M; ++l)
                    {
                        check[k][l] = 0;
                    }
                }
                queue<yx> q;
                q.push({ i, j });
                check[i][j] = 1;
                int cnt = -1;
                while(!q.empty())
                {
                    int qSize = q.size();
                    for (int k = 0; k < qSize; ++k)
                    {
                        yx now = q.front();
                        q.pop();
                        for (int l = 0; l < 4; ++l)
                        {
                            int y = now.y + dy[l];
                            int x = now.x + dx[l];
                            if (x >= 0 && y >= 0 && x < M && y < N && check[y][x] == 0 && arr[y][x] == 'L')
                            {
                                q.push({ y,x });
                                check[y][x] = 1;
                            }
                        }
                    }
                    cnt++;
                }
                if (answer < cnt)
                {
                    answer = cnt;
                }
            }
        }
    }
    cout << answer;
    return 0;
}