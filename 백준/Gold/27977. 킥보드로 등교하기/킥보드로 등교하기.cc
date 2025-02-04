#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;
int L, N, K;
vector<int> ch;
int check(int mid) {
    //cout << "mid: " << mid <<  "\n";
    int pos = 0;
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        //pos + mid까지가도 다음 주유소가 더 멀리 있으면.
        if (pos + mid < ch[i + 1]) {
            if (pos + mid < ch[i]) return 0;
            cnt++;
            pos = ch[i];
            //cout << pos << ", ";
        }
        if (pos + mid >= L) return cnt <= K;
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //수강신청 실패 1교시 개많음
    //킥보드 타자
    //0, L에 집 학교
    //N개의 충전소가 있음
    //최대 K번의 충전소 방문을 할거임
    //최소의 배터리 용량으로 가야한다.
    cin >> L >> N >> K;
    int a;
    int startIndex = 0;
    for (int i = 0; i < N; ++i) {
        cin >> a;
        ch.push_back(a);
    }
    ch.push_back(999999999);
    int left = 0;
    int right = 200222;
    int ans = 999999;
    while (left < right) {
        int mid = (left + right) / 2;
        if (check(mid)) {
            ans = mid;
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    cout << ans;
    return 0;
}