#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <string>
#include <unordered_map>
#include <bitset>
#include <stack>
#include <unordered_set>
#include <cstring>
using namespace std;
int N;
int arr[20][20];
int start[20];
int ans = 987654321;
void bt(int curr, int cnt)
{
    if (cnt == N / 2)
    {
        int s = 0;
        int ss = 0;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (start[i] && start[j]) s += arr[i][j];
                if (!start[i] && !start[j]) ss += arr[i][j];
            }
        }
        //cout << ss << " " << s << "\n";
        ans = min(ans, abs(ss - s));
        return;
    }
    if (curr == N) {
        return;
    }
    bt(curr + 1, cnt);
    start[curr] = 1;
    bt(curr + 1, cnt + 1);
    start[curr] = 0;
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
        }
    }
    bt(0, 0);
    cout << ans;
    return 0;
}
