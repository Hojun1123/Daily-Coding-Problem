#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	string buffer;
	string b;
	vector<int> a;
	while (cin >> buffer)
	{
		a.push_back(stoi(buffer));
	}
	for (int i = 0; i < a.size(); ++i)
	{
		if (i % 2 == 1)
			cout << a[i] + a[i - 1] << "\n";
	}
}