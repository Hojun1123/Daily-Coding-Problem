#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int N, L, R, X;
int arr[16];
vector<int> curr;
int cnt = 0;
void dfs(int pick, int index, int sum)
{
    if (index == N)
    {
        if (pick < 2) return;
        if (sum < L || sum > R) return;
        int minValue = 999999999;
        int maxValue = 0;
        for (int i = 0; i < curr.size(); ++i)
        {
            if (curr[i] > maxValue)
            {
                maxValue = curr[i];
            }
            if (curr[i] < minValue)
            {
                minValue = curr[i];
            }
        }
        if (maxValue - minValue < X) return;
        cnt++; return;
    }
    dfs(pick, index + 1, sum);
    curr.push_back(arr[index]);
    dfs(pick + 1, index + 1, sum + arr[index]);
    curr.pop_back();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> L >> R >> X;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }
    dfs(0, 0, 0);
    cout << cnt;
    return 0;
}