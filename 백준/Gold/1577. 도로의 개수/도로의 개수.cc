#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
using namespace std;
int N, M, K;
long long dp[102][102];
struct Node {
    int a, b, c, d;
    bool operator<(Node o) const {
        if (a < o.a) return true;
        else if (a > o.a) return false;
        if (b < o.b) return true;
        else if (b > o.b) return false;
        if (c < o.c) return true;
        else if (c > o.c) return false;
        if (d < o.d) return true;
        return false;
    }
};
set<Node> um;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> K;
    for (int i = 0; i < K; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        um.insert({a + 1, b + 1, c + 1, d + 1});
        um.insert({ c + 1, d + 1, a + 1, b + 1 });
    }
    dp[1][1] = 1;
    for (int i = 1; i <= N + 1; ++i) {
        for (int j = 1; j <= M + 1; ++j) {
            //i, j는 자신보다 작은 위아래 칸의 합
            if(um.find({i - 1, j, i, j}) == um.end()) dp[i][j] += dp[i - 1][j];
            if(um.find({i, j -1, i, j}) == um.end()) dp[i][j] += dp[i][j - 1];
        }
    }

    cout << dp[N + 1][M + 1];
    return 0;
}