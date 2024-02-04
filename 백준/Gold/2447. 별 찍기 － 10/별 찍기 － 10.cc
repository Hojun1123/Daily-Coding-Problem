#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <vector>
#include<cstring>
using namespace std;
int N;
int answer[7000][7000];
void recursion(int size, int y, int x)
{
    if (size == 0)
    {
        answer[y][x] = 1;
        return;
    }
    int yy = y;
    for (int i = 0; i < 3; i++)
    {
        int xx = x;
        for (int j = 0; j < 3; j++)
        {
            if (i == 1 && j == 1)
            {

            }
            else
            {
                recursion(size / 3, yy, xx);
            }
            xx += size;
        }
        yy += size;
    }
}
int main()
{
    cin >> N;
    recursion(N/3, 0, 0);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << (answer[i][j] == 0 ? ' ' : '*');
        }
        cout << "\n";
    }
    return 0;
}