#include <iostream>
using namespace std;
int T;
int main() {
	cin >> T;
	int check = 0;
	string c;
	for (int i = 0; i < T; ++i)
	{
		check = 0;
		cin >> c;
		for (int j = 0; j < c.length(); ++j)
		{
			if (c[j] == '(')
				check += 1;
			else
				check -= 1;

			if (check < 0)
				break;
		}

		cout << ((check == 0) ? "YES" : "NO") << "\n";
	}
	return 0;
}