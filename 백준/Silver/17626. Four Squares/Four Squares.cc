#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <list>
#include <cmath>
using namespace std;

int N;
int arr[50001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	
	double a;
	int aInt;
	int num;
	int result;
	for (int i = 1; i <= N; ++i)
	{
		a = sqrt(i);
		aInt = int(a);
		if (a - aInt == 0)
			arr[i] = 1;
		else
		{
			int minValue = 100;
			int j = 0;
			while(aInt - j >= 1)
			{
				num = i - (aInt - j) * (aInt - j);
				result = arr[num] + 1;
				if (minValue > result)
				{
					minValue = result;
				}
				j++;
			}
			arr[i] = minValue;
		}
	}

	cout << arr[N];
	return 0;
}

