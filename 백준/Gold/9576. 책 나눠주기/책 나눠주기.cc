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
int N, M, T;
struct Node {
    int a, b;
    bool operator<(Node o) const {
        if (b < o.b) return true;
        else if (b > o.b) return false;
        else return a < o.a;
    }
};
vector<Node> arr;
int check[1001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    for (int t = 0; t < T; ++t) {
        cin >> N >> M;
        arr.clear();
        for (int i = 0; i < M; ++i)
        {
            int a, b;
            cin >> a >> b;
            arr.push_back({ a, b });
        }
        sort(arr.begin(), arr.end());
        
        int cnt = 0;
        for (int i = 0; i < arr.size(); ++i)
        {
            int start = arr[i].a;
            int end = arr[i].b;
            for (int j = start; j <= end; ++j)
            {
                if (check[j] == 0)
                {
                    check[j] = 1;
                    cnt++;
                    break;
                }
            }
        }
        memset(check, 0, sizeof(check));
        cout << cnt << "\n";
    }
    return 0;
}