#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
using namespace std;
int x, y, w, h;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> x >> y >> w >> h;
	int a, b;
	a = w - x > x ? x : w - x;
	b = h - y > y ? y : h - y;

	cout << (a > b ? b : a);
	return 0;
}