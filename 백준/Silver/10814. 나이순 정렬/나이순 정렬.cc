#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <list>

using namespace std;
int arr[201];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<int, vector<string>> m;
	int n;
	int a;
	string b;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		cin >> b;
		arr[a] = 1;
		m[a].push_back(b);
	}

	for (int i = 1; i <= 200; ++i)
	{
		if (arr[i])
		{
			for (int j = 0; j < m[i].size(); ++j)
			{
				cout << i << " " << m[i][j] << "\n";
			}
		}
	}
	return 0;
}
