#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <vector>
#include <unordered_set>
using namespace std;
int N, M;
string arr[1000];
int check[1000][1000];
int answer[1000][1000];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
struct yx { int y, x; };
int board[1000][1000];
map<int, int> m;
void bfs(int sy, int sx, int key)
{
    queue<yx> q;
    int cnt = 1;
    q.push({ sy, sx });
    check[sy][sx] = 1;
    board[sy][sx] = key;
    while (!q.empty())
    {
        yx now = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int y = now.y + dy[i];
            int x = now.x + dx[i];
            if (x >= 0 && y >= 0 && x < M && y < N && check[y][x] == 0 && arr[y][x] == '0')
            {
                q.push({ y, x });
                board[y][x] = key;
                check[y][x] = 1;
                cnt++;
            }
        }
    }
    m[key] = cnt;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N >> M; 
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }
    int key = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (arr[i][j] == '0' && check[i][j] == 0)
            {
                bfs(i, j, key);
                key++;
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (arr[i][j] == '0') 
            {
                cout << 0;
                continue;
            }
            int now = 1;
            unordered_set<int> s;
            for (int k = 0; k < 4; ++k)
            {
                int y = dy[k] + i;
                int x = dx[k] + j;
                if (x >= 0 && y >= 0 && x < M && y < N && arr[y][x] == '0')
                {
                    s.insert(board[y][x]);
                }
            }
            for (auto k : s)
            {
                now += m[k];
            }
            cout << now %10;
        }
        cout << "\n";
    }
    return 0;
}