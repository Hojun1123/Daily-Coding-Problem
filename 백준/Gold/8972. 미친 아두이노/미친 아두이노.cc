#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
//종수는 미친 아두이노를 피해야함
//R,C
//항상 가까워지는 방향으로 한칸이동.
//체비쇼프 거리 문제
//R은 미친 아두이노. I는 종수
int dy[9] = { 1, 1, 1, 0, 0, 0, -1, -1, -1 };
int dx[9] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };
int R, C;
string input;
struct yx {
    int y, x;
    bool operator<(yx o) const {
        if (y < o.y) return true;
        else if (y > o.y) return false;
        return x < o.x;
    }
};
int board[100][100];
queue<yx> robot;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> R >> C;
    int sy, sx;
    for (int i = 0; i < R; ++i) {
        string a;
        cin >> a;
        for (int j = 0; j < C; ++j) {
            if (a[j] == 'I') {
                sy = i;
                sx = j;
            }
            else if (a[j] == 'R') {
                board[i][j] = 1;
                robot.push({ i, j });
            }
        }
    }
    cin >> input;

    int cnt = 1;
    for (int p = 0; p < input.size(); ++p) {
        int dir = (input[p] - '0') - 1;
        sy += dy[dir];
        sx += dx[dir];
        if (board[sy][sx]) {
            cout << "kraj " << cnt;
            return 0;
        }
        
        map<yx, int> m;
        while(!robot.empty())
        {
            //나아갈 칸 구하기
            int currY = robot.front().y;
            int currX = robot.front().x;
            robot.pop();
            //이전 칸 지우기
            board[currY][currX] = 0;
            int yy = currY + ((sy == currY) ? 0 : (sy < currY ? -1:1));
            int xx = currX + ((sx == currX) ? 0 : (sx < currX ? -1:1));
            if (yy == sy && xx == sx) {
                cout << "kraj " << cnt;
                return 0;
            }
            m[{ yy, xx }]++;
        }

        for (auto i = m.begin(); i != m.end(); ++i) {
            if (i->second == 1) {
                board[i->first.y][i->first.x] = 1;
                robot.push(i->first);
            }
        }
        cnt++;
    }
    board[sy][sx] = 2;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (board[i][j] == 1) {
                cout << 'R';
            }
            else if (board[i][j] == 2) {
                cout << 'I';
            }
            else {
                cout << '.';
            }
        }
        cout << "\n";
    }
    return 0;
}