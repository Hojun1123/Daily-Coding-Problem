#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <cmath>
#include <unordered_map>
#include <cstring>
#include <algorithm>
using namespace std;
int N;
int board[6155][6155];
void re(int height, int width, int y, int x)
{
    if (height <= 3)
    {
        board[y][x] = 1;
        board[y + 1][x - 1] = 1;
        board[y + 1][x + 1] = 1;
        for (int i = -2; i <= 2; ++i) {
            board[y + 2][x + i] = 1;
        }
    }
    else
    {
        re(height / 2, width / 2 , y, x);
        re(height / 2, width / 2, y + height / 2, x + (width / 2) );
        re(height / 2, width / 2, y + height / 2, x - (width / 2) );
    }

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    //int size = log2(N / 3);
    re(N, (6 * N / 3) / 2, 0, (6 * N / 3) / 2);
    for (int i = 0; i < N; ++i) {
        for (int j = 1; j < 6 * N / 3; ++j) {
            cout << (board[i][j] ? "*" : " ");
        }
         cout << "\n";
    }
    return 0;
}