#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
using namespace std;
int N, M;
vector<int> graph[100001];
long long dp[8][100001];
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= N; ++i) {
        dp[1][i] = graph[i].size();
    }

    for (int i = 2; i <= 7; ++i) {
        for (int j = 1; j <= N; ++j) {
            for (int k = 0; k < graph[j].size(); ++k) {
                dp[i][j] = (dp[i][j] + dp[i - 1][graph[j][k]]) % 1000000007;
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= N; ++i)ans = (ans +dp[7][i]) % 1000000007;
    cout << ans;
    return 0;
}