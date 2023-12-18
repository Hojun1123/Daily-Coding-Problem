#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;
int N;
map<int, vector<int>> graph;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	int a;
	for(int i = 0; i < N; ++i)
	{ 
		for (int j = 0; j < N; ++j)
		{
			cin >> a;
			if(a)
				graph[i].push_back(j);
		}
	}

	for (int startNode = 0; startNode < N; ++startNode)
	{
		int check[100];
		for (int i = 0; i < N; ++i)
		{
			check[i] = 0;
		}

		stack<int> s;
		s.push(startNode);
		int currDot;
		vector<int> currNodes;
		while (!s.empty())
		{
			currDot = s.top();
			s.pop();
			currNodes = graph[currDot];
			for (int k = 0; k < currNodes.size(); ++k)
			{
				if (!check[currNodes[k]])
				{
					check[currNodes[k]] = 1;
					s.push(currNodes[k]);
				}
			}
		}

		for (int i = 0; i < N; ++i)
		{
			cout << check[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}
