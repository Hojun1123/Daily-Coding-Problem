#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <list>
#include <cmath>
using namespace std;
int N, M;
int key[10];
bool check(int num)
{
	if (num == 0)
		return !key[0];
	while (num)
	{
		if (key[num % 10] == 1)
			return false;
		num /= 10;
	}
	return true;
}
int numLength(int num)
{
	if (num == 0)
		return 1;
	int count = 0;
	while (num)
	{
		num /= 10;
		++count;
	}
	return count;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	cin >> M;
	int answer = N > 99 ? N - 100 : 100 - N;
	int input;
	for (int i = 0; i < M; ++i)
	{
		cin >> input;
		key[input] = 1;
	}

	int right;
	int left;
	right = left = N;
	int count = 0;
	int length = numLength(N);
	int temp = 1000000;
	while (true)
	{
		if (left >= 0)
		{
			if (check(left))
			{
				temp = count + numLength(left);
				break;
			}
			left--;
		}
		if (right <= 1000000)
		{
			if (check(right))
			{
				temp = count + numLength(right);
				break;
			}
			right++;
		}
		count++;

		if (count > answer)
			break;
	}
	cout << (answer > temp ? temp : answer);
	return 0;
}