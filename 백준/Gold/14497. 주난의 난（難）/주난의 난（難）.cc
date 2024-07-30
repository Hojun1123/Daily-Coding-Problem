#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <unordered_map>
using namespace std;
struct yx {
    int y, x;
};
int N, M;
int sy, sx, ey, ex;
int check[300][300];
int arr[300][300];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
queue<yx> q;
queue<yx> result;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    cin >> sy >> sx >> ey >> ex;
    sx--; sy--; ex--; ey--;
    for (int i = 0; i < N; ++i)
    {
        string a;
        cin >> a;
        for (int j = 0; j < M; ++j)
        {
            if (a[j] == '0') {
                arr[i][j] = 0;
            }
            else if (a[j] == '1') {
                arr[i][j] = 1;
            }
            else if (a[j] == '#') {
                arr[i][j] = 2;
            }
        }
    }
    q.push({ sy, sx });
    check[sy][sx] = 1;

    int cnt = 0;
    while (true) {
        cnt++;
        while (!q.empty())
        {
            int qSize = q.size();
            for (int i = 0; i < qSize; ++i)
            {
                yx now = q.front();
                q.pop();
                if (arr[now.y][now.x] == 2) {
                    cout << cnt;
                    return 0;
                }
                for (int k = 0; k < 4; ++k)
                {
                    int y = dy[k] + now.y;
                    int x = dx[k] + now.x;
                    if (x < 0 || y < 0 || x >= M || y >= N) continue;
                    if (check[y][x]) continue;
                    check[y][x] = 1;
                    if (arr[y][x] == 1) {
                        result.push({ y, x });
                    }
                    else {
                        q.push({ y, x });
                    }
                }
            }
        }

        /*
        cout << "\n";
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) cout << arr[i][j];
            cout << "\n";
        }
        */

        while (!result.empty())
        {
            yx now = result.front();
            //cout << "curr: " << now.y << ", " << now.x << "\n";
            result.pop();
            arr[now.y][now.x] = 0;
            q.push(now);
        }
    }
    return 0;
}