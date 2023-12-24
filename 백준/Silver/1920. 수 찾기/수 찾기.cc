#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <list>
using namespace std;
int N, M;
vector<int> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int a;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());


	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		cin >> a;
		
		int left = 0;
		int right = v.size() - 1;
		int mid;
		while (true)
		{
			mid = (right + left) / 2;
			if (v[mid] > a)
			{
				right = mid - 1;
			}
			else if (v[mid] < a)
			{
				left = mid + 1;
			}
			else
			{
				cout << "1\n";
				break;
			}

			if (left > right)
			{
				cout << "0\n";
				break;
			}
		}
	}
	return 0;
}
