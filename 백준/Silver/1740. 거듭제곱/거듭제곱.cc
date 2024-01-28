#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <string>
#include <stack>
using namespace std;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    long long n;
    cin >> n;
    int arr[40];
    for (int i = 39; i >= 0; --i)
    {
        long long temp = (n >> i) & 1;
        arr[i] = temp;
    }

    long long answer = 0;
    long long mul = 1;
    for (int i = 0; i < 40; ++i)
    {
        answer += mul * arr[i];
        mul *= 3;   
    }
    cout << answer;
    return 0;
}