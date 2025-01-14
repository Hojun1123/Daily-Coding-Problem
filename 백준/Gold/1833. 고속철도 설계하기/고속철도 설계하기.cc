#include <vector>
#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <unordered_map>
#include <map>
#include <cmath>
#include <deque>
#include <unordered_set>
using namespace std;
int N;
int cost[200][200];
int arr[200];
int Find(int n) {
	if (n == arr[n]) return n;
	int ret = Find(arr[n]);
	arr[n] = ret;
	return ret;
}
struct Node {
	int a, b;
};
struct g {
	int a, b, c;
	bool operator<(const g& o) const {
		return c < o.c;
	}
};
vector<Node> v;
vector<g> graph;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> cost[i][j];
		}
		arr[i] = i;
	}
	int sc = 0;
	int ans = 0;
	for (int i = 0; i < N - 1; ++i) {
		for (int j = i + 1; j < N; ++j) {
			if (cost[i][j] < 0) {
				int r1 = Find(i);
				int r2 = Find(j);
				ans -= cost[i][j];
				if (r1 == r2) continue;
				if (r1 < r2) arr[r2] = r1;
				else arr[r1] = r2;
				sc++;
			}
			else graph.push_back({ i, j, cost[i][j] });
		}
	}
	sort(graph.begin(), graph.end());

	for (int i = 0; i < graph.size(); ++i) {
		if (N - 1 <= sc) {
			break;
		}
		int r1 = Find(graph[i].a);
		int r2 = Find(graph[i].b);
		if (r1 == r2) continue;
		sc++;
		if (r1 < r2) arr[r2] = r1;
		else arr[r1] = r2;
		v.push_back({ graph[i].a + 1, graph[i].b + 1});
		ans += graph[i].c;
	}


	cout << ans << " " << v.size() << "\n";
	for (int vv = 0; vv < v.size(); ++vv) {
		cout << v[vv].a<< " " << v[vv].b<< "\n";
	}
	return 0;
}