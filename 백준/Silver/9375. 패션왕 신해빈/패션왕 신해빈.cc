#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <list>
using namespace std;

int T, N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	
	for (int i = 0; i < T; ++i)
	{
		cin >> N;
		map<string, vector<string>> m;
		string s;
		string name;
		
		for (int j = 0; j < N; ++j)
		{
			cin >> name >> s;
			m[s].push_back(name);
		}

		int mul = 1;
		int size;
		for (auto iter = m.begin(); iter != m.end(); ++iter)
		{
			size = iter->second.size();
			mul *= (size + 1);
		}
		cout << mul - 1 << "\n";
	}


	return 0;
}

