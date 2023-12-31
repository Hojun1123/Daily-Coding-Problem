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
int T;
int N;
int bits[4] = { 8, 4, 2, 1 };
void solve(int _a, int _b);
typedef struct ab{
	int a;
	int b;
} ab;
int matrix[16][16];
map<char, int> toBit = {
	{'E', 0}, {'S' , 0}, {'T', 0}, {'J', 0},
	{'I', 1}, {'N', 1}, {'F', 1}, {'P', 1}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	string a;
	int bit = 0;
	for (int i = 0; i < 16; ++i)
	{
		for (int j = 0; j < 16; ++j)
		{
			solve(i, j);
		}
	}

	for (int i = 0; i < T; ++i)
	{
		cin >> N;
		if (N > 32)
		{
			for (int j = 0; j < N; ++j)
				cin >> a;
			cout << "0\n";
		}
		else
		{
			vector<int> arr;
			for (int j = 0; j < N; ++j)
			{
				cin >> a;
				bit = 0;
				for (int k = 0; k < 4; ++k)
				{
					bit += toBit[a[k]] * bits[k];
				}
				arr.push_back(bit);
			}

			int minValue = 13;
			int value;
			int qv, wv, ev;
			for (int q = 0; q < N; ++q)
			{
				qv = arr[q];
				for (int w = q + 1; w < N; ++w)
				{
					wv = arr[w];
					for (int e = w + 1; e < N; ++e)
					{
						ev = arr[e];
						value = matrix[qv][wv] + matrix[wv][ev] + matrix[qv][ev];
						if (minValue > value)
							minValue = value;
					}
				}
			}
			cout << minValue << "\n";
		}
	}
}

void solve(int _a, int _b)
{
	int a = _a, b = _b;
	int check;
	int result = 0;
	for (int i = 0; i < 4; ++i)
	{
		check = 0;
		if (a >= bits[i])
		{
			a -= bits[i];
			check ^= 1;
		}

		if (b >= bits[i])
		{
			b -= bits[i];
			check ^= 1;
		}

		if (check)
			result++;
	}
	matrix[_a][_b] = result;
}