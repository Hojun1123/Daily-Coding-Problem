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
int N, M, K;
struct Node {
	int a, b;
	int cost;
	bool operator<(const Node& o) const {
		return cost < o.cost;
	}
};
vector<Node> v;
int uf[1001];
int Find(int n) {
	if (uf[n] == n) return n;
	int ret = Find(uf[n]);
	uf[n] = ret;
	return ret;
}
int unused[10001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 1; i <= M; ++i) {
		int q, p;
		cin >> q >> p;
		v.push_back({ q, p, i });
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < K; ++i) {
		for (int k = 1; k <= N; ++k) uf[k] = k;

		int sc = 0;
		int score = 0;
		int fst = 10000;
		for (int k = 0; k < v.size(); ++k) {
			if (sc == N - 1) {
				break;
			}
			if (unused[k]) continue;
			int r1 = Find(v[k].a);
			int r2 = Find(v[k].b);
			if (r1 == r2) continue;
			if (r1 < r2) uf[r2] = r1;
			else uf[r1] = r2;
			fst = min(fst, k);
			sc++;
			score += v[k].cost;
		}
		unused[fst] = 1;
		if (sc == N - 1) {
			cout << score << " ";
		}
		else {
			cout << "0 ";
		}
	}
	return 0;
}