#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	string buffer;
	cin >> buffer;
	map<char, int> answer;
	for (char i = 'a'; i <= 'z'; ++i)
	{
		answer[i] = -1;
	}
	for (int i = 0; i < buffer.length(); ++i)
	{
		if (answer[buffer[i]] < 0)
			answer[buffer[i]] = i;
	}
	for (char i = 'a'; i <= 'z'; ++i)
	{
		cout << answer[i] << " ";
	}
	return 0;
}