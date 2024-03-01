#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <deque>
#include <unordered_map>
#include <cstring>
using namespace std;
string arr[1000];
bool check[2][1000][1000];
int N, M;
struct yx {
    int y, x;
    int b;
};
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }
    int cnt = 1;
    queue<yx> q;
    q.push({ 0, 0, 0 });
    check[0][0][0] = true;
    int b = 0;
    while (!q.empty())
    {
        int qSize = q.size();
        for (int i = 0; i < qSize; ++i)
        {
            yx now = q.front();
            q.pop();
            if (now.y == N - 1 && now.x == M - 1)
            {
                cout << cnt; return 0;
            }
            for (int k = 0; k < 4; ++k)
            {
                int y = now.y + dy[k];
                int x = now.x + dx[k];
                if (x >= 0 && y >= 0 && x < M && y < N && check[now.b][y][x] == 0)
                {
                    if (arr[y][x] == '0')
                    {
                        check[now.b][y][x] = 1;
                        q.push({ y, x, now.b });
                    }
                    else if(arr[y][x] == '1' && now.b == 0)
                    {
                        q.push({ y, x, 1 });
                        check[now.b][y][x] = 1;
                    }
                }
            }
        }
        cnt++;
    }
    cout << -1;
    return 0;
}