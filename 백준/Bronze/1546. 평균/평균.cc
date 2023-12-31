#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	int N;
	cin >> N;
	int a;
	int maxValue = 0;
	vector<int> v;
	for (int i = 0; i < N; ++i)
	{
		cin >> a;
		if (a > maxValue)
			maxValue = a;
		v.push_back(a);
	}

	int nScore;
	float sum = 0;
	for (int i = 0; i < N; ++i)
	{
		sum += v[i] / (float)maxValue * 100;
	}
	cout << sum / (float) N;
}