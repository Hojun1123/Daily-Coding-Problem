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
int N, M;
string arr[700];
int check[700][700];
int visited[700][700];
struct yx {
    int y, x;
};
int HY, HX;
int SY, SX;
int dy[4] = { 1, -1, 0 , 0 };
int dx[4] = { 0, 0, 1, -1 };
queue<yx> q;
bool isAble(int sy, int sx, int curr)
{
    for (int k = 0; k < 4; ++k)
    {
        int y = sy;
        int x = sx;
        while (true)
        {
            y += dy[k];
            x += dx[k];
            if (x < 0 || y < 0 || x >= M || y >= N || arr[y][x] == 'I') break;
            if (check[y][x] > curr) continue;
            else {
                return false;
            }
        }
    }
    return true;
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
            check[i][j] = 987654321;
        }
    }
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
        for (int j = 0; j < M; ++j)
        {
            if (arr[i][j] == 'V')
            {
                //해적
                q.push({ i, j });
                check[i][j] = 0;
            }
            else if (arr[i][j] == 'Y')
            {
                //수아
                SY = i;
                SX = j;
            }
        }
    }
    //1 ~ cnt
    //해당 숫자 - 1 번째에 해적이 도달할 수 있는 곳
    //수아의 4 방향 중, 섬이 사이에 없고, 만약 숫자가 1 ~ cnt
    int vcnt = 1;
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
                if (x < 0 || y < 0 || x >= M || y >= N || check[y][x] < 987654321 || arr[y][x] == 'I') continue;
                check[y][x] = vcnt;
                q.push({ y, x });
            }
        }
        vcnt++;
    }

    //for (int i = 0; i < N; ++i) { for (int j = 0; j < M; ++j) cout << check[i][j] << " "; cout << "\n"; }
    //해당 숫자보다 큰 경우에 진행 가능.
    q.push({ SY, SX });
    visited[SY][SX] = 1;
    int cnt = 1;
    while (!q.empty())
    {
        int qSize = q.size();
        for (int i = 0; i < qSize; ++i)
        {
            yx now = q.front();
            q.pop();
            if (arr[now.y][now.x] == 'T') {
                cout << "YES";
                return 0;
            }
            for (int k = 0; k < 4; ++k)
            {
                int y = dy[k] + now.y;
                int x = dx[k] + now.x;
                if (x < 0 || y < 0 || x >= M || y >= N || arr[y][x] == 'I' || visited[y][x]) continue;
                //if
                if (isAble(y, x, cnt))
                {
                    q.push({ y, x });
                    visited[y][x] = 1;
                }

            }
        }
        cnt++;
    }
    cout << "NO";
    return 0;
}
 