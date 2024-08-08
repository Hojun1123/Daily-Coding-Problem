#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <set>
using namespace std;
int N, arr[100000];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N; for (int i = 0; i < N; ++i) cin >> arr[i];
    int left = 0, right = N - 1, answer = 1100000000;
    while (left < right) {
        int curr = arr[left] + arr[right];
        if (abs(answer) > abs(curr)) {
            answer = curr;
        }
        if (curr < 0) left++;
        else right--;
    }
    cout << answer;
    return 0;
}
