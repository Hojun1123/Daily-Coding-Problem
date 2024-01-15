#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

int N, K;
int conv[200];

int robot[100];
// N인 컨베이어벨트가 있고, 
// 각 벨트의 칸은 2N 개의 칸으로 나누어져있음
// 1번칸이 올리는 위치, N 번 칸이 내리는 위치

// 1. 벨트가 로봇과 함께 한 칸 회전.
// 2. 가장 먼저 벨트에 올라간 로봇부터 벨트 방향으로 1 칸 이동
//  (해당 칸이 비어있고, 내구도가 1 이상 있어야함)
// 3. 로봇 올리기
// 4. 내구도가 0 인 ㅏㄴ의 개수가 K 개 이상이면 종료
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	// 0 ~ 2N -1 , 시작지점 0, 종료지점 N - 1
	int end = N - 1;
	int size = N * 2;
	for (int i = 0; i < size; ++i)
	{
		cin >> conv[i];
	}

	int currStep = 1;
	int b1, b2;
	int front;
	int step = 1;
	while (true)
	{
		front = conv[size - 1];
		for (int i = size - 1; i > 0; --i)
		{
			conv[i] = conv[i - 1];
		}
		for (int i = N - 1; i > 0; --i)
		{
			robot[i] = robot[i - 1];
		}
		robot[N - 1] = 0;
		robot[0] = 0;
		conv[0] = front;

		for (int i = N - 1; i > 0; --i)
		{
			if (conv[i] > 0 && robot[i] == 0)
			{
				if (robot[i - 1])
				{
					conv[i] -= 1;
				}
				robot[i] = robot[i - 1];
				robot[i - 1] = 0;
			}
		}

		if (conv[0] > 0)
		{
			robot[0] = 1;
			conv[0] -= 1;
		}

		int  cnt = 0;
		for (int i = 0; i < size; ++i)
		{
			if (conv[i] <= 0)
				cnt++;
		}

		if (cnt >= K)
		{
			break;
		}
		step++;
	}
	cout << step;
}