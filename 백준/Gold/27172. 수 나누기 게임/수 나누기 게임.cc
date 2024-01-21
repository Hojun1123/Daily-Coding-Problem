#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <map>
using namespace std;
int N;
int score[1000001];
int card[1000001];
int people[100000];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> people[i];
		card[people[i]] = 1;
	}
	int cnt;
	int curr;
	for (int i = 0; i < N; ++i)
	{
		curr = people[i];
		for (int j = curr * 2; j <= 1000000; j += curr)
		{
			if (card[j])
			{
				score[curr] ++;
				score[j] --;
				//cout << "w : " << curr << " " << "l : " << j << "\n";
			}
		}
	}
	for (int i = 0; i < N; ++i)
	{
		cout << score[people[i]] << " ";
	}
	return 0;
}