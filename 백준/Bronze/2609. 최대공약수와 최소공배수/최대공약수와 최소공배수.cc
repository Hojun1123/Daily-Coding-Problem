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
int M, N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	int temp;
	if (N < M)
	{
		temp = N;
		N = M;
		M = temp;
	}
	temp = N * M;
	int answer = 1;
	int i = M;
	while(i > 1)
	{
		if (N % i == 0 && M % i == 0)
		{
			answer *= i;
			N /= i;
			M /= i;
			i = M;
		}
		else
		{
			i--;
		}
	}

	cout << answer << "\n";
	cout << temp / answer;
	return 0;
}