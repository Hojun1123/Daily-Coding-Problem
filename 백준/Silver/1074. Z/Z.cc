#include <iostream>
#include <queue>
#include <stack>
#include <map>
using namespace std;
int N, r, c;
int recursion(int length)
{
	if (r == 0)
	{
		if (c == 0)
		{
			return 0;
		}
		else if (c == 1)
		{
			return 1;
		}
	}
	else if (r == 1)
	{
		if (c == 0)
		{
			return 2;
		}
		else if ( c == 1)
		{
			return 3;
		}
	}

	if (length <= r)
	{
		r -= length;
		if (length <= c)
		{
			c -= length;
			return recursion(length / 2) + length * length * 3;
		}
		else
		{
			return recursion(length / 2) + length * length * 2;
		}
	}
	else
	{
		if (length <= c)
		{
			c -= length;
			return recursion(length / 2) + length * length;
		}
		else
		{
			return recursion(length / 2);
		}
	}
}

int main() {
	cin >> N;
	cin >> r;
	cin >> c;
	int length = 1;
	for (int i = 0; i < N; ++i)
	{
		length *= 2;
	}

	cout << recursion(length / 2);

	return 0;
}
