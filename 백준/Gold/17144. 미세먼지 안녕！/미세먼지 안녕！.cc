#include <iostream>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
int R, C;   //R행, C열
int arr[50][50];
int prevArr[50][50];
int T;  //T초가 지난후의 미세먼지양출력
int Y; // 항상 X는 0
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> R >> C >> T;
    int input;
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            cin >> input;
            if (input == -1)
                Y = i;  //i - 1 , i
            arr[i][j] = input;
        }
    }

    int ax[4] = { 1, -1, 0, 0 };
    int ay[4] = { 0, 0, 1, -1 };
    int dx, dy;
   
    for (int t = 0; t < T; ++t)
    {
        for (int i = 0; i < R; ++i)
        {
            for (int j = 0; j < C; ++j)
            {
                prevArr[i][j] = arr[i][j];
            }
        }
        int amout;
        for (int i = 0; i < R; ++i)
        {
            for (int j = 0; j < C; ++j)
            {
                if (prevArr[i][j] <= 0)
                    continue;

                for (int k = 0; k < 4; ++k)
                {
                    dy = i + ay[k];
                    dx = j + ax[k];
                    if (dy >= 0 && dy < R && dx >= 0 && dx < C && prevArr[dy][dx] != -1)
                    {
                        amout = prevArr[i][j] / 5;
                        arr[dy][dx] += amout;
                        arr[i][j] -= amout;
                    }
                }
                
            }
        }

        int ty = Y - 1;
        int by = Y;
        for (int i = ty - 1; i > 0; i--)
        {
            arr[i][0] = arr[i - 1][0];
        }
        for (int i = by + 1; i < R - 1; i++)
        {
            arr[i][0] = arr[i + 1][0];
        }

        for (int j = 0; j < C - 1; j++)
        {
            arr[0][j] = arr[0][j + 1];
            arr[R - 1][j] = arr[R - 1][j + 1];
        }

        for (int i = 0; i < ty; i++)
        {
            arr[i][C - 1] = arr[i + 1][C - 1];
        }
        for (int i = R - 1; i > by; i--)
        {
            arr[i][C - 1] = arr[i - 1][C - 1];
        }

        for (int j = C - 1; j > 1; j--)
        {
            arr[ty][j] = arr[ty][j - 1];
            arr[by][j] = arr[by][j - 1];
        }

        arr[ty][1] = 0;
        arr[by][1] = 0;

    }
    int answer = 2;
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            answer += arr[i][j];
        }
    }
    cout << answer;
}