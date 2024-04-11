#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <cmath>
using namespace std;
int input[111111];
vector<int> arr;
int N;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    int a = 0;
    int b = 0;
    for (int i = 0; i < N; ++i) cin >> input[i];
    int s = 0;
    for (int i = 0; i < N; ++i) {
        s += input[i];
        if (input[i] % 2 == 1) {
            a += input[i] / 2;
            b++;
        }
        else if (input[i] % 2 == 0) {
            a += input[i] / 2;
        }
    }
    if (a >= b && s % 3 == 0) cout << "YES";
    else cout << "NO";
    return 0;
}

/*

3 2 2 2

4 4 4 
1 2 
1 2
1 2
1 2
2 4 6

12 21

8
1 0 0 1 1 1 7 4
*/
