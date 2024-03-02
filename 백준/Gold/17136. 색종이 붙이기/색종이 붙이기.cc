#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <deque>
#include <unordered_map>
#include <cstring>
using namespace std;
int board[10][10];
int answer = 987654321;
struct yx {
    int y, x;
};
vector<yx> v;
map<int, int> m = { {1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5} };
int zeroCnt = 0;
bool check(int sy, int sx, int s)
{
    for (int i = sy; i < sy + s; ++i)
    {
        for (int j = sx; j < sx + s; ++j)
        {
            if (i >= 10 || j >= 10 || board[i][j] == 0) return false;
        }
    }
    return true;
}
void coverArr(int sy, int sx, int s)
{
    for (int i = sy; i < sy + s; ++i)
    {
        for (int j = sx; j < sx + s; ++j)
        {
            board[i][j] = 0;
        }
    }
}
void bt(int cnt, int zero, int index)
{
    //cout << cnt << " ";
    //printArr();
    if (answer < cnt) return;
    if (zero == zeroCnt)
    {
        if (cnt < answer) answer = cnt;
        //cout << cnt << " ";
        return;
    }
    
    //backup
    int tmpArr[10][10];
    memcpy(tmpArr, board, 400);
    for (int i = index + 1; i < v.size(); ++i)
    {
        yx now = v[i];
        if (board[now.y][now.x] == 0)continue;
        for (int s = 5; s >= 1; --s)
        {
            if (m[s] && check(now.y, now.x, s))
            {
                m[s] --;
                //cout << now.y << " " << now.x << " " << s << "\n";
                coverArr(now.y, now.x, s);
                bt(cnt + 1, zero + s * s, i);
                memcpy(board, tmpArr, 400);
                m[s] ++;
            }
        }
        return;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            cin >> board[i][j];
            if (board[i][j])
            {
                v.push_back({ i, j });
                zeroCnt++;
            }
        }
    }
    bt(0, 0, -1);
    cout << (answer >= 100 ? -1 : answer);
    return 0;
}