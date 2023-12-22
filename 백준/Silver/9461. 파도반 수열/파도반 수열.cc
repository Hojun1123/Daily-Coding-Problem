#include <iostream>
using namespace std;

int T;
long long arr[101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;
    int n;
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 1;
    for (int j = 3; j < 100; ++j)
        arr[j] = arr[j - 2] + arr[j - 3];

    for (int i = 0; i < T; ++i)
    {
        cin >> n;
        cout << arr[n - 1] << "\n";
    }
    return 0;
}
