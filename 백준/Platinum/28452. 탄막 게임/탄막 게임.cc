#define _CRT_SECURE_NO_WARNINGS
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
#include <set>
using namespace std;
int N, M, T;
int X, Y;
int K;
struct yx {
    int y, x;
};
yx bollet[10000];
queue<yx> bq;
queue<yx> q;
int board[100][100];
int player[100][100];
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> T;
    cin >> Y >> X;
    cin >> K;
    for (int i = 0; i < K; ++i)
    {
        int x, y;
        cin >> y >> x;
        bq.push({ y, x });
        board[y][x] = 1;
    }

    q.push({ Y, X });
    player[Y][X] = 1;
    int cnt = 2;
    while (!q.empty())
    {
        int qSize = q.size();
        for (int i = 0; i < qSize; ++i)
        {
            yx pNow = q.front();
            q.pop();
            for (int k = 0; k < 8; ++k)
            {
                int y = dy[k] + pNow.y;
                int x = dx[k] + pNow.x;
                if (x < 0 || y < 0 || x >= M || y >= N) continue;
                if (player[y][x]) continue; 
                player[y][x] = cnt;
                q.push({ y, x });
            }
        }
        cnt++;
    }

    cnt = 2;
    while (!bq.empty())
    {
        int qSize = bq.size();
        for (int i = 0; i < qSize; ++i)
        {
            yx bNow = bq.front();
            bq.pop();
            for (int k = 0; k < 8; ++k)
            {
                int y = dy[k] + bNow.y;
                int x = dx[k] + bNow.x;
                if (x < 0 || y < 0 || x >= M || y >= N) continue;
                if (board[y][x]) continue;
                board[y][x] = cnt;
                bq.push({ y, x });
            }
        }
        cnt++;
    }
    /*
    cout << "player : \n";
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cout << player[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "bo : \n";
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cout << board[i][j] << " "; 
        }
        cout << "\n";
    }
    */
    bool result = false;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (board[i][j] > player[i][j] && T < board[i][j] - 1)
            {
                result = true;
            }
        }
        //cout << "\n";
    }
    
    cout << (result || K == 0 ? "YES" : "NO");
    return 0;
}