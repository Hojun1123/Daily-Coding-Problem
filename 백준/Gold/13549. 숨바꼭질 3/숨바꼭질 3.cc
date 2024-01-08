#include <iostream>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
int N, M;
int arr[100001];
int check[100001];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    if (M <= N)
    {
        cout << N - M;
        return 0;
    }
    deque<int> q;
    q.push_back(N);
    check[N] = 1;
    int temp;
    if (N >= M)
    {
        cout << N - M;
        return 0;
    }
    while (!q.empty())
    {  
        temp = q.front();
        q.pop_front();

        if (temp == M)
        {
            cout << check[M] - 1;
            return 0;
        }

        if (temp <= 50000 && check[temp * 2] == 0)
        {
            q.push_front(temp * 2);
            check[temp * 2] = check[temp];
        }

        if (temp > 0 && check[temp - 1] == 0)
        {
            q.push_back(temp - 1);
            check[temp - 1] = check[temp] + 1;
        }

        if (temp < 100000 && check[temp + 1] == 0)
        {
            q.push_back(temp + 1);
            check[temp + 1] = check[temp] + 1;
        }
    }
}