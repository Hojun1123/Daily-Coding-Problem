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
int N; string input;
struct Node {
	char a;
	int n;
};
vector<Node> v;
int status[155];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	cin >> input;
	int cc = 1;
	char prev = input[0];
	for (int i = 1; i < input.size(); ++i) {
		if (prev == input[i]) {
			cc++;
		}
		else {
			v.push_back({ prev, cc });
			prev = input[i];
			cc = 1;
		}
	}
	v.push_back({ prev, cc });
	
	int ans = v[0].n;
	int left = 0;
	int right = 1;
	int curr = v[0].n;
	status[v[0].a] += v[0].n;
	int cnt = 1;
	while (right < v.size()) {
		if (cnt < N) {
			if (status[v[right].a] == 0) {
				cnt++;
			}
			status[v[right].a] += v[right].n;
			curr += v[right++].n;
		}
		else if(cnt == N){
			if (status[v[right].a] > 0) {
				status[v[right].a] += v[right].n;
				curr += v[right++].n;
			}
			else {
				if (status[v[left].a] == v[left].n) {
					cnt--;
				}
				status[v[left].a] -= v[left].n;
				curr -= v[left++].n;
			}
		}
		else {
			if (status[v[left].a] == v[left].n) {
				cnt--;
			}
			status[v[left].a] -= v[left].n;
			curr -= v[left++].n;
			if (status[v[right].a] == 0) {
				cnt++;
			}
			status[v[right].a] += v[right].n;
			curr += v[right++].n;
		}
		//cout << left<< " " << right << " " << curr << "\n";
		ans = max(ans, curr);
	}
	cout << ans;
	return 0; 
}