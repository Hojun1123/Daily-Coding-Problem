#include <iostream>
#include <queue>
#include <stack>
#include <map>
using namespace std;
int N;
int result0[41];
int result1[41];
int a;
int main() {
	cin >> N;
    result0[0] = 1;
    result1[0] = 0;
    result0[1] = 0;
    result1[1] = 1;
    for (int i = 2; i <= 40; ++i)
    {
        result0[i] = result0[i - 1] + result0[i - 2];
        result1[i] = result1[i - 1] + result1[i - 2];
    }
    for (int i = 0; i < N; ++i)
    {
        cin >> a;
        cout << result0[a] << " " << result1[a] << "\n";
    }
	return 0;
}
