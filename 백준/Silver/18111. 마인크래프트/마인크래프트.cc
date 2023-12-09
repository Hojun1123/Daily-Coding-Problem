#include <iostream>
using namespace std;
int N, M, B;
int arr[500][500];
int answer = 200000000;
int answerHeight;

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	cin >> N; //i
	cin >> M; //j
	cin >> B; //블록 개수
	// w1은 2초, w2는 1초
	// w1: i,j의 가장 위의 블록을 제거하여 인벤토리에 넣음
	// w2: i,j의 가장 위에 블록을 쌓음
	int maxHeight = 0;
	int minHeight = 256;
	for (int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (maxHeight < arr[i][j])
				maxHeight = arr[i][j];
			if (minHeight > arr[i][j])
				minHeight = arr[i][j];
		}
	}

	for(int h = maxHeight; h >= minHeight; --h)
	{
		int time = 0;
		int diffHeight = 0;
		int inventory = B;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				 diffHeight = h - arr[i][j];
				if (diffHeight > 0)
				{
					time += diffHeight;
					inventory -= diffHeight;
					
				}
				else if (diffHeight < 0)
				{
					time -= 2 * diffHeight;
					inventory -= diffHeight;
				}
			}
		}

		if (inventory < 0)
			continue;
		if (answer > time)
		{
			answer = time;
			answerHeight = h;
		}
	}

	cout << answer << " " << answerHeight;
}