#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <cstring>
#include <cmath>
using namespace std;
int F, S, G, U, D;
int check[1000001];
queue<int> q;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> F >> S >> G >> U >> D;
	q.push(S);
	check[S] = 1;
	int cnt = 0;
	while (!q.empty()) {
		int qs = q.size();
		for (int i = 0; i < qs; ++i) {
			int k = q.front();
			q.pop();
			if (k == G) {
				cout << cnt;
				return 0;
			}
			int uu = k + U;
			if (uu <= F && check[uu] == 0) {
				check[uu] = 1;
				q.push(uu);
			}
			int dd = k - D;
			if (dd >= 1 && check[dd] == 0) {
				check[dd] = 1;
				q.push(dd);
			}
		}
		cnt++;
	}
	cout << "use the stairs";
	return 0;
}