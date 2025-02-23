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
int N, M, T;
//R, C, 비용은 1234
//최소의 비용으로 전용 통신망
struct Node {
	int a, b;
	int cost;
	bool operator<(const Node& o) const {
		return cost < o.cost;
	}
};
vector<Node> v;
int uf[250000];
int Find(int n) {
	if (n == uf[n]) return n;
	int ret = Find(uf[n]);
	uf[n] = ret;
	return ret;
}
void solve()
{
	v.clear();
	for (int i = 0; i < 250000; ++i) {
		uf[i] = i;
	}
	cin >> N >> M;
	int cc;
	for (int i = 0; i < N; ++i) {
		for (int j = 1; j < M; ++j) {
			cin >> cc;
			v.push_back({ i * 500 + j - 1, i * 500 + j, cc }); 
		}
	}
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> cc;
			v.push_back({ (i - 1) * 500 + j, i * 500 + j, cc });
		}
	}

	sort(v.begin(), v.end());
	int fin = N * M - 1;
	int sc = 0;
	int ans = 0;
	for (int i = 0; i < v.size(); ++i) {
		int r1 = Find(v[i].a);
		int r2 = Find(v[i].b);
		if (r1 == r2) continue;
		if (r1 < r2) uf[r2] = r1;
		else uf[r1] = r2;
		sc++;
		ans += v[i].cost;
		if (sc == fin) break;
	}
	cout << ans << "\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	for (int i = 0; i < T; ++i) solve();
	return 0;
}