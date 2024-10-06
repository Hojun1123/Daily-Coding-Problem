#include <iostream>
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
int N, M, K;
struct Node {
    int d, h, idx, n;
    bool operator<(Node o) const {
        if (d > o.d) return false;
        else if (d < o.d) return true;
        if (h > o.h) return false;
        else if (h < o.h) return true;
        if (idx > o.idx) return true;
        else if(idx < o.idx) return false;
    }
};
queue<Node> lines[100001];
priority_queue<Node> pq;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> K;
    int idx = 0;
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        lines[idx].push({ a, b, idx, i });
        idx++;
        if (idx == M) idx = 0;
    }

    for (int i = 0; i < M; ++i) {
        if (lines[i].empty()) continue;
        pq.push(lines[i].front());
        lines[i].pop();
    }

    int cnt = 0;
    while (!pq.empty()) {
        Node curr = pq.top();
        pq.pop();
        if (!(lines[curr.idx].empty())) {
            pq.push(lines[curr.idx].front());
            lines[curr.idx].pop();
        }
        if (curr.n == K) {
            cout << cnt;
            return 0;
        }
        cnt++;
    }
    return 0;
}