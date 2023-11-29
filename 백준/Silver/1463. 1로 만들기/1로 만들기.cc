#include <iostream>
#include <map>
using namespace std;
int main() {
	int X;
	cin >> X;
	int table[1000000];
	for (int i = 1; i < X; ++i)
		table[i] = X;

	table[X] = 0;
	for (int i = X; i >= 1; --i)
	{
		if (i % 3 == 0)
			table[i / 3] = min(table[i] + 1, table[i / 3]);
		if (i % 2 == 0)
			table[i / 2] = min(table[i] + 1, table[i / 2]);
		table[i - 1] = min(table[i] + 1, table[i - 1]);
	}
	cout << table[1];
	return 0;
}