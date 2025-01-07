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
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	string str;
	cin >> N >> str;
	int d = 0, k = 0, s = 0, h = 0;
	for (int i = 1; i <= N; ++i) {
		if (str[i - 1] == 'D') {
			d++;
		}
		else if (str[i - 1] == 'K') {
			k += d;
		}
		else if (str[i - 1] == 'S') {
			s += k;
		}
		else if (str[i - 1] == 'H') {
			h += s;
		}
	}
	cout << h;
	return 0;
}