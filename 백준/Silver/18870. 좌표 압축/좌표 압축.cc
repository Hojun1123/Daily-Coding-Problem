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
int arr[1000001];
priority_queue<int, vector<int>, greater<int>> b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;	// 정점개수
	int a;
	for (int i = 0; i < N; ++i)
	{
		cin >> a;
		arr[i] = a;
		b.push(a);
	}
	
	int index = 0;
	int prev = b.top();
	int curr;
	map<int, int> result;
	while (!b.empty())
	{
		curr = b.top();
		b.pop();
		if (prev != curr)
			index += 1;
		result[curr] = index;
		prev = curr;
	}

	for (int i = 0; i < N; ++i)
	{
		cout << result[arr[i]] << " ";
	}

	return 0;
}
