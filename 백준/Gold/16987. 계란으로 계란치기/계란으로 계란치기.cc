#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;
//7, 5
//3, 4
int s[9];
int w[9];
int N;
int ans = 0;
void bt(int index)
{
	//가장 왼쪽 것을 택함
	//안깨진 계란 중 하나를 침,
	//단 깨지거나 다른 안 깨진 계란이 없다면 넘어감.
	//이후 손에 든 계란을 두고 3번을 진행 2-3
	//3은 
	//왼... 오 한칸 오른쪽
	if (index == N) {
		int cnt = 0;
		for (int i = 0; i < N; ++i) {
			//cout << s[i] << " ";
			if (s[i] == 0) cnt++;
		}
		//cout << "\n";
		ans = max(ans, cnt);
		return;
	}
	else if (index > N)cout << "A";
	if (s[index] <= 0) {
		bt(index + 1);
		return;
	}
	int ef = 1;
	for (int i = 0; i < N; ++i) {
		if (i == index) continue;
		if (s[i] <= 0) continue;
		int bid = s[index];
		int bi = s[i];
		s[index] = max(0, s[index] - w[i]);
		s[i] = max(0, s[i] - w[index]);
		bt(index + 1);
		s[index] = bid;
		s[i] = bi;
		ef = 0;
	}
	if (ef) {
		bt(index + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> s[i] >> w[i];
	}
	bt(0);
	cout << ans;
	return 0;
}