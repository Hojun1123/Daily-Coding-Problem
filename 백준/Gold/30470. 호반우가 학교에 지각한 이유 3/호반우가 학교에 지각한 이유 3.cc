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
int N;
// 계단을 만들건데, 
//1 x: 호반우가 길이x의 통나무를 계단 옆에 나란히 세움
//2 x: 마물들이 계단에 위력 x의 마법을 사용
// 새로 세운 통나무는 항상 1번 통나무보다 김/
stack<long long> s;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        long long a, b; 
        cin >> a >> b;
        if (a == 1) {
            s.push(b);
        }
        else {
            if (s.empty()) continue;
            long long now = s.top();
            s.pop();
            s.push(max(now - b, 0LL));
        }
    }

    if (s.empty()) cout << 0;
    else {
        long long ans = 0;
        //기준
        long long prev = s.top();
        while (!s.empty()) {
            long long now = s.top();
            s.pop();
            //현재 통나무가 마지막보다 작거나 같으면. 항상 커짐.->맨뒤에꺼가 가장 큼.
            if (now <= prev) {
                ans += now;
                prev = now;
            }
            else {
                ans += prev;
            }
        }
        cout << ans;
    }
    return 0;
}