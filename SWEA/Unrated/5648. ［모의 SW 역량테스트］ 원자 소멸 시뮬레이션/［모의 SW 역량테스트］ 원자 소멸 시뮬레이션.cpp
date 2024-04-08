#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <string>
#include <unordered_map>
#include <bitset>
#include <stack>
#include <unordered_set>
#include <cstring>
#include <sstream>
using namespace std;
int N;
int T;
//상하좌우 0 ~3
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
struct atom {
	int x, y;
	int d, k;
	bool isDied;
};
struct collision {
	int t;
	int a, b;	//ab의 번호.
	bool operator<(collision o) const {
		return t < o.t;
	}
};
vector<atom> arr;
vector<collision> result;
void solve(int tc)
{
	arr.clear();
	result.clear();
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int a, b, c, d;	//xydk
		cin >> a >> b >> c >> d;
		arr.push_back({ a, b, c, d, false });
	}

	for (int i = 0; i < N - 1; ++i)
	{
		for (int j = i + 1; j < N; ++j)
		{
			int ad = arr[i].d;
			int bd = arr[j].d;
			if (ad == 0 && bd == 1 && arr[i].x == arr[j].x && arr[i].y <= arr[j].y) {
				result.push_back({ arr[j].y - arr[i].y, i, j });
			}
			else if (ad == 1 && bd == 0 && arr[i].x == arr[j].x && arr[i].y >= arr[j].y) {
				result.push_back({ arr[i].y - arr[j].y, i, j });
			}
			else if (ad == 2 && bd == 3 && arr[i].y == arr[j].y && arr[i].x >= arr[j].x) {
				result.push_back({ arr[i].x - arr[j].x, i, j });
			}
			else if (ad == 3 && bd == 2 && arr[i].y == arr[j].y && arr[i].x <= arr[j].x) {
				result.push_back({ arr[j].x - arr[i].x, i, j });
			}
			else if ((ad < 2 && bd > 1) || (ad > 1 && bd < 2))
			{
				int t1 = abs(arr[i].x - arr[j].x);
				int t2 = abs(arr[i].y - arr[j].y);
				if (t1 == t2)
				{
					if ((arr[i].x + dx[ad] * t1 == arr[j].x + dx[bd] * t1) && (arr[i].y + dy[ad] * t2 == arr[j].y + dy[bd] * t2)) {
						result.push_back({ t1 + t2, i, j });
					}
				}
			}
		}
	}
	sort(result.begin(), result.end());
	int energy = 0;
	int prev = 0;
	unordered_map<int, bool> checkDied;
	if (result.size()) {
		prev = result[0].t;
		checkDied[result[0].a] =true;
		checkDied[result[0].b] =true;
	}
	for (int i = 1; i < result.size(); ++i)
	{
		if (prev != result[i].t)
		{
			for(auto &j : checkDied)
			{
				arr[j.first].isDied = true;
				energy += arr[j.first].k;
			}
			prev = result[i].t;
			checkDied.clear();
		}
		int a = result[i].a;
		int b = result[i].b;
		//a 또는 b 중 하나가 죽었을 때 > 동 시간에 일어났으면 +
		if (arr[a].isDied || arr[b].isDied) continue;
		checkDied[a]=true;
		checkDied[b]=true;
	}
	for (auto &i : checkDied){
		if(i.second) energy += arr[i.first].k;
	}
	cout << "#" << tc << " " << energy << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	for (int i = 1; i <= T; ++i)
		solve(i);
	return 0;
}