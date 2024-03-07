#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <cstring>
#include <set>
using namespace std;
int N, M, K;
string arr[1000];
bool check[11][1000][1000];
struct yx {
    int y, x, d;
};
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
queue<yx> q;
vector<yx> v;
int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }
    q.push({ 0, 0, 0 });
    check[0][0][0] = 1;
    int cnt = 0;//냦
    int flag = 0;
    while (!q.empty()) {
        int qSize = q.size();
        for (int i = 0; i < qSize; ++i)
        {
            /*
            cout << cnt << "\n";
            for (int ii = 0; ii < N; ++ii)
            {
                for (int jj = 0; jj < M; ++jj)
                {
                    cout << check[2][ii][jj] << " ";
                }
                cout << "\n";
            }
            */
            yx now = q.front();
            q.pop();
            if (now.y == N - 1 && now.x == M - 1) {
                flag = true;
                break;
            }
            if (cnt % 2 == 1)
            {
                q.push(now);
            }
            for (int k = 0; k < 4; ++k)
            {
                int y = dy[k] + now.y;
                int x = dx[k] + now.x;
                if (x < 0 || y < 0 || x >= M || y >= N ) continue;
                if (arr[y][x] == '1' && now.d < K && check[now.d + 1][y][x] == 0) {
                    if (cnt % 2 == 0)
                    {
                        q.push({ y, x, now.d + 1 });
                        check[now.d + 1][y][x] = 1;
                    }
                }
                else if (check[now.d][y][x] == 0 && arr[y][x] == '0')
                {
                    check[now.d][y][x] = 1;
                    q.push({ y, x, now.d });
                }
            }
        }
        if (flag) break;
        cnt++;
    }
    cout << (flag ? cnt + 1 : -1);
    return 0;
}
