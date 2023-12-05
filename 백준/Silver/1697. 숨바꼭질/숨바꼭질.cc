#include <iostream>
#include <queue>
using namespace std;
int N, K;
int answer = 1;
int main() {
	cin >> N;	// 수빈 n
	cin >> K;	// 동생 k
	if (N == K)
	{
		cout << 0;
		return 0;
	}
	int table[200002];
	for (int i = 0; i <= 100000; ++i)
		table[i] = -1;
	queue<int> next;
	int temp;
	next.push(N);
	table[N] = 0;
	while (!next.empty())
	{
		temp = next.front();
		next.pop();
		//cout << temp << " ";
		if (temp < 0 || temp > 100000)
			continue;
		if (temp == K)
		{
			cout << table[temp];
			break;
		}

		if (table[temp + 1] == -1)
		{
			next.push(temp + 1);
			table[temp + 1] = table[temp] + 1;
		}

		if (table[temp - 1] == -1)
		{
			next.push(temp - 1);
			table[temp - 1] = table[temp] + 1;
		}
			
		if (table[temp * 2] == -1)
		{
			next.push(temp * 2);
			table[temp * 2] = table[temp] + 1;
		}
	}
	return 0;
}