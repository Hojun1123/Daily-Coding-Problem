#include <vector>
#include <cmath>
#include <iostream>
#include <stack>
#include <queue>
#include <cstring>
#include <map>
#include <unordered_map>
using namespace std;
int L, K;
long long SIZE;
struct yx {
    long long y, x;
    bool operator<(yx other) const
    {
        if (y < other.y) return true;
        else if (y > other.y) return false;
        if (x < other.x) return true;
        else if (x > other.x) return false;
        return false;
    }
};
map<yx, bool> m;
map<long long, int> op;
struct Line {
    yx a;
    yx b;
    bool isHoriz;   //수평인지
    Line() {};
    Line(yx d1, yx d2)  // LEFT, TOP 순으로 Push
    {
        if (d1.x == d2.x)   //수직
        {
            isHoriz = false;
            if (d1.y < d2.y)
            {
                a = d1;
                b = d2;
            }
            else
            {
                b = d1;
                a = d2;
            }
        }
        else   //수평
        {
            isHoriz = true;
            if (d1.x < d2.x)
            {
                a = d1;
                b = d2;
            }
            else
            {
                a = d2;
                b = d1;
            }
        }
    }
};
vector<Line> lines;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
long long checkCrossLine(Line line, int dir)
{
    long long minLen = 2100000000;
    int flag = true;
    for (Line& l : lines)
    {
        if (dir == 0)
        {
            if (l.a.y <= line.a.y && l.b.y >= line.a.y)
            {
                if (line.b.x >= l.a.x && line.a.x <= l.a.x)
                {
                    flag = false;
                    minLen = min(minLen, l.a.x - line.a.x);
                }
            }
        }
        else if (dir == 2)
        {
            if (l.a.y <= line.a.y && l.b.y >= line.a.y)
            {
                if (line.a.x <= l.b.x && line.b.x >= l.b.x)
                {
                    flag = false;
                    minLen = min(minLen, line.b.x - l.b.x);
                }
            }
        }
        else if (dir == 1)
        {
            if (l.a.x <= line.a.x && l.b.x >= line.a.x)
            {
                if (line.b.y >= l.a.y && line.a.y <= l.a.y)
                {
                    flag = false;
                    minLen = min(minLen, l.a.y - line.a.y);
                }
            }
        }
        else
        {
            if (l.a.x <= line.a.x && l.b.x >= line.a.x)
            {
                if (line.a.y <= l.b.y && line.b.y >= l.b.y)
                {
                    flag = false;
                    minLen = min(minLen, line.b.y - l.b.y);
                }
            }
        }
    }
    if (flag) return -1;
    return minLen;
}
void solve()
{
    cin >> L >> K;
    long long s = 0;
    for (int i = 0; i < K; ++i)
    {
        long long a;
        char b;
        cin >> a >> b;
        s = s + a;
        op[s] = (b == 'L' ? -1 : 1);
    }
    op[s + 200000000] = 0;
    SIZE = 2 * L + 1;
    m[{L, L}] = true;

    long long nowTime = 0;
    yx prevDot = { L, L };
    int snakeDir = 0;
    //각 경로를 선분 단위로 취급
    bool outflag = false;
    for (auto iter = op.begin(); iter != op.end(); ++iter)
    {
        //cout << nowTime << " : " << "y : " << prevDot.y << " " << "x : " << prevDot.x << "\n";
        long long ct = iter->first;
        int d = iter->second;

        // calculate distance
        long long diff = ct - nowTime;
        long long ny = prevDot.y + diff * dy[snakeDir];
        long long nx = prevDot.x + diff * dx[snakeDir];
        if (ny < 0 || nx < 0 || ny >= SIZE || nx >= SIZE)
        {
            if (snakeDir == 0)
            {
                nx = SIZE - 1;
                diff = nx - prevDot.x;
            }
            else if (snakeDir == 2) 
            { 
                nx = 0; 
                diff = prevDot.x - nx;
            }
            else if (snakeDir == 1)
            {
                ny = SIZE - 1;
                diff = ny - prevDot.y;
            }
            else 
            {
                ny = 0;
                diff = prevDot.y - ny;
            }
            long long r = checkCrossLine(Line(prevDot, {ny, nx}), snakeDir);
            if (r == -1)
                cout << nowTime + diff + 1;
            else
                cout << nowTime + r;
            return;
        }  //out
        //cout << ny << " " << nx << "\n";
        // check cross
        Line currLine = Line(prevDot, { ny, nx });
        long long result = checkCrossLine(currLine, snakeDir);
        if (result != -1)
        {
            nowTime += result;
            cout << nowTime;
            return;
        }
        nowTime = ct;
        currLine = Line(prevDot, { ny - dy[snakeDir], nx - dx[snakeDir] });
        lines.push_back(currLine);
        // update
        snakeDir = (4 + snakeDir + d) % 4;
        prevDot = { ny, nx };
    }

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}