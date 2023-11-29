#include <iostream>
#include <map>;
using namespace std;
int main() {
	int X;
	cin >> X;
	int table[1000000];
	for (int i = 1; i < X; ++i) { table[i] = X; }
	table[X] = 0;
	int* nt;
	int* dt;
	for (int i = X; i >= 1; --i)
	{
		nt = &table[i];
		dt = &table[i / 3];
		if (i % 3 == 0)
			*dt = min(*nt + 1, *dt);
		dt = &table[i / 2];
		if (i % 2 == 0)
			*dt = min(*nt + 1, *dt);
		dt = &table[i - 1];
		*dt = min(*nt + 1, *dt);
	}
	cout << table[1];
	return 0;
}