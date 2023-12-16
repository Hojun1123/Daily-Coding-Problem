#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int N, M;

int table[502][502];
int maxValue = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	cin >> M;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			cin >> table[i][j];
		}
	}
	
	int subSum = 0;

	for (int i = 1; i <= N; i++)
	{
		subSum = table[i][0] + table[i][1] + table[i][2] + table[i][3];
		for (int j = 4; j <= M; j++)
		{
			subSum += table[i][j];
			subSum -= table[i][j - 4];
			if (subSum > maxValue)
				maxValue = subSum;
		}
	}

	for (int i = 1; i <= M; i++)
	{
		subSum = table[0][i] + table[1][i] + table[2][i] + table[3][i];
		if (subSum > maxValue)
			maxValue = subSum;
		for (int j = 4; j <= N; j++)
		{
			subSum += table[j][i];
			subSum -= table[j - 4][i];
			if (subSum > maxValue)
				maxValue = subSum;
		}
	}

	for (int i = 1; i <= N - 1; i++)
	{
		subSum = table[i][1] + table[i][2] + table[i + 1][1] + table[i + 1][2];

		for (int j = 1; j <= M - 2; j++)
		{
			subSum += table[i][j + 2] + table[i + 1][j + 2];
			subSum -= table[i][j] + table[i + 1][j];
			if (subSum > maxValue)
				maxValue = subSum;
		}
	}

	int ay[8][4] = {
		{-1, -1, -1, 0}, {-1, 0, 1, 1}, {1, 1, 1, 0}, {-1, -1, 0, 1},
		{-1, -1, -1, 0}, {-1, -1, 0, 1}, {0, 1, 1, 1}, {-1, 0, 1, 1}
	};
	int ax[8][4] = {
		{ -1, 0, 1, 1}, { 1, 1, 1, 0}, { -1, 0, 1, -1}, {-1, 0, -1, -1},
		{-1, 0, 1, -1}, {0, 1, 1, 1}, {1, 1, 0 , -1}, {-1, -1, -1, 0}
	};
	int dy[8][3] = {
		{-1, -1, -1}, {1, 1, 1}, {-1, 0, 1}, {-1, 0, 1},
		{-1, -1, 0}, {0, -1,-1}, {-1, 0, 1}, {1, 0, -1}
	};
	int dx[8][3] = {
		{-1, 0, 1}, {-1, 0, 1}, {-1, -1, -1}, {1, 1, 1},
		{-1, 0, 1}, {-1, 0, 1}, {-1, -1, 0}, {-1, -1, 0}
	};

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			for (int k = 0; k < 8; ++k)
			{
				subSum = 0;
				for (int l = 0; l < 4; ++l)
				{
					subSum += table[i + ay[k][l]][j + ax[k][l]];
				}

				if (maxValue < subSum)
					maxValue = subSum;
			}

			for (int k = 0; k < 8; ++k)
			{
				subSum = table[i][j];
				for (int l = 0; l < 3; ++l)
				{
					subSum += table[i + dy[k][l]][j + dx[k][l]];
				}

				if (maxValue < subSum)
					maxValue = subSum;
			}
		}
	}

	cout << maxValue;
	return 0;
}
