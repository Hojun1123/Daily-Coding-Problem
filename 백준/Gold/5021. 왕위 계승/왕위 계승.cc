#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <string>
#include <unordered_map>
#include <bitset>
#include <stack>
#include <unordered_set>
#include <cstring>
#include <sstream>
using namespace std;
int N, M;
string name;
unordered_map<string, vector<string>> um;
vector<string> v;
unordered_map<string, pair<int, long long>> score;
queue<string> q;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    cin >> name;
    //자식 부모2
    long long initValue = (1LL << 51);
    for (int i = 0; i < N; ++i) {
        string a, b, c;
        cin >> a >> b >> c;
        if (score.find(a) == score.end()) score[a] = { 0, 0 };
        if (score.find(b) == score.end()) score[b] = { 0, 0 };
        if (score.find(c) == score.end()) score[c] = { 0, 0 };
        um[b].push_back(a);
        um[c].push_back(a);
        score[a] = { 2, 0 };    //무조건 in은 2, 부모의 수, 비용.
    }
    for (int i = 0; i < M; ++i) {
        string a;
        cin >> a;
        v.push_back(a);
    }
    score[name] = { 0, initValue };
    for (auto iter : score)
        if (iter.second.first == 0) q.push(iter.first);

    while (!q.empty()) {
        string now = q.front();
        //cout << now << " ";
        q.pop();
        for (auto iter = um[now].begin(); iter != um[now].end(); ++iter)
        {
            string nxt = *iter;
            score[nxt].second += score[now].second;
            if (--score[nxt].first == 0) {
                q.push(nxt);
                score[nxt].second /= 2;
            }
        }
    }
    double minV = 0;
    string ans = "";
    for (auto i : v)
    {
        if (minV < score[i].second) {
            minV = score[i].second;
            ans = i;
        }
    }
    cout << ans;
    return 0;
}