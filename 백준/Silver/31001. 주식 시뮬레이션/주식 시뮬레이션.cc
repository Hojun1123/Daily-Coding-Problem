#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <list>


using namespace std;
int N, Q;
long long M;
map<string, long long> company;
map<int, vector<string>> group;
map<string, long long> nowStock;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;	//회사의 개수
	cin >> M;	//현금
	cin >> Q;	//메뉴입력의 개수

	int gId;
	string name;
	int p;
	for (int i = 0; i < N; ++i)
	{
		cin >> gId;
		cin >> name;
		cin >> p;
		company[name] = p;
		group[gId].push_back(name);
		nowStock[name] = 0;
	}

	int in;
	long long n;
	long long nowCash = M;
	for (int i = 0; i < Q; ++i)
	{
		cin >> in;
		switch (in)
		{
		case 1:
			cin >> name;
			cin >> n;
			if (n * company[name] <= nowCash)
			{
				nowCash -= n * company[name];
				nowStock[name] += n;
			}
			break;
		case 2:
			cin >> name;
			cin >> n;
			if (nowStock[name] != 0)
			{
				if (nowStock[name] - n >= 0)
				{
					nowCash += company[name] * n;
					nowStock[name] -= n;
				}
				else
				{
					nowCash += company[name] * nowStock[name];
					nowStock[name] = 0;
				}
			}
			break;
		case 3:
			cin >> name;
			cin >> n;
			company[name] += n;
			if (company[name] < 0)
				company[name] = 0;
			break;
		case 4:
			cin >> gId;
			cin >> n;
			for (int k = 0; k < group[gId].size(); ++k)
			{
				company[group[gId][k]] += n;
				if (company[group[gId][k]] < 0)
					company[group[gId][k]] = 0;
			}

			break;
		case 5:
			cin >> gId;
			cin >> n;
			for (int k = 0; k < group[gId].size(); ++k)
			{
				long long gt = (long long)company[group[gId][k]];
				gt = gt * (100 + n) / 100;
				gt -= gt % 10;
				company[group[gId][k]] = gt;
			}
			break;
		case 6:
			cout << nowCash << "\n";
			break;
		case 7:
			n = nowCash;
			for (auto k = nowStock.begin(); k != nowStock.end(); ++k)
			{
				n += company[k->first] * k->second;
			}
			cout << n << "\n";
			break;
		default:
			break;
		}
	}

	return 0;
}
