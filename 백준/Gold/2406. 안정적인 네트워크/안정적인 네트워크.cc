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
int N, M;
struct Node {
	int a, b, c;
	bool operator<(const Node& o) const {
		return c < o.c;
	}
};
int arr[1001];
vector<Node> v;
int cost[1001][1001];
int Find(int n) {
	if (n == arr[n])return n;
	int ret = Find(arr[n]);
	arr[n] = ret;
	return ret;
}
struct rr {
	int a, b;
};
vector<rr> r;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	int a, b;
	int sc = 0;
	for (int i = 0; i < N; ++i) {
		arr[i] = i;
	}
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		if (a == 1 || b == 1) continue;
		int r1 = Find(a - 1);
		int r2 = Find(b - 1);
		if (r1 == r2) continue;
		sc++;
		if (r1 < r2) arr[r2] = r1;
		else arr[r1] = r2;
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> cost[i][j];
		}
	}
	for (int i = 1; i < N - 1; ++i) {
		for (int j = i + 1; j < N; ++j) {
			v.push_back({ i, j, cost[i][j] });
		}
	}
	sort(v.begin(), v.end());

	int answer = 0;
	for (int i = 0; i < v.size(); ++i) {
		if (sc >= N - 2) break;
		int r1 = Find(v[i].a);
		int r2 = Find(v[i].b);
		if (r1 == r2) continue;
		if (r1 < r2) arr[r2] = r1;
		else arr[r1] = r2;
		r.push_back({ v[i].a + 1, v[i].b + 1});
		sc++;
		answer += v[i].c;
	}
	cout << answer << " " << r.size() << "\n";
	for (int i = 0; i < r.size(); ++i) {
		cout << r[i].a << " " << r[i].b << "\n";
	}
	return 0;
}