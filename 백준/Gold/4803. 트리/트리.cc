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
int N, M, Q;
int uf[501];
int Find(int n) {
	if (n == uf[n]) return n;
	int ret = Find(uf[n]);
	uf[n] = ret;
	return ret;
}
int Union(int a, int b, unordered_set<int>& s) {
	int r1 = Find(a);
	int r2 = Find(b);
	if (r1 == r2) {
		return r1;
	}
	else if (r1 < r2) {
		uf[r2] = r1;
	}
	else {
		uf[r1] = r2;
	}
	if (s.find(r1) != s.end()) {
		s.insert(r2);
	}
	else if (s.find(r2) != s.end()) {
		s.insert(r1);
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	while (true) {
		cin >> N >> M;
		if (N == 0) break;
		
		//init
		int cnt = 0;
		for (int k = 1; k <= N; ++k) {
			uf[k] = k;
		}

		unordered_set<int> s, ss;
		for (int i = 0; i < M; ++i) {
			int a, b;
			cin >> a >> b;
			int r = Union(a, b, s);
			if (r) {
				s.insert(r);
			}
		}

		
		for (int i = 1; i <= N; ++i) {
			int curr = Find(i);
			if (s.find(curr) == s.end()) ss.insert(curr);
		}
		cnt = ss.size();

		if (cnt == 0) {
			cout << "Case " << t << ": No trees.\n";
		}
		else if (cnt == 1) {
			cout << "Case " << t << ": There is one tree.\n";
		}
		else {
			cout << "Case " << t << ": A forest of " << cnt << " trees.\n";
		}
		t++;
	}
	return 0;
}