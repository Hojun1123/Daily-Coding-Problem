#include <iostream>
#include <string>
#include <regex>
int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int test_case;
	std::cin >> test_case;
	for (int t = 0; t < test_case; t++)
	{
		std::string temp;
		std::cin >> temp;

		std::regex pattern("(100+1+|01)+");
		std::cout << (std::regex_match(temp, pattern) ? "YES" : "NO") << "\n";
	} 
}