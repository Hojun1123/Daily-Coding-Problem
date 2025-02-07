#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <queue>
#include <cstring>
#include <unordered_map>
using namespace std;
int N, K;
unordered_map<int, int> um;
queue<int> q;
long long ans = 0;
int ac = 0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    int a;
    for (int i = 0; i < N; ++i) {
        cin >> a;
        q.push(a);
        um[a] = 1;
    }
    long long cnt = 1;
    while (!q.empty()) {
        int qs = q.size();
        for (int i = 0; i < qs; ++i) {
            int now = q.front();
            q.pop();
            int left = now - 1;
            int right = now + 1;
            if (um[left] == 0) {
                ans += cnt;
                ac++;
                q.push(left);
                um[left] = 1;
                if (ac == K) {
                    cout << ans;
                    return 0;
                }
            }
            if (um[right] == 0) {
                ans += cnt;
                ac++;
                q.push(right);
                um[right] = 1;
                if (ac == K) {
                    cout << ans;
                    return 0;
                }
            }
        }
        cnt++;
    }
    //k개의 집을 짓는데, 하나의 위치는 샘터/집/암것도없
    //불행도가 최소가 되도록.
    return 0;
}