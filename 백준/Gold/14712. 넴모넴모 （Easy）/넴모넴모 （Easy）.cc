#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;
int N, M;
int arr[26][26];
int cnt = 0;
void bt(int y, int x)
{

    if (x == M + 1) {
        y += 1;
        x = 1;
    }
    if (y == N + 1) {
        cnt++;
        return;
    }
    if (arr[y - 1][x - 1] && arr[y - 1][x] && arr[y][x - 1])
    {
        bt(y, x + 1);
    }
    else {
        bt(y, x + 1);
        arr[y][x] = 1;
        bt(y, x + 1);
        arr[y][x] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin >> N >> M;
    bt(1, 1);
    cout << cnt;
    return 0;
 }