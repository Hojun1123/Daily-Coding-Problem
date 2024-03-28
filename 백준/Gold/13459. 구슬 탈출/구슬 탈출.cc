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
char arr[10][10];
char tmpArr[10][10];
struct Node {
    int ry, rx;
    int by, bx;
};
queue<Node> q;
int check[10][10][10][10];
int EY, EX;
int up(int ry, int rx, int by, int bx)
{
    //y - 1
    bool findHole = false;
    bool isFailed = false;
    int y1, y2, x1, x2;
    if (ry < by)
    {
        y1 = ry;
        x1 = rx;
        while (true)
        {
            y1--;
            if (arr[y1][x1] == '#') break;
            if (arr[y1][x1] == 'O') {
                findHole = true;
                break;
            }
        }
        y1++;
        y2 = by;
        x2 = bx;
        while (true)
        {
            y2 -= 1;
            if (arr[y2][x2] == '#') break;
            if (arr[y2][x2] == 'O') {
                isFailed = true;
                break;
            }
            if (y1 == y2 && x1 == x2 && (!findHole)) {
                break;
            }
        }
        y2++;

    }
    else
    {
        y2 = by;
        x2 = bx;
        while (true)
        {
            y2 -= 1;
            if (arr[y2][x2] == '#') break;
            if (arr[y2][x2] == 'O') {
                isFailed = true; 
                break;
            }

        }
        y2++;

        y1 = ry;
        x1 = rx;
        while (true)
        {
            y1 -= 1;
            if (arr[y1][x1] == '#') break;
            if (arr[y1][x1] == 'O') {
                findHole = true;
                break;
            }
            if (y1 == y2 && x1 == x2) {
                break;
            }
        }
        y1++;
    }
    if (isFailed) return -1;
    if (findHole) return 1;
    if (check[y1][x1][y2][x2]) return 0;
    q.push({ y1, x1, y2, x2 });
    check[y1][x1][y2][x2] = 1;
    return 0;
}
int down(int ry, int rx, int by, int bx)
{
    //y + 1
    bool findHole = false;
    bool isFailed = false;
    int y1, y2, x1, x2;
    if (ry > by)
    {
        y1 = ry;
        x1 = rx;
        while (true)
        {
            y1 += 1;
            if (arr[y1][x1] == '#') break;
            if (arr[y1][x1] == 'O') {
                findHole = true;
                break;
            }

        }
        y1--;
        y2 = by;
        x2 = bx;
        while (true)
        {
            y2 += 1;
            if (arr[y2][x2] == '#') break;
            if (arr[y2][x2] == 'O') {
                isFailed = true;
                break;
            }
            if (y1 == y2 && x1 == x2 && (!findHole)) {
                break;
            }
        }
        y2--;

    }
    else
    {
        y2 = by;
        x2 = bx;
        while (true)
        {
            y2 += 1;
            if (arr[y2][x2] == '#') break;
            if (arr[y2][x2] == 'O') {
                isFailed = true;
                break;
            }

        }
        y2--;

        y1 = ry;
        x1 = rx;
        while (true)
        {
            y1 += 1;
            if (arr[y1][x1] == '#') break;
            if (arr[y1][x1] == 'O') {
                findHole = true;
                break;
            }
            if (y1 == y2 && x1 == x2) {
                break;
            }
        }
        y1--;
    }
    if (isFailed) return -1;
    if (findHole) return 1;
    if (check[y1][x1][y2][x2]) return 0;
    q.push({ y1, x1, y2, x2 });
    check[y1][x1][y2][x2] = 1;
    return 0;
}

