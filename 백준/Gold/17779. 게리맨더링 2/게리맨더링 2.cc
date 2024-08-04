#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <set>
using namespace std;
int N;
// 각 구역은 다섯 선거구 중 하나에 포함 되어야 함
// 선거구는 구역을 적어도 하나 포함
// 각 구역은 모두 연결 되엉 ㅣㅆ어야 함
// 0 ~ 19, 0 ~ 19
// x + d1, y - 
int arr[20][20];
int board[20][20];
int answer = 987654321;
int allsum = 0;
void draw(int sy, int sx, int d1, int d2)
{
    memset(board, 0, sizeof(board));
    for (int i = 0; i <= d1; ++i)
    {
        board[sy - i][sx + i] = 1;
        board[sy + d2 - i][sx + d2 + i] = 1;
    }
    for (int i = 0; i <= d2; ++i)
    {
        board[sy + i][sx + i] = 1;
        board[sy - d1 + i][sx + d1 + i] = 1;
    }


    //1
    int sn[5] = { 0, 0, 0, 0, 0 };
    for (int i = 0; i < sy; ++i) {
        for (int j = 0; j <= sx + d1; ++j)
        {
            if (board[i][j]) break;
            //board[i][j] = 2;
            sn[0] += arr[i][j];
        }
    }
    //2
    for (int i = 0; i <= sy - d1 + d2; ++i) {
        for (int j = N - 1; j > sx + d1; --j)
        {
            if (board[i][j]) break;
            //board[i][j] = 3;
            sn[1] += arr[i][j];
        }
    }
    //3
    for (int i = sy; i < N; ++i) {
        for (int j = 0; j < sx + d2; ++j)
        {
            if (board[i][j]) break;
            //board[i][j] = 4;
            sn[2] += arr[i][j];
        }
    }
    //4
    for (int i = sy - d1 + d2 + 1; i < N; ++i) {
        for (int j = N - 1; j >= sx + d2; --j)
        {
            if (board[i][j]) break;
            //board[i][j] = 5;
            sn[3] += arr[i][j];
        }
    }

    //cout << sy << ", " << sx << "\n";
    //for (int i = 0; i < N; ++i) {for (int j = 0; j < N; ++j) cout << board[i][j] << " ";cout << "\n";}
    sn[4] = allsum - sn[0] - sn[1] - sn[2] - sn[3];
    //for (int i = 0; i < 5; ++i) cout << sn[i] << ", "; cout << "\n";
    int maxValue = 0;
    int minValue = 99999999;
    for (int i = 0; i < 5; ++i)
    {
        minValue = min(minValue, sn[i]);
        maxValue = max(maxValue, sn[i]);
    }
    answer = min(answer, maxValue - minValue);
}
void bt(int sy, int sx)
{
    if (sx == N)
    {
        bt(sy + 1, 0);
        return;
    }
    if (sy == N)
    {
        return;
    }
    for (int d2 = 1; d2 + sy <= N; d2++)
    {
        for (int d1 = 1; d1 + d2 + sx <= N; d1++)
        {
            if (sx + d1 + d2 >= N || sy - d1 < 0 || sy + d2 >= N) continue;
            draw(sy, sx, d1, d2);
        }
    }

    bt(sy, sx + 1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N; 
    for (int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            cin >> arr[i][j];
            allsum += arr[i][j];
        }
    }
    bt(0, 0);
    cout << answer;
    return 0;
}