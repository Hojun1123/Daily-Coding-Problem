#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;
int N, K;
int visited[100001];
queue<int> q;
stack<int> s;
int ans = 0;
int path[100001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;  //수빈이 동생
    memset(path, -1, sizeof(path));
    q.push(N);
    visited[N] = 1;
    while (!q.empty()) {
        int qSize = q.size();
        for (int i = 0; i < qSize; ++i) {
            int now = q.front();
            q.pop();
            if (now == K) {
                cout << ans << "\n";
                s.push(K);
                while (path[K] != -1) {
                    s.push(K = path[K]);
                }
                while (!s.empty()) {
                    cout << s.top() << " "; s.pop();
                }
                return 0;
            }
            if (now * 2 <= 100000 && !visited[now * 2]) {
                q.push(now * 2);
                path[now * 2] = now;
                visited[now * 2] = 1;
            }
            if (now < 100000 && !visited[now + 1]) {
                q.push(now + 1);
                path[now + 1] = now;
                visited[now + 1] = 1;
            }
            if (now > 0 && !visited[now - 1]){
                q.push(now - 1);
                path[now - 1] = now;
                visited[now - 1] = 1;
            }
        }
        ans++;
    }
    return 0;
}