int left(int ry, int rx, int by, int bx)
{
    //x - 1
    bool findHole = false;
    bool isFailed = false;
    int y1, y2, x1, x2;
    if (rx < bx)
    {
        y1 = ry;
        x1 = rx;
        while (true)
        {
            x1 -= 1;
            if (arr[y1][x1] == '#') break;
            if (arr[y1][x1] == 'O') {
                findHole = true;
                break;
            }

        }
        x1++;
        y2 = by;
        x2 = bx;
        while (true)
        {
            x2 -= 1;
            if (arr[y2][x2] == '#') break;
            if (arr[y2][x2] == 'O') {
                isFailed = true;
                break;
            }
            if (y1 == y2 && x1 == x2 && (!findHole)) {
                break;
            }
        }
        x2++;

    }
    else
    {
        y2 = by;
        x2 = bx;
        while (true)
        {
            x2 -= 1;
            if (arr[y2][x2] == '#') break;
            if (arr[y2][x2] == 'O') {
                isFailed = true;
                break;
            }

        }
        x2++;
        y1 = ry;
        x1 = rx;
        while (true)
        {
            x1 -= 1;
            if (arr[y1][x1] == '#') break;
            if (arr[y1][x1] == 'O') {
                findHole = true;
                break;
            }
            if (y1 == y2 && x1 == x2) {
                break;
            }
        }
        x1++;
    }
    if (isFailed) return -1;
    if (findHole) return 1;
    if (check[y1][x1][y2][x2]) return 0;
    q.push({ y1, x1, y2, x2 });
    check[y1][x1][y2][x2] = 1;
    return 0;
}

int right(int ry, int rx, int by, int bx)
{
    bool findHole = false;
    bool isFailed = false;
    int y1, y2, x1, x2;
    if (rx > bx)
    {
        y1 = ry;
        x1 = rx;
        while (true)
        {
            x1 += 1;
            if (arr[y1][x1] == '#') break;
            if (arr[y1][x1] == 'O') {
                findHole = true;
                break;
            }

        }
        x1--;
        y2 = by;
        x2 = bx;
        while (true)
        {
            x2 += 1;
            if (arr[y2][x2] == '#') break;
            if (arr[y2][x2] == 'O') {
                isFailed = true;
                break;
            }
            if (y1 == y2 && x1 == x2 && (!findHole)) {
                break;
            }
        }
        x2--;
    }
    else
    {
        y2 = by;
        x2 = bx;
        while (true)
        {
            x2 += 1;
            if (arr[y2][x2] == '#') break;
            if (arr[y2][x2] == 'O') {
                isFailed = true;
                break;
            }
        }
        x2--;
        y1 = ry;
        x1 = rx;
        while (true)
        {
            x1 += 1;
            if (arr[y1][x1] == '#') break;
            if (arr[y1][x1] == 'O') {
                findHole = true;
                break;
            }
            if (y1 == y2 && x1 == x2) {
                break;
            }
        }
        x1--;
    }
    if (isFailed) return -1;
    if (findHole) return 1;
    if (check[y1][x1][y2][x2]) return 0;
    q.push({ y1, x1, y2, x2 });
    check[y1][x1][y2][x2] = 1;
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    int ry, rx, by, bx;
    for (int i = 0; i < N; ++i)
    {
        string a;
        cin >> a;
        for (int j = 0; j < M; ++j)
        {
            arr[i][j] = a[j];
            if (arr[i][j] == 'O') {
                EY = i; EX = j;
            }
            else if (arr[i][j] == 'R') {
                ry = i; rx = j;
            }
            else if (arr[i][j] == 'B') {
                by = i; bx = j;
            }
        }
    }

    int cnt = 1;
    q.push({ ry, rx, by, bx });
    check[ry][rx][by][bx] = 1;
    while (!q.empty())
    {
        //cout << cnt << "\n";
        int qSize = q.size();
        for (int qs = 0; qs < qSize; qs++)
        {
            Node now = q.front();
            //cout << now.ry << " " << now.rx << ", " << now.by << " " << now.bx << "\n";
            q.pop();
            int ret = 0;
            ret = up(now.ry, now.rx, now.by, now.bx);
            if (ret == 1) {
                cout << 1;
                return 0;
            }
            ret = down(now.ry, now.rx, now.by, now.bx);
            if (ret == 1) {
                cout << 1;
                return 0;
            }
            ret = left(now.ry, now.rx, now.by, now.bx);
            if (ret == 1) {
                cout << 1;
                return 0;
            }
            ret = right(now.ry, now.rx, now.by, now.bx);
            if (ret == 1) {
                cout << 1;
                return 0;
            }
        }
        cnt++;
        if (cnt > 10) break;
    }
    cout << 0;
    return 0;
}
