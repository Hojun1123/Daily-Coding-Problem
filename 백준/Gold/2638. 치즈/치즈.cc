#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <string>
#include <unordered_map>
#include <bitset>
#include <stack>
#include <unordered_set>
#include <cstring>
using namespace std;
int arr[100][100];
int N, M;
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
struct yx { int y, x; };
queue<yx> q;
int ans = 0;
int check[100][100];
vector<yx> ch;
void melt()
{
    memset(check, 0, sizeof(check));
    ch.clear();
    for (int i = 0; i < M; ++i)
    {
        q.push({ 0, i });
        q.push({ N - 1, i });
        check[0][i] = 1;
        check[N - 1][i] = 1;
    }
    for (int i = 1; i < N - 1; ++i)
    {
        q.push({ i, 0 });
        q.push({ i, M - 1 });
        check[i][0] = 1;
        check[i][M - 1] = 1;
    }
    
    int tmp[100][100];
    memcpy(tmp, arr, sizeof(tmp));
    while (!q.empty())
    {
        int qSize = q.size();
        for (int i = 0; i < qSize; ++i)
        {
            yx now = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k)
            {
                int y = dy[k] + now.y;
                int x = dx[k] + now.x;
                if (x < 0 || y < 0 || x >= M || y >= N || check[y][x]) continue;
                if (arr[y][x])
                {
                    ch.push_back({ y, x });
                    continue;
                }
                q.push({ y, x });
                check[y][x] = 1;
            }
        }
    }

    for (yx i : ch)
    {
        int cnt = 0;
        //cout << i.y << " " << i.x << "\n";
        for (int k = 0; k < 4; ++k)
        {
            if (arr[i.y + dy[k]][i.x + dx[k]] == 0 && check[i.y + dy[k]][i.x + dx[k]]) cnt++;
        }
        if (cnt > 1) {
            if (tmp[i.y][i.x])ans--;
            tmp[i.y][i.x] = 0;
        }
    }
    memcpy(arr, tmp, sizeof(arr));
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> arr[i][j];
            ans += (arr[i][j] ? 1 : 0);
        }
    }

    int r = 0;
    while (true)
    {
        melt();
        r++;
        //cout << ans << "\n";
        if (ans <= 0) break;
    }
    cout << r;
    return 0;
}