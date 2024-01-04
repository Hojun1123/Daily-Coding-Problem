#include <iostream>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int N;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    int x, y, A, B;
    for (int _ = 0; _ < N; ++_)
    {
        cin >> A >> B >> x >> y;
        int index = x;
        if (x * y == 1)
        {
            cout << "1\n";
            continue;
        }

        while (true)
        {
            if (index % B == 0 && y == B)
            {
                cout << index << "\n";
                break;
            }
            else if (index % B == y)
            {
                cout << index << "\n";
                break;
            }
            if (index > A * B)
            {
                cout << "-1\n";
                break;
            }
            index += A;
        }
    }
}