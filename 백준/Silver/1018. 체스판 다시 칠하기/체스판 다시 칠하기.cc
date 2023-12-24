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
char arr[50][50];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	cin >> M;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> arr[i][j];
		}
	}

	int minValue = 64;
	char colors[2] = { 'W', 'B' };
	char color;
	for (int h = 0; h <= N - 8; h++)
	{
		for (int w = 0; w <= M - 8; w++)
		{
			int cnt = 0;
			for (int i = h; i < h + 8; ++i)
			{
				color = colors[i % 2];
				for (int j = w; j < w + 8; ++j)
				{
					if (j % 2 == 0 && color == arr[i][j])
					{
						cnt ++;
					}
					else if(j % 2 == 1 && color != arr[i][j])
					{
						cnt ++;
					}
				}
			}

			int temp = (32 > cnt) ? cnt : (64 - cnt);
			if (minValue > temp)
				minValue = temp;
		}
	}

	cout << minValue;
	return 0;
}
