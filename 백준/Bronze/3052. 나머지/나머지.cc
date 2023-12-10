#include <iostream>
#include <queue>
#include <stack>
#include <map>
using namespace std;
int arr[1000];
int main() {
	int a;
	int cnt = 0;
	for (int i = 1; i <= 10; i++)
	{
		cin >> a;
		int temp = a % 42;
		if (arr[temp])
			continue;
		else
		{
			arr[temp] = 1;
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}