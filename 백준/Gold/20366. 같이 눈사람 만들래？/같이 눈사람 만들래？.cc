#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;
int N;
int arr[600];
struct Node {
    int a, b, s;
};
bool cmp(const Node& a, const Node& b) {
    return a.s < b.s;
}
vector<Node> v;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            v.push_back({ i, j, arr[j] + arr[i] });
        }
    }
    //for (auto i : v) cout << i.a << " " << i.b << "\n";
    sort(v.begin(), v.end(), cmp);
    int ans = 2000000000;
    for (int i = 0; i < v.size() - 1; ++i) {
        for (int j = i + 1; j < v.size(); ++j) {
            if (v[i].a == v[j].a) continue;
            if (v[i].a == v[j].b) continue;
            if (v[i].b == v[j].a) continue;
            if (v[i].b == v[j].b) continue;
            ans = min(ans, v[j].s - v[i].s);
            break;
        }
    }
    cout << ans;
    return 0;
}