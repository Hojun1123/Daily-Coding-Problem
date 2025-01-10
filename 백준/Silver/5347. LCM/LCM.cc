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
long long a, b, i;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;cin >> t;
	while (t--) {
		cin >> a >> b;
		for (i = min(a, b); (i % max(a,b)) != 0; i += min(a, b)){}
		cout << i << "\n";
	}
	return 0;
}