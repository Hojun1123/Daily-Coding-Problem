#include <iostream>
#include <stack>
#include <vector>
#include <map>
using namespace std;
int N, A, B;
vector<int> weights;
vector<pair<int, int>> graph[100001];
int visited[100001];
void process()
{
	int maxWeight = 0;
	int answer = 0;
	for (int i = 0; i < weights.size(); ++i)
	{
		if (weights[i] > maxWeight)
		{
			maxWeight = weights[i];
		}
		answer += weights[i];
	}
	cout << answer - maxWeight;
}
void bfs(int next)
{
	if (next == B)
	{
		process();
		return;
	}

	for (int i = 0; i < graph[next].size(); ++i)
	{
		int nextNode = graph[next][i].first;
		int nextNodeWeight = graph[next][i].second;
		if (visited[nextNode] == 0)
		{
			visited[nextNode] = 1;
			weights.push_back(nextNodeWeight);
			bfs(graph[next][i].first);
			weights.pop_back();
			visited[nextNode] = 0;
		}
	}
}
int main()
{
	cin >> N >> A >> B;
	int s, e, w;
	for (int i = 0; i < N - 1; ++i)
	{
		cin >> s >> e >> w;
		graph[s].push_back({ e, w });
		graph[e].push_back({ s, w });
	}
	visited[A] = 1;
	bfs(A);
	return 0;
}