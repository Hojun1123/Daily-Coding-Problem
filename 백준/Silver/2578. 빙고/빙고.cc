#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int arr[5][5];
int check[5][5];
int nums[25];
int main()
{
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < 25; ++i)
	{
		cin >> nums[i];
	}

	int cnt;
	bool f;
	for (int p = 0; p < 25; ++p)
	{
		//빙고 체크
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (arr[i][j] == nums[p])
					check[i][j] = 1;
			}
		}

		//대각선
		cnt = 0;
		f = true;
		for (int i = 0; i < 5; ++i)
		{
			if (check[i][i] != 1)
			{
				f = false;
			}
		}
		if (f)
			cnt++;

		f = true;
		for (int i = 0; i < 5; ++i)
		{
			if (check[i][4 - i] != 1)
			{
				f = false;
			}
		}
		if (f)
			cnt++;

		//세로
		for (int i = 0; i < 5; ++i)
		{
			f = true;
			for (int j = 0; j < 5; ++j)
			{
				if (check[i][j] == 0)
					f = false;
			}
			if (f)
				cnt++;
		}
		//가로
		for (int i = 0; i < 5; ++i)
		{
			f = true;
			for (int j = 0; j < 5; ++j)
			{
				if (check[j][i] == 0)
					f = false;
			}
			if (f)
				cnt++;
		}

		if (cnt >= 3)
		{
			cout << p + 1;
			break;
		}
	}
	return 0;
}