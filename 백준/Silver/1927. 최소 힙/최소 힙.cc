#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <list>
using namespace std;
int N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> q;
	int a;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		if (a == 0)
		{
			if (q.empty())
			{
				cout << a << "\n";
			}
			else
			{
				cout << q.top() << "\n";
				q.pop();
			}
		}
		else
		{
			q.push(a);
		}
	}
	return 0;
}
