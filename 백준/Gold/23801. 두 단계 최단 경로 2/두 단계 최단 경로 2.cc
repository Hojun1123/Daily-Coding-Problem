#include <iostream>

#include <vector>

#include <map>

#include <algorithm>

#include <queue>

#include <cmath>

#include <stack>

#include <cstring>

#include <set>

#include <unordered_map>

using namespace std;

int N, M, P;

int S, E;

struct Node {

    int n;

    long long cost;

    bool operator<(Node o) const {

        return cost > o.cost;

    }

};

int mid[100000];

vector<Node> graph[100001];

long long answer[100001];

long long ans[100001];

priority_queue<Node> pq;

void solve()

{

    cin >> N >> M;

    for (int i = 0; i < M; ++i) {

        int a, b, c;

        cin >> a >> b >> c;

        graph[a].push_back({ b, c });

        graph[b].push_back({ a, c });

    }

    cin >> S >> E;

    cin >> P;

    for (int i = 0; i < P; ++i)
    {
        cin >> mid[i];
    }



    for (int i = 1; i <= N; ++i) answer[i] = 1e18;



    pq.push({ S, 0 });

    answer[S] = 0;

    while (!pq.empty()) {

        Node now = pq.top();

        pq.pop();

        if (answer[now.n] < now.cost) continue;

        for (int i = 0; i < graph[now.n].size(); ++i) {

            Node next = graph[now.n][i];

            long long nc = answer[now.n] + next.cost;

            if (nc >= answer[next.n]) continue;

            answer[next.n] = nc;

            pq.push({ next.n, nc });

        }

    }



    for (int i = 1; i <= N; ++i) ans[i] = 1e18;



    pq.push({ E, 0 });

    ans[E] = 0;

    while (!pq.empty()) {

        Node now = pq.top();

        pq.pop();

        if (ans[now.n] < now.cost) continue;

        for (int i = 0; i < graph[now.n].size(); ++i) {

            Node next = graph[now.n][i];

            long long nc = ans[now.n] + next.cost;

            if (nc >= ans[next.n]) continue;

            ans[next.n] = nc;

            pq.push({ next.n, nc });

        }

    }

    long long mv = 1e18;

    for (int i = 0; i < P; ++i)

    {

        //cout << ans[mid[i]] << " " << answer[mid[i]] << "\n";

        if (ans[mid[i]] < 1e18 && answer[mid[i]] < 1e18)
            mv = min(mv, ans[mid[i]] + answer[mid[i]]);

    }
    cout << (mv >= 1e18 ? -1 : mv);

}

int main()

{

    ios::sync_with_stdio(false);

    cout.tie(0);

    cin.tie(0);

    solve();

    return 0;

}