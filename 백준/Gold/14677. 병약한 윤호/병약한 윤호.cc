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
using namespace std;
int N;
string str;
int arr[1500];
int check[1500][1500];
struct Node {
	int start, end;
	int score;
};
queue<Node> q;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> str;
	int N3 = 3 * N;
	for (int i = 0; i < N3; ++i) {
		if (str[i] == 'B') arr[i] = 0;
		else if (str[i] == 'L') arr[i] = 1;
		else arr[i] = 2;
	}
	//3n
	q.push({ 0, N3 - 1, 0 });
	check[0][N3 - 1] = 1;
	int a = 0;
	int cnt = 0;
	while (!q.empty())
	{
		int qs = q.size();
		for (int i = 0; i < qs; ++i) {
			Node now = q.front();
			q.pop();
			a = max(now.score, a);
			// 앞
			if (now.start < N3 && now.start <= now.end) {
				if (arr[now.start] == cnt && check[now.start + 1][now.end] == 0) {
					q.push({ now.start + 1, now.end, now.score + 1 });
					check[now.start + 1][now.end] = 1;
				}
			}
			if (now.end >= 0 && now.end >= now.start) {
				if (arr[now.end] == cnt && check[now.start][now.end - 1] == 0) {
					q.push({ now.start, now.end - 1, now.score + 1 });
					check[now.start][now.end - 1] = 1;
				}
			}

		}
		cnt = (cnt + 1) % 3;
	}
	cout << a;
 	return 0;
}
