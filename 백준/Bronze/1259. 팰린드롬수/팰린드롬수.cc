#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <list>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string a;
	while (true)
	{
		cin >> a;
		if (a == "0")
			break;

		int left = 0;
		int right = a.size() - 1;
		int result = 0;
		while (left < right)
		{
			if (a[left] != a[right])
				result = 1;
			left++;
			right--;
		}

		cout << (result ? "no\n" : "yes\n");
	}


	return 0;
}
