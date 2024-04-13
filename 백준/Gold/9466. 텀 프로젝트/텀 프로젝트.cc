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
#include <sstream>
using namespace std;
int T, N;
int arr[111111];
int in[100001];
int visited[100001];
queue<int> q;
void solve()
{
    memset(in, 0, sizeof(in));
    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> arr[i];
    for (int i = 1; i <= N; ++i)
        in[arr[i]]++;
    for (int i = 1; i <= N; ++i)
    {
        if (in[i] == 0) {
            q.push(i);
            in[i] --;
        }
    }

    int ans = 0;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        ans++;
        in[arr[now]] -= 1;
        if (in[arr[now]] == 0)
            q.push(arr[now]);
    }
    //cout << "ans : ";
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    for (int i = 0; i < T; ++i) solve();
    return 0;
}