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
int N;
string a;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> a;
	//1, x e나w
	//벗어나는 경우x 무조건 e로 시작하고 w로 끝남
	int cnt = 0;
	for (int i = 0; i < N - 1; ++i) {
		if (a[i] == 'E' && a[i + 1] == 'W')cnt++;
	}
	cout << cnt;
	return 0;
}
