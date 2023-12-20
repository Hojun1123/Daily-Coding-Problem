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
stack<int> s;
int arr[1000001];
int answer[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> arr[i];
	}

	int num;
	answer[N] = -1;
	s.push(arr[N]);
	for (int i = N - 1; i >= 1; --i)
	{
		answer[i] = -1;
		while (!s.empty())
		{
			num = s.top();
			if (num > arr[i])
			{
				answer[i] = num;
				break;
			}
			else
			{
				s.pop();
			}
		}
		s.push(arr[i]);
	}

	for (int i = 1; i <= N; ++i)
	{
		cout << answer[i] << " ";
	}

	return 0;
}
