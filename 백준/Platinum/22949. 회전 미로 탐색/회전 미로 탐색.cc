#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
#include <deque>
#include <deque>
#include <map>
#include <vector>
#include <sstream>
using namespace std;
int N;
int visited[4][500][500];
int SIZE;
struct yx {
    int y, x, d;
};
struct Box {
    int box[4][4][4];
};
Box arr[125][125];
int dy[5] = { -1, 1, 0, 0, 0 };
int dx[5] = { 0, 0, 1, -1, 0 };
//S, .0가능, #1벽, E2
queue<yx> q;
void rotate(int y, int x)
{
    int tmp[4][4];
    for (int k = 0; k < 3; ++k)
    {
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                tmp[j][3 - i] = arr[y][x].box[k][i][j];
            }
        }
        memcpy(arr[y][x].box[k + 1], tmp, 64);
    }
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N;
    SIZE = 4 * N;
    for (int i = 0; i < SIZE; ++i)
    {
        string a;
        cin >> a;
        for (int j = 0; j < SIZE; ++j)
        {
            if (a[j] == 'S')
            {
                arr[i / 4][j / 4].box[0][i % 4][j % 4] = 0;
                q.push({ i, j, 0 });
                visited[0][i][j] = 1;
            }
            else if(a[j] == 'E') arr[i / 4][j / 4].box[0][i % 4][j % 4] = 2;
            else if(a[j] == '#') arr[i / 4][j / 4].box[0][i % 4][j % 4] = 1;
        }
    }
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            rotate(i, j);
        }
    }
    //debug
    /*
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j) cout << arr[i/4][j/4].box[3][i%4][j%4] << " ";
        cout << "\n";
    }
    */

    //bfs
    int cnt = 0;
    while (!q.empty())
    {
        int qSize = q.size();
        for (int i = 0; i < qSize; ++i)
        {
            yx now = q.front();
            //cout << now.y << " " << now.x << "\n";
            if (arr[now.y / 4][now.x / 4].box[now.d][now.y % 4][now.x % 4] == 2)
            {
                cout << cnt;
                return 0;
            }
            q.pop();

            for (int k = 0; k < 5; ++k)
            {
                int y = dy[k] + now.y;
                int x = dx[k] + now.x;
                if (x < 0 || y < 0 || x >= SIZE || y >= SIZE) continue;

                int yy = (y / 4) * 4 + (x % 4);
                int xx = (x / 4) * 4 + (3 - y % 4);
                if ((x / 4 == now.x / 4) && (y / 4 == now.y / 4))
                {
                    //same
                    int d = (now.d + 1) % 4;
                    if (visited[d][yy][xx] || arr[y / 4][x / 4].box[now.d][y % 4][x % 4] == 1) continue;
                    q.push({ yy, xx, d });
                    visited[d][yy][xx] = 1;
                }
                else
                {
                    //diff
                    if (visited[1][yy][xx] || arr[y / 4][x / 4].box[0][y % 4][x % 4] == 1) continue;
                    q.push({ yy, xx, 1 });
                    visited[1][yy][xx] = 1;
                }
            }
        }
        cnt++;
    }

    cout << -1;
    return 0;
}