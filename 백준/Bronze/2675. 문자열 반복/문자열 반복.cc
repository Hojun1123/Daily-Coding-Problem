#include <iostream>
#include <map>
using namespace std;
string s;
int N;
int n;
int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		cin >> s;
		for (int k = 0; k < s.size(); ++k)
		{
			for (int j = 0; j < n; ++j)
			{
				cout << s[k];
			}
		}
        cout << "\n";

	} 
}