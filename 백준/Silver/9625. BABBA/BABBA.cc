#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
int K;
int arr[46][2];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> K;
    //b > ba 
    // a > b
    arr[0][0] = 1;
    arr[0][1] = 0;
    for (int i = 1; i <= K; ++i)
    {
        arr[i][0] = arr[i - 1][1];
        arr[i][1] = arr[i - 1][0] + arr[i - 1][1];
    }
    cout << arr[K][0] << " " << arr[K][1];
}