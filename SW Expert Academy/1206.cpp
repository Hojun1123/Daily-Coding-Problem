#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int answer = 0;
		int length;
		cin >> length;
		int arr[1000];
		for (int i = 0; i < length; ++i)
		{
			cin >> arr[i];
		}

		for (int i = 2; i < length - 2; ++i)
		{
			int curr = arr[i];
			int minValue = max(max(max(arr[i - 2], arr[i - 1]), arr[i + 1]), arr[i + 2]);
			int result = curr - minValue;
			answer += (result > 0) ? result : 0;
			
		}
		cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}