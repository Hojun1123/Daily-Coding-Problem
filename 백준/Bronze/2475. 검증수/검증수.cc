#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
	int a;
	long long result = 0;
	for (int i = 0; i < 5; ++i)
	{
		cin >> a;
		result += a * a;
	}
	cout << result % 10;
	return 0;
}