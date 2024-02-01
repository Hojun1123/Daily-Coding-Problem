#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <vector>
using namespace std;
int n;
vector<int> v;
string curr = "";
map<int, int> check;
int answer = 987654321;
int base;
void dfs(int index)
{
	if (index == v.size())
	{
		int tmp = stoi(curr);
		if (base < tmp && tmp - base < answer)
		{
			answer = tmp - base;
		}
		return;
	}

	for (int i : v)
	{
		if (check[i] == 0)
			continue;
		curr += i + '0';
		check[i]--;
		dfs(index + 1);
		check[i]++;
		curr.pop_back();
	}
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> n;
	base = n;
	while (n)
	{
		v.push_back(n % 10);
		check[n % 10]++;
		n /= 10;
	}
	dfs(0);
	cout << (base + answer > 987654321 ? 0 : base + answer);
	return 0;
}
