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
string input[9];
int arr[9][9];
int row[9][10];
int col[9][10];
int box[10][10];
int flag = false;
int boxPos(int sy, int sx)
{
    if (sy < 3)
    {
        if (sx < 3) return 1;
        else if (sx < 6) return 2;
        else return 3;
    }
    else if (sy < 6)
    {
        if (sx < 3) return 4;
        else if (sx < 6) return 5;
        else return 6;
    }
    else
    {
        if (sx < 3) return 7;
        else if (sx < 6) return 8;
        else return 9;
    }
}
void bt(int y, int x)
{
    if (flag) return;
    if (y == 9)
    {
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                cout << arr[i][j];
            }
            cout << "\n";
        }
        flag = true;
        return;
    }
    if (x == 9)
    {
        bt(y + 1, 0);
        return;
    }
    if (arr[y][x] > 0)
    {
        bt(y, x + 1);
        return;
    }
    for (int i = 1; i <= 9; ++i)
    {
        int bp = boxPos(y, x);
        if (row[y][i] || col[x][i] || box[bp][i]) continue;
        arr[y][x] = i;
        row[y][i] = 1;
        col[x][i] = 1;
        box[bp][i] = 1;
        bt(y, x + 1);
        arr[y][x] = 0;
        row[y][i] = 0;
        col[x][i] = 0;
        box[bp][i] = 0;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 9; ++i)
    {
        cin >> input[i];
        for (int j = 0; j < 9; ++j)
        {
            int curr = input[i][j] - '0';
            arr[i][j] = curr;
            if (curr == 0) continue;
            row[i][curr] = 1;
            col[j][curr] = 1;
            box[boxPos(i, j)][curr] = 1;
        }
    }
    bt(0, 0);
    return 0;
}
