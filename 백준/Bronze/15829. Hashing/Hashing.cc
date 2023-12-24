#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <list>
using namespace std;
int N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int s = 1234567891;
	char a;
	cin >> N;
	long long sum = 0;
	long long p = 1;
	for (int i = 0; i < N; ++i)
	{
		cin >> a;
		p = a - 'a' + 1;
		for (int j = 0; j < i; ++j)
		{
			p *= 31;
			p %= s;
		}
		sum += p;
		sum %= s;
	}

	cout << sum;
	return 0;
}
