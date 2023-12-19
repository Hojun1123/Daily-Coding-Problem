#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <list>

using namespace std;
int N;
vector<pair<int, int>> q;
int cmp(pair<int, int>a, pair<int, int>b)
{
	if (a.second == b.second)return a.first < b.first;
	return a.second < b.second;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	int s, e;
	for(int i = 0; i < N; ++i)
	{ 
		cin >> s;
		cin >> e;
		q.push_back({ s, e });
	}
	sort(q.begin(), q.end(), cmp);

	//답 구하기
	int answer = 0;
	unsigned int t = 0;
	for (int i = 0; i < q.size(); ++i)
	{
		if (t > q[i].first)
		{
			continue;
		}
		else
		{
			t = q[i].second;
			answer += 1;
		}
	}


	cout << answer;

	return 0;
}
