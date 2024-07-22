#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <string>
using namespace std;
int N, M;
unordered_map<int, bool> check;
queue<int> q;
int s, e;
vector<int> arr[9] = { {1, 3}, {0,2,4}, {1,5},
                    {0,6,4}, {1,3,5,7}, {2,4,8},
                    {3,7}, {4,6,8}, {5,7}
};
int dd[10] = { 1000000000, 100000000, 10000000, 1000000, 100000, 10000, 1000, 100, 10, 1 };
int hpos(int n)
{
    for (int i = 8; i >= 0; --i) {
        int curr = n % 10;
        if (curr == 9) return i;
        n /= 10;
    }
}
void func(int n)
{
    int pos = hpos(n);//0~8
    for (int i = 0; i < arr[pos].size(); ++i)
    {
        int num = n;
        int a = n % dd[pos] / dd[pos + 1];
        int nxt = arr[pos][i];
        int b = n % dd[nxt] / dd[nxt + 1];
        //cout << a << ", " << b << "\n";
        num = num - a * dd[1 + pos] - b * dd[1 +nxt] + a * dd[1 + nxt] + b * dd[1 + pos];
        if (check[num]) continue;
        check[num] = true;
        q.push(num);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    s = 123456789;
    e = 0;
    for (int i = 100000000; i > 0; i /= 10) {
        int a;
        cin >> a;
        e += (a == 0 ? 9 : a) * i;
    }

    int cnt = 0;
    q.push(s);
    check[s] = 1;
    while (!q.empty())
    {
        int qSize = q.size();
        for (int i = 0; i < qSize; ++i)
        {
            if (q.front() == e) {
                cout << cnt;
                return 0;
            }
            func(q.front());
            q.pop();
        }
        cnt++;
    }
    cout << -1;
    return 0;
}