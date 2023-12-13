#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
using namespace std;
int N, M;
map<int, string> p1;
map<string, int> p2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin >> M;
	
	string name;
	for (int i = 1; i <= N; ++i)
	{
		cin >> name;
		p1[i] = name;
		p2[name] = i;
	}

	string input;
	for (int i = 0; i < M; ++i)
	{
		cin >> input;
		if (p2.find(input) != p2.end())
		{
			cout << p2[input] << "\n";
		}
		else if (p1.find(stoi(input)) != p1.end())
		{
			cout << p1[stoi(input)] << "\n";
		}

	}
	return 0;
}
