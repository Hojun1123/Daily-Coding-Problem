#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <vector>
using namespace std;
int N, K;
queue<int> q;
int check[2][500001];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N >> K;

    q.push(N);
    check[0][N] = 1;
    int t = 0;
    while (!q.empty())
    {
        int qSize = q.size();
        for (int i = 0; i < qSize; ++i)
        {
            int tmp = q.front();
            //cout << tmp << " " << K << "\n";
            q.pop();
            if (check[t % 2][K])
            {
                cout << t;
                return 0;
            }

            if (tmp - 1 >= 0 && check[(t + 1)%2][tmp - 1] == 0)
            {
                q.push(tmp - 1);
                check[(t + 1) % 2][tmp - 1] = 1;
            }
            if (tmp + 1 <= 500000 && check[(t + 1) %2][tmp + 1] == 0)
            {
                q.push(tmp + 1);
                check[(t + 1) % 2][tmp + 1] = 1;
            }
            if (tmp != 0 && tmp * 2 <= 500000 && check[(t + 1) %2][tmp * 2] == 0)
            {
                q.push(tmp * 2);
                check[(t + 1) % 2][tmp * 2] = 1;
            }
        }
        t++;
        K += t;
        if (K > 500000)
            break;
    }
    cout << -1;
    return 0;
}