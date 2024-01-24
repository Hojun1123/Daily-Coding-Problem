#include <iostream>
#include <vector>
using namespace std;
int  N;
int cnt = 0;
vector<pair<int, int>> v;
void hanoi(int n, int s, int e, int sub)
{
	if (n == 1)
	{
		cnt++;
		v.push_back({ s, e });
		return;
	}
	hanoi(n - 1, s, sub, e);
	cnt++;
	v.push_back({ s, e });
	hanoi(n - 1, sub, e, s);
}
int main()
{	
	cin >> N;
	hanoi(N, 1, 3, 2);
	cout << cnt << "\n";
	for (auto i = v.begin(); i != v.end(); ++i)
	{
		cout << i->first << " " << i->second << "\n";
	}
	return 0;
}

//
