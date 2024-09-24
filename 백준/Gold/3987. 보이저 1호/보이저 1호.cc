#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
using namespace std;
int N, M;
string arr[501];
int SY, SX;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int check[501][501][4];
char cc[4] = { 'U', 'R', 'D', 'L' };
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; ++i) cin >> arr[i];
    //U R D L
    cin >> SY >> SX;
    SY--; SX--;
    
    int maxTime = 0;
    int maxIndex = 0;
    for (int i = 0; i < 4; ++i)
    {
        memset(check, 0, sizeof(check));
        int t = 0;
        int y = SY;
        int x = SX;
        int dir = i;
        while (true)
        {
            if (x < 0 || y < 0 || x >= M || y >= N) break;
            if (check[y][x][dir]) {
                cout << cc[i] << "\n";
                cout << "Voyager";
                return 0;
            }
            char curr = arr[y][x];
            if (curr == '.') {
                check[y][x][dir] = 1;
            }
            else if (curr == '/') {
                if (dir == 0) {
                    dir = 1;
                }
                else if (dir == 1) {
                    dir = 0;
                }
                else if (dir == 2) {
                    dir = 3;
                }
                else {
                    dir = 2;
                }
            }
            else if (curr == '\\') {
                if (dir == 0) {
                    dir = 3;
                }
                else if (dir == 1) {
                    dir = 2;
                }
                else if (dir == 2) {
                    dir = 1;
                }
                else {
                    dir = 0;
                }
            }
            else if (curr == 'C') {
                break;
            }
            y += dy[dir];
            x += dx[dir];
            t++;
        }
        if (maxTime < t) {
            maxTime = t;
            maxIndex = i;
        }
    }
    cout << cc[maxIndex] << "\n";
    cout << maxTime;
    return 0;
}