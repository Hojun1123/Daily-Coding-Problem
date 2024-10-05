#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <map>
using namespace std; 
int N;
int T;
string str;
struct Node {
    int a;
    int e;
    bool operator<(Node o) const {
        if (e < o.e) return true;
        else if (e > o.e) return false;
        return a < o.a;
    }
};
void solve()
{
    cin >> N;
    cin >> str;
    // 끝나는 애가 가장 빠른것.
    int endTime[150];
    memset(endTime, 0, sizeof(endTime));
    for (int i = 0; i < N; ++i) {
        endTime[str[i]] = i * 5;
    }
    int bt = 0;
    for (int i = 0; i < N; ++i) {
        bt += endTime[str[i]] - i * 5;
    }

    vector<Node> v;
    for (int i = 0; i < N; ++i) {
        v.push_back({str[i], endTime[str[i]] });
    }
    sort(v.begin(), v.end());

    int endTime2[150];
    memset(endTime2, 0, sizeof(endTime2));
    for (int i = 0; i < N; ++i) {
        endTime2[v[i].a] = i * 5;
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        //cout << endTime2[v[i].a] - i * 5 << "\n";
        ans += endTime2[v[i].a] - i * 5;
    }
    cout << bt - ans << "\n";
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    for (int i = 0; i < T; ++i) solve();
    return 0;
}