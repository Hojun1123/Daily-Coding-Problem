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
	int N, M, input, curr = 0, ans = 0;
	priority_queue<int, vector<int>, less<>> pq;
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> input;
		curr += input;
		pq.push(input);
		if (curr < M)continue;
		else {
			//cout << i << " "<< curr <<" " << pq.top() << "\n";
			ans++;
			curr -= 2 * pq.top();
			pq.pop();
		}
	}
	cout << ans;
	return 0;
}