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
int N, M;
int arr[50][50];
int answer = 2100000000;
int check[14];
int cnt = 0;
struct yx {
    int y;
    int x;
};
vector<yx> chicken;
vector<yx> home;
int distance()
{
    int result = 0;
    for (yx i : home)
    {
        int minDis = 987654321;
        for (int j = 0; j < chicken.size(); ++j)
        {
            if (!check[j]) continue;
            int d = abs(i.y - chicken[j].y) + abs(i.x - chicken[j].x);
            if (d < minDis)
            {
                minDis = d;
            }
        }
        result += minDis;
    }
    return result;
}
void recursion(int index)
{
    if (index == chicken.size())
    {
        if (cnt == M)
        {
            int tmp = distance();
            if (tmp < answer)
            {
                answer = tmp;
            }
        }
        return;
    }
    recursion(index + 1);
    cnt++;
    check[index] = 1;
    recursion(index + 1);
    check[index] = 0;
    cnt--;
}
int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 2)
            {
                chicken.push_back({ i , j });
            }
            else if (arr[i][j] == 1)
            {
                home.push_back({ i, j });
            }
        }
    }
    recursion(0);
    cout << answer;
    return 0;
}