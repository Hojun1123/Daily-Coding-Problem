#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <vector>
using namespace std;
int arr[12];
vector<int> curr;
int input;
void dfs(int index)
{
	if (curr.size() == 6)
	{
		for (int i = 0; i < 6; ++i)
		{
			cout << curr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = index + 1; i < input; ++i)
	{
		curr.push_back(arr[i]);
		dfs(i);
		curr.pop_back();
	}
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	while (true)
	{
		cin >> input;
		if (input == 0)
			break;

		for (int i = 0; i < input; ++i)
		{
			cin >> arr[i];
		}
		dfs(-1);
		cout << "\n";
	}
	return 0;
}
