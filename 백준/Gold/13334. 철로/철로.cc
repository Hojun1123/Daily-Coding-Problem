#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
using namespace std;
int N, D;
struct Node {
	int a, b;
	bool operator<(const Node& o) const {
		return a < o.a;
	}
};
vector<Node> v;
vector<Node> ret;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int a, b;
		cin >> a >> b;
		if (a < b) v.push_back({ a, b });
		else v.push_back({ b, a });
	}
	cin >> D;
	for (int i = 0; i < N; ++i) {
		if (v[i].b - v[i].a > D) continue;//
		//4-7, 3, 4+,5-
		//4-7, 5, 2+, 5-
		//a-b, a- (D-(b-a)) = b - D, a+1
		ret.push_back({ v[i].b - D, 1});
		ret.push_back({ v[i].a + 1, -1});
	}
	sort(ret.begin(), ret.end());
	ret.push_back({ 111111111, 0 });
	int cnt = 0;
	int start = 0;
	int idx = 0;
	int ans = 0;
	while(idx < ret.size() - 1){
		//cout << cnt << " ";
		start = ret[idx].a;
		cnt += ret[idx].b;
		if (start == ret[idx + 1].a) {
			idx++;
			continue;//뒤꺼랑 같으면 또함
		}
		ans = max(ans, cnt);
		idx++;
	}
	ans = max(ans, cnt);
	cout << ans;
	return 0;
}