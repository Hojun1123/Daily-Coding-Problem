#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	string buffer;
	cin >> buffer;
	int a;
	cin >> a;
	cout << buffer[a - 1];
	return 0;
}