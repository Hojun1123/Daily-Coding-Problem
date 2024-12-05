#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
// 민식이는 두개 명령을 지원함
//type c: 현재 글 맨 뒤에 c를 추가
//undo t: 이전 t초 동안 수행된 작업을 역순으로 되돌림
int N;
struct Node {
	int p;
	char str;
	int str2;
	int t;
};
vector<Node> arr;
stack<char> ans;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		string a;
		cin >> a;
		if (a == "type") {
			char b; int c;
			cin >> b >> c;
			arr.push_back({ 1, b, 0 , c });
		}
		else {
			int b, c;
			cin >> b >> c;
			arr.push_back({ 0, '0', b, c});
		}
	}
	int t = 2100000000;
	for (int i = N - 1; i >= 0; --i) {
		if (arr[i].t >= t) continue;
		if (arr[i].p) {
			ans.push(arr[i].str);
			continue;
		}
		int tt = max(1, arr[i].t - arr[i].str2);
		t = min(t, tt);
		//cout << t << " ";
	}
	while (!ans.empty()) {
		cout << ans.top();
		ans.pop();
	}
	return 0;
}