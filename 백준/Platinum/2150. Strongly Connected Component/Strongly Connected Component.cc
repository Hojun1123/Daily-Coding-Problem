#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <string>
using namespace std;
vector<int> graph[10001];
vector<int> rev[10001];
int N, M;
stack<int> s;
int visited[10001];
int visited2[10001];
vector<vector<int>> ans;
struct zip {
    int k, v;
    bool operator<(zip o) const {
        return v < o.v;
    }
};
vector<zip> result;
void dfs(int nxt)
{
    for (int i = 0; i < graph[nxt].size(); ++i) {
        int curr = graph[nxt][i];
        if (visited[curr]) continue;
        visited[curr] = 1;
        dfs(curr);
    }
    s.push(nxt);
}
void dfs2(int nxt, int idx)
{
    for (int i = 0; i < rev[nxt].size(); ++i) {
        int curr = rev[nxt][i];
        if (visited2[curr]) continue;
        visited2[curr] = 1;
        dfs2(curr, idx);
    }
    ans[idx].push_back(nxt);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    int a, b;
    for (int i = 0; i < M; ++i)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        rev[b].push_back(a);
    }
    for (int i = 1; i <= N; ++i) {
        if (visited[i]) continue;
        visited[i] = 1;
        dfs(i);
    }

    //while (!s.empty()) { cout << s.top() << " "; s.pop(); }

    int idx = 0;
    while (!s.empty())
    {
        int curr = s.top();
        s.pop();
        if (visited2[curr]) continue;
        visited2[curr] = 1;
        ans.push_back(vector<int>());
        dfs2(curr, idx);
        idx++;
    }

    for (int i = 0; i < idx; ++i) {
        sort(ans[i].begin(), ans[i].end());
    }

    for (int i = 0; i < ans.size(); ++i) {
        result.push_back({ i, ans[i][0] });
    }
    sort(result.begin(), result.end());

    cout << result.size() << "\n";
    for (int i = 0; i < result.size(); ++i) {
        int index = result[i].k;
        for (int j = 0; j < ans[index].size(); ++j) {
            cout << ans[index][j] << " ";
        }
        cout << "-1\n";
    }
    return 0;
}