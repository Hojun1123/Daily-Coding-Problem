#include <iostream>
#include <vector>
#include <map>
#include <deque>
#include <list>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <cstring>
#include <list>
using namespace std;
int R, C, M;
struct Shark {
    bool died;
    int y, x;
    int speed;
    int dir;    //1 2 3 4 > 위 아래 오른쪽 왼쪽
    int size;
};
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
vector<Shark> shark;
vector<int> board[100][100];    //이동 후 상어의 위치
int catchedSharkSizeSum = 0;
void solve()
{
    //1. player가 1 칸 > 이동
    //2. 해당 열에 가장 가까운 상어를 잡음, 상어는 사라짐
    //3. 상어가 이동
    // - 속도대로 이동하고, 만약 칸을 넘어 이동하려고하면 반대로 이동
    for (int pos = 0; pos < C; ++pos)
    {
        //1.
        for (int r = 0; r < R; ++r)
        {
            if (board[r][pos].size() > 0)
            {
                catchedSharkSizeSum += shark[board[r][pos][0]].size;
                shark[board[r][pos][0]].died = true;
                //cout << board[r][pos][0] << " : ";
                break;
            }
        }
        for (int i = 0; i < R; ++i)
        {
            for (int j = 0; j < C; ++j)
            {
                board[i][j].clear();
            }
        }
        //2.
        for (int sIndex = 0; sIndex < shark.size(); ++sIndex)
        {
            if (shark[sIndex].died) continue;
            int currSpeed = shark[sIndex].speed;
            int currDir = shark[sIndex].dir;
            int y = shark[sIndex].y;
            int x = shark[sIndex].x;
            if (currDir < 2)
            {
                //상하
                currSpeed = currSpeed % (2 * (R - 1));
                for (int i = 0; i < currSpeed; ++i)
                {
                    y += dy[currDir];
                    if (y < 0 || y >= R)
                    {
                        currDir = (currDir == 0 ? 1 : 0);
                        y += dy[currDir] * 2;
                    }
                }
            }
            else
            {
                //좌우
                currSpeed = currSpeed % (2 * (C - 1));
                for (int i = 0; i < currSpeed; ++i)
                {
                    x += dx[currDir];
                    if (x < 0 || x >= C)
                    {
                        currDir = (currDir == 2 ? 3 : 2);
                        x += dx[currDir] * 2;
                    }
                }
            }
            board[y][x].push_back(sIndex);
            shark[sIndex].dir = currDir;
            shark[sIndex].y = y;
            shark[sIndex].x = x;
        }

        for (int i = 0; i < R; ++i)
        {
            for (int j = 0; j < C; ++j)
            {
                int cSize = board[i][j].size();
                if (cSize == 0) continue;
                int maxSize = shark[board[i][j][0]].size;
                int maxIndex = board[i][j][0];
                for (int k = 1; k < cSize; ++k)
                {
                    int kIndex = board[i][j][k];
                    if (maxSize < shark[kIndex].size)
                    {
                        shark[maxIndex].died = true;
                        maxSize = shark[kIndex].size;
                        maxIndex = kIndex;
                    }
                    else
                    {
                        shark[kIndex].died = true;
                    }
                }
                board[i][j].clear();
                board[i][j].push_back(maxIndex);
            }
        }
        /*
        cout << "\n";
        for (int i = 0; i < R; ++i)
        {
            for (int j = 0; j < C; ++j)
            {
                if (board[i][j].size())
                    cout << board[i][j][0] + 1;
                else
                    cout << 0;
            }
            cout << "\n";
        }
        */
    }
    cout << catchedSharkSizeSum;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> R >> C >> M;
    for (int i = 0; i < M; ++i)
    {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        shark.push_back({false, a - 1, b - 1, c, d - 1, e });
        board[a - 1][b - 1].push_back(i);
    }
    solve();
    return 0;
}
