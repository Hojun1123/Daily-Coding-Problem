#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <cmath>
using namespace std;
long long A, B, C;
long long recursion(int n)
{
    if (n == 1) return A;
    else {
        long long r = recursion(n / 2) % C;
        if (n % 2 == 0) {
            return (r * r) % C;
        }
        else{
            return A * ((r * r) % C);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> A >> B >> C;
    //A를 B 승을 C로 나눔.
    cout << recursion(B) % C;
    return 0;
}
