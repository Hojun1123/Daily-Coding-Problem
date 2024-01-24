#include <iostream>
#include <map>
using namespace std;
int N;
char arr[80];
bool answer = 0;
bool check(int depth)
{
	int mid, left;
	int len = 1;
	bool f;
	while (true)
	{
		mid = depth - len + 1;
		left = mid - len;
		if (left < 0)
			break;
		f = true;
		for (int i = 0; i < len; ++i)
		{
			if (arr[mid + i] == arr[left + i])
			{
				f = false;
			}
			else
			{
				f = true;
				break;
			}
		}
		if (!f)
			return false;
		len++;
	}
	return true;
}

void recursion(int depth)
{
	if (answer)
		return;
	if (depth == N)
	{
		for (int i = 0; i < N; ++i)
			cout << arr[i];
		answer = 1;
		return;
	}	
	for (char i = '1'; i <= '3'; ++i)
	{
		if (arr[depth - 1] == i)
			continue;

		arr[depth] = i;

		if (check(depth))
		{
			recursion(depth + 1);
		}
	}
}
int main()
{
	cin >> N;
	for (char i = '1'; i <= '3'; ++i)
	{
		arr[0] = i;
		recursion(1);
	}
	return 0;
}