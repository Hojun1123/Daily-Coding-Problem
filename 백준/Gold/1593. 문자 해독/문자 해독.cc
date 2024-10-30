#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#include <unordered_map>
#include <regex>
using namespace std;
int N, M;
string a, b;
int cnt[144];
int ret[144];
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    cin >> a >> b;
    for (int i = 0; i < N; ++i) {
        ret[a[i]]++;
        cnt[b[i]]++;
    }

    int answer = 0;
    for (int i = N; i < M; ++i) {
        int r = 0;
        for (char k = 'A'; k <= 'Z'; ++k) {
            //if (cnt[k] != 0) cout << k << ", " << cnt[k] << "\n";
            if (ret[k] == cnt[k]) continue;
            r = 1;
        }
        for (char k = 'a'; k <= 'z'; ++k) {
            //if (cnt[k] != 0) cout << k << ", " << cnt[k] << "\n";
            if (ret[k] == cnt[k]) continue;
            r = 1;
        }

        if (r == 0) answer++;

        cnt[b[i - N]]--;
        cnt[b[i]]++;
    }


    int r = 0;
    for (int k = 'A'; k <= 'Z'; ++k) {
        if (ret[k] == cnt[k]) continue;
        r = 1;
        break;
    }
    for (int k = 'a'; k <= 'z'; ++k) {
        if (ret[k] == cnt[k]) continue;
        r = 1;
        break;
    }
    if (r == 0) answer++;
    cout << answer;
    return 0;
}