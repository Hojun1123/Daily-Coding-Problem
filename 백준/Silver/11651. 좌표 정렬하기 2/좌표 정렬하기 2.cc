#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <list>
#include <cmath>
using namespace std;

int N;
typedef struct yx
{
	int y;
	int x;
} yx;

struct cmp {
	bool operator()(yx a, yx b)
	{
		if (a.y == b.y)
		{
			return a.x > b.x;
		}
		else
		{
			return a.y > b.y;
		}
	}
};

priority_queue<yx, vector<yx>, cmp> q;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	
	int x, y;
	for (int i = 0; i < N; ++i)
	{
		cin >> x >> y;
		q.push({ y, x });
	}

	while (!q.empty())
	{
		cout << q.top().x << " " << q.top().y << "\n";
		q.pop();
	}
	return 0;
}

