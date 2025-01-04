#include <vector>
#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <unordered_map>
#include <map>
#include <cmath>
#include <deque>
using namespace std;
int N, K, M;
struct Node {
	int n;
	long long cost;
	bool operator<(const Node& o) const {
		return cost > o.cost;
	}
};
priority_queue<Node> pq;
long long ret[5][200001];
long long result[5][5][200001];
vector<Node> graph[200001];
int hashMap[5];
void dijkstra(int index) {
	int start = hashMap[index];
	for (int i = 1; i <= N; ++i) {
		//10^15
		ret[index][i] = 1000000000000000;
	}

	pq.push({ start, 0 });
	ret[index][start] = 0;
	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();
		if (now.cost > ret[index][now.n]) continue;
		for (int i = 0; i < graph[now.n].size(); ++i) {
			Node nxt = graph[now.n][i];
			long long nxtCost = nxt.cost + ret[index][now.n];
			if (nxtCost >= ret[index][nxt.n]) continue;
			ret[index][nxt.n] = nxtCost;
			pq.push({ nxt.n, nxtCost });
		}
	}
}
void dijkstra2(int a, int b) {
	for (int i = 1; i <= N; ++i) {
		//a, b, i
		result[a][b][i] = ret[a][i] + ret[b][i];
		pq.push({ i, result[a][b][i] });
	}
	//a, b로부터 어떤x의 최단거리
	while (!pq.empty())
	{
		Node now = pq.top();
		pq.pop();
		if (now.cost > result[a][b][now.n]) continue;
		for (int i = 0; i < graph[now.n].size(); ++i) {
			Node nxt = graph[now.n][i];
			long long nxtCost = nxt.cost + result[a][b][now.n];
			if (result[a][b][nxt.n] <= nxtCost) continue;
			result[a][b][nxt.n] = nxtCost;
			pq.push({ nxt.n, nxtCost });
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K >> M;

	for (int i = 0; i < K; ++i) {
		// 각 인덱스를 매치
		cin >> hashMap[i];
	}
	for (int i = 0; i < M; ++i) {
		int a, b;
		long long c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}

	// 다익
	for (int i = 0; i < K; ++i) {
		dijkstra(i);
	}

	// K 3이하는 중복이 일어나진 않음
	if (K < 4) {
		int minIndex = 0;
		long long minCost = 5000000000000000;
		for (int i = 1; i <= N; ++i) {
			long long currCost = 0;
			for (int j = 0; j < K; ++j) {
				currCost += ret[j][i];
			}
			if (minCost > currCost) {
				minCost = currCost;
				minIndex = i;
			}
		}
		cout << minCost;
	}
	else if (K == 4) {
		//4 이상부터 동선이 겹칠 수 있는데, 최단거리 -> 안 겹치는 경우
		//다 돌리면, 1억2천?
		for (int a = 0; a < K - 1; ++a) {
			for (int b = a + 1; b < K; ++b) {
				//10개 case. -> 다익 10개?
				dijkstra2(a, b);
			}
		}
		int gp[3][4] = {
			{0, 1, 2, 3}
			,{0, 2, 1, 3}
			,{0, 3, 1, 2}
		};

		int minIndex = 0;
		long long minCost = 5000000000000000;
		for (int i = 1; i <= N; ++i) {
			for (int g = 0; g < 3; ++g) {
				long long currCost = result[gp[g][0]][gp[g][1]][i] + result[gp[g][2]][gp[g][3]][i];
				if (minCost > currCost) {
					minCost = currCost;
					minIndex = i;
				}
			}
		}
		cout << minCost;
	}
	else if (K == 5) {
		//5개에 대해 조합
		//5 * 3개 = 15
		int gp[15][5] = {
			{0, 1, 2, 3, 4},{0, 2, 1, 3, 4},{0, 3, 1, 2, 4},
			{0, 1, 2, 4, 3},{0, 2, 1, 4, 3},{0, 4, 1, 2, 3},
			{0, 1, 3, 4, 2},{0, 4, 1, 3, 2},{0, 3, 1, 4, 2},
			{0, 4, 2, 3, 1},{0, 2, 3, 4, 1},{0, 3, 2, 4, 1},
			{1, 4, 2, 3, 0},{2, 4, 1, 3, 0},{3, 4, 1, 2, 0},
		};

		int minIndex = 0;
		long long minCost = 5000000000000000;
		for (int i = 1; i <= N; ++i) {
			for (int g = 0; g < 15; ++g) {
				long long currCost = result[gp[g][0]][gp[g][1]][i] + result[gp[g][2]][gp[g][3]][i] + ret[gp[g][4]][i];
				if (minCost > currCost) {
					minCost = currCost;
					minIndex = i;
				}
			}
		}
		cout << minCost;
	}
	return 0;
}