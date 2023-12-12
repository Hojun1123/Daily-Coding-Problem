#include <iostream>
#include <queue>
#include <stack>
#include <map>
#define G 2
#define R 1
#define B 0
using namespace std;
int N;
int arr[100][100];
int arr2[100][100];
int check[100][100];
int check2[100][100];
typedef struct yx
{
	int y;
	int x;
} yx;
int main() {
	cin >> N;
	string temp;
	for (int i = 0; i < N; ++i)
	{
		cin >> temp;
		for (int j = 0; j < N; ++j)
		{
			if (temp[j] == 'B')
			{
				arr2[i][j] = arr[i][j] = 1;
			}
			else if (temp[j] == 'G')
			{
				arr2[i][j] = arr[i][j] = 0;
			}
			else
			{
				arr2[i][j] = 0;
				arr[i][j] = 2;
			}
		}
	}


	int arrX[4] = { 1, -1, 0, 0 };
	int arrY[4] = { 0, 0, 1, -1 };
	int y, x, dy, dx;
	int color;
	int result1 = 0, result2 = 0;
	stack<yx> s;
	while (true)
	{
		while (!s.empty())
		{
			y = s.top().y;
			x = s.top().x;
			s.pop();
			check[y][x] = 1;
			for (int i = 0; i < 4; ++i)
			{
				dy = y + arrY[i];
				dx = x + arrX[i];
				if (dy >= 0 && dy < N && dx >= 0 && dx < N && check[dy][dx] == 0 && color == arr[dy][dx])
				{
					s.push({ dy, dx });
				}
			}

		}

		int set = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (check[i][j] == 0)
				{
					s.push({ i, j });
					set = 1;
					color = arr[i][j];
					result1 += 1;
					break;
				}
			}
			if (set == 1)
				break;
		}
	
		if (s.empty())
			break;
	}
	
	while (true)
	{
		while (!s.empty())
		{
			y = s.top().y;
			x = s.top().x;
			s.pop();
			check2[y][x] = 1;
			for (int i = 0; i < 4; ++i)
			{
				dy = y + arrY[i];
				dx = x + arrX[i];
				if (dy >= 0 && dy < N && dx >= 0 && dx < N && check2[dy][dx] == 0 && color == arr2[dy][dx])
				{
					s.push({ dy, dx });
				}
			}

		}

		int set = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (check2[i][j] == 0)
				{
					s.push({ i, j });
					set = 1;
					color = arr2[i][j];
					result2 += 1;
					break;
				}
			}
			if (set == 1)
				break;
		}

		if (s.empty())
			break;
	}

	cout << result1 << " " << result2;
	return 0;
}