#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
int N, M;
struct Node {
    int a, cost;
    bool operator<(Node o) const {
        return cost > o.cost;
    }
};
vector<Node> arr[5001];
int answer[5001];
int S, E;
void bt()
{
    for (int i = 1; i <= N; ++i)
    {
        answer[i] = 987654321;
    }
    priority_queue<Node> pq;
    pq.push({ S , 0 });
    answer[S] = 0;
    while (!pq.empty())
    {
        Node now = pq.top();
        pq.pop();
        for (int i = 0; i < arr[now.a].size(); ++i)
        {
            Node next = arr[now.a][i];
            int nextCost = next.cost + answer[now.a];
            if (nextCost >= answer[next.a]) continue;
            pq.push({ next.a, nextCost });
            answer[next.a] = nextCost;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a].push_back({ b, c });
        arr[b].push_back({ a, c });
    }
    cin >> S >> E;
    bt();
    cout << answer[E];
    return 0;
}