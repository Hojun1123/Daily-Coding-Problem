#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;
int N;
int a, b;
int arr[10001];
int check[10001];
queue<int> q;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N; for (int i = 1; i <= N; ++i) cin >> arr[i]; cin >> a >> b;
	q.push(a);
	check[a] = 1;
	int cnt = 0;
	while (!q.empty()) {
		int qs = q.size();
		for (int i = 0; i < qs; ++i) {
			int curr = q.front(); q.pop();
			if (curr == b) {
				cout << cnt; return 0;
			}
			for (int k = curr - arr[curr]; k > 0; k -= arr[curr]) {
				if (check[k]) continue;
				q.push(k);
				check[k] = 1;
			}
			for (int k = curr + arr[curr]; k <= N; k += arr[curr]) {
				if (check[k]) continue;
				q.push(k);
				check[k] = 1;
			}
		}
		cnt++;
	}
	cout << -1;
	return 0;
}