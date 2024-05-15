#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;
int N, M;
string arr[10];
//LRUD
struct yx {
    int y1, x1, y2, x2;
};
int visited[10][10][10][10];
queue<yx> q;
//LRUD 0123
yx path[10][10][10][10];
char op[10][10][10][10];
//빨강을 구멍에 넣어야함.
void Left(int _by, int _bx, int _ry, int _rx)
{
    int by = _by, bx = _bx, ry = _ry, rx = _rx;
    if (bx < rx) {
        while (true) {
            bx -= 1;
            if (arr[by][bx] == '#') break;//벽
            else if (arr[by][bx] == 'O') return;//실패
        }
        bx += 1;
        while (true) {
            rx -= 1;
            if (arr[ry][rx] == '#') break;
            else if (arr[ry][rx] == 'O') {
                rx -= 1;
                break;
            }
            else if (ry == by && rx == bx) break;
        }
        rx += 1;
    }
    else {
        while (true) {
            rx -= 1;
            if (arr[ry][rx] == '#') break;
            else if (arr[ry][rx] == 'O') {
                rx -= 1;
                break;
            }
        }
        rx += 1;
        while (true) {
            bx -= 1;
            if (arr[by][bx] == '#') break;
            else if (arr[by][bx] == 'O') return;
            else if (by == ry && bx == rx) break;
        }
        bx += 1;
    }
    if (visited[by][bx][ry][rx]) return;
    q.push({ by, bx, ry, rx });
    visited[by][bx][ry][rx] = 1;
    path[by][bx][ry][rx] = { _by, _bx, _ry, _rx };
    op[by][bx][ry][rx] = 'L';
}
void Right(int _by, int _bx, int _ry, int _rx)
{
    int by = _by, bx = _bx, ry = _ry, rx = _rx;
    if (bx > rx) {
        // < 파란공먼저
        while (true) {
            bx += 1;
            if (arr[by][bx] == '#') break;//벽
            else if (arr[by][bx] == 'O') return;//실패
        }
        bx -= 1;
        while (true) {
            rx += 1;
            if (arr[ry][rx] == '#') break;
            else if (arr[ry][rx] == 'O') {
                rx += 1;
                break;
            }
            else if (ry == by && rx == bx) break;
        }
        rx -= 1;
    }
    else {
        while (true) {
            rx += 1;
            if (arr[ry][rx] == '#') break;
            else if (arr[ry][rx] == 'O') {
                rx += 1;
                break;
            }
        }
        rx -= 1;
        while (true) {
            bx += 1;
            if (arr[by][bx] == '#') break;
            else if (arr[by][bx] == 'O') return;
            else if (by == ry && bx == rx) break;
        }
        bx -= 1;
    }
    if (visited[by][bx][ry][rx]) return;
    q.push({ by, bx, ry, rx });
    visited[by][bx][ry][rx] = 1;
    path[by][bx][ry][rx] = { _by, _bx, _ry, _rx };
    op[by][bx][ry][rx] = 'R';
}
void Up(int _by, int _bx, int _ry, int _rx)
{
    int by = _by, bx = _bx, ry = _ry, rx = _rx;
    if (by < ry) {
        // < 파란공먼저
        while (true) {
            by -= 1;
            if (arr[by][bx] == '#') break;//벽
            else if (arr[by][bx] == 'O')return;//실패
        }
        by += 1;
        while (true) {
            ry -= 1;
            if (arr[ry][rx] == '#') break;
            else if (arr[ry][rx] == 'O') {
                ry -= 1;
                break;
            }
            else if (ry == by && rx == bx) break;
        }
        ry += 1;
    }
    else {
        while (true) {
            ry -= 1;
            if (arr[ry][rx] == '#') break;
            else if (arr[ry][rx] == 'O') {
                ry -= 1;
                break;
            }
        }
        ry += 1;
        while (true) {
            by -= 1;
            if (arr[by][bx] == '#') break;
            else if (arr[by][bx] == 'O') return;
            else if (by == ry && bx == rx) break;
        }
        by += 1;
    }
    if (visited[by][bx][ry][rx]) return;
    q.push({ by, bx, ry, rx });
    visited[by][bx][ry][rx] = 1;
    path[by][bx][ry][rx] = { _by, _bx, _ry, _rx };
    op[by][bx][ry][rx] = 'U';
}
void Down(int _by, int _bx, int _ry, int _rx)
{
    int by = _by, bx = _bx, ry = _ry, rx = _rx;
    if (by > ry) {
        while (true) {
            by += 1;
            if (arr[by][bx] == '#') break;//벽
            else if (arr[by][bx] == 'O')return;//실패
        }
        by -= 1;
        while (true) {
            ry += 1;
            if (arr[ry][rx] == '#') break;
            else if (arr[ry][rx] == 'O') {
                ry += 1;
                break;
            }
            else if (ry == by && rx == bx) break;
        }
        ry -= 1;
    }
    else {
        while (true) {
            ry += 1;
            if (arr[ry][rx] == '#') break;
            else if (arr[ry][rx] == 'O') {
                ry += 1;
                break;
            }
        }
        ry -= 1;
        while (true) {
            by += 1;
            if (arr[by][bx] == '#') break;
            else if (arr[by][bx] == 'O') return;
            else if (by == ry && bx == rx) break;
        }
        by -= 1;
    }
    if (visited[by][bx][ry][rx]) return;
    q.push({ by, bx, ry, rx });
    visited[by][bx][ry][rx] = 1;
    path[by][bx][ry][rx] = { _by, _bx, _ry, _rx };
    op[by][bx][ry][rx] = 'D';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    int a, b, c, d;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        for (int j = 0; j < M; ++j) {
            if (arr[i][j] == 'B') {
                a = i; b = j;
                arr[i][j] = '.';
            }
            else if (arr[i][j] == 'R') {
                c = i; d = j;
                arr[i][j] = '.';
            }
        }
    }
    q.push({ a, b, c, d });
    visited[a][b][c][d] = 1;
    int cnt = 0;
    while (!q.empty())
    {
        int qSize = q.size();
        for (int i = 0; i < qSize; ++i)
        {
            yx now = q.front();
            q.pop();
            if (arr[now.y2][now.x2] == 'O') {
                //find
                cout << cnt << "\n";
                stack<char> s;
                yx nxt = now;
                while (true) {
                    s.push(op[nxt.y1][nxt.x1][nxt.y2][nxt.x2]);
                    nxt = path[nxt.y1][nxt.x1][nxt.y2][nxt.x2];
                    if (nxt.y1 == a && nxt.x1 == b && nxt.y2 == c && nxt.x2 == d) break;
                }
                while (!s.empty()) {
                    cout << s.top();
                    s.pop();
                }
                return 0;
            }
            Left(now.y1, now.x1, now.y2, now.x2);
            Right(now.y1, now.x1, now.y2, now.x2);
            Up(now.y1, now.x1, now.y2, now.x2);
            Down(now.y1, now.x1, now.y2, now.x2);
        }
        cnt++;
        if (cnt > 10) break;
    }
    cout << -1;
    return 0;
}