#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <queue>
#include <string>
using namespace std;
bool visitedStation[100001];
vector<int> connectStation[1001]; //해당인덱스(튜브)가 어떤 역에 연결됬는지
vector<int> connectTube[100001];	// 해당인덱스(역)이 어떤 튜브에 연결됬는지

int main()
{
	//N 개의 역이 있음, 서로 다른 K 개의 역을 연결하고 있음
	//빨강은 하이퍼튜브고 파랑이 역
	//하이퍼가 연결됬다는 뜻은 해당 3 개가 연결되있다는 의미
	int N, K, M;
	cin >> N >> K >> M;
	for (int i = 1; i <= M; ++i)
	{
		for (int j = 0; j < K; ++j)
		{
			int a;
			cin >> a;
			connectStation[i].push_back(a);
			connectTube[a].push_back(i);
		}
	}

	queue<int> q;
	q.push(1);
	visitedStation[1] = 1;
	int depth = 1;
	while (!q.empty())
	{
		int qSize = q.size();
		for (int i = 0; i < qSize; ++i)
		{
			int tmp = q.front();
			q.pop();
			//cout << tmp << " ";
			if (tmp == N)
			{
				cout << depth;
				return 0;
			}

			for (int k : connectTube[tmp])
			{
				for (int l : connectStation[k])
				{
					if (visitedStation[l] == 0)
					{
						visitedStation[l] = 1;
						q.push(l);
					}
				}
			}
		}
		depth++;
	}
	cout << -1;
	return 0;
}