#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <unordered_map>
using namespace std;
// 사람수, K개, 음식 개수
int N;
struct Node {
    int n, flag;
    bool operator<(Node o) const {
        return n < o.n;
    }
};
vector<Node> node;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int ss, ee;
        cin >> ss >> ee;
        node.push_back({ ss, 1 });
        node.push_back({ ee, -1 });
    }
    sort(node.begin(), node.end());
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < node.size(); ++i)
    {
        cnt += node[i].flag;
        if (i + 1 < node.size() && node[i + 1].n == node[i].n) continue;
        //cout << node[i].n << ": " << cnt << "\n";
        ans = max(ans, cnt);
    }
    cout << ans;
    return 0;
}