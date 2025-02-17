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
string dp[255];
string add(string a, string b) {
	//a > b
	int ai = a.size() - 1;
	for (int i = b.size() - 1; i >= 0; --i) {
		a[ai--] += (b[i] - '0');
	}

	for (int i = a.size() - 1; i > 0; --i) {
		if (a[i] > '9') {
			int num = a[i] - '0';
			a[i - 1] += 1;
			a[i] = '0' + num - 10;
		}
	}

	if (a[0] > '9') {
		a[0] = (a[0] - '0' - 10) + '0';
		return '1' + a;
	}
	return a;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	dp[0] = "1";
	dp[1] = "1";
	dp[2] = "3";	
	dp[3] = "5";
	for (int i = 4; i <= 250; ++i) {
		string tmp = add(dp[i - 2], dp[i - 2]);
		dp[i] = add(tmp, dp[i - 1]);
	}


	while (cin >> N) {
		cout << dp[N] <<"\n";
	}
	return 0;
}