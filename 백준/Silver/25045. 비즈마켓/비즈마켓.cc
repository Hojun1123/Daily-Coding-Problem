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
int N, M;
long long A[200000];
long long B[200000];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)cin >> A[i];
	for (int i = 0; i < M; ++i)cin >> B[i];
	long long ans = 0;
	sort(A, A + N, greater<>());
	sort(B, B + M);
	for (int i = 0; i < min(N, M); ++i) {
		if(A[i] - B[i] > 0) ans += (A[i] - B[i]);
	}
	cout << ans;
	return 0; 
}