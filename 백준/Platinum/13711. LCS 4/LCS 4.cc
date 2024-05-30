#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
int A[100001];
int B[100001];
int index[100001];
int dp[100001];
int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        // 특정 값이 몇 번 인덱스인지 나타내는 index 배열, A 값에 따른 인덱스 배열로 치환
        index[A[i]] = i;
    }
    int end = 0;
    dp[0] = -1;
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
        // B 배열에는 해당 값의 인덱스를 저장
        B[i] = index[B[i]];
        if (dp[end] < B[i]) {
            // 현재 값이 현재 LIS 값 보다 뒤에 있을 경우
            dp[++end] = B[i];
        }
        else {
            int* idx = lower_bound(dp, dp + end + 1, B[i]);
            *idx = B[i];
        }
    }
    cout << end;
    //for (int i = 0; i <= end; ++i) cout << dp[i] << " ";
    return 0;
 }