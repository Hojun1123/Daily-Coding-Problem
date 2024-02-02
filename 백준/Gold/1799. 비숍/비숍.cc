#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <vector>
using namespace std;
int N, K;
int board[10][10];
struct yx {
    int y;
    int x;
};
vector<yx> v;
vector<yx> nv;
vector<yx> nc[100];
vector<yx> odd;
vector<yx> even;
int cnt = 0;
int oddCnt =0;
int evenCnt = 0;
int oddMax = 0;
int evenMax = 0;
int dy[4] = {-1, 1, 1, -1};
int dx[4] = { 1, 1, -1, -1 };
bool check(int y, int x)
{
    int yy, xx;
    for (int i = 0; i < 4; ++i)
    {
        yy = y;
        xx = x;
        while (true)
        {
            yy += dy[i];
            xx += dx[i];
            if (yy < 0 || xx < 0 || yy >= N || xx >= N)
                break;

            if (board[yy][xx] == 2)
            {
                return false;
            }
        }
    }
    return true;
}
void oddbt(int depth)
{
    if(depth == odd.size())
    {
        if(oddCnt > oddMax)
            oddMax = oddCnt;
        return;    
    }
    
    oddbt(depth + 1);
    int y = odd[depth].y;
    int x = odd[depth].x;
    if(!check(y, x))
        return;
    board[y][x] = 2;
    oddCnt ++;
    oddbt(depth+1);
    oddCnt --;
    board[y][x] = 1;
}
void evenbt(int depth)
{
    if(depth == even.size())
    {
        if(evenCnt > evenMax)
            evenMax = evenCnt;
        return;    
    }
    
    evenbt(depth + 1);
    int y = even[depth].y;
    int x = even[depth].x;
    if(!check(y, x))
        return;
    board[y][x] = 2;
    evenCnt ++;
    evenbt(depth+1);
    evenCnt --;
    board[y][x] = 1;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            cin >> board[i][j];
            if (board[i][j])
                v.push_back({ i, j });
        }
    }
    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = 0; j < v.size(); ++j)
        {
            if (i == j)
                continue;
            if (abs(v[i].y - v[j].y) == abs(v[i].x - v[j].x))
            {
                nc[i].push_back(v[j]);
            }
        }
    }
    int index = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        if (nc[i].size() == 0)
        {
            board[v[i].y][v[i].x] = 2;
            cnt++;
        }
        else
        {
            nv.push_back({ v[i].y, v[i].x });
        }
    }
    for(int i = 0; i< nv.size(); ++i)
    {
        if((nv[i].y + nv[i].x) % 2)
        {
            odd.push_back({nv[i].y, nv[i].x});
        }
        else
        {
            even.push_back({nv[i].y, nv[i].x});
        }
    }
    oddbt(0);
    evenbt(0);
    cout << cnt + oddMax + evenMax;
    return 0;
}