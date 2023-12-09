#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;
int H, W, N;
int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		cin >> H;	//층수
		cin >> W;	//방수
		cin >> N;	//순서
		int y = N % H;
		int x = N / H + 1;
		if (y == 0)
		{
			y = H;
			x -= 1;
		}
		y *= x < 10 ? 10 : 1;
		cout << y << x << "\n";
	}
	return 0;
}