#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
using namespace std;
int M;
int arr[21];

int main() {
	cin >> M;
	string s;
	int c;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < M; ++i)
	{
		cin >> s;
		if (s == "all")
		{
			for (int k = 1; k <= 20; ++k)
			{
				arr[k] = 1;
			}
		}
		else if (s == "empty")
		{
			for (int k = 1; k <= 20; ++k)
			{
				arr[k] = 0;
			}
		}
		else if(s == "check")
		{
			cin >> c;
			cout << arr[c] << "\n";
		}
		else if (s == "remove")
		{
			cin >> c;
			arr[c] = 0;
		}
		else if (s == "toggle")
		{
			cin >> c;
			arr[c] ^= 1;
		}
		else if (s == "add")
		{
			cin >> c;
			arr[c] = 1;
		}
	}
	return 0;
}
