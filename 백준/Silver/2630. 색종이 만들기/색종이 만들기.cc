#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#define BLUE 1
#define WHITE 0
using namespace std;

int N;

int table[128][128];
int check[128][128];
int blueCount = 0;	//1
int whiteCount = 0;	//0

void recursion(int y, int x, int size)
{
	if (size == 1)
	{
		if (table[y][x] == 0)
			whiteCount += 1;
		else
			blueCount += 1;
	}
	else
	{
		int sum = 0;
		for (int i = y; i < y + size; ++i)
		{
			for (int j = x; j < x + size; ++j)
			{
				sum += table[i][j];
			}
		}

		if (sum == 0)
			whiteCount += 1;
		else if (sum == size * size)
			blueCount += 1;
		else
		{
			int _s = size / 2;
			recursion(y, x, _s);
			recursion(y + _s, x, _s);
			recursion(y, x + _s, _s);
			recursion(y + _s, x + _s, _s);
		}
	}	

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> table[i][j];
		}
	}

	recursion(0, 0, N);
	
	cout << whiteCount << "\n";
	cout << blueCount << "\n";
	return 0;
}
