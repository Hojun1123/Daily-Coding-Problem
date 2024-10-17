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
using namespace std;
int N, M;
vector<int> v;
vector<int> vv;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    for (int i = 0; i < N - 1; ++i) {
        vv.push_back(v[i + 1] - 1 - v[i]);
    }
    sort(vv.begin(), vv.end());
    int answer = N;
    for (int i = 0; i < N - M; ++i) {
        answer += vv[i];
    }
    cout << answer;
    return 0;
}