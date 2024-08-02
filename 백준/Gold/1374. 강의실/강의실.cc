#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <set>
using namespace std;
int N;
struct Node {
    int n, p;
    bool operator<(Node o) const {
        return n < o.n;
    }
};
vector<Node> v;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({ b, 1 });
        v.push_back({ c, -1 });
    }

    sort(v.begin(), v.end());

    int cnt = 0;
    int result = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        Node curr = v[i];
        cnt += curr.p;
        if (i + 1 < v.size() && curr.n == v[i + 1].n) continue;
        result = max(result, cnt);
    }
    cout << result;
    return 0;
}