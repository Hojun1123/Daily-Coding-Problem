#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;
int N, M, X;
//3색 그래프
//무방향, 검파빨
//그래프와 함께 분말X스푼, 스푼을 뿌리면 빨파 1
//1, N으로 가는 최단 경로의 길이가 길수록 그래프가 더 맛있음으
struct Input {
	int n;
	long long cost;
	int color;
};
struct Node {
	int n;
	long long cost;
	bool operator<(const Node& o) const {
		return cost > o.cost;
	}
};
priority_queue<Node> pq;
vector<Input> graph[200001];
long long answer[200001];
long long dijkstra(long long red, long long blue)
{
	for (int i = 1; i <= N; ++i) {
		answer[i] = 1000000000000000;
	}
	pq.push({1, 0});
	answer[1] = 0;
	while (!pq.empty())
	{
		Node now = pq.top();
		pq.pop();
		if (now.cost > answer[now.n])continue;
		for (int i = 0; i < graph[now.n].size(); ++i) {
			Input nxt = graph[now.n][i];
			long long nxtCost = nxt.cost + answer[now.n];
			if (nxt.color == 1) {
				nxtCost = nxtCost + red;
			}
			else if (nxt.color == 2) {
				nxtCost = nxtCost + blue;
			}
			if (nxtCost < answer[nxt.n]) {
				answer[nxt.n] = nxtCost;
				pq.push({ nxt.n, nxtCost });
			}
		}
	}
	/*
	int cnt = 0;
	for (int i = N; i != 1; i = path[i][0]) {
		cnt++;
	}*/
	//cout << red << " :" << answer[N] << "\n";
	return answer[N];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> X;
	long long ia, ib, ic, id;
	for (int i = 0; i < M; ++i) {
		//U V W P
		//a,b를 연결, w, 색 p 검 빨 파
		cin >> ia >> ib >> ic >> id;
		graph[ia].push_back({ (int)ib, ic, (int)id });
		graph[ib].push_back({(int)ia, ic, (int)id});
	}
	//1 ~ N;
	if (X < 3) {
		long long ans = -1;
		for (int i = 0; i <= X; ++i) {
			ans = max(ans, dijkstra(i, X - i));
		}
		cout << ans;
		return 0;
	}

	long long left = 0;
	long long right = X;
	//cout << dijkstra(0) << ", " << dijkstra(X) << ".\n";
	//for (int i = 0; i <= X; ++i) dijkstra(i);
	while (right - left >= 3) {
		long long lm = (left * 2 + right) / 3;
		long long rm = (right * 2 + left) / 3;
		if (dijkstra(lm, X - lm) < dijkstra(rm, X - rm)) {
			left = lm;
		}
		else {
			right = rm;
		}
	}
	long long ans = -1;
	for (int i = 0; i < 3; ++i) {
		long long curr = left + i;
		ans = max(ans, dijkstra(curr, X - curr));
	}
	cout << ans;
	return 0;
}