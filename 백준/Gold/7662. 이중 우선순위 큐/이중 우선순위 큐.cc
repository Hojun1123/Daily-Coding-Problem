#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <list>


using namespace std;
int T;
int K;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	char op;
	int num;
	for (int _ = 0; _ < T; ++_)
	{
		priority_queue<int, vector<int>> maxQueue;
		priority_queue<int, vector<int>, greater<>> minQueue;
		map<int, int> m;
		int size = 0;
		cin >> K;
		for (int __ = 0; __ < K; ++__)
		{
			cin >> op >> num;
			if (size == 0)
			{
				maxQueue = priority_queue<int, vector<int>>();
				minQueue = priority_queue<int, vector<int>, greater<>>();
			}
			else
			{
				while (m[minQueue.top()] == 0)
				{
					minQueue.pop();
				}
				while (m[maxQueue.top()] == 0)
				{
					maxQueue.pop();
				}
			}
			if (op == 'I')
			{
				maxQueue.push(num);
				minQueue.push(num);
				m[num] += 1;
				size++;
			}
			else
			{
				if (size > 0)
				{
					size--;
					if (num == -1)
					{
						m[minQueue.top()] -= 1;
					}
					else
					{
						m[maxQueue.top()] -= 1;
					}
				}
			}
		}
		if (size == 0)
			cout << "EMPTY\n";
		else
		{
			while (m[minQueue.top()] == 0)
			{
				minQueue.pop();
			}
			while (m[maxQueue.top()] == 0)
			{
				maxQueue.pop();
			}
			cout << maxQueue.top() << " " << minQueue.top() << "\n";
		}
	}
	return 0;
}
