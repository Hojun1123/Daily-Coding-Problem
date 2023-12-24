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
	
	int arr[3];
	int temp;

	while (true)
	{
		cin >> arr[0] >> arr[1] >> arr[2];
		if (arr[0] == 0)
			break;

		sort(arr, arr + 3);

		if (arr[0] * arr[0] + arr[1] * arr[1] == arr[2] * arr[2])
			cout << "right\n";
		else
			cout << "wrong\n";
	}
	return 0;
}
