#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
	string answer;
	int a;
	int prev;
	cin >> prev;
	answer = (prev == 1) ? "ascending" : "descending";
	for (int i = 0; i < 7; ++i)
	{
		cin >> a;
		if (prev - a != 1 && prev - a != -1)
		{
			answer = "mixed";
		}
		prev = a;
	}
	cout << answer;
	return 0;
}