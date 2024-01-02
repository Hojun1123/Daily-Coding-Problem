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
int arr[100];
int table[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}

	table[1] = 1;
	for (int i = 2; i <= 1000; ++i)
	{
		if (table[i])
			continue;
		for (int j = 2 * i; j <= 1000; j += i)
		{
			table[j] = 1;
		}
	}
	
	int answer = 0;
	for (int i = 0; i < N; ++i)
		answer += (table[arr[i]]) ? 0 : 1;

	cout << answer;
	return 0;
}