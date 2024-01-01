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
int A, B;
int check[10000];
string answer;
/*
DSLR 
레지스터에 0~10000 의 십진수 저장 가능 : n

D : 2n % 10000
S : n - 1, n이 0 이면 9999
L : 왼편으로 회전
R : 오른편으로 회전

*/
typedef struct data
{
	int num;
	string op;
} data;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	int n, qSize, nNum;
	string temp;
	for (int i = 0; i < T; ++i)
	{
		bool fFlag = false;
		cin >> A >> B;
		for (int i = 0; i < 10000; ++i)
			check[i] = 0;

		queue<struct data> q;
		q.push({ A, "" });
		check[A] = 1;
		while (!q.empty())
		{
			qSize = q.size();
			for (int j = 0; j < qSize; ++j)
			{
				n = q.front().num;
				temp = q.front().op;
				q.pop();
				if (n == B)
				{
					cout << temp << "\n";
					fFlag = true;
					break;
				}

				nNum = n * 2 % 10000;
				if (check[nNum] == 0)
				{
					q.push({ nNum, temp + 'D' });
					check[nNum] = 1;
				}

				nNum = (n > 0 ? n - 1 : 9999);
				if (check[nNum] == 0)
				{
					q.push({ nNum, temp + 'S' });
					check[nNum] = 1;
				}

				int cnt = 0;
				int arr[4] = { 0, 0 ,0 ,0 };
				while (n)
				{
					arr[cnt++] = n % 10;
					n /= 10;
				}
				int leftNum = arr[0] * 10 + arr[1] * 100 + arr[2] * 1000 + arr[3];
				int rightNum = arr[0] * 1000 + arr[1] + arr[2] * 10 + arr[3] * 100;
				if (check[leftNum] == 0)
				{
					q.push({ leftNum, temp + 'L' });
					check[leftNum] = 1;
				}
				if (check[rightNum] == 0)
				{
					q.push({ rightNum, temp + 'R' });
					check[rightNum] = 1;
				}
			}
			if (fFlag)
				break;
		}
	}
}