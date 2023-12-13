#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
int N, M;
map<string, int> p;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin >> M;
	
	string name;

	for (int i = 0; i < N; ++i)
	{
		cin >> name;
		p[name] = 1;
	}

	for (int i = 0; i < M; ++i)
	{
		cin >> name;
		p[name] += 1;
	}

	vector<string> ans;
	for (map<string, int>::iterator iter = p.begin(); iter != p.end(); ++iter)
	{
		if ((*iter).second == 2)
			ans.push_back((*iter).first);
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << "\n";
	return 0;
}
