#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <list>
#include <cmath>
using namespace std;
int N, K;
int check[200001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> K;
	queue<int> q;
	q.push(N);
	check[N] = 1;
	int qSize;
	int temp;
	int time = 0;
	int answer = 0;
	bool out = false;
	while (!q.empty())
	{
		qSize = q.size();
		for (int i = 0; i < qSize; ++i)
		{
			temp = q.front();
			q.pop();
			check[temp] = 1;
			if (temp == K)
			{
				answer++;
				out = true;
			}

			if (temp > 0 && check[temp - 1] == 0)
			{
				q.push(temp - 1);
			}
			if (temp < 199999 && check[temp + 1] == 0)
			{
				q.push(temp + 1);
			}
			if (temp <= 100000 && check[temp * 2] == 0)
			{
				q.push(temp * 2);
			}
		}
		if (out)
			break;
		time++;
	}
	cout << time << "\n" << answer;
	return 0;
}