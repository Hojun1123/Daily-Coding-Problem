#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <string>
using namespace std;
int N, M;
int check[101];
int visitedCnt[101];
int visited[101];
struct Node {
    int n, cost;
};
vector<Node> graph[101];
vector<Node> rev[101];
int answer[101];
vector<int> path[101];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int fg = 0;
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == b) fg = 1;
        graph[a].push_back({ b, -c });
        rev[b].push_back({ a, -c });
    }

    for (int i = 1; i <= N; ++i) answer[i] = 1987654321;
   
    // 역방향으로 각 노드가 도착점에 도달 가능한지 검사
    queue<int> q;
    q.push(N);
    check[N] = 1;
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int i = 0; i < rev[now].size(); ++i)
        {
            Node nxt = rev[now][i];
            if (check[nxt.n]) continue;
            check[nxt.n] = 1;
            q.push(nxt.n);
        }
    }
    if (check[1] == 0) {
        //시작점이 도착점에 도달 불가한 경우
        cout << -1;
        return 0;
    }

    // SPFA
    q.push(1);
    answer[1] = 0;
    visited[1] = 1;
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        visitedCnt[now]++;
        visited[now] = 0;
        if (visitedCnt[now] >= N) {
            cout << -1;
            return 0;
        }
        for (int i = 0; i < graph[now].size(); ++i)
        {
            Node nxt = graph[now][i];
            int nxtCost = answer[now] + nxt.cost;
            if (check[nxt.n] == 0) continue;
            if (nxtCost > answer[nxt.n]) continue;
            else if (nxtCost == answer[nxt.n]) {
                path[nxt.n].push_back(now);
            }
            else {
                path[nxt.n].clear();
                path[nxt.n].push_back(now);
                answer[nxt.n] = nxtCost;
                if (visited[nxt.n] == 0)
                {
                    visited[nxt.n] = 1;
                    q.push(nxt.n);
                }
            }
        }
    }
    
    stack<int> ans;
    for (int i = N; i != 1; i = path[i][0]) {        
        ans.push(i);
    }
    cout << "1 ";

    while (!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }
    return 0;
}