#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <stack>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
using namespace std;
int N, M;
int cost[501][501];
struct Node {
    int a, b, c;
};
vector<Node> arr;
struct Edge {
    int n, c;
    bool operator<(Edge o) const {
        return c > o.c;
    }
};
priority_queue<Edge> pq;
// 새로운 파티장과 기존 파티장이 연결될 수 있는 도로를 만듬
// 단방향
// A에서 B로 갈때 A - ? - B
int ans[501][501];
void dijkstra(int s, int e) {

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            ans[i][j] = 1987654321;
        }
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> ans[i][j];
        }
    }
    
    //a b c d
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            for (int k = 1; k <= N; ++k) {
                ans[j][k] = min(ans[j][k], ans[j][i] + ans[i][k]);
            }
        }
    }

    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << (ans[a][b] <= c ? "Enjoy other party\n" : "Stay here\n");
    }

    
    return 0;
}