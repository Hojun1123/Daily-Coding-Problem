#include <iostream>
#include <sstream>
#include <map>
using namespace std;
int N;
int arr[12];
map<int, int> op;
int minValue = 2000000000;
int maxValue = -2000000000;
void dfs(int num, int a)
{
    if (a == N)
    {
        if (maxValue < num)
            maxValue = num;
        if (minValue > num)
            minValue = num;
        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        if (op[i] == 0) continue;
        op[i] -= 1;
        if (i == 0)
        {
            dfs(num + arr[a], a + 1);
        }
        else if (i == 1)
        {
            dfs(num - arr[a], a + 1);
        }
        else if (i == 2)
        {
            dfs(num * arr[a], a + 1);
        }
        else
        {
            dfs(num / arr[a], a + 1);
        }
        op[i] += 1;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }
    //+-x%
    for (int i = 0; i < 4; ++i)
    {
        int a;
        cin >> a;
        op[i] = a;
    }
    dfs(arr[0], 1);
    cout << maxValue << "\n" << minValue;
    return 0;
}