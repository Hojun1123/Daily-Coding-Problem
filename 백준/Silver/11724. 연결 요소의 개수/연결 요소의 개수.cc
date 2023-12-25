#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <list>


using namespace std;
int N, M;
int check[1001];
map<int, vector<int>> graph;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;	// 정점개수
	cin >> M;	// 간선개수

	int a, b;
	for(int i = 0; i < M; ++i)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);

	}

	int answer = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (check[i])
			continue;

		stack<int> s;
		s.push(i);
		check[i] = 1;
		while (!s.empty())
		{
			a = s.top();
			s.pop();

			for (int j = 0; j < graph[a].size(); ++j)
			{
				if (check[graph[a][j]] == 0)
				{
					s.push(graph[a][j]);
					check[graph[a][j]] = 1;
				}
			}
		}

		answer++;
	}

	cout << answer;
	return 0;
}
