#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <string>
using namespace std;
int arr[16][16];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string a, b;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        int cnt = 0;
        for (int j = 0; j < a.size(); ++j)
            cnt += (a[j] - '0') ^ (b[j] - '0');
        cout << "Hamming distance is " << cnt << ".\n";
    }
    
    return 0;
}