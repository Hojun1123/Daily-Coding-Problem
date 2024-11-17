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
long long arr[10001];
priority_queue <long long, vector<long long>, greater<>> pq;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; ++i) cin >> arr[i];
    sort(arr, arr + N, greater<>());
    int index = 0;
    while (pq.size() < M && index < N) {
        pq.push(arr[index++]);
    }
    long long ans = 0;
    for (int i = index; i < N; ++i) {
        long long curr = pq.top();
        pq.pop();
        //cout << curr <<", "<<  + arr[i] << "\n";
        pq.push(curr + arr[i]);
    }
    while (!pq.empty()) {
        ans = pq.top();
        pq.pop();
    }
    cout << ans;
    return 0;
}