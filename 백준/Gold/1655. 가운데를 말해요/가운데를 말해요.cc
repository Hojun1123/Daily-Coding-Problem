#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <vector>
using namespace std;
int N;
priority_queue<int, vector<int>, greater<int>> minQ;
priority_queue<int, vector<int>, less<int>> maxQ;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	int index = 0;
	int a;
	while(true)
	{
		cin >> a;
		maxQ.push(a);
		if (!minQ.empty() && minQ.top() < maxQ.top())
		{
			a = minQ.top();
			minQ.pop();
			minQ.push(maxQ.top());
			maxQ.pop();
			maxQ.push(a);
		}
		index++;
		cout << maxQ.top() << "\n";
		if (index == N) break;
		cin >> a;
		minQ.push(a);
		if (minQ.top() < maxQ.top())
		{
			a = minQ.top();
			minQ.pop();
			minQ.push(maxQ.top());
			maxQ.pop();
			maxQ.push(a);
		}
		cout << maxQ.top() << "\n";
		index++;
		if (index == N) break;
	}
	return 0;
}