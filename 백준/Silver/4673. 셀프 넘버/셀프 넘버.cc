#include <iostream>
#include <queue>
int d(int _n);
using namespace std;
int N, K;
int table[10000];
int main() {
	int a = 0;
	for (int i = 1; i <= 10000; ++i)
	{
		while (true)
		{
			a = d(i);
			if (a > 10000 || table[a])
				break;
			table[a] = 1;
		}
	}

	for (int i = 1; i <= 10000; ++i)
	{
		if(!table[i])
			cout << i << "\n";
	}
	return 0;
}

int d(int _n)
{
	int result = _n;
	while (_n)
	{
		result += _n % 10;
		_n /= 10;
	}
	return result;
}