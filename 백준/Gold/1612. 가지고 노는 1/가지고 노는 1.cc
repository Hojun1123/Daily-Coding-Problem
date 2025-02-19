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
int N;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	if (N == 1) cout << 1;
	else if (N % 2 == 0 || N % 5 == 0) {
		cout << -1;
	}
	else {
		long long mod = 1 % N;
		int cnt = 1;
		while (1) {
			if (mod == 0) {
				break;
			}
			mod = (10 * mod + 1) % N;
			cnt++;
		}
		cout << cnt;
	}
	return 0;
}