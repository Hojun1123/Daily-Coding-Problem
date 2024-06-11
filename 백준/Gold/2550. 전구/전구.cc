#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
int a[10011];
int b[10011];
int bb[10011];
int ab[10011];
int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> a[i];
    for (int i = 0; i < N; ++i) {
        cin >> b[i];
        bb[b[i]] = i;
    }
    for (int i = 0; i < N; ++i) {
        ab[i] = bb[a[i]];
    }

    int end = 0;
    vector<int> ans;
    vector<int> path;
    ans.push_back(ab[0]);
    path.push_back(0);
    for (int i = 1; i < N; ++i)
    {
        if (ans.back() < ab[i]) {
            ans.push_back(ab[i]);
            path.push_back(++end);
        }
        else {
            auto it = lower_bound(ans.begin(), ans.end(), ab[i]);
            *it = ab[i];
            path.push_back(it - ans.begin());
        }
    }

    vector<int> ret;
    int flag = end;
    for (int i = N - 1; i >= 0; i--) {
        if (path[i] == flag)
        {
            ret.push_back(b[ab[i]]);
            flag--;
        }
        if (flag == -1) break;
    }
    sort(ret.begin(), ret.end());
    cout << ret.size() << "\n";
    for (int i : ret) cout << i << " ";
    return 0;
}