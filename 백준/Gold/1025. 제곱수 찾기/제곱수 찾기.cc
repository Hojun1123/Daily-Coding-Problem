#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <unordered_map>
using namespace std;
int N, M;
int arr[9][9];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    string input;
    for (int i = 0; i < N; ++i) {
        cin >> input;
        for (int j = 0; j < M; ++j)
            arr[i][j] = input[j] - '0';
    }
    //step
    int answer = -1;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            for (int y = -N + 1; y < N; ++y)
            {
                for (int x = -M + 1; x < M; ++x)
                {
                    int num = 0;
                    int s = 1;
                    int cnt = 0;
                    int cy = i;
                    int cx = j;
                    if (x == 0 && y == 0)
                    {
                        if (arr[y][x] == 0 || arr[y][x] == 1 || arr[y][x] == 4 || arr[y][x] == 9)
                            answer = max(answer, arr[y][x]);
                        continue;
                    }
                    while (true)
                    {
                        num += s * arr[cy][cx];
                        s *= 10;
                        cy += y;
                        cx += x;
                        int tmp = sqrt(num);
                        if (tmp * tmp == num) {
                            answer = max(answer, num);
                        }
                        if (cy < 0 || cx < 0 || cy >= N || cx >= M) break;
                    }
                }
            }
        }
    }
    cout << answer;
    return 0;
}