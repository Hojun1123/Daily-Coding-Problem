#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
using namespace std;
int N, M;
map<string, string> p1;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin >> M;
	
	string name;
	string key;

	for (int i = 0; i < N; ++i)
	{
		cin >> name;
		cin >> key;
		p1[name] = key;
	}

	string input;
	for (int i = 0; i < M; ++i)
	{
		cin >> key;
		cout << p1[key] << "\n";
	}
	return 0;
}
