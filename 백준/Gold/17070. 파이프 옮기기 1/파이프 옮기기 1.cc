#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <deque>
#include <unordered_map>
#include <cstring>
using namespace std;
int N;
int arr[16][16];
int answer = 0;
struct yx {
    int y, x;
};
int py = 0, px = 1, dir = 0;
void bt()
{
    if (py == N - 1 && px == N - 1)
    {
        answer++;
        return;
    }
    if (dir == 0)
    {
        if (px + 1 < N && arr[py][px + 1] == 0)
        {
            px++;
            bt();
            px--;
        }
        if (px + 1 < N && py + 1 < N && arr[py][px + 1] == 0 && arr[py + 1][px] == 0 && arr[py + 1][px + 1] == 0)
        {
            dir = 1;
            py++;
            px++;
            bt();
            py--;
            px--;
            dir = 0;
        }
    }
    else if (dir == 1)
    {
        if (px + 1 < N && arr[py][px + 1] == 0)
        {
            dir = 0;
            px++;
            bt();
            px--;
            dir = 1;
        }
        if (px + 1 < N && py + 1 < N && arr[py][px + 1] == 0 && arr[py + 1][px] == 0 && arr[py + 1][px + 1] == 0)
        {
            py++;
            px++;
            bt();
            py--;
            px--;
        }
        if (py + 1 < N && arr[py + 1][px] == 0)
        {
            dir = 2;
            py++;
            bt();
            py--;
            dir = 1;
        }
    }
    else
    {
        if (px + 1 < N && py + 1 < N && arr[py][px + 1] == 0 && arr[py + 1][px] == 0 && arr[py + 1][px + 1] == 0)
        {
            dir = 1;
            py++;
            px++;
            bt();
            py--;
            px--;
            dir = 2;
        }
        if (py + 1 < N && arr[py + 1][px] == 0)
        {
            py++;
            bt();
            py--;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> arr[i][j];
        }
    }
    bt();
    cout << answer;
    return 0;
}