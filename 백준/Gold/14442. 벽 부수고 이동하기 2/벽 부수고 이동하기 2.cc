#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <vector>
using namespace std;
int N, M, K;
string arr[1000];
bool check[11][1000][1000];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
struct yx { 
    int y, x, k;
};

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N >> M >> K; 
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }
    queue<yx> q;
    q.push({ 0, 0, 0 });
    check[0][0][0] = 1;
    int cnt = 1;
    while (!q.empty())
    {
        int qSize = q.size();
        for (int i = 0; i < qSize; ++i)
        {
            yx now = q.front();
            q.pop();
            if (now.y == N - 1 && now.x == M - 1)
            {
                cout << cnt;
                return 0;
            }
            for (int k = 0; k < 4; ++k)
            {
                int y = now.y + dy[k];
                int x = now.x + dx[k];
                if (y < 0 || x < 0 || x >= M || y >= N || check[now.k][y][x]) continue;
                if (arr[y][x] == '0')
                {
                    q.push({ y, x, now.k });
                    check[now.k][y][x] = 1;
                }
                else
                {
                    if (now.k < K && check[now.k + 1][y][x] == 0)
                    {
                        q.push({ y, x, now.k + 1 });
                        check[now.k + 1][y][x] = 1;
                    }
                }
            }
        }
        cnt++;
    }
    cout << -1;
    return 0;
}